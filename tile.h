#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
class Tile {
public:
	/* ==== Constructors ==== */
	Tile();

	Tile(bool hasMine);

	/* ==== Get/Set methods ==== */

	void setisRevealed(bool isRevealed);

	void setHasMine(bool hasMine);

	void setIsFlagged(bool isFlagged);

	bool getisRevealed() const;

	bool getHasMine() const;

	bool getIsFlagged() const;

	void setXPos(unsigned int xPos);

	unsigned int getXPos() const;

	void setYPos(unsigned int yPos);

	unsigned int getYPos() const;

	vector<Tile*> getAdjacentTiles() const;

	/* ==== Other operations ==== */

	void AddAdjacentTile(Tile* tile);

	void PrintInfo() const;

	//Using the adjacent tiles vector, count the number of nearby mines
	unsigned int CountNearbyMines() const;

	//Reveals this tile and any other adjacent tile that is not a mine using recursion
	void RevealTiles();

private:
	vector<Tile*> adjacentTiles;
	bool isRevealed;
	bool hasMine;
	bool isFlagged;
	unsigned int xPos;
	unsigned int yPos;
};