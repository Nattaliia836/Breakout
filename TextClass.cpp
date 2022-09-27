#include <iostream>
#include "TextClass.h"
#include "ConstVariable.h"
#include <SFML\Graphics.hpp>

using namespace sf;


TextClass::TextClass() {
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error!" << std::endl;
	}
	//sf::Clock clock;
	
	//textLevel.setString(fillText("Level: ", level));
	//textScore.setString(fillText("Score: ", score));
	//textTime.setString(fillText("Time: ", time));
	//textCountLives.setString("Lives: 3");

	fillBasic(textLevel, "Level: ", level, (MAX_WIGTH / 2) - 80, 0, 25);
	fillBasic(textScore, "Score: ", score, 0, 20, 18);
	time = timeInSeconds.asSeconds();
	fillBasic(textTime, "Time: ", time, (MAX_WIGTH - 100), 0, 18);
	fillBasic(textCountLives,"Lives: ", lives, 0, 0, 18);
	
}


void TextClass::fillBasic(Text& textObj, std::string text, int count, float positionX, float positionY, float size) {
	textObj.setFont(font);
	textObj.setCharacterSize(size);
	textObj.setString(text + std::to_string(count));
	textObj.setFillColor(sf::Color::White);
	textObj.setPosition(positionX, positionY);
	if (text == "Level: ") {
		textObj.setStyle(sf::Text::Bold);
	}
}

void TextClass::fillCounters(int newLives, int newScore, Time newTime) {
	time = newTime.asSeconds();
	textTime.setString("Time: " + std::to_string(time));
	
	lives = newLives;
	textCountLives.setString("Lives: " + std::to_string(lives));
	if (lives == 0) {
		textCountLives.setStyle(sf::Text::Bold);
		textCountLives.setFillColor(sf::Color::Red);
		fillEndText("YOU LOSE!", true);

	}

	score = newScore;
	textScore.setString("Score: " + std::to_string(newScore));

	if (score == MAX_SCORE_LEVEL_ONE) {
		fillEndText("YOU WIN!", false);
	}

}

void TextClass::fillEndText(std::string endText, bool isColorRed) {
	isEnd = true;
	textEnd.setFont(font);
	textEnd.setCharacterSize(50);
	textEnd.setString(endText);

	if (isColorRed) {
		textEnd.setFillColor(sf::Color::Red);
	}
	else {
		textEnd.setFillColor(sf::Color::Blue);
	}
	textEnd.setStyle(sf::Text::Bold);
	textEnd.setPosition((MAX_WIGTH / 2) - 120, (MAX_HEIGHT / 2) - 20);
}

Text TextClass::getTextLevel() {
	return textLevel;
}

Text TextClass::getTextScore() {
	return textScore;
}

Text TextClass::getTextTime() {
	return textTime;
}

Text TextClass::getTextCountLives() {
	return textCountLives;
}

Text TextClass::getTextEnd() {
	return textEnd;
}

bool TextClass::isGameEnd() {
	return isEnd;
}


