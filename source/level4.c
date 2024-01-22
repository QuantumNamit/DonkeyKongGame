/*
Name -Namit Aneja
UCID - 30146188

Name - Aminreza Abbasi 
UCID - 30159887

COURSE -CPSC359
ASSIGNMENT 4 
*/

// included image.h, framebuffer.h and define CLO_REG variable.
#include "image.h"
#include  "framebuffer.h"
#define CLO_REG   0XFE003004  
                                                                                          
// Create the structure for the PLayer.
struct Player{
      int x ;
      int y;
};

// initialize two integer arrays.
int donkeyKongPosition[2];
int donkeyKongCollision[2];


// defining siX counters for the health packs.

int health_pack_counter4_a=0;
int health_pack_counter4_b=0;
int health_pack_counter4_c=0;
int health_pack_counter4_d=0;
int health_pack_counter4_e=0;
int health_pack_counter4_f=0;

char str[3];                                                                              // define an array of characters.

// start of the border-draw function, this function will draw the borders of the string.
// by using the while loops and drawImage function.

void border_draw4(){                                                                      
                                                                                          
            int i=2;  
             while(i<36){ 
               drawImage(i*32,2*32,&tilemap.images[45]);    
               i=i+1;
             }
     
             drawImage(37*32,2*32,&tilemap.images[45]);    

             int j=2 ;

            while(j<20){ 
               drawImage(2*32,j*32,&tilemap.images[45]);    
               j=j+1;
             }

            int k =2;
            while(k<20){ 
               drawImage(37*32,k*32,&tilemap.images[45]);    
               k=k+1;
             }


            int l =2;
            while(l<38){ 
               drawImage(l*32,20*32,&tilemap.images[45]);    
               l=l+1;
             }

            for(int i =2 ;i<38;i++){

             drawImage(i*32,21*32,&tilemap.images[4]);
      }
}

 // start of the drawLevel4. This function will create/draw the game screen.
 // by using nested for-loops and normal for-loops.

void drawLevel4( unsigned int level[22][39] )
{
      for(int row =3 ; row <20 ;row++){
         for(int col =3 ;col<37 ; col++){
             unsigned int imageNumber =level[row][col];
             int x =col*32;
             int y = row*32;
             drawImage(x,y,&tilemap.images[44]);
         }
      }
      
      // drawiing the walls of the level 4.
      for(int i=4;i<19;i++){
          drawImage(5*32,i*32,&tilemap.images[46]);

      }
        for(int i=5;i<36;i++){
          drawImage(i*32,4*32,&tilemap.images[46]);

      }


        for(int i=6;i<19;i++){
           drawImage(7*32,i*32,&tilemap.images[46]);

       }

         for(int i=7;i<36;i++){
           drawImage(i*32,6*32,&tilemap.images[46]);

       }   

        for(int i=8;i<19;i++){
           drawImage(9*32,i*32,&tilemap.images[46]);

       }

         for(int i=9;i<36;i++){
           drawImage(i*32,8*32,&tilemap.images[46]);

       }  

        for(int i=10;i<19;i++){
           drawImage(11*32,i*32,&tilemap.images[46]);

       }

         for(int i=11;i<36;i++){
           drawImage(i*32,10*32,&tilemap.images[46]);

       } 

       
        for(int i=12;i<19;i++){
           drawImage(13*32,i*32,&tilemap.images[46]);

       }

         for(int i=13;i<36;i++){
           drawImage(i*32,12*32,&tilemap.images[46]);

       }  

         for(int i=14;i<19;i++){
           drawImage(15*32,i*32,&tilemap.images[46]);

       }

         for(int i=15;i<36;i++){
           drawImage(i*32,14*32,&tilemap.images[46]);

       } 
 
          for(int i=16;i<19;i++){
           drawImage(17*32,i*32,&tilemap.images[46]);

       }

         for(int i=17;i<36;i++){
           drawImage(i*32,16*32,&tilemap.images[46]);

       } 

        drawImage(35*32,5*32,&tilemap.images[46]);
        drawImage(35*32,9*32,&tilemap.images[46]);
        drawImage(35*32,11*32,&tilemap.images[46]);
        drawImage(35*32,13*32,&tilemap.images[46]);
        drawImage(35*32,15*32,&tilemap.images[46]);



      // drawing the ladders of the level 4.

      for(int i=10;i<16;i++){
      drawImage(20*32,i*32,&tilemap.images[26]);
      }
      for(int i=2;i<4;i++){
      drawImage(36*32,i*32,&tilemap.images[26]);
      }

      // drawing the word "T I M E " on the bottom of the screen.
      drawImage(2*32,21*32,&tilemap.images[20]);
      drawImage(3*32,21*32,&tilemap.images[13]);
      drawImage(4*32,21*32,&tilemap.images[15]);      
      drawImage(5*32,21*32,&tilemap.images[10]);


      // drawing the word "S C O R E" on the bottom of the screen.
      drawImage(16*32,21*32,&tilemap.images[19]);
      drawImage(17*32,21*32,&tilemap.images[8]);
      drawImage(18*32,21*32,&tilemap.images[17]);      
      drawImage(19*32,21*32,&tilemap.images[18]);
      drawImage(20*32,21*32,&tilemap.images[10]);


      // drawing the hearts shapes, count on them as a game health.
      drawImage(32*32,21*32,&tilemap.images[25]);
      drawImage(34*32,21*32,&tilemap.images[25]);
      drawImage(36*32,21*32,&tilemap.images[25]);      


}

