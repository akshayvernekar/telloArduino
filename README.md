# telloArudino
This is a arudino library for controlling DJI tello through ESP32

This library controls the tello by sending commands via UDP as mentioned in the SDK documenatation in below link
https://www.ryzerobotics.com/tello/downloads

## How to use the library ?
1. To download , enter "git clone https://github.com/akshayvernekar/telloArudino.git" in the terminal(Mac/linux) or command prompt(Windows) or  click the DOWNLOAD ZIP button .

2. Place the "tello" folder in your arduinosketchfolder/libraries/ folder. 
You may need to create the libraries subfolder if its your first library. Restart the IDE.

3. In your Arudino Playground application go to Sketch > Include Library > choose "tello" from Contributed Libraries section to include this library in your skecth. Go to examples\tello_example.ino for example usage .

## Using the example:
	Replace the 'networkName' and 'networkPswd' with the SSID and password of your drone .
