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


// Created the structure player.

struct Player{                                                                              

      int x ;
      int y;

};

// Initializing two arrays, donkeykong position
// and donkeykong collision.

int donkeyKongPosition[2];
int donkeyKongCollision[2];


// Initializing the counters for each of the health packs.

int health_pack_counter=0;
int health_pack_counter1=0;
int health_pack_counter2=0;
int health_pack_counter3=0;
int health_pack_counter4=0;

char str[3];                                                                                 // create an array of characters called str.


                                                                             
// Start of the border-draw function.
// This function will draw the borders of the screen.
// By using DrawImage function, and while loops. 

void border_draw(){                                                                                                 
            int i=2;  

             while(i<36){ 
               drawImage(i*32,2*32,&tilemap.images[0]);    
               i=i+1;
             }
     
             drawImage(37*32,2*32,&tilemap.images[0]);    

             int j=2 ;

            while(j<20){ 
               drawImage(2*32,j*32,&tilemap.images[0]);    
               j=j+1;
             }

            int k =2;
            while(k<20){ 
               drawImage(37*32,k*32,&tilemap.images[0]);    
               k=k+1;
             }

            int l =2;
            while(l<38){ 
               drawImage(l*32,20*32,&tilemap.images[0]);    
               l=l+1;
             }

            for(int i =2 ;i<38;i++){

             drawImage(i*32,21*32,&tilemap.images[4]);
      }
}


// Start of the drawLevel function.
// This function will draw the game screen for the first level.

