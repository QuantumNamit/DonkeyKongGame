/*
Name -Namit Aneja
UCID - 30146188

Name - Aminreza Abbasi 
UCID - 30159887

COURSE -CPSC359
ASSIGNMENT 4 
*/


// Include the image.h and framebuffer.h

#include "image.h"
#include  "framebuffer.h"
#define CLO_REG   0XFE003004   


 // making a structure Player.                                                                                          
struct Player{

      int x ;
      int y;

};
 
 
// initialize two integer arrays.

int donkeyKongPosition[2];
int donkeyKongCollision[2];

// initialize the counters needed for the health pack functions.

int health_pack_counter2_a=0;
int health_pack_counter2_b=0;
int health_pack_counter2_c=0;
int health_pack_counter2_d=0;
int health_pack_counter2_e=0;

char str1[3];                                                                               // making a character array which is str1.

// This function (border_draw2) will draw the borders for level 2.

void border_draw2(){

            int i=2;  

             while(i<36){ 
               drawImage(i*32,2*32,&tilemap.images[27]);    
               i=i+1;
             }
     
             drawImage(37*32,2*32,&tilemap.images[27]);    

             int j=2 ;

            while(j<20){ 
               drawImage(2*32,j*32,&tilemap.images[27]);    
               j=j+1;
             }

            int k =2;
            while(k<20){ 
               drawImage(37*32,k*32,&tilemap.images[27]);    
               k=k+1;
             }

            int l =2;
            while(l<38){ 
               drawImage(l*32,20*32,&tilemap.images[27]);    
               l=l+1;
             }

            for(int i =2 ;i<38;i++){

             drawImage(i*32,21*32,&tilemap.images[4]);

    }

}

// This function (drawLevel2) will draw the game screen.

void drawLevel2( unsigned int level[22][39] ) {


      // These two for loops will draw the game screen. which is including tiles as
      // a background.

      for(int row =3 ; row <20 ;row++){                                                     
                                                                                            
         for(int col =3 ;col<37 ; col++){
             unsigned int imageNumber =level[row][col];
             int x =col*32;
             int y = row*32;
             drawImage(x,y,&tilemap.images[36]);
         }
      }


    // This part of the code will draw the walls.    

    for(int i=3;i<10;i++){
          drawImage(i*32,17*32,&tilemap.images[0]);

      }
    for(int i=11;i<18;i++){
          drawImage(i*32,15*32,&tilemap.images[0]);

      }


    for(int i=19;i<36;i++){
          drawImage(i*32,13*32,&tilemap.images[0]);

      }

    for(int i=3;i<20;i++){
          drawImage(i*32,10*32,&tilemap.images[0]);

      }   

    for(int i=21;i<36;i++){
          drawImage(i*32,10*32,&tilemap.images[0]);

      }     
    for(int i=23;i<37;i++){
          drawImage(i*32,7*32,&tilemap.images[0]);

      }

    for(int i=9;i<23;i++){
          drawImage(i*32,7*32,&tilemap.images[0]);

      }

    for(int i=3;i<8;i++){
          drawImage(i*32,5*32,&tilemap.images[0]);

      }

    for(int i=28;i<37;i++){
          drawImage(i*32,4*32,&tilemap.images[0]);

      }  


    // This part of the code will draw the ladders. 

    for(int i =15 ;i<18;i++){

       drawImage(10*32,i*32,&tilemap.images[26]);

      }

     for(int i =13 ;i<16;i++){

       drawImage(18*32,i*32,&tilemap.images[26]);

      }

      for(int i =10 ;i<13;i++){

       drawImage(20*32,i*32,&tilemap.images[26]);

      }

      for(int i =10 ;i<14;i++){

       drawImage(36*32,i*32,&tilemap.images[26]);

      }

      for(int i =5 ;i<8;i++){

       drawImage(8*32,i*32,&tilemap.images[26]);

      }
       for(int i =4 ;i<7;i++){

       drawImage(27*32,i*32,&tilemap.images[26]);

      }

       for(int i =2 ;i<4;i++){

       drawImage(36*32,i*32,&tilemap.images[26]);

      }

      // This part of the code, will draw the word "T I M E" on the bottom of the screen.


      drawImage(2*32,21*32,&tilemap.images[20]);
      drawImage(3*32,21*32,&tilemap.images[13]);
      drawImage(4*32,21*32,&tilemap.images[15]);      
      drawImage(5*32,21*32,&tilemap.images[10]);

      // This part of the code, will draw the word "S C O R E" on the bottom of the screen.

      drawImage(16*32,21*32,&tilemap.images[19]);
      drawImage(17*32,21*32,&tilemap.images[8]);
      drawImage(18*32,21*32,&tilemap.images[17]);      
      drawImage(19*32,21*32,&tilemap.images[18]);
      drawImage(20*32,21*32,&tilemap.images[10]);

      // This part of the code, will draw the health (hearts) on the bottom of the screen.

      drawImage(32*32,21*32,&tilemap.images[25]);
      drawImage(34*32,21*32,&tilemap.images[25]);
      drawImage(36*32,21*32,&tilemap.images[25]);      

    

}

