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


// Create the struct for the player.

struct Player{                                                                                      

      int x ;
      int y;

};

// initialize two integer arrays, for the collision stuff and donkeykong's position. 

int donkeyKongPosition[2];
int donkeyKongCollision[2];

// initialize 7 counter for the health packs.

int health_pack_counter3_a=0;                                                                   
int health_pack_counter3_b=0;
int health_pack_counter3_c=0;
int health_pack_counter3_d=0;
int health_pack_counter3_e=0;
int health_pack_counter3_f=0;
int health_pack_counter3_g=0;


char str[3];                                                                                    // create a character array.


// start of the border draw function, which will draw the borders of the game screen.
void border_draw3(){

             while(i<36){ 
               drawImage(i*32,2*32,&tilemap.images[40]);    
               i=i+1;
             }
     
             drawImage(37*32,2*32,&tilemap.images[40]);    

             int j=2 ;

            while(j<20){ 
               drawImage(2*32,j*32,&tilemap.images[40]);    
               j=j+1;
             }

            int k =2;
            while(k<20){ 
               drawImage(37*32,k*32,&tilemap.images[40]);    
               k=k+1;
             }

            int l =2;
            while(l<38){ 
               drawImage(l*32,20*32,&tilemap.images[40]);    
               l=l+1;
             }

            for(int i =2 ;i<38;i++){

             drawImage(i*32,21*32,&tilemap.images[4]);

      }
}

// Start of the draw level function which will draw the game screen.
// drawing the background of the game screen.

void drawLevel3( unsigned int level[22][39] )
{
      for(int row =3 ; row <20 ;row++){
         for(int col =3 ;col<37 ; col++){
             unsigned int imageNumber =level[row][col];
             int x =col*32;
             int y = row*32;
             drawImage(x,y,&tilemap.images[41]);                                                   
         }
      }

      // drawing the walls for level 3.

      for(int i=12;i<28;i++){
          drawImage(i*32,19*32,&tilemap.images[3]);

      }

      for(int i=4;i<11;i++){
          drawImage(i*32,18*32,&tilemap.images[3]);

      }

      for(int i=14;i<18;i++){
          drawImage(4*32,i*32,&tilemap.images[3]);

      }

      for(int i=29;i<36;i++){
          drawImage(i*32,18*32,&tilemap.images[3]);

      }

      for(int i=14;i<25;i++){
          drawImage(i*32,17*32,&tilemap.images[3]);

      }
        for(int i=12;i<27;i++){
          drawImage(i*32,15*32,&tilemap.images[3]);

      }

        for(int i=3;i<7;i++){
          drawImage(i*32,12*32,&tilemap.images[3]);

      }
        for(int i=33;i<37;i++){
          drawImage(i*32,12*32,&tilemap.images[3]);

      }      

        for(int i=14;i<18;i++){
          drawImage(35*32,i*32,&tilemap.images[3]);

      }     
       for(int i=10;i<29;i++){
          drawImage(i*32,13*32,&tilemap.images[3]);

      }

      for(int i=8;i<32;i++){
          drawImage(i*32,11*32,&tilemap.images[3]);

      }   

     for(int i=6;i<33;i++){
          drawImage(i*32,9*32,&tilemap.images[3]);

      }     
     for(int i=3;i<36;i++){
          drawImage(i*32,7*32,&tilemap.images[3]);

      }

     for(int i=4;i<37;i++){
          drawImage(i*32,5*32,&tilemap.images[3]);

      }  

      // Drawing the ladders for level 3.

     for(int i =14 ;i<19;i++){

       drawImage(3*32,i*32,&tilemap.images[26]);

      }

     for(int i =14 ;i<19;i++){

       drawImage(36*32,i*32,&tilemap.images[26]);

      }

      for(int i =12 ;i<14;i++){

       drawImage(7*32,i*32,&tilemap.images[26]);

      }

      for(int i =12 ;i<14;i++){

       drawImage(32*32,i*32,&tilemap.images[26]);

      }

      for(int i =5 ;i<11;i++){

       drawImage(20*32,i*32,&tilemap.images[26]);

      }
      for(int i =2 ;i<5;i++){

       drawImage(36*32,i*32,&tilemap.images[26]);

      }

      // drawing the word "T I M E" on the bottom of the screen.

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

      // Drawing the hearts for showing the game health.

      drawImage(32*32,21*32,&tilemap.images[25]);
      drawImage(34*32,21*32,&tilemap.images[25]);
      drawImage(36*32,21*32,&tilemap.images[25]);      

}