void drawLevel( unsigned int level[22][39] )
{
      // These two for loops will draw the background of the screen.
      for(int row =3 ; row <20 ;row++){                                                       
         for(int col =3 ;col<37 ; col++){
             unsigned int imageNumber =level[row][col];

             int x =col*32;
             int y = row*32;

             drawImage(x,y,&tilemap.images[1]);
         }
      }
      
      // This part of the code will draw the walls using drawImage function.
      for(int i=17;i<26;i++){                                                                 
          drawImage(i*32,16*32,&tilemap.images[3]);

      }

      for(int i=20;i<25;i++){
          drawImage(i*32,14*32,&tilemap.images[3]);

      }

      for(int i=3;i<11;i++){
          drawImage(i*32,13*32,&tilemap.images[3]);
      }

      for(int i=11;i<20;i++){
          drawImage(i*32,10*32,&tilemap.images[3]);

      }   

      for(int i=21;i<37;i++){
          drawImage(i*32,10*32,&tilemap.images[3]);

        } 

      for(int i=27;i<33;i++){
          drawImage(i*32,7*32,&tilemap.images[3]);

        }

      for(int i=28;i<37;i++){
          drawImage(i*32,4*32,&tilemap.images[3]);

        }  



      // In this part, we are using drawImage and for loops in order to
      // draw the ladders 
      drawImage(25*32,15*32,&tilemap.images[26]);
      drawImage(25*32,14*32,&tilemap.images[26]);


    for(int i =10 ;i<13;i++){

       drawImage(10*32,i*32,&tilemap.images[26]);

      }

     for(int i =7 ;i<10;i++){

       drawImage(33*32,i*32,&tilemap.images[26]);

      }

      for(int i =4 ;i<7;i++){

       drawImage(27*32,i*32,&tilemap.images[26]);

      }

      for(int i =2 ;i<4;i++){
// make the timer 65 seconds, which would be exactly 60 seconds for each
                                                                                                          // level.

      for(int i =10 ;i<14;i++){

       drawImage(20*32,i*32,&tilemap.images[26]);

      }



      // This part of the code, will draw the word "T I M E" at the
      // bottom of the screen.

      drawImage(2*32,21*32,&tilemap.images[20]);
      drawImage(3*32,21*32,&tilemap.images[13]);
      drawImage(4*32,21*32,&tilemap.images[15]);      
      drawImage(5*32,21*32,&tilemap.images[10]);


      // This part of the code, will draw the word "S C O R E" at the
      // bottom of the screen.

      drawImage(16*32,21*32,&tilemap.images[19]);
      drawImage(17*32,21*32,&tilemap.images[8]);
      drawImage(18*32,21*32,&tilemap.images[17]);      
      drawImage(19*32,21*32,&tilemap.images[18]);
      drawImage(20*32,21*32,&tilemap.images[10]);

      // This part of the code, will draw the hearts that are needed
      // as the health of the game, which is on the bottom of the screen.

      drawImage(32*32,21*32,&tilemap.images[25]);
      drawImage(34*32,21*32,&tilemap.images[25]);
      drawImage(36*32,21*32,&tilemap.images[25]);      
}


// This function will create the health packs on the game screen.    

void health_packs(){

      drawImage(12*32,6*32,&tilemap.images[30]);
      drawImage(18*32,5*32,&tilemap.images[30]);
      drawImage(11*32,16*32,&tilemap.images[30]);    
      drawImage(25*32,12*32,&tilemap.images[30]);  
      drawImage(32*32,14*32,&tilemap.images[30]);  

}

// This function, will check that whether the donkeykong gets
// the health pack or not. By comparing the location of the donkeykong
// and the location of the health packs (compare their coordinates)


int donkeyKong_gets_healthpack(struct Player donkeyKong, int timeLeft){


if(timeLeft<=50){
     if((donkeyKong.x==12) && (donkeyKong.y==6) ){
      if(health_pack_counter==0){
        health_pack_counter=1;
        return 1;
      }
     }

     if((donkeyKong.x==18) && (donkeyKong.y==5) ){
       if(health_pack_counter1==0){
        health_pack_counter1=1;
        return 1;
      }
     }

     if((donkeyKong.x==11) && (donkeyKong.y==16) ){

       if(health_pack_counter2==0){
        health_pack_counter2=1;
        return 1;
      }
     }

     if((donkeyKong.x==25) && (donkeyKong.y==12) ){

       if(health_pack_counter3==0){
        health_pack_counter3=1;
        return 1;
      }
     }

     if((donkeyKong.x==32) && (donkeyKong.y==14) ){

       if(health_pack_counter4==0){
        health_pack_counter4=1;
        return 1;
      }
     }
}
return 0;
}

// This function will check whether the donkeyKong reached the ladder
// or not. By comparing the donkeyKong's location with the ladder's position.
// By comparing their coordinates.

int if_donkey_kong_reached_ladder(struct Player donkeyKong){



    for(int i =14 ;i<16;i++){

       if((donkeyKong.x==25) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=25;
            donkeyKongPosition[1]=13;

            donkeyKong.y=13;
            return 1;
       }

      }

    for(int i =10 ;i<13;i++){

       if((donkeyKong.x==10) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=10;
            donkeyKongPosition[1]=9;            
            return 1;
       }

      }

     for(int i =7 ;i<10;i++){


       if((donkeyKong.x==33) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=33;
            donkeyKongPosition[1]=6;  
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

      for(int i =10 ;i<14;i++){

       if((donkeyKong.x==20) && (donkeyKong.y==i)){

            donkeyKongPosition[0]=20;
            donkeyKongPosition[1]=9;  
        return 1;
      } 
      }
      return 0;


}

// As we can understand from the name of the function,
// this function will check the boundary collisions of the donkeyKong.
// By comparing the donkeyKong's position with the boundaries.

int boundary_collisions(struct Player donkeyKong){

      
    for(int i=17;i<26;i++){

          if((donkeyKong.x==i) && donkeyKong.y==16){

                   return 1;
            
             }

      }
    for(int i=20;i<25;i++){

          if((donkeyKong.x==i) && ( donkeyKong.y==14)){


              return 1;
             }

      }


    for(int i=3;i<11;i++){
          if((donkeyKong.x==i) && ( donkeyKong.y==13)){

              return 1;
             }

      }

   for(int i=11;i<20;i++){

     if((donkeyKong.x==i) && ( donkeyKong.y==10)){


              return 1;
             }

      }   

    for(int i=21;i<37;i++){

        if((donkeyKong.x==i) && ( donkeyKong.y==10)){


              return 1;
             }

      }     
    for(int i=27;i<33;i++){
      if((donkeyKong.x==i) && ( donkeyKong.y==7)){


              return 1;
             }

      }

    for(int i=28;i<37;i++){
     if((donkeyKong.x==i) && ( donkeyKong.y==4)){

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

// This function will draw the obstacles on the screen at random locations.   

void obstacles(struct Player donkeyKong ){

       drawImage(32*32,3*32,&tilemap.images[39]);
       drawImage(34*32,3*32,&tilemap.images[39]);
       drawImage(33*32,5*32,&tilemap.images[39]);

       drawImage(11*32,11*32,&tilemap.images[39]);
       drawImage(11*32,12*32,&tilemap.images[39]);
       drawImage(20*32,8*32,&tilemap.images[39]);
       drawImage(5*32,5*32,&tilemap.images[39]);
       drawImage(5*32,17*32,&tilemap.images[39]);      
       drawImage(9*32,3*32,&tilemap.images[39]);         
       drawImage(33*32,17*32,&tilemap.images[39]);        
}


// This function will check whether the donkey kong hits
// the obstacles or not. By comparing the donkeyKong's position
// with the position of the obstacles (comparing their coordinates). 

int donkeyKong_hits_obstacle(struct Player donkeyKong){


            if((donkeyKong.x==32)&& (donkeyKong.y==3)){
              
                  return 1;
            }  

            if((donkeyKong.x==34)&& (donkeyKong.y==3)){
              
                  return 1;
            }

            if((donkeyKong.x==33)&& (donkeyKong.y==5)){
              
                  return 1;
            }

            if((donkeyKong.x==11)&& (donkeyKong.y==11)){
              
                  return 1;
            }

            if((donkeyKong.x==11)&& (donkeyKong.y==12)){
              
                  return 1;
            }
            if((donkeyKong.x==20)&& (donkeyKong.y==8)){
              
                  return 1;
            }

            if((donkeyKong.x==5)&& (donkeyKong.y==5)){
              
                  return 1;
            }  

            if((donkeyKong.x==5)&& (donkeyKong.y==17)){
              
                  return 1;
            } 

            if((donkeyKong.x==9)&& (donkeyKong.y==3)){
              
                  return 1;
            } 

            if((donkeyKong.x==33)&& (donkeyKong.y==17)){
              
                  return 1;
            }               
            return 0;
}



// This function will implement the level 1 stuff.
// declaring the needed variables, and create the needed for loop.

void level1(){
                                                                                                         
      int p=0;
      int health_pack_timer_constant=0;
      int storing_time=0;
      unsigned *clo= (unsigned*) CLO_REG; 
      unsigned int game_starts_at= *clo;
      unsigned int game_ends_at=game_starts_at +(65)* 1000000;
      unsigned int level[22][38];

      for(int i=0 ; i<22 ; i++){
        for(int j=0 ; j<38;j++){
            level[i][j]=0;
        }
      }

      fillScreen(0x00000000);                                                                   // This line of code will fills the screen.
      struct Player donkeyKong ={3,19};                                                         // make an instance for the struct.
      border_draw();                                                                            // call border-draw function to draw the borders.
      drawLevel(level);                                                                         // call drawLevel function to draw the game screen.
      drawImage(donkeyKong.x *32 , donkeyKong.y *32 , &tilemap.images[2]);                      // draw the donkey kong.
      obstacles(donkeyKong);                                                                    // call the obstacles function to draw the obstacles.
      drawString(2,2,"Welcome to Level 1 :)", 0x4F);                                            // printning something on the top of the screen.
      drawImage(22*32,21*32,&tilemap.images[34]);                                               // Print 15 on the bottom of the screen as the score.


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

              unsigned int current_time=*clo;                                                    // create the needed variables.                     
              unsigned int time_left_seconds=(game_ends_at-current_time)/1000000;                

                  if((time_left_seconds==50) && (health_pack_timer_constant==0) ){               // health packs should be appeared after 10 seconds.
                  health_packs();
                  health_pack_timer_constant=1;
              }

              if(time_left_seconds==0){                                                          // if the time is over, go to the exit screen display.

                    health_pack_counter=0;                                                        // initializing the counters by zero in order to refresh the counters.
                    health_pack_counter1=0;                                                       // As we want to deal with health packs. 
                    health_pack_counter2=0;
                    health_pack_counter3=0;
                    health_pack_counter4=0;
                  exit_screen_display();
              }
                                                                                                  // save the remaining time.
                  if(storing_time==0){
                  storing_time=time_left_seconds;
              }

                                                                                                  // Implementing an algorithm to calculate the time of the game.
                                                                                                  // 
              unsigned int least_significant_number = (time_left_seconds %10);
              char least_significant_number_char = (char)least_significant_number +48;

              unsigned int two_digit_number = (time_left_seconds /10);
              unsigned int second_least_significant_number =two_digit_number%10;

              char second_least_significant_number_char = (char)second_least_significant_number +48;       

              unsigned int one_digit_number = (two_digit_number /10);

              unsigned int third_least_significant_number =one_digit_number%10;
                
              char third_least_significant_number_char = (char)third_least_significant_number +48;     

              str[2]=least_significant_number_char;
              str[1]=second_least_significant_number_char;
              str[0]=third_least_significant_number_char;

              drawString(230, 685,str,0x4F);


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

              if(state_change(dummy,buttons)){                                                    // checking if the dummy state is different than the buttons state.
                                                                                                  // if yes; then             



                        if(buttons[4]==0){                                                        // if button 5 has been pressed                                                                                       
                                  y_dir-=1;                                                            
                                wait(1000000/7);                                                  // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                  // because of the hardware issues
                        }    

                        if(buttons[5]==0){                                                        // if button 6 has been pressed

                          

                                  y_dir+=1;                                     
                                  wait(1000000/7);                                                // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                  // because of the hardware issues
                        }       

                        if(buttons[6]==0){                                                        // if button 7 has been pressed

                            
                                  x_dir-=1;                                           
                                  wait(1000000/7);                                                // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                  // because of the hardware issues
                        }      

                        if(buttons[7]==0){                                                        // if button 8 has been pressed                                                                     
                                  x_dir+=1;
                                                              
                                  wait(1000000/7);                                                // wait for this much microsecond to completely make sure that there are no double print statements
                                                                                                  // because of the hardware issues
                        }  
                        
                        if(buttons[3]==0){                                                        // if button 4 has been pressed

                                  game_menu();                                                    // GO to the game menu.

                        }  
                    
                        store_state(dummy,buttons);                                               // call store_state function


                                                                                                  // If donkeyKong recched the ladder, update the position of
                                                                                                  // the donkeyKong.

                        if(if_donkey_kong_reached_ladder(donkeyKong)==1){

                                drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[26]);          
                                donkeyKong.x=donkeyKongPosition[0];
                                donkeyKong.y=donkeyKongPosition[1];

                                if((donkeyKong.x==36) && (donkeyKong.y==1)){
                                                                                                  // Initialzing the counters for deadling with health packs.
                                    health_pack_counter=0;
                                    health_pack_counter1=0;
                                    health_pack_counter2=0;
                                    health_pack_counter3=0;
                                    health_pack_counter4=0;

                                    level2();                                                     // As the donkey Kong complete the level 1 successfuly.
                                                                                                  // go to level 2.
                        }
                                drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[2]);                                                      
                        }


                        // If donkeyKong does not reached ladder.

                        else{

                                  drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[1]);  

                                  // change the position of the donkeyKong.

                                  donkeyKong.x+=x_dir;                                            
                                  donkeyKong.y+=y_dir;

                                  // If donkeyKong reach the obstacles and collision at the same time.

                                  if((boundary_collisions(donkeyKong)==0) && (donkeyKong_hits_obstacle(donkeyKong)==0)){ 
                                              
                                        drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                  }


                                  // If donkeyKong gets the healthpacks:

                                  if(donkeyKong_gets_healthpack(donkeyKong,time_left_seconds)==1){
                                      
                                        // if the health (heart) is 1.     
                                        if(p==1){

                                          // changing the score, number of hearts, and updating the coordinate
                                          // of the donkeykong.

                                          drawImage(36*32,21*32,&tilemap.images[25]);                
                                          drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[1]) ;
                                          drawImage(22*32,21*32,&tilemap.images[34]);                                                
                                          donkeyKong.x+=x_dir;
                                          donkeyKong.y+=y_dir;
                                          p=0;  
                                    
                                        }

                                        // if the health (hearts) is/are 2.
                                        if(p==2){

                                          // changing the score, number of hearts, and updating the coordinate
                                          // of the donneeded stuff,keykong.

                                          drawImage(34*32,21*32,&tilemap.images[25]); 
                                          drawImage(donkeyKong.x*32 ,donkeyKong.y*32, &tilemap.images[1]);
                                          drawImage(22*32,21*32,&tilemap.images[33]);   

                                          donkeyKong.x+=x_dir;
                                          donkeyKong.y+=y_dir;
                                          p=1;
                                    
                                        }                                               

                                    }   

                                  // If boundary-collisions happened, do the following:

                                  if(boundary_collisions(donkeyKong)==1){

                                    donkeyKong.x-=x_dir;
                                    donkeyKong.y-=y_dir;
                                    drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                        }  

                                  // If donkeyKong hits the obstacle:

                                  if(donkeyKong_hits_obstacle(donkeyKong)==1){

                                          p++;

                                          // if it is the first hit, decrease its health and score.
                                          if(p==1){
                                          drawImage(36*32,21*32,&tilemap.images[4]);
                                          drawImage(22*32,21*32,&tilemap.images[33]); 

                                        }

                                          // if it is the second hit, decrease its health score.
                                          if(p==2){

                                          drawImage(34*32,21*32,&tilemap.images[4]); 
                                          drawImage(22*32,21*32,&tilemap.images[32]); 
                                        }

                                          // if it is the third hit, decrease its health and score
                                          // and go to exit screen.

                                          if(p==3){

                                            p=0;
                                            drawImage(22*32,21*32,&tilemap.images[35]); 
                                            drawImage(32*32,21*32,&tilemap.images[4]); 

                                            // initialzing the counters for health packs as well.

                                            health_pack_counter=0;
                                            health_pack_counter1=0;
                                            health_pack_counter2=0;
                                            health_pack_counter3=0;
                                            health_pack_counter4=0;

                                            exit_screen_display();                                        // show the exit screen display.
                                        }

                                          donkeyKong.x+=x_dir;                                            // update the position of the donkeyKong.
                                          donkeyKong.y+=y_dir;

                                          if(boundary_collisions(donkeyKong)==1){                         // if boundary collision happened, just:

                                          donkeyKong.x-=2*x_dir;
                                          donkeyKong.y-=2*y_dir;
                                        }  
                                          drawImage(donkeyKong.x *32 , donkeyKong.y*32, &tilemap.images[2]);
                                    
                        }

                        }        
                        }
                        }
                        }


                               