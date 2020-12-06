/*
 * Tello.h
 *
 *  Created on: Mar 26, 2019
 *      Author: akki
 */

#ifndef TELLO_H_
#define TELLO_H_

#include <string.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <string>

using namespace std;
class Tello
{
private :
	bool isInitialised ;
	WiFiUDP* udpclient;
	string sendCommand(string command);
	bool check_range(int x, int min, int max);

public:
	Tello();
	~Tello();
	
	void init();

	bool takeoff();
	bool land();
	bool startVideoStream();
	bool stopVideoStream();
	bool turnOff();
	bool up(int x);
	bool down(int x);
	bool left(int x);
	bool right(int x);
	bool forward(int x);
	bool back(int x);
	bool rotate_clockwise(int deg);
	bool rotate_anticlockwise(int deg);

	bool flip_front();
	bool flip_right();
	bool flip_left();
	bool flip_back();

	bool setSpeed(int x);
	bool sendRCcontrol(int a,int b,int c, int d);
	bool changeWifi(string ssid, string password);

	int getSpeed();
	int getBattery();
	int getTime();
	int getHeight();
	int getTemperature();
	int getAltitude();
	int getBaro();
	int getAcceleration();
	int getTof();
	int getWifiSnr();

};

#endif /* TELLO_H_ */