// start of the health-packs3 function, which will draw the healthpacks for level 3.
void health_packs3(){

      drawImage(5*32,4*32,&tilemap.images[30]);
      drawImage(32*32,16*32,&tilemap.images[30]);
      drawImage(34*32,10*32,&tilemap.images[30]);    
      drawImage(8*32,6*32,&tilemap.images[30]);
      drawImage(11*32,10*32,&tilemap.images[30]);  
      drawImage(27*32,8*32,&tilemap.images[30]);
      drawImage(7*32,16*32,&tilemap.images[30]); 
}

// start of the donkey-kong-healthpacks3 function
// which will check whether the donkeyKong get the health pack or not.

// By comparing the coordinate of the donkeyKong, with the coordinate
// of the health packs, we can understand.

int donkeyKong_gets_healthpack3(struct Player donkeyKong, int timeLeft){



 if(timeLeft<=50){
     if((donkeyKong.x==5) && (donkeyKong.y==4) ){
       if(health_pack_counter3_a==0){
      health_pack_counter3_a=1;
        return 1;
      }     
      }
     if((donkeyKong.x==32) && (donkeyKong.y==16) ){
      if(health_pack_counter3_b==0){
        health_pack_counter3_b=1;
        return 1;
      }
     }
     if((donkeyKong.x==34) && (donkeyKong.y==10) ){
      if(health_pack_counter3_c==0){
        health_pack_counter3_c=1;
        return 1;
      }
     }
     if((donkeyKong.x==8) && (donkeyKong.y==6) ){
      if(health_pack_counter3_d==0){
        health_pack_counter3_d;
        return 1;
      }
     }
     if((donkeyKong.x==11) && (donkeyKong.y==10) ){
      if(health_pack_counter3_e==0){
        health_pack_counter3_e=1;
        return 1;
      }
     }
     if((donkeyKong.x==27) && (donkeyKong.y==8) ){
      if(health_pack_counter3_f==0){
        health_pack_counter3_f=1;
        return 1;
      }
     }
      if((donkeyKong.x==7) && (donkeyKong.y==16) ){
      if(health_pack_counter3_g==0){
        health_pack_counter3_g=1;
        return 1;
      }
     }
 }
return 0;
}

// Start of the donkey-Kong-reached-ladder function
// which will check whether the donkeyKong reached the ladder or not.

int if_donkey_kong_reached_ladder3(struct Player donkeyKong){

    // we can check this by comparing the position of the donkeyKong, with the position
    // of the ladders.
    for(int i =14 ;i<19;i++){

       if((donkeyKong.x==3) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=3;
            donkeyKongPosition[1]=13;
            donkeyKong.y=13;
            return 1;
       }

      }

    for(int i =12 ;i<14;i++){

       if((donkeyKong.x==7) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=7;
            donkeyKongPosition[1]=11;            
            return 1;
       }

      }

     for(int i =12 ;i<14;i++){


       if((donkeyKong.x==32) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=32;
            donkeyKongPosition[1]=11;  
        return 1;
      } 

      }

      for(int i =14 ;i<19;i++){

       if((donkeyKong.x==36) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=36;
            donkeyKongPosition[1]=13;  
        return 1;
      } 
      }

      for(int i =5 ;i<11;i++){

       if((donkeyKong.x==20) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=20;
            donkeyKongPosition[1]=4;  
        return 1;
      } 
      }

      for(int i =2 ;i<5;i++){

       if((donkeyKong.x==36) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=36;
            donkeyKongPosition[1]=1;  
        return 1;
      } 
      }
      return 0;

}

// This function will check the boundary collisions od donkeyKong.
// again by using the coordinate/position of the donkey Kong.

