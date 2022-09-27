#ifndef BLOCK_CHARACTERISTIC_H
#define BLOCK_CHARACTERISTIC_H

#include <SFML\Graphics.hpp>
//#include "ConstVariable.h"

using namespace sf;

struct Block—haracteristic {
	int level = 1;		// 1, 2, 3
	float x = 0;
	float y = 0;
};

struct BlockStruct {
	bool isAlive = true;
	RectangleShape block;
	int blockLevel;
};

struct Pair {
	bool isAliveBlock = 1;
	int numberBlock = 0;
};

#endif	//BLOCK_CHARACTERISTIC_H