// Start of the health-packs function, which will draw the healthpacks on the screen of level 4.

void health_packs4(){

      drawImage(6*32,3*32,&tilemap.images[30]);
      drawImage(10*32,7*32,&tilemap.images[30]);    
      drawImage(21*32,9*32,&tilemap.images[30]);  
      drawImage(24*32,18*32,&tilemap.images[30]);
      drawImage(26*32,11*32,&tilemap.images[30]);  
      drawImage(28*32,13*32,&tilemap.images[30]);  
}

 // Start of the donkeyKong-gets-healthpacks function, it will check whether the
// donkeyKong gets the healthpacks or not.
// we can do this by comparing the donkeyKong position with the healthpacks position.

int donkeyKong_gets_healthpack4(struct Player donkeyKong ,int timeLeft){

// the healthpacks should be appeared after 10 seconds.

if(timeLeft<=50){                                                                     
     if((donkeyKong.x==6) && (donkeyKong.y==3) ){
      if(health_pack_counter4_a==0){
        health_pack_counter4_a=1;
        return 1;
      }     
      }

     if((donkeyKong.x==10) && (donkeyKong.y==7) ){
      if(health_pack_counter4_b==0){
        health_pack_counter4_b=1;
        return 1;
      }     
      }
     if((donkeyKong.x==21) && (donkeyKong.y==9) ){
      if(health_pack_counter4_c==0){
        health_pack_counter4_c=1;
        return 1;
      }     
      }
     if((donkeyKong.x==24) && (donkeyKong.y==18) ){
      if(health_pack_counter4_d==0){
        health_pack_counter4_d=1;
        return 1;
      }     
      }
     if((donkeyKong.x==26) && (donkeyKong.y==11) ){
      if(health_pack_counter4_e==0){
        health_pack_counter4_e=1;
        return 1;
      }   
     }
      if((donkeyKong.x==28) && (donkeyKong.y==13) ){
      if(health_pack_counter4_f==0){
        health_pack_counter4_f=1;
        return 1;
      }   
     }    
}
return 0;
}

// If the donkey-Kong reaches the ladder, it will change the position of the donkey kong.
// It will do this by comparing the donkey kong coordinate and ladder coordinate. 

int if_donkey_kong_reached_ladder4(struct Player donkeyKong){


    for(int i =10 ;i<16;i++){

       if((donkeyKong.x==20) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=20;
            donkeyKongPosition[1]=9;

            donkeyKong.y=9;
            return 1;
       }

      }
      for(int i =2 ;i<4;i++){

       if((donkeyKong.x==36) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=36;
            donkeyKongPosition[1]=1;

            donkeyKong.y=1;
            return 1;
       }
      }
      return 0;
}

// This function will check whether the boundary collision has happened or not. 
// by comparing the position of donkeyKong with the position of borders.