// This condition will check whether the donkeyKong is reached the ladder or not.
// If yes, the position the donkeyKong will be changed.

int if_donkey_kong_reached_ladder2(struct Player donkeyKong){     
    for(int i =15 ;i<18;i++){

       if((donkeyKong.x==10) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=10;
            donkeyKongPosition[1]=14;

            return 1;
       }

      }

    for(int i =13 ;i<16;i++){

       if((donkeyKong.x==18) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=18;
            donkeyKongPosition[1]=12;            
            return 1;
       }

      }

     for(int i =10 ;i<13;i++){


       if((donkeyKong.x==20) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=20;
            donkeyKongPosition[1]=9;  
        return 1;
      } 

      }

      for(int i =10 ;i<14;i++){

       if((donkeyKong.x==36) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=36;
            donkeyKongPosition[1]=9;  
        return 1;
      } 
      }

      for(int i =5 ;i<8;i++){

       if((donkeyKong.x==8) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=8;
            donkeyKongPosition[1]=4;  
        return 1;
      } 
      }

      for(int i =4 ;i<7;i++){

       if((donkeyKong.x==27) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=27;
            donkeyKongPosition[1]=3;  
        return 1;
      } 
      }

      for(int i =2 ;i<4;i++){

       if((donkeyKong.x==36) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=36;
            donkeyKongPosition[1]=1;  
        return 1;
      } 
      }
      return 0;
}


// drawing the health packs for level 2

void health_packs2(){

      drawImage(12*32,6*32,&tilemap.images[31]);
      drawImage(18*32,5*32,&tilemap.images[31]);
      drawImage(11*32,16*32,&tilemap.images[31]);    
      drawImage(25*32,12*32,&tilemap.images[31]);  
      drawImage(32*32,14*32,&tilemap.images[31]);  

}

// Checking whether the donkeyKong gets the healthpack or not.

int donkeyKong_gets_healthpack2(struct Player donkeyKong, int timeLeft){

      if(timeLeft<=50){
          if((donkeyKong.x==12) && (donkeyKong.y==6) ){
            if(health_pack_counter2_a==0){
              health_pack_counter2_a=1;
              return 1;
            }
          }

          if((donkeyKong.x==18) && (donkeyKong.y==5) ){
            if(health_pack_counter2_b==0){
              health_pack_counter2_b=1;
              return 1;
            }

          }
          if((donkeyKong.x==11) && (donkeyKong.y==16) ){

            if(health_pack_counter2_c==0){
              health_pack_counter2_c=1;
              return 1;

            }
          }
          if((donkeyKong.x==25) && (donkeyKong.y==12) ){

            if(health_pack_counter2_d==0){
              health_pack_counter2_d=1;
              return 1;
            }
          }
          if((donkeyKong.x==32) && (donkeyKong.y==14) ){

            if(health_pack_counter2_e==0){
              health_pack_counter2_e=1;
              return 1;
            }
          }
}

return 0;
}

