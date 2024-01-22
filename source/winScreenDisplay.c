/*
Name -Namit Aneja
UCID - 30146188

Name - Aminreza Abbasi 
UCID - 30159887

COURSE -CPSC359
ASSIGNMENT 4 
*/

// included snes.h, framebuffer.h and image.h

#include "snes.h"
#include "framebuffer.h"
#include "image.h"



// This function will display the win screen for the player.
win_screen_display(){

            fillScreen(0x00000000);                                                             // Fill the win screen.
            int i=0;  


                                                                                                // drawing the win screen using while loops.
            while(i<1250){ 
                drawImage(i,0,&tilemap.images[41]);    
                i=i+32;
                        }

            int j=0 ;

            while(j<690){ 
                    drawImage(0,j,&tilemap.images[41]);    
                    j=j+32;
                        }

            int k =0;
            while(k<690){ 
                    drawImage(1250,k,&tilemap.images[41]);    
                    k=k+32;
                        }


            int l =0;
            while(l<1250){ 
                        drawImage(l,690,&tilemap.images[41]);    
                        l=l+32;
                        }

            for(int row =1 ; row <22 ;row++){
                    for(int col =1 ;col<39 ; col++){

                        int x =col*32;
                        int y = row*32;

                        drawImage(x,y,&tilemap.images[27]);                                    // draw the backgorund of the win screen.


                    }
                }


                // initialize the variables c and d.

                int c=20*32 -78;
                int d= 8*32;

                // Draw the following words on the screen: "Y O U" and "W O N"

                drawImage(c,d, &tilemap.images[23]);
                drawImage(c+32,d, &tilemap.images[17]);
                drawImage(c+32+32,d, &tilemap.images[21]);
                drawImage(c+32+32+32+32,d, &tilemap.images[48]);
                drawImage(c+32+32+32+32+32,d, &tilemap.images[13]);
                drawImage(c+32+32+32+32+32+32,d, &tilemap.images[16]);

                // reinitialize the variable c, and initalize the variable e.

                c=17*32 -78;
                int e= 13*32;

                // Draw the following words on the screen "P R E S S ", "A N Y" and "B U T T O N"

                drawImage(c,e, &tilemap.images[50]);
                drawImage(c+32,e, &tilemap.images[18]);
                drawImage(c+32+32,e, &tilemap.images[10]);
                drawImage(c+32+32+32,e, &tilemap.images[19]);
                drawImage(c+32+32+32+32,e, &tilemap.images[19]);
                drawImage(c+32+32+32+32+32+32,e, &tilemap.images[6]);
                drawImage(c+32+32+32+32+32+32+32,e, &tilemap.images[16]);
                drawImage(c+32+32+32+32+32+32+32+32,e, &tilemap.images[23]);
                drawImage(c+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[49]);
                drawImage(c+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[21]);
                drawImage(c+32+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[20]);               
                drawImage(c+32+32+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[20]);    
                drawImage(c+32+32+32+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[17]);        
                drawImage(c+32+32+32+32+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[16]);   
                    

                        int buttons[16];                                                                   // defining the buttons array.
                        int dummy[16];                                                                     // defining the dummy array       
                        int value;                                                                         // defining integer value.

                        initSNES();                                                                        // calling initSNES function

                        void printf(char *str) {                                                           // creating the printf function.
                            uart_puts(str);                                                                // using uart_puts.
                        }  

                        printf("Created By Namit Aneja and Aminreza Abbasi \n");                           // print statement    
                        
                        printf("\nPlease press a button ...\n");                                           // print statement

                        for(int i=0 ;i<16;i++){                                                            // starting the for loop for 16 times because SNES has 16 buttons

                                    buttons[i]=1;                                                          // initializing the buttons array by 1
                                    dummy[i]=1;                                                            // initializing the dummy array by 1.

                        }


                        // Statrting a while loop.
                        while(1){                                                                                   


                                    setCLock();                                                            // setting the clock pin to 1.

                                    setLatch();                                                            // setting the latch pin to 1.

                                    wait(12);                                                              // waiting for 12 micro seconds.    

                                    clearLatch();                                                          // clearing the latch pin

                                    int i=0;                                                               // initializing variable i by 0.
                                    while(i<16){                                                           // looping till i<16    

                                                wait(6);                                                   // waiting for 6 micro seconds 
                                                clrCLock();                                                // clearing the clock pin

                                                wait(6);                                                   // waiting for 6 micro seconds

                                                value=readData();                                          // reading the value from the data pin and save it to the variable "value"

                                                buttons[i]=value;                                          // storing the values in the buttons array.

                                                setCLock();                                                // setting the clock.
                                                i++;                                                       // incrementing i by 1.                                    
                                    }

                        // checking if the dummy state is different than the buttons state.
                        // if yes; then 

                        if(state_change(dummy,buttons)){                                                   
                                                                                                                      
                                    if(buttons[0]==0){                                                     // if button 1 has been pressed

                                        menu_display();                                                    // call menu display
                                    }

                                    if(buttons[1]==0){                                                     // if button 2 has been pressed
                                                                                                           
                                            menu_display();                                                // call menu display
                                    }  

                                    if(buttons[2]==0){                                                     // if button 3 has been pressed

                                            menu_display();                                                // call menu display
                                    }  

                                    if(buttons[3]==0){                                                     // if button 4 has been pressed

                                             menu_display();                                               // call menu display.
                                    }    

                                    if(buttons[4]==0){                                                     // if button 5 has been pressed          

                                              menu_display();                                              // Call menu display.
                                    }    

                                    if(buttons[5]==0){                                                     // if button 6 has been pressed

                                              menu_display();                                              // call menu display.         
                                    }       

                                    if(buttons[6]==0){                                                     // if button 7 has been pressed

                                          menu_display();                                                  // call menu display.
                                             
                                    }      

                                    if(buttons[7]==0){                                                     // if button 8 has been pressed

                                            menu_display();                                                // call menu display.
                                                                                                           
                                    }  

                                    if(buttons[8]==0){                                                     // if button 9 has been pressed

                                             menu_display();                                               // call menu display.

                                    }   

                                    if(buttons[9]==0){                                                     // if button 10 has been pressed

                                           menu_display();                                                 // call menu display

                                    }             
                                    
                                    if(buttons[10]==0){                                                    // if button 11 has been pressed

                                             menu_display();                                               // call menu display
                                                                                                           
                                    }

                                    if(buttons[11]==0){                                                    // if button 12 has been pressed

                                             menu_display();                                               // call menu display.
                                                                                                           
                                    }    
                                    store_state(dummy,buttons);                                            // call store_state function
                                    }
   
                                    }

}