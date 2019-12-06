# telloArduino
This is a Arduino library for controlling DJI tello through ESP32

This library controls the tello by sending commands via UDP as mentioned in the SDK documenatation in below link
https://www.ryzerobotics.com/tello/downloads

## How to use the library ?
1. To download , enter "git clone https://github.com/akshayvernekar/telloArduino.git" in the terminal(Mac/linux) or command prompt(Windows) or  click the DOWNLOAD ZIP button .

2. Place the "tello" folder in your arduinosketchfolder/libraries/ folder. 
You may need to create the libraries subfolder if its your first library. Restart the IDE.

3. In your Arduino Playground application go to Sketch > Include Library > choose "tello" from Contributed Libraries section to include this library in your skecth. Go to examples\tello_example.ino for example usage .

## API usage
	1. Create the object
	Tello tello
	
	2. Initialise the Object after your device gets the IP address
	tello.init()
	
	3 .Once the object is initalised you can use the various fubnctions to send commands to tello.
	To take-off:
		bool takeoff();
		
	For Tello auto land:
		bool land();
		
	Set video stream on:
		bool startVideoStream();
		
	Set video stream off:
		bool stopVideoStream();
	
	Stop all motors immediately:
		bool turnOff();
	
	Tello fly up with distance x cm(min:20cm , max = 500 cm):
		bool up(int x);
		
	Tello fly down with distance x cm(min:20cm , max = 500 cm):	
		bool down(int x);
		
	Tello fly left with distance x cm(min:20cm , max = 500 cm):
		bool left(int x);
	
	Tello fly right with distance x cm(min:20cm , max = 500 cm):
		bool right(int x);
	
	Tello fly forward with distance x cm(min:20cm , max = 500 cm):
		bool forward(int x);
	
	Tello fly back with distance x cm(min:20cm , max = 500 cm):
		bool back(int x);
	
	Tello rotate x degree clockwise(min:1, max:3600):
		bool rotate_clockwise(int deg);
		
	Tello rotate x degree counter-clockwise	(min:1, max:3600):
		bool rotate_anticlockwise(int deg);
		
	Ask Tello to flip front:
		bool flip_front();
		
	Ask Tello to flip Right:
		bool flip_right();
		
	Ask Tello to flip Left:
		bool flip_left();
	
	Ask Tello to flip Back:
		bool flip_back();
		
	Set speed to x cm/s:
		bool setSpeed(int x);
	
	Send RC control via four channels(Yet to be implemented):
		bool sendRCcontrol(int x,int y,int z);
		
	Set Wi-Fi with SSID password(Works only with EDU version, so havent tested):
		bool changeWifi(string ssid, string password);
	
	@return for all the above commands: 
		true = if tello sent "ok" response for the command sent.
		false = if no response was received from tello, since the transmission is UDP 
			there might be packet loss and the response might have been lost.
	
	Get Speed:
		int getSpeed();
		@return: speed value ranges from 1-100
	
	Get Battery level percentage:
		int getBattery();
		@return: battery percentage 0-100
		
	Get Current Flying time:
		int getTime();
		@return: time in seconds
	
	Get current flying height:
		int getHeight();
		@return: height in cms value range 0-3000
	
	Get temperature (°C):
		int getTemperature();
		@return: value range 0-90
	
	Get barometer value (m):
		int getBaro();
		@return: value in meters

## Using the example:
	Replace the 'networkName' and 'networkPswd' with the SSID and password of your drone .
