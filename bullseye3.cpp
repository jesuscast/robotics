//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#pragma config(Motor,  port2,           frontRightLift,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backRightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontLeftLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backLeftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftClaw,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,           backLeft,      tmotorVex393_MC29, openLoop)

#pragma platform(VEX)


//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////


void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;


        // All activities that occur before the competition starts
        // Example: clearing encoders, setting servo positions, ...
}


//Lifting
bool liftUp = false;
bool liftDown = false;
bool liftMoving = false;
int fRL = 1;
int bRL = 1;
int fLL = 1;
int bLL = 1;

//claw
bool openClaw = false;
bool closeClaw = false;


//Joystick
//int btn6Up = true;
//int btn6Down = true;
int liftBtnUp = true;
int liftBtnDown = true;
int btn5Up = true;
int btn5Down = true;


void Joysticking() {
        liftBtnUp = vexRT[Btn6U];
        liftBtnDown = vexRT[Btn6D];
        btn5Up = vexRT[Btn5U];
        btn5Down = vexRT[Btn5D];
}


void Lifting() {
        if ((liftBtnUp == 1) || (liftBtnDown == 1)) {
                liftMoving = true;
                if (liftBtnUp == 1) {
                        liftUp = true;
                        liftDown = false;
                        } else if (liftBtnDown == 1) {
                        liftDown = true;
                        liftUp = false;
                }
                } else {
                liftMoving = false;
                liftUp = false;
                liftDown = false;
        }


        if (liftMoving == true) {
                if (liftUp) {
                    motor[frontRightLift] = 80*fRL;
                    motor[backRightLift] = 80*bRL;
                    motor[frontLeftLift] = 80*fLL;
                    motor[backLeftLift] = 80*bLL;
                    wait1Msec(10);
                    } else if (liftDown) {
                      motor[frontRightLift] = -80*fRL;
                      motor[backRightLift] = -80*bRL;
                      motor[frontLeftLift] = -80*fLL;
                      motor[backLeftLift] = -80*bLL;
                      wait1Msec(10);
                    }
        } else {
          motor[frontRightLift] = 0;
          motor[backRightLift] = 0;
          motor[frontLeftLift] = 0;
          motor[backLeftLift] = 0;
          wait1Msec(10);
        }
}


void ClawMoving(){
        if(btn5Up==1 || btn5Down==1){
                if(btn5Up==1){
                        openClaw = true;
                }
                if(btn5Down==1){
                        closeClaw = true;
                }
        }
        if(openClaw==true && closeClaw==false){
                motor[leftClaw] = 50;
                wait1Msec(200);
                motor[leftClaw] = 0;
                openClaw = false;
        }
        else if(closeClaw==true && openClaw==false){
                motor[leftClaw] = -50;
                wait1Msec(200);
                motor[leftClaw] = 0;
                closeClaw = false;
        }
}
void Driving(){
        //Right side of the robot is controlled by the right joystick, Y-axis
        if ( (vexRT[Ch3]>15) || (vexRT[Ch3]<-15)){
                motor[frontRight] = vexRT[Ch3];
                motor[backRight]  = -vexRT[Ch3];
        }
        else {
                motor[frontRight] = 0;
                motor[backRight]  = 0;
        }
        //Left side of the robot is controlled by the left joystick, Y-axis
        if( (vexRT[Ch2]>15) || (vexRT[Ch2]<-15) ){
                motor[frontLeft] = -vexRT[Ch2];
                motor[backLeft]  = vexRT[Ch2];
        }
        else {
                motor[frontLeft] = 0;
                motor[backLeft]  = 0;
        }
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////


task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................


        AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}


/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////


task usercontrol()
{
        // User control code here, inside the loop


        while (true)
        {
          // This is the main execution loop for the user control program. Each time through the loop
          // your program should update motor + servo values based on feedback from the joysticks.


          // .....................................................................................
          // Insert user code here. This is where you use the joystick values to update your motors, etc.
          // .....................................................................................


          Joysticking();
                Lifting();
                Driving();
                ClawMoving();
        }
}
