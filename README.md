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
	// 1. Create the object
	Tello tello
	
	// 2. Initialise the Object after your device gets the IP address
	tello.init()
	
	// 3 .Once the object is initalised you can use the various fubnctions to send commands to tello.

## Using the example:
	Replace the 'networkName' and 'networkPswd' with the SSID and password of your drone .
