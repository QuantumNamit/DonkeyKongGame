/*
Name -Namit Aneja
UCID - 30146188

Name - Aminreza Abbasi 
UCID - 30159887

COURSE -CPSC359
ASSIGNMENT 4 
*/

#include "gpio.h"


#define CLO_REG   0XFE003004                                                                        // defining CLO_REG base address
#define GPIO_BASE 0xFE200000                                                                        // defining GPIO_BASE address

static unsigned * gpio =(unsigned *)GPIO_BASE ;                                                     // defining the pointer gpio storing the address of GPIO_BASE


#define INP_GPIO(g)  *(gpio +((g)/10))&= ~(7 <<((g%10)*3))                                          // defining the INP_GPIO
#define OUT_GPIO(g)  *(gpio +((g)/10))|= (1 <<((g%10)*3))                                           // defining the OUT_GPIO



#define  CLK       11                                                                               // Pin for CLOCK line in 11
#define  LAT       9                                                                                // Pin for LATCH line is  9 
#define  DAT       10                                                                               // Pin for the DATA  line is 10




void initSNES(){                                                                                     // function to intialise the SNES controller

               INP_GPIO(CLK);                                                                        // setting the clock line to input function
               OUT_GPIO(CLK);                                                                        // setting the clock line to output function
   
               INP_GPIO(LAT);                                                                        //  setting the latch line to input function
               OUT_GPIO(LAT);                                                                        //  setting the latch line to output function

               INP_GPIO(DAT);                                                                        //  setting the Data line to input function

               }



void setLatch(){                                                                                     // function to set the latch pin  

               *GPSET0|=1<< LAT;                                                                     //  setting the latch pin to 1

               }

void clearLatch(){                                                                                    // function to clear the latch pin        

               *GPCLR0|=1<< LAT;                                                                      //  clearing the latch pin to 1

                  }



void setCLock(){                                                                                      // function to set the clock pin  

               *GPSET0|=1<< CLK;                                                                      //  setting the clock pin to 1

               }

void clrCLock(){                                                                                      //  function to clear the clock pin

               *GPCLR0|=1<< CLK;                                                                      //  clearing the clock pin to 0
   
               }


int readData(){                                                                                       // function to read the data pin  

               int v;                                                                                 // declaring a integer v
               v=(*GPLEV0>>DAT) & 1;                                                                  // storing the value of data pin 

               return v;                                                                              // returning the value of the data pin 

              }

void setDatapin(){                                                                                    // function to set the data pin     

               *GPSET0|=1<< DAT;                                                                      // setting the data pin to 1

               }


void wait(int time){                                                                                   // function to wait  Wwith time as the parameter

               unsigned *clo= (unsigned*) CLO_REG;                                                     // declaring the pointer to the the CLO_REG           
               unsigned c=*clo+time;                                                                   // adding the parameter time to the rpi clock 
               while(c>*clo);                                                                          // making it wait

               }

int state_change(int dummy[],int buttons[]){                                                            // function to check whether the state has been chnage or not


               for(int i =0 ;i<16;i++){                                                                 // starting the for loop for 16 times because SNES has 16 buttons
                  
                    if(dummy[i] != buttons[i]){                                                          // if the any value inside the dummy array different than the value inside the buttons array return 1
                     return 1 ;

                  }
                  } 
               return 0;                                                                                  // else return 0;

               }

void store_state(int dummy[],int buttons[]){                                                              // function to store the state of the buttons array to the dummy array

               for(int i =0 ;i<16;i++){                                                                   // starting the for loop for 16 times because SNES has 16 buttons     

                   dummy[i] = buttons[i];                                                                 //  storing the values

               }

               }
               
