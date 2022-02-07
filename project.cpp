/********************************************************************************************
* Author :MOHAMMED  B.  ALIYU     U1776384
* MASTER THESIS
* Filename : DESIGN OF  ARM CORTEX M-3 AND LABVIEW INTERFACE
* Date :14/09/2018

******************************************************************/
#include "mbed.h"
#include "defines.h"
#include "TextLCD.h" 
void ledd();                                             //function to read lead statutus from labview
void switchs();                                         //function to write the led status 
void read();                                            //function to receive string from labview
void LCD_clearLine();                                   //function to clear the string from labview
void ReadFromPC();                                      //function for read string if something is write on labview
void DisplayFromPC(void);                                 //function to display string on lcd

DigitalOut led1(RC0);                                   
DigitalOut led2(RC1);
DigitalOut led3(RC2);
DigitalOut led4(RC3);
DigitalOut led5(RC4);
DigitalOut led6(RC5);
DigitalOut led7(RC6);
DigitalOut led8(RC7);
DigitalIn switch1(RD0);
DigitalIn switch2(RD1);
DigitalIn switch3(RD2);
DigitalIn switch4(RD3);
DigitalIn switch5(RD4);
DigitalIn switch6(RD5);
DigitalIn switch7(RD6);
DigitalIn switch8(RD7);
AnalogIn x(PA0); //LDR
AnalogIn y(PA1); //temperature
AnalogIn z(PA2); //potentiometer
int Index_StringFromPC=0; 
char StringFromPC[17]=" ";  //array sent fro labview
char analogselection=0;     //declaring a variable
TextLCD lcd(PA_11, PB_12, PC_8, PC_6, PC_5, PA_12 ); //initialize text input
     
float smth;
float smth2;
float smth3;
float smth4;
float smth5;
float smth6;
float smth7;
float smth8;
float pot;
float ldr;
float temp;
float ON, OFF;
float led1status, led2status, led3status, led4status, led5status, led6status, led7status, led8status;


Serial pc(USBTX, USBRX);               //set usb serial port


int main()
{
 
  while(1)
    {
          
     
          read();                                    //display string from labview function
          //ledd();                                     //turning led fromlabview function
          //switchs();                                  //reading the switches and sensors from mbed
     
        
   }    
}
   



//function read analague signals and digital output
       
     void switchs()
 {  
    ON = 1;                                                    
    OFF = 0; 
    //checks to see if the switch is clicked and
    //the led is off
     if( switch1==1 || led1status > 0)                 //switch     1    and led 1                            /
     {    
         smth = ON;                                     //turns on the switch1 on labview if so
        
     }
        else
     { 
        smth = OFF;                                   //turns off the switch1 if it is not
        
     }
      
      if( switch2==1 || led2status > 0)
       {
       smth2 = ON;                                    //turns on the switch2 on labview if so
       }
       
        else
       { 
        smth2 = OFF;                                 //turns off the switch2 if it is not
       }
         if( switch3==1 || led3status > 0)
       {
       smth3 = ON;                                       //turns on the switch3 on labview if so
       }
       
        else
       { 
        smth3 = OFF;                                     //turns off the switch3 if it is not    
       }
         if( switch4==1 || led4status > 0)
       {
       smth4 = ON;                                     //turns on the switch4 on labview if so
       }
       
        else
       { 
        smth4 = OFF;                                   //turns off the swtich4 if it is not
       }
         if( switch5==1 || led5status > 0)
       {
       smth5 = ON;                                    //turns on the switch5 on labview if so
       } 
       
        else
       { 
        smth5 = OFF;                                   //turns off the switch5 if it is not
       }
         if( switch6==1 || led6status > 0)
       {
       smth6 = ON;                                   //turns on the switch6 on labview if so
       }
       
        else
       { 
        smth6 = OFF;                                 //turns off the switch6 if it is not
       }
         if( switch7==1 || led7status > 0)
       {
       smth7 = ON;                                         //turns on the switch7 on labview if so
       }
       
        else
       { 
        smth7 = OFF;                                    //turns off the switch7 if it is not
       }
         if( switch8==1 || led8status > 0)
       {
       smth8 = ON;                                       //turns on the switch8 on labview if so
       }
       
        else
       { 
        smth8 = OFF;                                   //turns off the switch8 if it is not
       }
       //the leds are the stastus of the outcome of if statements
        led1 = smth;                                    
        led2 = smth2;
        led3 = smth3;
        led4 = smth4;
        led5 = smth5;
        led6 = smth6;
        led7 = smth7;
        led8 = smth8;
         //reading analogue signals from mbed
         pot = z.read();                                    //reads the value of the potentiometer
         pot = pot*10; 
         wait(0.02);
         ldr= x.read();                                    //reads the value of the LDR
         ldr = ldr *100;   
         wait(0.02);
         temp = y.read();                                  //reads the value of the lm35 sensor
         temp = temp *220;    
         wait(0.02);
         //prints the status of the led/switches on labview and displays the value of the sensors read
         pc.printf("%f,%f,%f,%f,%f,%f,%f,%f,%9f,%90f,%90f,%sf\n",smth,smth2, smth3, smth4, smth5, smth6, smth7,smth8, pot, ldr, temp); 

}


