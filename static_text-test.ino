
#include <SoftwareSerial.h>
#include <SPI.h>       
#include <DMD.h>        
#include <TimerOne.h>   
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#define DISPLAYS_ACROSS 15
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}
void setup(void)
{
   Serial.begin(9600);
   Timer1.attachInterrupt( ScanDMD );  
   dmd.clearScreen( true );   
}
void loop(void)
{
   dmd.clearScreen( true );       //"true" turns every led on panel off.
   dmd.selectFont(SystemFont5x7); //using small fonts
   //To draw a line (straight or otherwise) from location x1, y1 to x2, y2 use:
   //dmd.drawLine(  x1, y1, x2, y2, GRAPHICS_NORMAL );
   dmd.drawLine( 0,0, 479, 0, GRAPHICS_NORMAL ); //(0,0) is the starting point. (95,0) is the ending point. total 96 columns (0 to 95) *HORIZONTAL LINE*
   dmd.drawLine( 0,15, 479, 15, GRAPHICS_NORMAL ); //(0,15) is the bottom-left corner in row-1. (95,15) is the bottom right corner in row-1. *HORIZONTAL LINE*
   dmd.drawLine( 0,0, 0, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 32,0, 32, 15, GRAPHICS_NORMAL ); //*COLUMN 2 DEMARCATION*
   dmd.drawLine( 64,0, 64, 15, GRAPHICS_NORMAL ); //*COLUMN 3 DEMARCATION*
   dmd.drawLine( 96,0, 96, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 128,0, 128, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 160,0, 160, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 192,0, 192, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 224,0, 224, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 256,0, 256, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 288,0, 288, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 320,0, 320, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 352,0, 352, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 384,0, 384, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 416,0, 416, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 448,0, 448, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 480,0, 480, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   
    //To display a line of text, use the following: dmd.drawString( x,y, "text,", z, GRAPHICS_NORMAL );
   //where x and y are the coordinates for the top-left pixel of the first character in the line of text being displayed, 
   //text is the text to display, 
   //and z is the length of the text to display in characters. 
   
   //dmd.drawString(68,4,"S.NO",4,GRAPHICS_NORMAL); //63,64,65,66,67,68

   dmd.drawString(388,4,"LANE",4,GRAPHICS_NORMAL); 
   dmd.drawString(420,4,"FREE",4,GRAPHICS_NORMAL); //32,33,34
   dmd.drawString(450,4,"SLOTS",5,GRAPHICS_NORMAL); //63,64,65,66,67,68
   dmd.drawString(292,4,"L  1",4,GRAPHICS_NORMAL); //63,64,65,66,67,68
   dmd.drawString(196,4,"L  2",4,GRAPHICS_NORMAL); //63,64,65,66,67,68
   dmd.drawString(100,4,"L  3",4,GRAPHICS_NORMAL); //32,33,34
   dmd.drawString(4,4,"L  4",4,GRAPHICS_NORMAL);
   
   dmd.drawLine(31,0,31, 15, GRAPHICS_NORMAL );
   dmd.drawLine(63,0, 63, 15, GRAPHICS_NORMAL );
   dmd.drawLine(95,0, 95, 15, GRAPHICS_NORMAL );
   dmd.drawLine(127,0, 127, 15, GRAPHICS_NORMAL);
   dmd.drawLine(159,0, 159, 15, GRAPHICS_NORMAL);
   dmd.drawLine(191,0, 191, 15, GRAPHICS_NORMAL);
   dmd.drawLine(223,0, 223, 15, GRAPHICS_NORMAL);
   //dmd.drawLine( 224,0, 224, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 255,0, 255, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 287,0, 287, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 319,0, 319, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 351,0, 351, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 383,0, 383, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 415,0, 415, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 447,0, 447, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*
   dmd.drawLine( 479,0, 479, 15, GRAPHICS_NORMAL ); //*VERTICAL LINE*

    unsigned int offset = 0;
    unsigned int index = 0;
    unsigned int temp;
    unsigned int count_of_zero=0;
    unsigned int arr[10];
    int inputserial;
    unsigned int intinputserial;
    offset = 0;
    index=0;
    String str;
    const int ledPin = 13; // 13 for standard arduino
    char stringLane1[2];
    char countLane1[1];
    
    dmd.selectFont(Arial_Black_16);

    if(Serial.available())
       {    
        if(Serial.find("S1")) //Serial.find("S1")
        {
          stringLane1[0]='A';
          //digitalWrite(ledPin,HIGH);
          //delay(2000);
          //digitalWrite(ledPin,LOW);
          delay(100);
          //inputserial = Serial.read();
          str = Serial.readString();
          Serial.println(str);
          inputserial = str.toInt();
          Serial.println(inputserial);
          //Serial.write(inputserial);
          Serial.println(inputserial);
          intinputserial = inputserial;
          
          offset = 0;
          index=0;
          while(offset<8)
          {
            temp = intinputserial&1;
            
            arr[index++] = temp;
            intinputserial>>=1;
    
            offset++;
          }
          for (int index2 = 0; index2<8; index2++)
          {
            if(arr[index2]==0)
            {
              stringLane1[1]=index2+'0';
              count_of_zero++;
              dmd.drawString(360,1,stringLane1,2,GRAPHICS_NORMAL); 
              delay(2000);
              Serial.print("A");
              Serial.println(index2);
            }
            //Serial.print(count_of_zero);
            //Serial.print("count is "+count_of_zero);
          }
          Serial.print(" Count is ");
          Serial.println(count_of_zero);
          countLane1[0]=count_of_zero+'0';
          dmd.drawString(334,1,countLane1,1,GRAPHICS_NORMAL); 
    
        }
      }
    delay(5000);
}





