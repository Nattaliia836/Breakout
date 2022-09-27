#include <iostream>
#include <SFML/Graphics.hpp>
#include "BallClass.h"
#include "PlatformClass.h"
#include "ConstVariable.h"
#include "TextClass.h"
#include "BlockCharacteristics.h"
#include "BlockClass.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1000, 600), "Breakout");

	BallClass ball{};
	PlatformClass platform {};
	TextClass text{};
	BlockClass blocks{};

	sf::Clock clock;
	bool isTimeToStart = false;


	ball.fillVectorBlocks(blocks.getVectorBlocks());

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime().asSeconds() > 3.0 && !isTimeToStart) {
			isTimeToStart = true;
			Time timeInSeconds = clock.restart();
		}

		platform.movePlatform();

		if (isTimeToStart) {
			ball.fillPositionPlatform(platform.getPositionX());
			ball.moveBall();

			text.fillCounters(ball.getLivesCount(), ball.getScoreCount(), clock.getElapsedTime());

			if (ball.isTimeToUpdate()) {
				blocks.updateVectorData(ball.returnVectorData());
			}

		}
		
		window.clear();

		window.draw(ball.getBall());
		window.draw(platform.getPlatform()); 
		window.draw(text.getTextLevel());
		window.draw(text.getTextScore());
		window.draw(text.getTextTime());
		window.draw(text.getTextCountLives());
		
		if (text.isGameEnd()) {
			window.draw(text.getTextEnd());
		}

		for (auto v : blocks.getVectorBlocks()) {
			if (v.isAlive) {
				window.draw(v.block);
			}
		}

		window.display();
	}

	return 0;
}