int boundary_collisions4(struct Player donkeyKong){

 
    for(int i=2 ; i<36 ;i++) {
 
        if((donkeyKong.x==i) && ( donkeyKong.y==2)){
             return 1;
        }
      }

      if((donkeyKong.x==37) && ( donkeyKong.y==2)){
             return 1;
        }

      int j=2 ;

    while(j<20){ 

        if((donkeyKong.x==2) && ( donkeyKong.y==j)){
             return 1;
        }
        j=j+1;
      }

    int k =2;
    while(k<20){ 

        if((donkeyKong.x==37) && ( donkeyKong.y==k)){
           return 1;
        }
        k=k+1;
      }


    int l =2;
    while(l<38){ 
        if((donkeyKong.x==l) && ( donkeyKong.y==20)){
             return 1;
        }       
        l=l+1;
      }


     for(int i=4;i<19;i++){

        if((donkeyKong.x==5) && ( donkeyKong.y==i)){
              return 1;
        }  

      }
      for(int i=5;i<36;i++){

         if((donkeyKong.x==i) && ( donkeyKong.y==4)){
             return 1;
        }              

      }


      for(int i=6;i<19;i++){

          if((donkeyKong.x==7) && ( donkeyKong.y==i)){
             return 1;
          }  

       }

      for(int i=7;i<36;i++){

         if((donkeyKong.x==i) && ( donkeyKong.y==6)){
             return 1;
        }  

       }   

      for(int i=8;i<19;i++){
            if((donkeyKong.x==9) && ( donkeyKong.y==i)){
             return 1;
        }  

       }

      for(int i=9;i<36;i++){
         if((donkeyKong.x==i) && ( donkeyKong.y==8)){
             return 1;
        }  

       }  

      for(int i=10;i<19;i++){
        if((donkeyKong.x==11) && ( donkeyKong.y==i)){
             return 1;
        }  

       }

      for(int i=11;i<36;i++){
          if((donkeyKong.x==i) && ( donkeyKong.y==10)){
             return 1;
        }  

       } 

       
      for(int i=12;i<19;i++){
        if((donkeyKong.x==13) && ( donkeyKong.y==i)){
             return 1;
        }  

       }

      for(int i=13;i<36;i++){
        if((donkeyKong.x==i) && ( donkeyKong.y==12)){
             return 1;
        }  

       }  

      for(int i=14;i<19;i++){
          if((donkeyKong.x==15) && ( donkeyKong.y==i)){
             return 1;
          }  

       }

      for(int i=15;i<36;i++){
          if((donkeyKong.x==i) && ( donkeyKong.y==14)){
             return 1;
        }  

       } 
 
      for(int i=16;i<19;i++){
        if((donkeyKong.x==17) && ( donkeyKong.y==i)){
             return 1;
        }  

       }

      for(int i=17;i<36;i++){
        if((donkeyKong.x==i) && ( donkeyKong.y==16)){
             return 1;
        }  

       } 

return 0;

}



// This function will draw the obstacles for level 4.

void obstacles4(struct Player donkeyKong){

       drawImage(25*32,3*32,&tilemap.images[24]);
       drawImage(30*32,3*32,&tilemap.images[24]);
       drawImage(35*32,3*32,&tilemap.images[24]);

       drawImage(36*32,13*32,&tilemap.images[24]);
       drawImage(36*32,6*32,&tilemap.images[24]);
       drawImage(36*32,8*32,&tilemap.images[24]);

       drawImage(8*32,5*32,&tilemap.images[24]);
       drawImage(11*32,7*32,&tilemap.images[24]);
       drawImage(14*32,9*32,&tilemap.images[24]);
       drawImage(17*32,11*32,&tilemap.images[24]);
       drawImage(21*32,13*32,&tilemap.images[24]);
       drawImage(24*32,15*32,&tilemap.images[24]);
       drawImage(16*32,9*32,&tilemap.images[24]);
       drawImage(18*32,9*32,&tilemap.images[24]);

       drawImage(3*32,7*32,&tilemap.images[24]);
       drawImage(4*32,11*32,&tilemap.images[24]);
       drawImage(3*32,14*32,&tilemap.images[24]);

}



// This function will check whether the donkeyKong hits the obstacles or not.
// By comparing the donkeyKong position with the obstacles position.

