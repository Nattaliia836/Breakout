#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include "PlatformClass.h"
#include "BlockCharacteristics.h"

//using namespace sf;

class BallClass {
public:
	BallClass();
	void fillPositionPlatform(float position);
	void moveBall();
	CircleShape getBall();
	int getLivesCount();
	int getScoreCount();
	bool isBallMove();

	void fillVectorBlocks(std::vector<BlockStruct> Blocks);
	//Pair isBlockAlive();




	bool isTimeToUpdate();
	std::vector<BlockStruct> returnVectorData();

private:
	void hittingWall(std::string direction);
	void hittingBlocksRange();

	CircleShape ball;
	std::string directionX = "right";
	std::string directionY = "top";
	float platformPositionX = 0;
	bool isMoving = true;
	float plusSpeed = 0;
	int livesCount = 3;
	int score = 0;

	//int sizeBreakVector = 0;
	//std::vector<int> blockBreackId;

	std::vector<BlockStruct> blocksVector;

	bool timeToUpdate = 0;
};

#endif	//BALL_CLASS_H