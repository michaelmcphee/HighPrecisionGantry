// Motor B & D control up and down motion (B being L and D being R), Motor A controls left and right, Motor C controls enter
// Assumes actuator motor is at top

void press_key(int speed);
//Presses a key
int manualOverride(int speed);
//Enters a console
void setDatum(int speed);
//Calibrates the robot
void typeString (int*keysToType, int datumOffsetX, int datumOffsetY, int sizeOfArray);
//Iterates through a keysToType array typing each key
void configureAllSensors();
//Configures sensors
int environmentChecking(int xoffset, int yoffset);
//Types a desired string based on an inputted index array
void driveToKey(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int delayKey,
int xoffset, int yoffset);
//Drives to a desired key

void checkIfAboveAndToLeft(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int
delayKey, int xoffset, int yoffset);
void checkIfBelowAndToLeft(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int
delayKey, int xoffset, int yoffset);
void checkIfAboveAndToRight(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int
delayKey, int xoffset, int yoffset);
void checkIfBelowAndToRight(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int
delayKey, int xoffset, int yoffset);
/*These four functions are used by typeString to evaluate all cases of where a key could be relative to the current position*/
void easterEgg (int xoffset, int yoffset);
/*If the enter and top buttons are held at the end of the type hello world task the robot will enter a loop typing that its been trying to contact you about your cars extended warranty� the loop is set to only two iterations for the convenience of demonstrating this without waiting several minutes for it to finish, however should the user wish for it to type more iterations, they simply need to change this value.*/


const char keysArray[29] = {'/','a', 'b', 'c', 'd', 'e', 'f', 'g','h','i','j','k','l','m','n','o',
'p','q','r','s','t','u','v','w','x','y','z',' ','#'};
//Parallel array 1 key map.
/*The two commented out arrays are a previous key map. The group often used this to debug by comparing how changing one value impacted the alignment of a key
const int coordinateX[28]={25,130,435,310,270,260,320,400,470,575,535,590,667,578,500,635,711,136,315,220,
373,519,381,185,236,460,185,440};
const int coordinateY[28]={25,120,55,60,110,170,110,110,110,165,100,110,125,65,60,171,171,176,171,112,162,
162,65,190,51,172,57,3};
*/
const int coordinateX[29]={25,155,435,305,270,260,330,400,468,575,535,590,668,578,500,650,711,136,323,
210,395,519,381,193,232,450,185,440,865};
//Parallel array 2 map for x coordinates of related keys
const int coordinateY[29]={25,155,95,95,155,220,155,155,155,220,155,155,155,95,95,220,220,220,220,155,220,
220,95,220,95,220,95,29,155};
//Parallel array 3 map for y coordinates of related keys


const int helloworld[12]={8, 5, 12, 12, 15, 27, 23, 15, 18, 12, 4, 28};
//Key indexes to type hello world
const int finger[89] = {8, 15, 23, 27, 3, 15, 21, 12, 4, 27, 25, 15, 21, 27, 20, 15, 21, 3, 8, 27, 25, 15,
21, 18, 27, 6, 9, 14, 7, 5, 18, 27, 20, 15, 27, 13, 25, 27, 3, 15, 12, 15, 21, 18, 27, 19, 5, 14,
19, 15, 18, 27, 25, 15, 21, 27, 4, 9, 19, 1, 16, 16, 15, 9, 14, 20, 27, 13, 5, 27, 1, 14, 4, 27,
13, 1, 11, 5, 27, 13, 5, 27, 19, 15, 27, 19, 1, 4, 28};
//Key indexes to type a response after a user touches their finger to the colour sensor
const int goodbyeworld[14]={7, 15, 15, 4, 2, 25, 5, 27, 23, 15, 18, 12, 4, 28};
//Key indexes to type goodbye world
const int light [43]={7, 5, 20, 27, 20, 8, 1, 20, 27, 12, 9, 7, 8, 20, 27, 15, 21, 20, 27, 15, 6, 27, 13,
25, 27, 6, 1, 3, 5, 27, 9, 27, 3, 1, 14, 14, 15, 20, 27, 19, 5, 5, 28};
//Key indexes to type a phrase in response to a change in ambient lighting
const int shush [36] = {25, 15, 21, 27, 1, 18, 5, 27, 2, 5, 9, 14, 7, 27, 20, 15, 15, 27, 12, 15, 21, 4,
27, 16, 12, 5, 1, 19, 5, 27, 19, 8, 21, 19, 8, 28};
//Key indexes to type a phrase in response to a loud environment
const int obstacle [21] = {20, 8, 5, 18, 5, 27, 9, 19, 27, 1, 14, 27, 15, 2, 19, 20, 1, 3, 12, 5, 28};
//Key indexes to type a phrase in response to a vertical obstruction
const int carwarranty [69] = {23, 5, 27, 8, 1, 22, 5, 27, 2, 5, 5, 14, 27, 20, 18, 25, 9, 14, 7, 27, 20,
15, 27, 3, 15, 14, 20, 1, 3, 20, 27, 25, 15, 21, 27, 1, 2, 15, 21, 20, 27, 25, 15, 21, 18, 27, 3,
1, 18, 19, 27, 5, 24, 20, 5, 14, 4, 5, 4, 27, 23, 1, 18, 18, 1, 14, 20, 25, 28};
//Key indexes for the easterEgg function
const int abc [27] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
24, 25, 26, 28};
//Key indexes for the alphabet, useful for debugging and for checking calibration

