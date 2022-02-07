/*   Include file to simplify mbed programming - Compatible with E-Block and MinkroC  */
/*******************************************************************************************************/
//PORTA 
#define PA0 PA_0        //LDR
#define PA1 PA_1        //Temp sensor
#define PA2 PA_4	//POT
#define PA3 PB_0
#define PA4 PC_1
#define PA5 PC_0
#define PA6 PC_3
#define PA7 PC_2
/**********************************************/

// PORTB
#define RB0 PC_8        //PWM 
#define RB1 PC_6        //PWM
#define RB2 PC_5 
#define RB3 PA_12 
#define RB4 PA_11 
#define RB5 PB_12 
#define RB6 PB_11 
#define RB7 PB_2  
BusOut PORTB(RB0,RB1,RB2,RB3,RB4,RB5,RB6,RB7);
/*************************************************/

//PORTC
#define RC0 PC_9
#define RC1 PB_8
#define RC2 PB_9
#define RC3 PA_5
#define RC4 PA_6
#define RC5 PA_7
#define RC6 PB_6
#define RC7 PC_7
BusOut PORTC(RC0,RC1,RC2,RC3,RC4,RC5,RC6,RC7);
/*************************************************/

//PORTD
#define RD0 PB_1        //PWM
#define RD1 PB_15       //PWM
#define RD2 PB_14       //PWM
#define RD3 PB_13       //PWM
#define RD4 PC_4
#define RD5 PA_10
#define RD6 PB_3
#define RD7 PB_5
BusIn PORTD(RD0,RD1,RD2,RD3,RD4,RD5,RD6,RD7);
/*************************************************/ 

//PORTF
#define RF0 PB_7
#define RF1 PA_15       //PWM
#define RF2 PA_13
#define RF3 PC_12
#define RF4 PC_10
#define RF5 PC_11
#define RF6 PD_2
#define RF7 PB_4       //PWM
BusOut PORTF(RF0,RF1,RF2,RF3,RF4,RF5,RF6,RF7);