// This method will check the boundary-collisions for the donkeyKong.    

int boundary_collisions2(struct Player donkeyKong){

      
      for(int i=3;i<10;i++){

        if((donkeyKong.x==i) && (donkeyKong.y==17)){

          return 1;
        }

      }
        for(int i=11;i<18;i++){

        if((donkeyKong.x==i) && (donkeyKong.y==15)){

          return 1;
        }

      }

       for(int i=19;i<36;i++){

        if((donkeyKong.x==i) && (donkeyKong.y==13)){

          return 1;
        }        

      }

      for(int i=3;i<20;i++){

        if((donkeyKong.x==i) && (donkeyKong.y==10)){

          return 1;

        }        


      }   

    for(int i=21;i<36;i++){

        if((donkeyKong.x==i) && (donkeyKong.y==10)){

          return 1;
        }      

      }     

    for(int i=23;i<37;i++){

        if((donkeyKong.x==i) && (donkeyKong.y==7)){

          return 1;
        }      
  
      }

    for(int i=9;i<23;i++){

        if((donkeyKong.x==i) && (donkeyKong.y==7)){

          return 1;
        }      

      }

    for(int i=3;i<8;i++){
        if((donkeyKong.x==i) && (donkeyKong.y==5)){

          return 1;
        }      

      }

    for(int i=28;i<37;i++){
        if((donkeyKong.x==i) && (donkeyKong.y==4)){

          return 1;
        }      
 
      }  

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

return 0;
}

// draw the obstacles for level 2 and put them on the screen.

void obstacles2(struct Player donkeyKong){

          drawImage(30*32,3*32,&tilemap.images[24]);
          drawImage(32*32,3*32,&tilemap.images[24]);
          drawImage(13*32,12*32,&tilemap.images[24]);
          drawImage(19*32,9*32,&tilemap.images[24]);
          drawImage(19*32,8*32,&tilemap.images[24]);
          drawImage(35*32,8*32,&tilemap.images[24]);
          drawImage(35*32,9*32,&tilemap.images[24]);
          drawImage(9*32,4*32,&tilemap.images[24]);    
                                
}

// checking whether the donkeykong hits the obstacle or not.
// By comparing the coordinates (positions) of the donkeyKong and obstacle.

int donkeyKong_hits_obstacle2(struct Player donkeyKong){


            if((donkeyKong.x==30)&& (donkeyKong.y==3)){
              
                  return 1;
            }  

            if((donkeyKong.x==32)&& (donkeyKong.y==3)){
              
                  return 1;
            }

            if((donkeyKong.x==13)&& (donkeyKong.y==12)){
              
                  return 1;
            }

            if((donkeyKong.x==19)&& (donkeyKong.y==9)){
              
                  return 1;
            }

            if((donkeyKong.x==19)&& (donkeyKong.y==8)){
              
                  return 1;
            }
            if((donkeyKong.x==35)&& (donkeyKong.y==8)){
              
                  return 1;
            }

            if((donkeyKong.x==35)&& (donkeyKong.y==9)){
              
                  return 1;
            }  

            if((donkeyKong.x==9)&& (donkeyKong.y==4)){
              
                  return 1;
            } 
            return 0;

}

// in this method, all the needed stuff for level 2 will be implemented.

