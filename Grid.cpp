#include "Grid.h"

Grid::Grid(){
	
	// Initialize Grids
	for (int x = 0; x < rows - 1; x++) {
		for (int y = 0; y < cols - 1; y++) {
			this->currentGrid[x][y] = 0;
			this->previousGrid[x][y] = 0;
		}
	}
}

void Grid::Update() {
	for (int x = 0; x < rows-1; x++)
	{
		for (int y = 0; y < cols-1; y++)
		{
			if (previousGrid[x][y] != 0) {

				if (previousGrid[x][y + 1] == 0) {
					currentGrid[x][y] = 0;
					currentGrid[x][y + 1] = 1;
				}
				else if (previousGrid[x + 1][y + 1] == 0 && previousGrid[x - 1][y + 1] == 0) {
					bool choice = rand() % 2;

					currentGrid[x][y] = 0;
					if (choice == 0) {
						currentGrid[x + 1][y + 1] = 1;
					}
					else {
						currentGrid[x - 1][y + 1] = 1;
					}

				}

				else if (previousGrid[x - 1][y + 1] == 0) {
					currentGrid[x][y] = 0;
					currentGrid[x - 1][y + 1] = 1;
				}
				else if (previousGrid[x + 1][y + 1] == 0) {
					currentGrid[x][y] = 0;
					currentGrid[x + 1][y + 1] = 1;
				}
			}
			

		}
	}
}

void Grid::ResetGrid() {
	for (int x = 0; x < rows - 1; x++)
	{
		for (int y = 0; y < cols - 1; y++)
		{
			previousGrid[x][y] = 0;
			currentGrid[x][y] = 0;
		}
	}
}

void Grid::Instantiate(int x, int y, int value) {
	if (x > 0 && x < rows && y > 0 && y < cols)
		currentGrid[x][y] = value;
}

void Grid::Draw(sf::RenderWindow& window) {
	for (int x = 0; x < rows - 1; x++)
	{
		for (int y = 0; y < cols - 1; y++)
		{
			if (currentGrid[x][y] != 0) {

				sf::RectangleShape cell = sf::RectangleShape();
				cell.setSize(sf::Vector2f(cell_size, cell_size));
				cell.setPosition(x * cell_size, y * cell_size);
				cell.setFillColor(sf::Color::Yellow);

				window.draw(cell);
			}
			previousGrid[x][y] = currentGrid[x][y];
		}
	}
}



Grid::~Grid(){}

