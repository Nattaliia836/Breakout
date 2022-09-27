#ifndef CONST_VARIABLE_H
#define CONST_VARIABLE_H

#include "BlockCharacteristics.h"

const int MAX_WIGTH = 1000;
const int MAX_HEIGHT = 600;

const float BALL_RADIUS = 10;
const float BALL_SPEED = 0.1;

const float PLATFORM_SPEED = 0.25;
const float PLATFORM_WIGTH = 200;
const float PLATFORM_HEIGHT = 20;
const float PLATFORM_LEVEL = 550;

const float BLOCK_WIGTH = 99;
const float BLOCK_HEIGHT = 20;
const float START_BLOCK_POSITION_X = 150;
const float START_BLOCK_POSITION_Y = 150;

const int MAX_SCORE_LEVEL_ONE = 26;

const std::vector<Block—haracteristic> LEVEL_ONE = {	// level, xPosition, yPosition
	{3, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 0), START_BLOCK_POSITION_Y},
	{1, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 1), START_BLOCK_POSITION_Y},
	{3, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 2), START_BLOCK_POSITION_Y},
	{1, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 3), START_BLOCK_POSITION_Y},
	{2, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 4), START_BLOCK_POSITION_Y},
	{1, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 5), START_BLOCK_POSITION_Y},
	{2, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 6), START_BLOCK_POSITION_Y},
	{1, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 0), START_BLOCK_POSITION_Y + (BLOCK_HEIGHT + 1)},
	{2, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 1), START_BLOCK_POSITION_Y + (BLOCK_HEIGHT + 1)},
	{1, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 2), START_BLOCK_POSITION_Y + (BLOCK_HEIGHT + 1)},
	{3, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 3), START_BLOCK_POSITION_Y + (BLOCK_HEIGHT + 1)},
	{1, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 4), START_BLOCK_POSITION_Y + (BLOCK_HEIGHT + 1)},
	{2, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 5), START_BLOCK_POSITION_Y + (BLOCK_HEIGHT + 1)},
	{3, START_BLOCK_POSITION_X + ((BLOCK_WIGTH + 1) * 6), START_BLOCK_POSITION_Y + (BLOCK_HEIGHT + 1)}
};



#endif	//CONST_VARIABLE_H