int donkeyKong_hits_obstacle4(struct Player donkeyKong){

            if((donkeyKong.x==25)&& (donkeyKong.y==3)){             
                  return 1;
            }

            if((donkeyKong.x==30)&& (donkeyKong.y==3)){              
                  return 1;
            }

            if((donkeyKong.x==35)&& (donkeyKong.y==3)){              
                  return 1;
            }

            if((donkeyKong.x==36)&& (donkeyKong.y==13)){             
                  return 1;
            }  

            if((donkeyKong.x==36)&& (donkeyKong.y==6)){             
                  return 1;
            }

            if((donkeyKong.x==36)&& (donkeyKong.y==8)){              
                  return 1;
            }     

            if((donkeyKong.x==8)&& (donkeyKong.y==5)){             
                  return 1;
           }

            if((donkeyKong.x==11)&& (donkeyKong.y==7)){             
                  return 1;
            }  

            if((donkeyKong.x==14)&& (donkeyKong.y==9)){             
                  return 1;
            }  

            if((donkeyKong.x==17)&& (donkeyKong.y==11)){             
                  return 1;
            }  

            if((donkeyKong.x==21)&& (donkeyKong.y==13)){              
                  return 1;
            } 

            if((donkeyKong.x==24)&& (donkeyKong.y==15)){              
                  return 1;
            }      
            if((donkeyKong.x==16)&& (donkeyKong.y==9)){              
                  return 1;
            } 
            if((donkeyKong.x==18)&& (donkeyKong.y==9)){              
                  return 1;
            }
            if((donkeyKong.x==3)&& (donkeyKong.y==7)){              
                  return 1;
            }   
            if((donkeyKong.x==4)&& (donkeyKong.y==11)){              
                  return 1;
            } 

            if((donkeyKong.x==3)&& (donkeyKong.y==14)){              
                  return 1;
            }                                                                                  
      
            return 0;
}

  // This function will implement all the necessary code for level 4.

  void level4(){

               // defining variables.                                                                                         
               int p_3=0;
               int health_pack_timer_constant=0;
               int storing_time=0;
               unsigned clo= (unsigned) CLO_REG; 
               unsigned int game_starts_at= *clo;
               unsigned int game_ends_at=game_starts_at +(65* 1000000);                                   // calculate time of each level, which is 60 minutes.  

               unsigned int level[22][38];

               for(int i=0 ; i<22 ; i++){

                  for(int j=0 ; j<38;j++){

                      level[i][j]=0;
                  }
               }

                fillScreen(0x00000000);                                                                    // This line will draw the screen of the game.

                struct Player donkeyKong ={3,19};                                                          // Create an instance of the Player structure.

                border_draw4();                                                                            // Draw the borders of level 4 screen

                drawLevel4(level);                                                                         // Draw the whole game screen for level 4.
                drawImage(donkeyKong.x *32 , donkeyKong.y *32 , &tilemap.images[2]);                       // Draw the donkey Kong
                obstacles4(donkeyKong);                                                                    // Draw the obstacles.
                drawString(2,2,"Welcome to Level 4 :)", 0x4F);                                             // draw the string on the top=left of the screen.
                drawImage(22*32,21*32,&tilemap.images[34]);                                                // draw the game's time, which is 15.

               int buttons[16];                                                                            // defining the buttons array.
               int dummy[16];                                                                              // defining the dummy array       
               int value;                                                                                  // defining integer value.

               void printf(char *str) {                                                                    // creating the printf function.
                  uart_puts(str);                                                                          // using uart_puts.
               }  

               for(int i=0 ;i<16;i++){                                                                     // starting the for loop for 16 times because SNES has 16 buttons

                        buttons[i]=1;                                                                      // initializing the buttons array by 1
                        dummy[i]=1;                                                                        // initializing the dummy array by 1.

               }

               initSNES();                                                                                 // calling initSNES fnuction.


               while(1){                                                                                   // Statrting a while loop.
    
                                                                                                           // defining the variables current time and time=left-seconds.
                        unsigned int current_time=*clo;                     
                        unsigned int time_left_seconds=(game_ends_at-current_time)/1000000;

                            if((time_left_seconds==50) && (health_pack_timer_constant==0) ){               // The healthpacks will be appeared after 10 seconds.
                            health_packs4();
                            health_pack_timer_constant=1;
                        }

                        if(time_left_seconds==0){                                                          // If the time is over, initialize the counters for healthpacks
                                                                                                           // by zero, then call the exit-screen-display.
                             health_pack_counter4_a=0;
                             health_pack_counter4_b=0;
                             health_pack_counter4_c=0;
                             health_pack_counter4_d=0;
                             health_pack_counter4_e=0;
                             health_pack_counter4_f=0;
                            exit_screen_display();
                        }
                                                                                                            // save the remaining time in storing-time variable.
                            if(storing_time==0){
                            storing_time=time_left_seconds;
                        }

                                                                                                            // This is an algorithm for calculating the time of and show it.
                                                                                                            
                        unsigned int least_significant_number = (time_left_seconds %10);
                        char least_significant_number_char = (char)least_significant_number +48;
                        unsigned int two_digit_number = (time_left_seconds /10);
                        unsigned int second_least_significant_number =two_digit_number%10;
                        char second_least_significant_number_char = (char)second_least_significant_number +48;       
                        unsigned int one_digit_number = (two_digit_number /10);
                        unsigned int third_least_significant_number =one_digit_number%10;
                        char third_least_significant_number_char = (char)third_least_significant_number +48;     
                        
                                                                                                          // Draw the time on the bottom-left of the screen.
                        str[2]=least_significant_number_char;
                        str[1]=second_least_significant_number_char;
                        str[0]=third_least_significant_number_char;
                        drawString(230,685,str,0x4F);

                        setCLock();                                                                        // setting the clock pin to 1.

                        setLatch();                                                                        // setting the latch pin to 1.

                        wait(12);                                                                          // waiting for 12 micro seconds.    

                        clearLatch();                                                                      // clearing the latch pin

                        int i=0;                                                                           // initializing variable i by 0.
                        while(i<16){                                                                       // looping till i<16    

                                    wait(6);                                                               // waiting for 6 micro seconds 
                                    clrCLock();                                                            // clearing the clock pin

                                    wait(6);                                                               // waiting for 6 micro seconds

                                    value=readData();                                                      // reading the value from the data pin and save it to the variable "value"

                                    buttons[i]=value;                                                      // storing the values in the buttons array.

                                    setCLock();                                                            // setting the clock.
                                    i++;                                                                   // incrementing i by 1.                           
                        }

                        int y_dir=0;
                        int x_dir=0;

                        if(state_change(dummy,buttons)){                                                   // checking if the dummy state is different than the buttons state.
                                                                                                           // if yes; then             
 


                                    if(buttons[4]==0){                                                     // if button 5 has been pressed                                                                                       
                                             y_dir-=1;                                                            
                                            wait(1000000/7);                                               // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                           // because of the hardware issues
                                    }    

                                    if(buttons[5]==0){                                                     // if button 6 has been pressed

                                      

                                             y_dir+=1;                                     
                                             wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                           // because of the hardware issues
                                    }       

                                    if(buttons[6]==0){                                                     // if button 7 has been pressed

                                        
                                             x_dir-=1;                                           
                                             wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                           // because of the hardware issues
                                    }      

                                    if(buttons[7]==0){                                                     // if button 8 has been pressed                                                                     
                                             x_dir+=1;
                                                                          
                                             wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                           // because of the hardware issues
                                    }  
                                    
                                    if(buttons[3]==0){                                                     // if button 4 has been pressed

                                             game_menu();                                                  // call the game-menu function.
                                    }  
                                
                                    store_state(dummy,buttons);                                            // call store_state function

                                                                                                           // if the donkeyKong reached ladder.
                                    if(if_donkey_kong_reached_ladder4(donkeyKong)==1){

                                                                                                           // change the position of the donkey Kong.

                                                      drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[26]);
                                                      donkeyKong.x=donkeyKongPosition[0];
                                                      donkeyKong.y=donkeyKongPosition[1];

                                                      if(donkeyKong.x==36 && donkeyKong.y==1){             // if the donkey-Kong reach the final/finish tile:
                                                                                                           // reinitialized the counters for healthpacks by 0.
                                                                                                           // call the win-screen-display function. 
                                                        health_pack_counter4_a=0;
                                                        health_pack_counter4_b=0;
                                                        health_pack_counter4_c=0;
                                                        health_pack_counter4_d=0;
                                                        health_pack_counter4_e=0;
                                                        health_pack_counter4_f=0;
                                                      
                                                         win_screen_display();
                                                      }
                                                      drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[2]);                                                      
                                                }
                                        
                                    // if the donkey-kong does not reach the LADDER:
                                    else{


                                             drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[44]);

                                            // keep track of the position of the donkey Kong.
                                            donkeyKong.x+=x_dir;
                                            donkeyKong.y+=y_dir;

                                            // If donkey kong does not hit the obstacle and does not have
                                            // collision with the boundaries.

                                            if((boundary_collisions4(donkeyKong)==0) && (donkeyKong_hits_obstacle4(donkeyKong)==0)){
                                                  drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                            }

                                            // if DonkeyKong gets the heallthpacks: 

                                            if(donkeyKong_gets_healthpack4(donkeyKong,time_left_seconds)==1){
                                               
                                                // if donkeykong gets the first healthpack:
                                                // increase the score and health(hearts)

                                                if(p_3==1){
                                                  drawImage(36*32,21*32,&tilemap.images[25]); 
                                                  drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[44]) ;
                                                  drawImage(22*32,21*32,&tilemap.images[34]);                                                
                                                  donkeyKong.x+=x_dir;
                                                  donkeyKong.y+=y_dir;
                                                  p_3=0;
                                            
                                               }

                                              // if donkeyKong gets the second healthpack
                                              // increase the score and health(hearts).
                                               if(p_3==2){

                                                  drawImage(34*32,21*32,&tilemap.images[25]); 
                                                  drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[44]);
                                                  drawImage(22*32,21*32,&tilemap.images[33]);   
                                                  donkeyKong.x+=x_dir;
                                                  donkeyKong.y+=y_dir;
                                                  p_3=1;
                                               }                                               

                                                                                                            
                                            }   
                                            // if donkeyKong has boundary collision:

                                            if(boundary_collisions4(donkeyKong)==1){

                                              donkeyKong.x-=x_dir;
                                              donkeyKong.y-=y_dir;
                                              drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                                 }  

                                            // if donkey-Kong hits the obstacles:

                                            if(donkeyKong_hits_obstacle4(donkeyKong)==1){


                                                p_3++;
                                                // if the donkey-kong hits the obtsacle for the first time:
                                                // decrease the score and health(hearts).

                                                if(p_3==1){
                                                drawImage(36*32,21*32,&tilemap.images[4]);
                                                drawImage(22*32,21*32,&tilemap.images[33]); 
                                                }

                                                // if the donkey kong hits the obstacle for the second time:
                                                // decrease the score and health(hearts).

                                                if(p_3==2){
                                                drawImage(34*32,21*32,&tilemap.images[4]); 
                                                drawImage(22*32,21*32,&tilemap.images[32]); 
                                                }

                                                // if the donkey-kong hits the obstacle for the third time:
                                                // decrease the score and health(hearts).
                                                // and if the donkey kong died, display the exit screen.
                                                if(p_3==3){
                                                      p_3=0;
                                                      drawImage(22*32,21*32,&tilemap.images[35]); 
                                                      drawImage(32*32,21*32,&tilemap.images[4]); 
                                                      health_pack_counter4_a=0;
                                                      health_pack_counter4_b=0;
                                                      health_pack_counter4_c=0;
                                                      health_pack_counter4_d=0;
                                                      health_pack_counter4_e=0;
                                                      health_pack_counter4_f=0;
                                                      exit_screen_display();
                                                }  
                                                donkeyKong.x+=x_dir;
                                                donkeyKong.y+=y_dir;
                                                
                                              // if the boundary collision is happened:
                                              if(boundary_collisions4(donkeyKong)==1){                       

                                                donkeyKong.x-=2*x_dir;
                                                donkeyKong.y-=2*y_dir;
                                              }  
                                                drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                                
                                           } 
     
                                  }        
                                  }
                                  }
                                  }