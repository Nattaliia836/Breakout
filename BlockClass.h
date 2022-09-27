#ifndef BLOCK_CLASS_H
#define BLOCK_CLASS_H

#include "BlockCharacteristics.h"
#include "PlatformClass.h"

//using namespace sf;

class BlockClass {
public:
	BlockClass();
	std::vector<BlockStruct> getVectorBlocks();
	//void getIdBreakBlock(int i);

	void updateVectorData(std::vector<BlockStruct> blocks);
	
	//void fillColor();
	//~BlockClass();
private:
	void levelOneFill();

	std::vector<BlockStruct> Blocks;
};

#endif	//BLOCK_CLASS_H