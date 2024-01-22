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


// Start of the exit-screen display  

exit_screen_display(){           

            fillScreen(0x00000000);
            int i=0;  


            // initializing the coordinates for
            // drawing the scrreen.
            // CHoosing the needed colors(tiles) as well.

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

                        drawImage(x,y,&tilemap.images[27]);


                    }
                }

           // initializing the  variables c and d.

            int c=20*32 -78;
            int d= 8*32;

            // Drawing the word  "Y O U"

            drawImage(c,d, &tilemap.images[23]);                                                            
            drawImage(c+32,d, &tilemap.images[17]);
            drawImage(c+32+32,d, &tilemap.images[21]);

            // Drawing the word  "L O S E"

            drawImage(c+32+32+32+32,d, &tilemap.images[47]);
            drawImage(c+32+32+32+32+32,d, &tilemap.images[17]);
            drawImage(c+32+32+32+32+32+32,d, &tilemap.images[19]);
            drawImage(c+32+32+32+32+32+32+32,d, &tilemap.images[10]); 

            c=17*32 -78;

            // initializing the  variables c and d.

            int e= 13*32;

            // Drawing the word  "P R E S S"

            drawImage(c,e, &tilemap.images[50]);
            drawImage(c+32,e, &tilemap.images[18]);
            drawImage(c+32+32,e, &tilemap.images[10]);
            drawImage(c+32+32+32,e, &tilemap.images[19]);
            drawImage(c+32+32+32+32,e, &tilemap.images[19]);

            // Drawing the word  "A N Y"

            drawImage(c+32+32+32+32+32+32,e, &tilemap.images[6]);
            drawImage(c+32+32+32+32+32+32+32,e, &tilemap.images[16]);
            drawImage(c+32+32+32+32+32+32+32+32,e, &tilemap.images[23]);

            // Drawing the word  "B U T T O N"

            drawImage(c+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[49]);
            drawImage(c+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[21]);
            drawImage(c+32+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[20]);               
            drawImage(c+32+32+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[20]);    
            drawImage(c+32+32+32+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[17]);        
            drawImage(c+32+32+32+32+32+32+32+32+32+32+32+32+32+32+32,e, &tilemap.images[16]);   



            struct Arrow arrow={786,352};                                                               // making an instance of the structure.

            int buttons[16];                                                                            // defining the buttons array.
            int dummy[16];                                                                              // defining the dummy array       
            int value;                                                                                  // defining integer value.

            initSNES();                                                                                 // calling initSNES function

            void printf(char *str) {                                                                    // creating the printf function.
                uart_puts(str);                                                                         // using uart_puts.
            }  

            printf("Created By Namit Aneja and Aminreza Abbasi \n");                                    // print statement    
            
            printf("\nPlease press a button ...\n");                                                    // print statement

            for(int i=0 ;i<16;i++){                                                                     // starting the for loop for 16 times because SNES has 16 buttons

                        buttons[i]=1;                                                                   // initializing the buttons array by 1
                        dummy[i]=1;                                                                     // initializing the dummy array by 1.

            }


            while(1){                                                                                   // Statrting a while loop.


                        setCLock();                                                                     // setting the clock pin to 1.

                        setLatch();                                                                     // setting the latch pin to 1.

                        wait(12);                                                                       // waiting for 12 micro seconds.    


                        clearLatch();                                                                   // clearing the latch pin


                        int i=0;                                                                        // initializing variable i by 0.
                        while(i<16){                                                                    // looping till i<16    

                                    wait(6);                                                            // waiting for 6 micro seconds 
                                    clrCLock();                                                         // clearing the clock pin

                                    wait(6);                                                            // waiting for 6 micro seconds

                                    value=readData();                                                   // reading the value from the data pin and save it to the variable "value"


                                    buttons[i]=value;                                                   // storing the values in the buttons array.

                                    setCLock();                                                         // setting the clock.
                                    i++;                                                                // incrementing i by 1.
                        
                        }


            if(state_change(dummy,buttons)){                                                            // checking if the dummy state is different than the buttons state.
                                                                                                        // if yes; then    

                        if(buttons[0]==0){                                                              // if button 0 has been pressed

                            menu_display();                                                             // displaying menu screen

                        }

                        if(buttons[1]==0){                                                              // if button 1 has been pressed
                                                                                                
                                menu_display();                                                         // displaying menu screen
                        }  

                        if(buttons[2]==0){                                                              // if button 2 has been pressed

                                menu_display();                                                         // displaying menu screen
                                                                                               
                        }  

                        if(buttons[3]==0){                                                              // if button 3 has been pressed

                                    menu_display();                                                     // displaying menu screen                                     

                        }    

                        if(buttons[4]==0){                                                              // if button 4 has been pressed          

                                    menu_display();                                                     // displaying menu screen
                                                                                                
                        }    

                        if(buttons[5]==0){                                                              // if button 5 has been pressed

                                    menu_display();                                                     // displaying menu screen
                                                                                                
                        }       

                        if(buttons[6]==0){                                                              // if button 6 has been pressed

                                menu_display();                                                         // displaying menu screen
                                    
                                                                                                
                        }      

                        if(buttons[7]==0){                                                              // if button 8 has been pressed

                                menu_display();                                                         // displaying menu screen
                                                                                                
                        }  

                        if(buttons[8]==0){                                                              // if button 9 has been pressed

                                    menu_display();                                                     // displaying menu screen

                        }   

                        if(buttons[9]==0){                                                              // if button 10 has been pressed

                                menu_display();                                                         // displaying menu screen

                        }             
                        
                        if(buttons[10]==0){                                                             // if button 11 has been pressed

                                    menu_display();                                                     // displaying menu screen
                                                                                                
                        }

                        if(buttons[11]==0){                                                             // if button 12 has been pressed

                                    menu_display();                                                     // displaying menu screen
                                                                                                
                        }    

                        store_state(dummy,buttons);                                                     // call store_state function

                        }

                    } 

}