int boundary_collisions3(struct Player donkeyKong){

      
    for(int i=12;i<28;i++){
          if((donkeyKong.x==i) && (donkeyKong.y==19)){
             return 1;

      }
      }

      for(int i=4;i<11;i++){

          if((donkeyKong.x==i) && (donkeyKong.y==18)){
             return 1;

      }
      }

      for(int i=14;i<18;i++){

          if((donkeyKong.x==4) && (donkeyKong.y==i)){
             return 1;            
      }
      }

      for(int i=29;i<36;i++){

           if((donkeyKong.x==i) && (donkeyKong.y==18)){
             return 1;           

      }
      }

      for(int i=14;i<25;i++){
          if((donkeyKong.x==i) && (donkeyKong.y==17)){
             return 1;            

      }
      }

      for(int i=12;i<27;i++){

          if((donkeyKong.x==i) && (donkeyKong.y==15)){
             return 1;            

      }
      }
        for(int i=3;i<7;i++){

           if((donkeyKong.x==i) && (donkeyKong.y==12)){
             return 1;           

      }
      }

        for(int i=33;i<37;i++){

          if((donkeyKong.x==i) && (donkeyKong.y==12)){
             return 1;            
      }      

      }
        for(int i=14;i<18;i++){

           if((donkeyKong.x==35) && (donkeyKong.y==i)){
             return 1;           

      } 
      }

       for(int i=10;i<29;i++){

           if((donkeyKong.x==i) && (donkeyKong.y==13)){
             return 1;           

      }
      }

      for(int i=8;i<32;i++){

           if((donkeyKong.x==i) && (donkeyKong.y==11)){
             return 1;           

      }   
      }
    for(int i=6;i<33;i++){
        if((donkeyKong.x==i) && (donkeyKong.y==9)){
             return 1;


      }    
      }
    for(int i=3;i<36;i++){
            
            if((donkeyKong.x==i) && (donkeyKong.y==7)){
             return 1;

      }
      }

    for(int i=4;i<37;i++){
            
            if((donkeyKong.x==i) && (donkeyKong.y==5)){
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
  
// This function will draw/create the obstacles for level 3.
void obstacles3(struct Player donkeyKong){

       drawImage(33*32,3*32,&tilemap.images[43]);     
       drawImage(33*32,4*32,&tilemap.images[43]);  
       drawImage(4*32,13*32,&tilemap.images[43]);   
       drawImage(5*32,13*32,&tilemap.images[43]);  
       drawImage(6*32,13*32,&tilemap.images[43]);   
       drawImage(35*32,13*32,&tilemap.images[43]);   
       drawImage(34*32,13*32,&tilemap.images[43]);  
       drawImage(33*32,13*32,&tilemap.images[43]);         
       drawImage(17*32,10*32,&tilemap.images[43]);                  
       drawImage(23*32,10*32,&tilemap.images[43]); 
       drawImage(15*32,8*32,&tilemap.images[43]);   
       drawImage(25*32,8*32,&tilemap.images[43]) ; 
       drawImage(13*32,6*32,&tilemap.images[43]) ;   
       drawImage(27*32,6*32,&tilemap.images[43]) ;                       
}

// This function will check whether the donkeyKong hit the obstacle or not.
// we can do this by comparing the position of the donkeyKong with the position
// of the obstacles.

int donkeyKong_hits_obstacle3(struct Player donkeyKong){

            if((donkeyKong.x==33)&& (donkeyKong.y==3)){             
                  return 1;
            }

            if((donkeyKong.x==33)&& (donkeyKong.y==4)){              
                  return 1;
            }

            if((donkeyKong.x==4)&& (donkeyKong.y==13)){              
                  return 1;
            }

            if((donkeyKong.x==5)&& (donkeyKong.y==13)){             
                  return 1;
            }  

            if((donkeyKong.x==6)&& (donkeyKong.y==13)){             
                  return 1;
            }

            if((donkeyKong.x==35)&& (donkeyKong.y==13)){              
                  return 1;
            }     

            if((donkeyKong.x==34)&& (donkeyKong.y==13)){             
                  return 1;
           }

            if((donkeyKong.x==33)&& (donkeyKong.y==13)){             
                  return 1;
            }  

            if((donkeyKong.x==17)&& (donkeyKong.y==10)){             
                  return 1;
            }  

            if((donkeyKong.x==35)&& (donkeyKong.y==13)){             
                  return 1;
            }  

            if((donkeyKong.x==23)&& (donkeyKong.y==10)){              
                  return 1;
            } 

            if((donkeyKong.x==15)&& (donkeyKong.y==8)){              
                  return 1;
            }      
            if((donkeyKong.x==15)&& (donkeyKong.y==8)){              
                  return 1;
            } 
            if((donkeyKong.x==25)&& (donkeyKong.y==8)){              
                  return 1;
            }
            if((donkeyKong.x==13)&& (donkeyKong.y==6)){              
                  return 1;
            }   
            if((donkeyKong.x==27)&& (donkeyKong.y==6)){              
                  return 1;
            }                                                                    
      
          return 0;

}

// This function will implement all the necessary stuff for the level 3 of our game.
void level3(){

              // declaring the variables, and also implement the needed for loop.
               int p_2=0;
               int health_pack_timer_constant=0;
               int storing_time=0;
               unsigned clo= (unsigned) CLO_REG; 
               unsigned int game_starts_at= *clo;
               unsigned int game_ends_at=game_starts_at +(65* 1000000);

               unsigned int level[22][38];

               for(int i=0 ; i<22 ; i++){

                  for(int j=0 ; j<38;j++){

                      level[i][j]=0;
                  }
               }

                                                                                                          // Fill the screen
                fillScreen(0x00000000);                                   
                struct Player donkeyKong ={3,19};                                                         // making an instance of the Player structure
                border_draw3();                                                                           // drawing the borders of the game.
                drawLevel3(level);                                                                        // drawing the game screen.
                drawImage(donkeyKong.x *32 , donkeyKong.y *32 , &tilemap.images[2]);                      // draw the donkeyKong
                obstacles3(donkeyKong);                                                                   // drawing the obstacles.
                drawString(2,2,"Welcome to Level 3 :)", 0x4F);                                            // printing a string on the top-left of the screen.
                drawImage(22*32,21*32,&tilemap.images[34]);                                               // drawing the initial score which is 15.


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

               initSNES();                                                                                 // call initSNES function.


               while(1){                                                                                   // Statrting a while loop.
    

                                                                                                        // declare two variables.
                    unsigned int current_time=*clo;
                    unsigned int time_left_seconds=(game_ends_at-current_time)/1000000;
                                                                                                        // the health packs will be appeared after 10 seconds.
                        if((time_left_seconds==50) && (health_pack_timer_constant==0) ){
                        health_packs3();
                        health_pack_timer_constant=1;
                    }
                                                                                                        // if the time is over, initialize the counters for health packs by 0
                                                                                                        // then go to the exit screen by calling the exit-screen-display().
                    if(time_left_seconds==0){
                        health_pack_counter3_a=0;
                        health_pack_counter3_b=0;
                        health_pack_counter3_c=0;
                        health_pack_counter3_d=0;
                        health_pack_counter3_e=0;
                        health_pack_counter3_f=0;
                        health_pack_counter3_g=0;
                        exit_screen_display();
                    }

                                                                                                        // store the remaining time.
                        if(storing_time==0){
                        storing_time=time_left_seconds;
                    }
                                                                                                        // implement an algorithm for getting the time of the game.
                    unsigned int least_significant_number = (time_left_seconds %10);
                    char least_significant_number_char = (char)least_significant_number +48;
                    unsigned int two_digit_number = (time_left_seconds /10);
                    unsigned int second_least_significant_number =two_digit_number%10;
                    char second_least_significant_number_char = (char)second_least_significant_number +48;       
                    unsigned int one_digit_number = (two_digit_number /10);
                    unsigned int third_least_significant_number =one_digit_number%10;
                    char third_least_significant_number_char = (char)third_least_significant_number +48;     

                    str[2]=least_significant_number_char;                                              // store each digit into an array of strings.
                    str[1]=second_least_significant_number_char;
                    str[0]=third_least_significant_number_char;

                    drawString(230,685,str,0x4F);                                                       // drawing the time on the botttom-left of the screen.

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

                    if(state_change(dummy,buttons)){   


                          // checking if the dummy state is different than the buttons state.
                          // if yes; then             


                          if(buttons[4]==0){                                                      // if button 5 has been pressed                                                                                       
                                    y_dir-=1;                                                            
                                  wait(1000000/7);                                                // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                  // because of the hardware issues
                          }    

                          if(buttons[5]==0){                                                      // if button 6 has been pressed

                                    y_dir+=1;                                     
                                    wait(1000000/7);                                              // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                  // because of the hardware issues
                          }       

                          if(buttons[6]==0){                                                       // if button 7 has been pressed

                              
                                    x_dir-=1;                                           
                                    wait(1000000/7);                                               // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                   // because of the hardware issues
                          }      

                          if(buttons[7]==0){                                                       // if button 8 has been pressed                                                                     
                                    x_dir+=1;
                                                                
                                    wait(1000000/7);                                               // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                   // because of the hardware issues
                          } 
                            
                          if(buttons[3]==0){                                                       // if button 4 has been pressed

                                  game_menu();                                                     // Go to the game menu

                          }  
                      
                          store_state(dummy,buttons);                                              // call store_state function


                            // If donkeyKong reached ladder.

                            if(if_donkey_kong_reached_ladder3(donkeyKong)==1){

                                  // change the position of the donkey Kong.

                                  drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[26]);
                                  donkeyKong.x=donkeyKongPosition[0];
                                  donkeyKong.y=donkeyKongPosition[1];

                                  // if the donkeyKong reach the final/finish spot:
                                  // initialize the counters for healthpacks by zero,
                                  // then go to level 4. 
                                  if(donkeyKong.x==36 && donkeyKong.y==1){
                                    health_pack_counter3_a=0;
                                    health_pack_counter3_b=0;
                                    health_pack_counter3_c=0;
                                    health_pack_counter3_d=0;
                                    health_pack_counter3_e=0;
                                    health_pack_counter3_f=0;
                                    health_pack_counter3_g=0;
                                    level4();
                                  }
                                  drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[2]);                                                      
                            }


                            // if the donkeyKong does not reach the ladder.
                            else{

                                    drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[41]);

                                    donkeyKong.x+=x_dir;
                                    donkeyKong.y+=y_dir;

                                    // if the donkyKong does not have doundary collison and
                                    // does not hit the obstacles.

                                    if((boundary_collisions3(donkeyKong)==0) && (donkeyKong_hits_obstacle3(donkeyKong)==0)){
                                                
                                          drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                    }

                                    // if the donkeyKong get the healthpacks:

                                    if(donkeyKong_gets_healthpack3(donkeyKong,time_left_seconds)==1){
                                        
                                        // if the donkeyKong gets the first health pack
                                        // increase the score and health if necessary.

                                        if(p_2==1){                                                          
                                          drawImage(36*32,21*32,&tilemap.images[25]); 
                                          drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[41]) ;
                                          drawImage(22*32,21*32,&tilemap.images[34]);                                                
                                          donkeyKong.x+=x_dir;
                                          donkeyKong.y+=y_dir;
                                          p_2=0;
                                    
                                        }


                                        // if the donkeyKong gets the second health pack
                                        // increase the health and score if necessary

                                        if(p_2==2){

                                          drawImage(34*32,21*32,&tilemap.images[25]); 
                                          drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[41]);
                                          drawImage(22*32,21*32,&tilemap.images[33]);   

                                          donkeyKong.x+=x_dir;
                                          donkeyKong.y+=y_dir;
                                          p_2=1;
                                    
                                        }                                               


                                    }   

                                    // if the donkeyKong has the boundary collision:
                                    if(boundary_collisions3(donkeyKong)==1){

                                      donkeyKong.x-=x_dir;
                                      donkeyKong.y-=y_dir;
                                      drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                          }  


                                    // If the donkeyKong hits the obstacle.
                                    if(donkeyKong_hits_obstacle3(donkeyKong)==1){


                                        p_2++;

                                        if(p_2==1){                                                   // if the donkeyKong hit the first obstacle.
                                                                                                      // decrease the score and health.
                                        drawImage(36*32,21*32,&tilemap.images[4]);
                                        drawImage(22*32,21*32,&tilemap.images[33]); 

                                        }

                                        if(p_2==2){                                                    // if the donkeyKong hits the second obstacle.
                                                                                                       // decrease the score and health.
                                        drawImage(34*32,21*32,&tilemap.images[4]); 
                                        drawImage(22*32,21*32,&tilemap.images[32]); 

                                        }
                                                                                                        // if the donkeyKong hits the third obstacle:
                                                                                                        // decrease the score and health. if necessary
                                                                                                        // if it's the case, kill the donkeyKong and go to exit screen.
                                        if(p_2==3){
                                        p_2=0;
                                        drawImage(22*32,21*32,&tilemap.images[35]); 
                                        drawImage(32*32,21*32,&tilemap.images[4]); 
                                        health_pack_counter3_a=0;
                                        health_pack_counter3_b=0;
                                        health_pack_counter3_c=0;
                                        health_pack_counter3_d=0;
                                        health_pack_counter3_e=0;
                                        health_pack_counter3_f=0;
                                        health_pack_counter3_g=0;                                                
                                        exit_screen_display();
                                        }
                          
                                        donkeyKong.x+=x_dir;
                                        donkeyKong.y+=y_dir;

                                      if(boundary_collisions3(donkeyKong)==1){                           // if boundary collision is happened:

                                        donkeyKong.x-=2*x_dir;
                                        donkeyKong.y-=2*y_dir;
                                      }  
                                        drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                      
                                    } 

                              }        
                              }
                              }
                                  }