// All of the following index array were made using the written C++ code. The C++ code is not a focus of this project, simply an aid to avoid creating these arrays by hand.

const int userModifiableXOffset = -20;
const int  userModifiableYOffset = -20;
//For emergency recalibration these offsets shift the position of each key in the array. Use as a last resort.
const int delayKeyPress = 5;
//This is the delay between going to a key and pressing it, helpful for debugging
const int testSpeed = 50;
//Optimal accuracy and precision is at 50% speed, but it works reliably up 80% speed.

task main()
{
	setDatum(testSpeed); // Calibration
	int datumOffsetX = -nMotorEncoder(motorA)-userModifiableXOffset;
	int datumOffsetY = -nMotorEncoder(motorB)-userModifiableYOffset;
	//EV3 Calculated offsets taking into account the user modifiable offsets
	typeString(helloworld, datumOffsetX, datumOffsetY, sizeof(helloworld)/sizeof(helloworld[0]));
	//Types hello world
	wait1Msec(1000);
	easterEgg(datumOffsetX, datumOffsetY);
	//Checks if the enter and top brick buttons are held, if so an easter egg is executed
	environmentChecking(datumOffsetX, datumOffsetY);
	//Enters a state where the sensors can be armed and disarmed so the EV3 can react accordingly
	wait1Msec(3000);
	manualOverride(testSpeed);
//Allows manual control of the robot if the top and bottom brick buttons are held
	}


void press_key(int speed)
{
	nMotorEncoder(motorC)=0;
	const float InertialLinearTolerance = 0.041;
	const float yInterceptOfInertiaModel = 0.5;
	const float correctionTolerance = (speed*InertialLinearTolerance)+yInterceptOfInertiaModel;
	//Uses the slope of the line for a line of speed vs. error to account for error at variable speed
	motor[motorC] = speed;
	while (nMotorEncoder(motorC)<(360-correctionTolerance)){}
	//Does a full rotation implementing the previously calculated correction tolerance
	motor[motorC] = 0;
	wait1Msec(200);
}



void setDatum(int speed)
{
	//setdatum goes at full speed for user convenience
	configureAllSensors();
	displayString(1, "Set pusher before starting");
	displayString(2, "...then press enter");
	while (!getButtonPress(buttonEnter))
//Waits for enter button to be pressed
	{}
	while (getButtonPress(buttonEnter))
	{}
	displayString(1, "                                   ");
	displayString(1, "   STANDBY: CALIBRATING            ");
	displayString(2, "                          ");
	motor[motorA] = -100;
	wait1Msec(1500);
	motor[motorB] = motor[motorD] = -100;
	wait1Msec(2500);
	//motor[motorB] = motor[motorD]= motor[motorA] = motor[motorC] = 0;
	nMotorEncoder[motorA] =	nMotorEncoder[motorB] = nMotorEncoder[motorC] = nMotorEncoder[motorD]= 0;
	//Goes to the bottommost corner of the plane, then sets that corner as a 0,0 datum
	driveToKey(0, coordinateX, coordinateY, speed, keysArray, delayKeyPress,0,0);
/*Attempts to approach a point very close to the (0,0) datum thereby allowing an offset to be
calibarated for how close to the datum can the system reliably approach*/
	displayString(1, "                                   ");
	displayString(1, "@ (%.0f,%.0f), & %.0f", nMotorEncoder(motorA), nMotorEncoder(motorB),
testSpeed);
	//Displays datum, useful for debugging
}

