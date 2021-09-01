#include <iostream>
#include <cmath>
#include <SFML\Graphics.hpp>
#include "Grid.h"

#define WIDTH 1000
#define HEIGHT 800
#define CELL_SIZE 4

using namespace std;

int GetDistance(int x1, int y1, int x2, int y2);

int main() {
	
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "FallingSand Cellular Automata", sf::Style::Close);

	window.setFramerateLimit(60);
	int rows = WIDTH / CELL_SIZE, 
		cols = HEIGHT / CELL_SIZE;

	Grid grid = Grid();
	int instatiate_radius = 70;

	const float updateRate = 0.01f;
	float countDownMS = updateRate;
	float toggleCounterMS = 0.0f;
	float toggleThresholdMS = 0.125f;

	sf::Clock clock;

	bool isPaused = false;

	while (window.isOpen()) {
		window.clear();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				
				int _x = floor(pos.x / CELL_SIZE);
				int _y = floor(pos.y / CELL_SIZE);

				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < cols; j++)
					{
						int x = i * CELL_SIZE, 
							y = j * CELL_SIZE;

						int dist = GetDistance(pos.x, pos.y, x, y);
						if (dist <= instatiate_radius) {
							grid.Instantiate(i, j, 1);

						}
					}
				}

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (toggleCounterMS > toggleThresholdMS) {
					isPaused = !isPaused;
					toggleCounterMS = 0.0f;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				grid.ResetGrid();
			}
		}

		float sec = clock.restart().asSeconds();
		countDownMS -= sec;
		toggleCounterMS += sec;

		if (countDownMS < 0.0f) {
			if (!isPaused) {
				grid.Update();
				countDownMS = updateRate;
			}
		}

		grid.Draw(window);
		window.display();
	}
	return 0;
}

int GetDistance(int x1, int y1, int x2, int y2) {
	return int (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

