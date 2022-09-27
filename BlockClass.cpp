#include "BlockClass.h"
#include "ConstVariable.h"
#include <SFML/Graphics.hpp>
#include "BlockCharacteristics.h"

using namespace sf;

BlockClass::BlockClass() {

	levelOneFill();
}

/*
struct Block—haracteristic {
	int level = 1;		// 1, 2, 3
	float x;
	float y;
};
*/

void BlockClass::levelOneFill() {
	for (auto v : LEVEL_ONE) {
		BlockStruct pushBlock;
		pushBlock.block.setPosition(v.x, v.y);
		pushBlock.blockLevel = v.level;

		if (v.level == 1) {
			pushBlock.block.setFillColor(Color::Green);
		}
		else if (v.level == 2) {
			pushBlock.block.setFillColor(Color::Blue);
		}
		else if (v.level == 3) {
			pushBlock.block.setFillColor(Color::Yellow);
		}
		else {
			pushBlock.block.setFillColor(Color::Red);
			std::cout << "Error block level";
		}

		pushBlock.block.setSize(Vector2f(BLOCK_WIGTH, BLOCK_HEIGHT));

		Blocks.push_back(pushBlock);
	}
}

std::vector<BlockStruct> BlockClass::getVectorBlocks() {
	return Blocks;
}

void BlockClass::updateVectorData(std::vector<BlockStruct> blocks) {
	for (int i = 0; i < blocks.size(); i++) {
		if (blocks[i].isAlive != Blocks[i].isAlive) {
			Blocks[i].isAlive = blocks[i].isAlive;
			Blocks[i].block.setFillColor(Color::Black);
			break;
		}
	}
}