void driveToKey(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int delayKey,
int xoffset, int yoffset)
{
	displayString(1, "->(%.0f,%.0f) Key: %c", coordinateX[index-1], coordinateY[index-1],
keysArray[index]);
	//Displays key it is trying to go to
	//Checks if at key already
	checkIfAboveAndToLeft(index, coordinateX,coordinateY, speed, keysArray, delayKey, xoffset,
yoffset);
	checkIfBelowAndToLeft(index, coordinateX,coordinateY, speed, keysArray, delayKey, xoffset,
yoffset);
	checkIfAboveAndToRight(index, coordinateX,coordinateY, speed, keysArray, delayKey, xoffset,
yoffset);
	checkIfBelowAndToRight(index, coordinateX,coordinateY, speed, keysArray, delayKey, xoffset,
yoffset);
	wait1Msec(200);
	press_key(speed);
	displayString(1, "                                   "); // Clears line of key to go to.
}
int manualOverride(int speed)
{

	if (getButtonPress(buttonDown)!=1 && getButtonPress(buttonUp)!=1)
	{
		return 1;
	}
	speed +=50;
	//full speed
	while (true)
	{
		displayString(10, "Override console:");
		displayString(12, "X Coordinate: %.0f (MotorA)", nMotorEncoder(motorA));
//Displays X coord
		displayString(13, "Y Coordinate: %.0f (MotorB)", nMotorEncoder(motorB));
//Displays Y coord
		displayString(11, "Press up and down to exit.");
		wait1Msec(1000);
		if (getButtonPress(buttonDown)==1 && getButtonPress(buttonUp)==1)
		{
			return 1;
			//A user can hold up and down when they wish to exit
		}
		if (getButtonPress(buttonUp)==1)
		{
			motor[motorB] = motor[motorD] = speed;
			wait1Msec(20); // Pulse width modulation :)
			motor[motorB] = motor[motorD] = 0;
		}
		if (getButtonPress(buttonDown)==1)
		{
			motor[motorB] = motor[motorD] = -speed;
			wait1Msec(20);
			motor[motorB] = motor[motorD] = 0;
		}
		if (getButtonPress(buttonLeft)==1)
		{
			motor[motorA] = -speed;
			wait1Msec(20);
			motor[motorA] = 0;
		}
		if (getButtonPress(buttonRight)==1)
		{
			motor[motorA] = speed;
			wait1Msec(20);
			motor[motorA] = 0;
		}
		if (getButtonPress(buttonEnter)==1)
		{
			press_key(speed);
		}
	}
}

void typeString(int* keysToType, int datumOffsetX, int datumOffsetY, int sizeOfArray)
{
	for (int count = 0; count < sizeOfArray; count ++)
	{ //iterates through array of keysToType
		driveToKey(keysToType[count], coordinateX, coordinateY, testSpeed, keysArray,
delayKeyPress, datumOffsetX, datumOffsetY);
	}
}

void configureAllSensors()
{
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Color;
	SensorType[S3] = sensorEV3_Ultrasonic;
	SensorType[S4] = sensorSoundDB;
}

int environmentChecking(int xoffset, int yoffset)
{
	displayString(2, "Use touch sensor to arm");
	while(SensorValue[S1] != 1)
	{}
	while(SensorValue[S1] == 1)
	{}
	time1[T1] = 0;
	while(time1[T1] < 300000)
	{
		displayString(2, "                       ");
		displayString(2, "ARMED");
		if (SensorValue[S1]==1) //Checks if disarmed
		{
			displayString(2, "                                 ");
			displayString(2, "DISARMED SHUT DOWN ENABLED");
			displayString(3, "hold U&D to ent/ext debug");
			typeString(goodbyeworld, xoffset, yoffset, sizeof(goodbyeworld)/
sizeof(goodbyeworld[0]));
			return 1;
		}
		if (SensorValue[S2]>40) //Checks if there is a finger touching the colour sensor
		{
			typeString(finger, xoffset, yoffset, sizeof(finger)/sizeof(finger[0]));
		}
		if (SensorValue[S4]==100) //Checks if the room is too loud
		{
			typeString(shush, xoffset, yoffset, sizeof(shush)/sizeof(shush[0]));
		}
		if (SensorValue[S3] > 45 && SensorValue[S3] < 50) //Checks if there is an obstacle
		{
			typeString(obstacle, xoffset, yoffset, sizeof(obstacle)/sizeof(obstacle[0]));
		}
	}
	return 1;
}

