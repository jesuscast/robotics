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
                motor[rightClaw] = 50;
                wait1Msec(200);
                motor[leftClaw] = 0;
                motor[rightClaw] = 0;
                openClaw = false;
        }
        else if(closeClaw==true && openClaw==false){
                motor[leftClaw] = -50;
                motor[rightClaw] = -50;
                wait1Msec(200);
                motor[leftClaw] = 0;
                motor[rightClaw] = 0;
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
