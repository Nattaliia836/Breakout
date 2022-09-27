#ifndef PLATFORM_CLASS_H
#define PLATFORM_CLASS_H

#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;

class PlatformClass {
public:
	PlatformClass();
	void movePlatform();
	RectangleShape getPlatform();
	float getPositionX();
private:
	RectangleShape platform;
};

#endif	//PLATFORM_CLASS_H