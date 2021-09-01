#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Grid {
public:
	Grid();
	void Update();
	void ResetGrid();
	void Instantiate(int x, int y, int value);
	void Draw(sf::RenderWindow& window);
	~Grid();
private:
	int width = 1000, height = 800; 
	int cell_size = 4;
	
	static const int rows = 251;
	static const int cols = 201;
	int previousGrid[rows][cols];
	int currentGrid[rows][cols];
};