#include "PlatformClass.h"
#include "ConstVariable.h"
#include <SFML/Graphics.hpp>

using namespace sf;

PlatformClass::PlatformClass() {
	RectangleShape rectangle(Vector2f(200.f, 20.f));
	platform = rectangle;
	platform.move(((MAX_WIGTH - PLATFORM_WIGTH) / 2), PLATFORM_LEVEL);
	platform.setFillColor(Color::White);
}

void PlatformClass::movePlatform() {
	if (sf::Keyboard::isKeyPressed(Keyboard::A) || sf::Keyboard::isKeyPressed(Keyboard::Left)) {
		if (platform.getPosition().x > 0) {
			platform.move(-PLATFORM_SPEED, 0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(Keyboard::D) || sf::Keyboard::isKeyPressed(Keyboard::Right)) {
		if (platform.getPosition().x < (MAX_WIGTH - PLATFORM_WIGTH)) {
			platform.move(PLATFORM_SPEED, 0);
		}
	}
}

RectangleShape PlatformClass::getPlatform() {
	return platform;
}

float PlatformClass::getPositionX() {
	return platform.getPosition().x;
}