void checkIfAboveAndToLeft(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int
delayKey, int xoffset, int yoffset)
{
	//if moving right and down
	if(nMotorEncoder[motorA]<=coordinateX[index] && nMotorEncoder[motorB]>=coordinateY[index])
	{
		//move y
		motor[motorB]=motor[motorD]=-speed;
		while(nMotorEncoder[motorB]>(coordinateY[index]-yoffset))
		{}
		wait1Msec(delayKey);
		while(nMotorEncoder[motorB]>(coordinateY[index]-yoffset))
		{}
		motor[motorB]=motor[motorD]=0;
		//move x
		motor[motorA]=speed;
		while(nMotorEncoder[motorA]<(coordinateX[index]-xoffset))
		{}
		wait1Msec(delayKey);
		while(nMotorEncoder[motorA]<(coordinateX[index]-xoffset))
		{}
		motor[motorA]=0;
	}
}
void checkIfBelowAndToLeft(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int
delayKey, int xoffset, int yoffset)
{
	//if moving right and up
	if(nMotorEncoder[motorA]<=coordinateX[index] && nMotorEncoder[motorB]<=coordinateY[index])
	{
		//move y
		motor[motorB]=motor[motorD]=speed;
		while(nMotorEncoder[motorB]<(coordinateY[index]-yoffset))
		{}
		wait1Msec(delayKey);
		while(nMotorEncoder[motorB]<(coordinateY[index]-yoffset))
/*Rechecks if at key, this helps with avoiding infinite loops, check future improvements in software section of the report*/
		{}
		motor[motorB]=motor[motorD]=0;
		//move x
		motor[motorA]=speed;
		while(nMotorEncoder[motorA]<(coordinateX[index]-xoffset))
		{}
		wait1Msec(delayKey);
		while(nMotorEncoder[motorA]<(coordinateX[index]-xoffset))
		{}
		motor[motorA]=0;
	}
}
void checkIfAboveAndToRight(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int
delayKey, int xoffset, int yoffset)
{
	//if moving left and down
	if(nMotorEncoder[motorA]>=coordinateX[index] && nMotorEncoder[motorB]>=coordinateY[index])
	{
		//move y
		motor[motorB]=motor[motorD]=-speed;
		while(nMotorEncoder[motorB]>(coordinateY[index]-yoffset))
		{}
		wait1Msec(delayKey);
		while(nMotorEncoder[motorB]>(coordinateY[index]-yoffset))
		{}
		motor[motorB]=motor[motorD]=0;
		//move x
		motor[motorA]=-speed;
		while(nMotorEncoder[motorA]>(coordinateX[index]-xoffset))
		{}
		wait1Msec(delayKey);
		while(nMotorEncoder[motorA]>(coordinateX[index]-xoffset))
		{}
		motor[motorA]=0;
	}
}

void checkIfBelowAndToRight(int index, int* coordinateX, int* coordinateY, int speed, char* keysArray, int
delayKey, int xoffset, int yoffset)
{
	//if moving left and up
	if(nMotorEncoder[motorA]>=coordinateX[index] && nMotorEncoder[motorB]<=coordinateY[index])
	{
		//move y
		motor[motorB]=motor[motorD]=speed;
		while(nMotorEncoder[motorB]<(coordinateY[index]-yoffset))
		{}
		wait1Msec(delayKey);
		while(nMotorEncoder[motorB]<(coordinateY[index]-yoffset))
		{}
		motor[motorB]=motor[motorD]=0;
		//move x
		motor[motorA]=-speed;
		while(nMotorEncoder[motorA]>(coordinateX[index]-xoffset))
		{}
		wait1Msec(delayKey);
		while(nMotorEncoder[motorA]>(coordinateX[index]-xoffset))
		{}
		motor[motorA]=0;
	}
}

void easterEgg (int xoffset, int yoffset)
{
	if (getButtonPress(buttonEnter) && getButtonPress(buttonUp))
	{
		for (int count = 1; count < 2; count ++)
		{
			typeString(carwarranty, xoffset, yoffset, sizeof(carwarranty)/
sizeof(carwarranty[0]));
		}
	}
}