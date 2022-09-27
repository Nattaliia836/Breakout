#include "BallClass.h"
#include "ConstVariable.h"
#include <SFML/Graphics.hpp>

using namespace sf;

BallClass::BallClass() {

	ball.setRadius(BALL_RADIUS);
	ball.setFillColor(Color(200, 200, 200));

	ball.setOutlineThickness(2.f);
	ball.setOutlineColor(Color(255, 255, 255, 150));
	ball.move(500, 300);

	directionX = "right";
	directionY = "top";

	//positionX = ball.getPosition().x;
	//positionY = ball.getPosition().y;
}

void BallClass::fillPositionPlatform(float position) {
	platformPositionX = position;
}

void BallClass::moveBall() {
	if(isMoving) {

		if (ball.getPosition().x > (START_BLOCK_POSITION_X - 2 * BALL_RADIUS) && 
			ball.getPosition().x < MAX_WIGTH - START_BLOCK_POSITION_X  &&
			ball.getPosition().y >(START_BLOCK_POSITION_Y - 2 * BALL_RADIUS) &&
			ball.getPosition().y < MAX_HEIGHT - (START_BLOCK_POSITION_Y + 5 * (BLOCK_HEIGHT + 1))
			) {
			hittingBlocksRange();

		}

		if (ball.getPosition().y > PLATFORM_LEVEL - BALL_RADIUS) {
			//std::cout << "Hello " << std::endl;
			if (ball.getPosition().x > platformPositionX && ball.getPosition().x < platformPositionX + PLATFORM_WIGTH) {
				directionY = "top";

				if (ball.getPosition().x < platformPositionX + (PLATFORM_WIGTH / 4)) {
					plusSpeed = 0.05;
					directionX = "left";
				}
				else if (ball.getPosition().x > (platformPositionX + ((PLATFORM_WIGTH / 4) * 3))){
					plusSpeed = 0.05;
					directionX = "right";
				}
			}
		}		

		if (ball.getPosition().x < (MAX_WIGTH - 2 * BALL_RADIUS) && ball.getPosition().x > 0) {
			if (directionX == "right") {
				ball.move((BALL_SPEED + plusSpeed), 0);	
			}
			else if (directionX == "left") {
				ball.move(-(BALL_SPEED + plusSpeed), 0);
			}
		}
		else {
			hittingWall(directionX);
		}


		if (ball.getPosition().y < (MAX_HEIGHT - 2 * BALL_RADIUS) && ball.getPosition().y > 0) {
			if (directionY == "bottom") {
				ball.move(0, BALL_SPEED);
			}
			else if (directionY == "top") {
				ball.move(0, -BALL_SPEED);
			}
		}
		else {
			hittingWall(directionY);
		}
	}
	else {
		ball.setPosition(platformPositionX + (PLATFORM_WIGTH / 2), PLATFORM_LEVEL - (BALL_RADIUS * 2));
		if (livesCount != 0) {
			if (sf::Keyboard::isKeyPressed(Keyboard::Up) || sf::Keyboard::isKeyPressed(Keyboard::Space)) {
				isMoving = true;
			}
		}
	}
}

void BallClass::hittingWall(std::string direction) {
	if (direction == "right") {
		ball.move(-(BALL_SPEED + plusSpeed), 0);
		directionX = "left";
	}
	else if (direction == "left") {
		ball.move((BALL_SPEED + plusSpeed), 0);
		directionX = "right";
	}
	else if (direction == "bottom") {
		isMoving = false;
		plusSpeed = 0;
		if (livesCount > 0) {
			livesCount--;
		}
	}
	//else if (direction == "bottom") {
	else if (direction == "top") {
		ball.move(0, BALL_SPEED);
		directionY = "bottom";
	}

}

void BallClass::hittingBlocksRange() {
	//for (auto blockStructObject : blocksVector) {
	for (int i = 0; i < blocksVector.size(); i++) {
		if (blocksVector[i].isAlive == 1) {

			if (ball.getPosition().x >= blocksVector[i].block.getPosition().x - (2 * BALL_RADIUS) &&
				ball.getPosition().x <= (blocksVector[i].block.getPosition().x + BLOCK_WIGTH + 1) &&
				ball.getPosition().y >= blocksVector[i].block.getPosition().y - (2 * BALL_RADIUS + 1) &&
				ball.getPosition().y < (blocksVector[i].block.getPosition().y + BLOCK_HEIGHT + 2)
				) {
				bool isBallHitting = false;
				if (directionX == "right" && directionY == "bottom") {
					if (ball.getPosition().y > (blocksVector[i].block.getPosition().y - (BALL_RADIUS * 2)) &&
						ball.getPosition().y <= (blocksVector[i].block.getPosition().y + BLOCK_HEIGHT - BALL_RADIUS)
						) {
						directionY = "top";
						isBallHitting = true;
					}
					else {
						directionX = "left";
						isBallHitting = true;
					}
				}
				else if (directionX == "right" && directionY == "top") {
					if (ball.getPosition().y >= (blocksVector[i].block.getPosition().y - BALL_RADIUS) &&
						ball.getPosition().y < (blocksVector[i].block.getPosition().y + BLOCK_HEIGHT)
						) {
						directionX = "left";
						isBallHitting = true;
					}
					else {
						directionY = "bottom";
						isBallHitting = true;
					}
				}
				else if (directionX == "left" && directionY == "top") {
					if (ball.getPosition().y >= blocksVector[i].block.getPosition().y - BALL_RADIUS &&
						ball.getPosition().y < (blocksVector[i].block.getPosition().y + BLOCK_HEIGHT)
						) {
						directionX = "right";
						isBallHitting = true;
					}
					else {
						directionY = "bottom";
						isBallHitting = true;
					}

				}
				else if (directionX == "left" && directionY == "bottom") {
					if (ball.getPosition().y > (blocksVector[i].block.getPosition().y - (BALL_RADIUS * 2)) &&
						ball.getPosition().y <= (blocksVector[i].block.getPosition().y + BLOCK_HEIGHT - BALL_RADIUS)
						) {
						directionX = "right";
						isBallHitting = true;
					}
					else {
						directionY = "top";
						isBallHitting = true;
					}
				}

				if (isBallHitting) {
					blocksVector[i].blockLevel -= 1;
					if (blocksVector[i].blockLevel == 0) {
						blocksVector[i].isAlive = false;
						timeToUpdate = true;
					}
					score++;
					if (score == MAX_SCORE_LEVEL_ONE) {
						isMoving = false;
					}
				}

				break;
			}
		}
	}
}

CircleShape BallClass::getBall() {
	return ball;
}

int BallClass::getLivesCount() {
	return livesCount;
}

int BallClass::getScoreCount() {
	return score;
}

bool BallClass::isBallMove() {
	return isMoving;
}

void BallClass::fillVectorBlocks(std::vector<BlockStruct> Blocks) {
	blocksVector = Blocks;
}


bool BallClass::isTimeToUpdate() {
	if (timeToUpdate) {
		timeToUpdate = false;
		return (!timeToUpdate);
	}
	return timeToUpdate;
}

std::vector<BlockStruct> BallClass::returnVectorData() {
	return blocksVector;
}




