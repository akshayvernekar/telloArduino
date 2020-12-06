/*
 * Tello.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: akki
 */

#include "Tello.h"

static const char* TELLOIPADDRESS = "192.168.10.1";
static const int COMMAND_PORT = 8889;
static const int STATUS_PORT = 8890;
#define MAXBUFFSIZE 512


using namespace std;

Tello::Tello()
{
	isInitialised = false;
}

Tello::~Tello()
{

}

void Tello::init()
{
	udpclient = new WiFiUDP();
	//This initializes udp and transfer buffer
	udpclient->begin(COMMAND_PORT);
	isInitialised = true;
	string response = sendCommand("command");

	//if response is other than "ok" then we consider as error 
	if(response.compare("ok"))
	{
		isInitialised = true;
	}
}


string Tello::sendCommand(string command)
{
	if(!isInitialised)
		return "error";

	udpclient->beginPacket(TELLOIPADDRESS, COMMAND_PORT);
  	udpclient->write((const unsigned char*)command.c_str(), command.length());
  	udpclient->endPacket();

	char buffer[MAXBUFFSIZE]={0};
	udpclient->parsePacket();
	int n = udpclient->read(buffer, MAXBUFFSIZE);
	if(n > 0)
	{
		buffer[n] = '\0';
	}
	printf("sendCommand: %s response=%s\n",command.c_str(),buffer);

	return string(buffer);
}

bool Tello::takeoff()
{
	string response = sendCommand("takeoff");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::land()
{
	string response = sendCommand("land");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::startVideoStream()
{
	string response = sendCommand("streamon");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::stopVideoStream()
{
	string response = sendCommand("streamoff");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::turnOff()
{
	string response = sendCommand("emergency");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::up(int x)
{
	char buff[10];
	string command = "up " + string(itoa(x,buff,10));
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::down(int x)
{
	char buff[10];
	string command = "down " + string(itoa(x,buff,10));
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::left(int x)
{
	char buff[10];
	string command = "left " + string(itoa(x,buff,10));
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::right(int x)
{
	char buff[10];
	string command = "right " + string(itoa(x,buff,10));
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::forward(int x)
{
	char buff[10];
	string command = "forward " + string(itoa(x,buff,10));
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::back(int x)
{
	char buff[10];
	string command = "back " + string(itoa(x,buff,10));
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::rotate_clockwise(int deg)
{
	char buff[10];
	string command = "cw " + string(itoa(deg,buff,10));
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::rotate_anticlockwise(int deg)
{
	char buff[10];
	string command = "ccw " + string(itoa(deg,buff,10));
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::flip_front()
{
	string response = sendCommand("flip f");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::flip_right()
{
	string response = sendCommand("flip r");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::flip_left()
{
	string response = sendCommand("flip l");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::flip_back()
{
	string response = sendCommand("flip b");
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::setSpeed(int x)
{
	char buff[10];
	string command = "speed " + string(itoa(x,buff,10));
	string response ;
	if((x < 10) || (x > 100))
	{
		//cout << "speed out of range " << endl;
		return false;
	}

	response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

//“a” = left/right (-100-100)
//“b” = forward/backward (-100-100)
//“c” = up/down (-100-100)
//“d” = yaw (-100-100)
bool Tello::sendRCcontrol(int a, int b, int c, int d)
{
	if(!(check_range(a, -100, 100)) || !(check_range(b, -100, 100)) || !(check_range(c, -100, 100)) || !(check_range(d, -100, 100))){
		return false;
	}
	char buff[10];
	string _a = string(itoa(a, buff, 10));
	string _b = string(itoa(b, buff, 10));
	string _c = string(itoa(c, buff, 10));
	string _d = string(itoa(d, buff, 10));
	string command = "rc " + _a.append(" ") + _b.append(" ") + _c.append(" ") + _d;
	string response = sendCommand(command);

	if (!response.compare("ok"))
	{
		return true;
	}
	return false;
}

bool Tello::changeWifi(string ssid, string password)
{
	string command = "wifi "+ ssid + " " +password;
	string response = sendCommand(command);
	if(!response.compare("ok"))
	{
		return true;
	}
	return false;
}

int Tello::getSpeed()
{
	string command = "speed?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;

}

int Tello::getBattery()
{
	string command = "battery?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

int Tello::getTime()
{
	string command = "time?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

int Tello::getHeight()
{
	string command = "height?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

int Tello::getTemperature()
{
	string command = "temp?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

int Tello::getAltitude()
{
	string command = "attitude?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

int Tello::getBaro()
{
	string command = "baro?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

int Tello::getAcceleration()
{
	string command = "acceleration?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

int Tello::getTof()
{
	string command = "tof?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

int Tello::getWifiSnr()
{
	string command = "wifi?";
	string response = sendCommand(command);
	int x = atoi(response.c_str());
	return x;
}

bool Tello::check_range(int x, int min, int max)
{
	return (min < x && x < max);
}
