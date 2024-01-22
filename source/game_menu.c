/*
Name -Namit Aneja
UCID - 30146188

Name - Aminreza Abbasi 
UCID - 30159887

COURSE -CPSC359
ASSIGNMENT 4 
*/

// Include the snes.h , framebuffer.h and image.h.

#include "snes.h"
#include "framebuffer.h"
#include "image.h"


// create  the struct Arrow.

struct Arrow{                
     int x;
     int y;
};

// start of the game_menu function. This function will
// display the menu of the game.

void game_menu(){

// This for loop will draw the menu of the game.

     for(int row =10 ; row <17 ;row++){
          for(int col =15 ;col<26 ; col++){
               int x =col*32;
               int y = row*32;
               drawImage(x,y,&tilemap.images[27]);
          }
          }

          // initialize the needed variables c and d

          int c=20*32 -78;
          int d= 11*32;


          // draw the word  "S T A R T "

          drawImage(c,d, &tilemap.images[19]);
          drawImage(c+32,d, &tilemap.images[20]);
          drawImage(c+32+32,d, &tilemap.images[6]);
          drawImage(c+32+32+32,d, &tilemap.images[18]);
          drawImage(c+32+32+32+32,d, &tilemap.images[20]);

          drawImage(786,352, &tilemap.images[5]);

          // draw the word  "E X I T "

          drawImage(c+15,d+96, &tilemap.images[10]);
          drawImage(c+15+32,d+96, &tilemap.images[22]);
          drawImage(c+15+32+32,d+96, &tilemap.images[13]);
          drawImage(c+15+32+32+32,d+96, &tilemap.images[20]);





          struct Arrow arrow={786,352};                                                               // Making an instance for the structue. 

          int buttons[16];                                                                            // defining the buttons array.
          int dummy[16];                                                                              // defining the dummy array       
          int value;                                                                                  // defining integer value.

          initSNES();                                                                                 // calling initSNES function

          void printf(char *str) {                                                                    // creating the printf function.
          uart_puts(str);                                                                             // using uart_puts.
          }  

          printf("Created By Namit Aneja and Aminreza Abbasi \n");                                    // print statement    
     
          printf("\nPlease press a button ...\n");                                                    // print statement

          for(int i=0 ;i<16;i++){                                                                     // starting the for loop for 16 times because SNES has 16 buttons

               buttons[i]=1;                                                                          // initializing the buttons array by 1
               dummy[i]=1;                                                                            // initializing the dummy array by 1.

          }


          while(1){                                                                                   // Statrting a while loop.


               setCLock();                                                                            // setting the clock pin to 1.

               setLatch();                                                                            // setting the latch pin to 1.

               wait(12);                                                                              // waiting for 12 micro seconds.    


               clearLatch();                                                                          // clearing the latch pin


               int i=0;                                                                               // initializing variable i by 0.
               while(i<16){                                                                           // looping till i<16    

                              wait(6);                                                                // waiting for 6 micro seconds 
                              clrCLock();                                                             // clearing the clock pin

                              wait(6);                                                                // waiting for 6 micro seconds

                              value=readData();                                                       // reading the value from the data pin and save it to the variable "value"


                              buttons[i]=value;                                                       // storing the values in the buttons array.


                              setCLock();                                                             // setting the clock.
                              i++;                                                                    // incrementing i by 1.
                    
               }

               
               if(state_change(dummy,buttons)){                                                       // checking if the dummy state is different than the buttons state.


                              if(buttons[8]==0){                                                      // if button 9 has been pressed

                                        printf("\nYou have pressed A\n");                             // print statement 

                                        if(arrow.y==352){

                                             level1();                                                // call level 1 to show the other code.
                                        }

                                        else if(arrow.y==446){
                                        fillScreen(0x00000000);
                                        }

                                        
                                        printf("\nPlease press a button ...\n");                      // print statement
                                        wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                      // because of the hardware issues
                              }  

                              if(buttons[4]==0){                                                      // if button 5 has been pressed          

                                        printf("\nYou have pressed Joy-pad UP\n");                    // print statement.

                                        if(arrow.y==446){

                                             arrow.y=352;
                                             drawImage(arrow.x, arrow.y,&tilemap.images[5]);
                                             drawImage(arrow.x,446,&tilemap.images[27]);

                                        }
                                        printf("\nPlease press a button ...\n");                      // print statement.
                                        wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                      // because of the hardware issues
                              }    

                              if(buttons[5]==0){                                                      // if button 6 has been pressed

                                        printf("\nYou have pressed Joy-pad DOWN\n");                  // print statement

                                        drawImage(arrow.x,arrow.y,&tilemap.images[27]);
                                        arrow.y=446;
                                        drawImage(arrow.x, arrow.y,&tilemap.images[5]);


                                        printf("\nPlease press a button ...\n");                       // print statement.
                                        wait(1000000/7);                                               // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                       // because of the hardware issues
                              }       

                              
                              store_state(dummy,buttons);                                              // call store_state function

                              }
     } 
}