void level2(){

               // declared the needed variables to use them. and using for loop.
               int p_1=0;                                                                     
               int health_pack_timer_constant=0;                                                
               int storing_time=0;
               unsigned *clo= (unsigned*) CLO_REG; 
               unsigned int game_starts_at= *clo;

               // make the timer 65 seconds, which would be exactly 60 seconds for each
               // level.

               unsigned int game_ends_at=game_starts_at +(65)* 1000000;                                   
               unsigned int level[22][38];

               for(int i=0 ; i<22 ; i++){

                  for(int j=0 ; j<38;j++){

                      level[i][j]=0;

                  }
               }

              // this line of code will fill the screen for you.
                                                                                                        
              fillScreen(0x00000000);
              struct Player donkeyKong ={3,19};                                                            // create instance for the struct.
              border_draw2();                                                                              // call the border_draw2 in order to draw the borders for level 2.

              drawLevel2(level);                                                                           // call drawLevel2 in order to draw the game screen.
                                                                                                           // other stuff like printing a string, create the score for the game screen.
              drawImage(donkeyKong.x *32 , donkeyKong.y *32 , &tilemap.images[2]);                        
              obstacles2(donkeyKong);
              drawString(2,2,"Welcome to Level 2 :)", 0x4F); 
              drawImage(22*32,21*32,&tilemap.images[34]); 


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
               
               initSNES();                                                                                 // calling initSNES function.


               while(1){                                                                                   // Statrting a while loop.
    
                                                                                                           // defining needed variables.
                        unsigned int current_time=*clo;
                        unsigned int time_left_seconds=(game_ends_at-current_time)/1000000;
                                                                                                           // health packs should be appeared after 10 seconds.
                            if((time_left_seconds==50) && (health_pack_timer_constant==0) ){
                            health_packs2();
                            health_pack_timer_constant=1;
                        }
                                                                                                           // if the time is over, initialize all the counters for 
                                                                                                           // health packs by zero. Then display the exit-screen
                        if(time_left_seconds==0){
                            health_pack_counter2_a=0;
                            health_pack_counter2_b=0;
                            health_pack_counter2_c=0;
                            health_pack_counter2_d=0;
                            health_pack_counter2_e=0;
                            exit_screen_display();
                        }
                                                                                                            // if there is remaining time, save it.
                            if(storing_time==0){
                            storing_time=time_left_seconds;
                        }
                                                                                                            // we are using an algorithm for finding the time and place the time
                                                                                                            // on the bottom of the screen.
                        unsigned int least_significant_number = (time_left_seconds %10);

                        char least_significant_number_char = (char)least_significant_number +48;

                        unsigned int two_digit_number = (time_left_seconds /10);

                        unsigned int second_least_significant_number =two_digit_number%10;
                         
                        char second_least_significant_number_char = (char)second_least_significant_number +48;       

                        unsigned int one_digit_number = (two_digit_number /10);

                        unsigned int third_least_significant_number =one_digit_number%10;
                         
                        char third_least_significant_number_char = (char)third_least_significant_number +48;     

                        str1[2]=least_significant_number_char;
                        str1[1]=second_least_significant_number_char;
                        str1[0]=third_least_significant_number_char;

                       drawString(230, 685,str1,0x4F);                                                     // draw the timer on the bottom of the screen.


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

                        int y_dir=0;                                                                       // initialzing the coordintes by zero.
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

                                            game_menu();                                                   // go to the game menu.

                                    }  
                            
                                    store_state(dummy,buttons);                                            // call store_state function
 

                                                                                                           // This part of code will check that whether the donkeyKong reached the ladder or not.
                                    if(if_donkey_kong_reached_ladder2(donkeyKong)==1){

                                                                                                           // changing the position of the donkeyKong and move it.

                                                      drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[26]);
                                                      donkeyKong.x=donkeyKongPosition[0];
                                                      donkeyKong.y=donkeyKongPosition[1];

                                                      // if donkeyKong reaches the final spot, it will initialize all the counters
                                                      // for health packs by zero, then it will goes to level3.
                                                      
                                                      if((donkeyKong.x==36) && (donkeyKong.y==1)){
                                                        health_pack_counter2_a=0;
                                                        health_pack_counter2_b=0;
                                                        health_pack_counter2_c=0;
                                                        health_pack_counter2_d=0;
                                                        health_pack_counter2_e=0;
                                                        level3();
                                                      }

                                                      drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[2]);                                                      
                                        }
                                        
                                                                                                         

                                    else{

                                            // changing the coordinates of the donkeyKong. 

                                            drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[36]);
                                            // if the donkeyKong does not reach the ladder
                                            donkeyKong.x+=x_dir;
                                            donkeyKong.y+=y_dir;


                                            // if the donkeyKong hits the obstacle and has a boundary collision at the same time:

                                            if((boundary_collisions2(donkeyKong)==0) && (donkeyKong_hits_obstacle2(donkeyKong)==0)){
                                                        
                                                  drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                            }

                                             // if the donkeyKong gets the healthpacks.

                                            if(donkeyKong_gets_healthpack2(donkeyKong,time_left_seconds)==1){
                                               
                                               // if it gets the first health pack, it will changes the score, and health

                                               if(p_1==1){
                                                  drawImage(36*32,21*32,&tilemap.images[25]); 
                                                  drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[36]) ;
                                                  drawImage(22*32,21*32,&tilemap.images[34]);                                                
                                                  donkeyKong.x+=x_dir;
                                                  donkeyKong.y+=y_dir;
                                                  p_1=0;
                                            
                                               }

                                               // if it gets the second health pack, it will changes the score and health as well.

                                               if(p_1==2){

                                                  drawImage(34*32,21*32,&tilemap.images[25]); 
                                                  drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[36]);
                                                  drawImage(22*32,21*32,&tilemap.images[33]);   
                                                  donkeyKong.x+=x_dir;
                                                  donkeyKong.y+=y_dir;
                                                  p_1=1;
                                            
                                               }                                               

                                            }   

                                            // if the donkeyKong has the boundary collison, its coordinates will be changed.

                                            if(boundary_collisions2(donkeyKong)==1){

                                              donkeyKong.x-=x_dir;
                                              donkeyKong.y-=y_dir;
                                              drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                                 }  
                                                                                                            
                                            // if the donkeyKong hits the obstacles:

                                            if(donkeyKong_hits_obstacle2(donkeyKong)==1){


                                                p_1++;
                                                if(p_1==1){                                                // if the donkeyKong hits the obstacle for the first time, the score and the health
                                                                                                           // will be changed.
                                                drawImage(36*32,21*32,&tilemap.images[4]);
                                                drawImage(22*32,21*32,&tilemap.images[33]); 
 

                                                }
                                                                                                           // if the donkeyKong hits the obstacle for the second time, the score and health will be changed.
                                                if(p_1==2){
                                                drawImage(34*32,21*32,&tilemap.images[4]); 
                                                drawImage(22*32,21*32,&tilemap.images[32]); 
                                                }

                                                                                                           // if the donkeyKong hits the obstacle for the third time, it's gonna die.
                                                                                                           // the exit screen will be displayed. Also the health and the score will be changed.
                                                if(p_1==3){
                                                p_1=0;
                                                drawImage(22*32,21*32,&tilemap.images[35]); 
                                                drawImage(32*32,21*32,&tilemap.images[4]); 
                                                health_pack_counter2_a=0;
                                                health_pack_counter2_b=0;
                                                health_pack_counter2_c=0;
                                                health_pack_counter2_d=0;
                                                health_pack_counter2_e=0;
                                                exit_screen_display();
                                                }                                     
                                                donkeyKong.x+=x_dir;
                                                donkeyKong.y+=y_dir;
                                                                                                          // if the donkeyKong has the boundary collision: its position will be changed.
                                              if(boundary_collisions2(donkeyKong)==1){

                                                donkeyKong.x-=2*x_dir;
                                                donkeyKong.y-=2*y_dir;
                                              }  
                                                drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                              
                                           } 

     
                                  }        
                                  }
                                  }
                                  }