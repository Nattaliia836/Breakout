#ifndef TEXT_CLASS_H
#define TEXT_CLASS_H

#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;

class TextClass {
public:
	TextClass();
	void fillCounters(int newLives, int newScore, Time newTime);
	Text getTextLevel();
	Text getTextScore();
	Text getTextTime();
	Text getTextCountLives();
	Text getTextEnd();
	bool isGameEnd();

private:
	void fillBasic(Text& textObj, std::string text, int count, float positionX, float positionY, float size);
	void fillEndText(std::string endText, bool isColorRed);

	Font font;
	Text textLevel;
	Text textScore;
	Text textTime;
	Text textCountLives;
	Text textEnd;
	int level = 1;
	int score = 0;
	int lives = 3;
	int time = 0;
	Time timeInSeconds = seconds(0.1f);
	bool isEnd = false;
};

#endif	//TEXT_CLASS_H