///funtion to read leds status from LabVIEW

void ledd()
{  
       //print leds status from labview on mbed
         pc.scanf("%f,%f,%f,%f,%f,%f,%f,%f",&led1status, &led2status, &led3status , &led4status , &led5status , &led6status , &led7status , &led8status  ); 
          //if current led status is less than 1
           if (led1status<1)                   
         {
             led1=false;                                     //turn off led 1
         }
         else 
         {
             led1=true;                                     //turn on led 1
         }
         
         
         if (led2status<1)
         {
             led2=false;                                   //turn off led 2
         }
         else 
         {
             led2=true;                                //turn on led 2
         }
          
         if (led3status<1)
         {
             led3=false;                                   //turn on led 3
         }
         else 
         {
             led3=true;                                     //turn on led 3
         } 
         if (led4status<1)
         {
             led4=false;                                  //turn off led 4
         }
         else 
         {
             led4=true;                                     //turn on led 4
         }
         if (led5status<1)
         {
             led5=false;                                   //turn off led 5
         } 
         else 
         {
             led5=true;                                 //turn on led 5
         }
          if (led6status<1)
         {
             led6=false;                                   //turn off led 6
         }
         else 
         {
             led6=true;                                   //turn on led 
         }
         if (led7status<1)
         {
             led7=false;                                    //turn off led 7
         }
         else 
         {
             led7=true;                                     //turn on led 7
         }
         if (led8status<1)
         {
             led8=false;                                    //turn off led 8
         }
         else 
         {
             led8=true;                                       //turn on led 8
         } 
  
  
    
} 


 //function to read string from labview
void read()
{
    pc.scanf("%s",StringFromPC);                      //read the string form labview
    DisplayFromPC();                                   //display the string from labview
}

//function to display string form labview 
void DisplayFromPC(void)
{
   
    lcd.locate(0,0) ;                                                 //cursor position
    lcd.printf("%s", StringFromPC) ;                                   //display string from PC on LCD
    wait(1.0);                                                          //delay
      // initialzing the character string                                                                          
    for (Index_StringFromPC=0;Index_StringFromPC<17;Index_StringFromPC++)  
    {
        StringFromPC[Index_StringFromPC] = ' ' ;                            
    }
    LCD_clearLine() ;                                                  //clear string line
    lcd.locate(0,0) ;                                   
    Index_StringFromPC = 0;                                            //return the string form labview to zero
    lcd.cls();                                                          //clear lcd
}


//function to read string from labview
void ReadFromPC()
{
    analogselection=0;
    StringFromPC[Index_StringFromPC] = pc.getc();                         //allow the string to be transfered from labview
      
    pc.putc((int) StringFromPC[Index_StringFromPC]);                     //display the charcter on labview
      
    if (StringFromPC[Index_StringFromPC] == '\r')                        //if the entered is pressd after a string is inputed
    {
        DisplayFromPC() ;                                                  //display the string on LCD
    }
   
}


//function to clear string 
void LCD_clearLine()
{
    char i=0;                 //variable to increment through the letters
    for (i=0; i<17; i++)             //so long it is less than 17 keep increasing
    {
        lcd.locate(0,i);             //lcd locate the current cursor postion
        lcd.putc(' ');                //lcd the put the value of the current positon
    }
}