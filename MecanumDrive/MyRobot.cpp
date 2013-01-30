#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{
	Jaguar fl;
	Jaguar fr;
	Jaguar rl;
	Jaguar rr;
	RobotDrive myRobot; // robot drive system
	Joystick stick; // Extreme3DPro
/*	Joystick stick2; //optional second stick */
	

public:
	RobotDemo(void):

	/*	stick2(2), */
		fl(1),
		fr(2),
		rl(3),
		rr(4),
		myRobot(fl, rl, fr, rr),	// these must be initialized in the same order
		stick(1)		// as they are declared above.
	{
		//myRobot.SetExpiration(0.1);
	}

	
	void Autonomous(void)
	{

	}


	void OperatorControl(void)
	{
		
		DriverStationLCD *screen = DriverStationLCD::GetInstance();
		
		while (IsOperatorControl())
		{
			/* Using the Extreme3DPro Joystick */
			myRobot.MecanumDrive_Cartesian(stick.GetY(), stick.GetX(), stick.GetTwist(), 0.0);
			screen->PrintfLine(DriverStationLCD::kUser_Line1,"FL: %.3f, FR: %.3f", fl.Get(), fr.Get());
			screen->PrintfLine(DriverStationLCD::kUser_Line2,"BL: %.3f, BR: %.3f", rl.Get(), rr.Get());
			screen->PrintfLine(DriverStationLCD::kUser_Line3,"X: %.3f, Y: %.3f", stick.GetX(), stick.GetY());
			screen->PrintfLine(DriverStationLCD::kUser_Line4,"y", rr.Get());
			screen->PrintfLine(DriverStationLCD::kUser_Line5,"B: %f", rr.Get());
			screen->PrintfLine(DriverStationLCD::kUser_Line6,"Back Right: %f", rr.Get());
			
			/* Using two Joysticks */
// 	 	 	myRobot.MecanumDrive_Cartesian(stick.GetY(), stick.GetX(), stick2.GetX(), 0.0);
			/* Using an Xbox controller */
//			myRobot.MecanumDrive_Cartesian(stick.GetY(), stick.GetX(), stick.GetZ(), 0.0);

//			screen->PrintfLine(DriverStationLCD::kUser_Line1("FL: .3f%",wheelFL));
			
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);

  
