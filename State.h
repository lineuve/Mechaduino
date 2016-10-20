//Contains the declaration of the state variables for the control loop  

#ifndef __STATE_H__
#define __STATE_H__


//interrupt vars

extern volatile float ei;
extern volatile int U;  //control effort (abs)
extern volatile float r;  //setpoint
extern volatile float y;  // measured angle
extern volatile float yw;
extern volatile float yw_1;
extern volatile float e;  // e = r-y (error)
extern volatile float p;  // proportional effort
extern volatile float i;  // integral effort
extern volatile float PA;  //

extern volatile float u;  //real control effort (not abs)
extern volatile long counter;

extern volatile long wrap_count;
extern volatile float y_1;

extern volatile float ITerm;

extern volatile char mode;


extern int dir;
extern int stepNumber;
extern void output(float,int);

extern volatile int enabled;

extern volatile int uMAX;
extern volatile int uPEAK;
extern volatile int uSTEP;

extern volatile int PEAKCounter;
extern int maxPEAKCounter;
extern int PEAKSPERSECOND;


extern volatile float ITerm;

extern volatile char mode;


//___________________________________

extern const float pi;
extern const int  half;//128;

extern float new_angle; //input angle
extern float current_angle; //current angle
extern float diff_angle;
extern int val1;
extern int val2;


#endif