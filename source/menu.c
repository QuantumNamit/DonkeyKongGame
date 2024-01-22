/*
Name -Namit Aneja
UCID - 30146188

Name - Aminreza Abbasi 
UCID - 30159887

COURSE -CPSC359
ASSIGNMENT 4 
*/

// included snes.h and framebuffer. and image.h 

#include "snes.h"
#include "framebuffer.h"
#include "image.h"

// Create the struct Arrow for the exit screen

struct Arrow{
     
     int x;
     int y;

};

// Start of the menu display function
void menu_display(){

     // initializing the coordinates for
     // drawing the scrreen.
     // CHoosing the needed colors(tiles) as well.

     fillScreen(0x00000000);
     int i=0;  

     while(i<1250){ 
     drawImage(i,0,&tilemap.images[3]);    
     i=i+32;
          }

     int j=0 ;

     while(j<690){ 
     drawImage(0,j,&tilemap.images[3]);    
     j=j+32;
          }

     int k =0;
     while(k<690){ 
     drawImage(1250,k,&tilemap.images[3]);    
     k=k+32;
          }


     int l =0;
     while(l<1250){ 
          drawImage(l,690,&tilemap.images[3]);    
          l=l+32;
          }

     for(int row =1 ; row <22 ;row++){
     for(int col =1 ;col<39 ; col++){

          int x =col*32;
          int y = row*32;

          drawImage(x,y,&tilemap.images[4]);


     }
     }


     int a= 15*32;
     int b= 2*32;

     // Drawing the word  "D O N K E Y K O N G "
     drawImage(a, b, &tilemap.images[9]);
     drawImage(a+32, b, &tilemap.images[17]);

     drawImage(a+64, b, &tilemap.images[16]);
     drawImage(a+96, b, &tilemap.images[14]);
     drawImage(a+96+32, b, &tilemap.images[10]);
     drawImage(a+96+64, b, &tilemap.images[23]);
     
     drawImage(a+96+64+32, b, &tilemap.images[2]);
     drawImage(a+96+64+64, b, &tilemap.images[14]);
     drawImage(a+96+64+96, b, &tilemap.images[17]);

     drawImage(a+96+64+96+32, b, &tilemap.images[16]);
     drawImage(a+96+64+96+32+32, b, &tilemap.images[11]);


     // Drawing the word  "C R E A T E D B Y "
     drawImage(a, b+64, &tilemap.images[8]);
     drawImage(a+32, b+64, &tilemap.images[18]);
     drawImage(a+32+32, b+64, &tilemap.images[10]);
     drawImage(a+32+32+32, b+64, &tilemap.images[6]);
     drawImage(a+32+32+32+32, b+64, &tilemap.images[20]);
     drawImage(a+32+32+32+32+32, b+64, &tilemap.images[10]);
     drawImage(a+32+32+32+32+32+32, b+64, &tilemap.images[9]);
     drawImage(a+32+32+32+32+32+32+64, b+64, &tilemap.images[4]);
     drawImage(a+32+32+32+32+32+32+64+32, b+64, &tilemap.images[7]);
     drawImage(a+32+32+32+32+32+32+64+32+32, b+64, &tilemap.images[23]);

     // Drawing the word  "N A M I T  "
     drawImage(a-64, b+128, &tilemap.images[16]);
     drawImage(a-64+32, b+128, &tilemap.images[6]);
     drawImage(a-64+32+32, b+128, &tilemap.images[15]);
     drawImage(a-64+32+32+32, b+128, &tilemap.images[13]);
     drawImage(a-64+32+32+32+32, b+128, &tilemap.images[20]);

     // Drawing the word  "A N D "
     drawImage(a-64+32+32+32+32+64, b+128, &tilemap.images[6]);
     drawImage(a-64+32+32+32+32+64+32, b+128, &tilemap.images[16]);
     drawImage(a-64+32+32+32+32+64+32+32, b+128, &tilemap.images[9]);

     // Drawing the word  "A M I N "
     drawImage(a-64+32+32+32+32+64+32+32+64, b+128, &tilemap.images[6]);
     drawImage(a-64+32+32+32+32+64+32+32+64+32, b+128, &tilemap.images[15]);
     drawImage(a-64+32+32+32+32+64+32+32+64+32+32, b+128, &tilemap.images[13]);
     drawImage(a-64+32+32+32+32+64+32+32+64+32+32+32, b+128, &tilemap.images[16]);


     int c=20*32 -78;
     int d= 11*32;
     // Drawing the word  "S T A R T "
     drawImage(c,d, &tilemap.images[19]);
     drawImage(c+32,d, &tilemap.images[20]);
     drawImage(c+32+32,d, &tilemap.images[6]);
     drawImage(c+32+32+32,d, &tilemap.images[18]);
     drawImage(c+32+32+32+32,d, &tilemap.images[20]);

     drawImage(786,352, &tilemap.images[5]);

     // Drawing the word  "E X I T "
     drawImage(c+15,d+96, &tilemap.images[10]);
     drawImage(c+15+32,d+96, &tilemap.images[22]);
     drawImage(c+15+32+32,d+96, &tilemap.images[13]);
     drawImage(c+15+32+32+32,d+96, &tilemap.images[20]);





struct Arrow arrow={786,352};

int buttons[16];                                                                            // defining the buttons array.
int dummy[16];                                                                              // defining the dummy array       
int value;                                                                                  // defining integer value.

initSNES();                                                                                 // calling initSNES function

void printf(char *str) {                                                                    // creating the printf function.
     uart_puts(str);                                                                        // using uart_puts.
}  

printf("Created By Namit Aneja and Aminreza Abbasi \n");                                    // print statement    

printf("\nPlease press a button ...\n");                                                    // print statement

for(int i=0 ;i<16;i++){                                                                     // starting the for loop for 16 times because SNES has 16 buttons

          buttons[i]=1;                                                                     // initializing the buttons array by 1
          dummy[i]=1;                                                                       // initializing the dummy array by 1.

}


while(1){                                                                                   // Statrting a while loop.


          setCLock();                                                                       // setting the clock pin to 1.

          setLatch();                                                                       // setting the latch pin to 1.

          wait(12);                                                                         // waiting for 12 micro seconds.    


          clearLatch();                                                                     // clearing the latch pin


          int i=0;                                                                          // initializing variable i by 0.
          while(i<16){                                                                      // looping till i<16    

                         wait(6);                                                           // waiting for 6 micro seconds 
                         clrCLock();                                                        // clearing the clock pin

                         wait(6);                                                           // waiting for 6 micro seconds

                         value=readData();                                                  // reading the value from the data pin and save it to the variable "value"


                         buttons[i]=value;                                                  // storing the values in the buttons array.


                         setCLock();                                                        // setting the clock.
                         i++;                                                               // incrementing i by 1.
               
          }

          
          if(state_change(dummy,buttons)){                    

                                   level1();
                              }


                              else if(arrow.y==446){
                                   fillScreen(0x00000000);
                              }

                              
                              printf("\nPlease press a button ...\n");                      // print statement
                              wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                            // because of the hardware issues
                         }  

                         if(buttons[4]==0){                                                 // if button 5 has been pressed          

                              printf("\nYou have pressed Joy-pad UP\n");                    // print statement.

                              if(arrow.y==446){

                                   arrow.y=352;
                                   drawImage(arrow.x, arrow.y,&tilemap.images[5]);
                                   drawImage(arrow.x,446,&tilemap.images[4]);

                              }
                              printf("\nPlease press a button ...\n");                      // print statement.
                              wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                            // because of the hardware issues
                         }    

                         if(buttons[5]==0){                                                 // if button 6 has been pressed

                              printf("\nYou have pressed Joy-pad DOWN\n");                  // print statement

                              drawImage(arrow.x,arrow.y,&tilemap.images[4]);
                              arrow.y=446;
                              drawImage(arrow.x, arrow.y,&tilemap.images[5]);


                              printf("\nPlease press a button ...\n");                      // print statement.
                              wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                            // because of the hardware issues
                         }       

                         
                         store_state(dummy,buttons);                                        // call store_state function

                         }
          






