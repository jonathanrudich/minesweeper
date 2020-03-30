#include "tile.h"
#include <iostream>
using namespace std;

Tile::Tile()
{
	this->hasMine = false;
	this->isRevealed = false;
	this->isFlagged = false;
}

Tile::Tile(bool hasMine)
{

	this->hasMine = hasMine;
	this->isRevealed = false;
	this->isFlagged = false;
}

void Tile::setisRevealed(bool isRevealed)
{
	this->isRevealed = isRevealed;
}

void Tile::setHasMine(bool hasMine)
{
	this->hasMine = hasMine;
}

void Tile::setIsFlagged(bool isFlagged)
{
	this->isFlagged = isFlagged;
}

bool Tile::getisRevealed() const
{
	return isRevealed;
}

bool Tile::getHasMine() const
{
	return hasMine;
}

bool Tile::getIsFlagged() const
{
	return isFlagged;
}

void Tile::setXPos(unsigned int xPos)
{
	this->xPos = xPos;
}

unsigned int Tile::getXPos() const
{
	return xPos;
}

void Tile::setYPos(unsigned int yPos)
{
	this->yPos = yPos;
}

unsigned int Tile::getYPos() const
{
	return yPos;
}

vector<Tile*> Tile::getAdjacentTiles() const
{
	return adjacentTiles;
}

void Tile::AddAdjacentTile(Tile* tile)
{
	adjacentTiles.push_back(tile);
}

void Tile::PrintInfo() const
{
	cout << "Is clicked: " << isRevealed << endl;
	cout << "Has mine: " << hasMine << endl;
	cout << "Is flagged: " << isFlagged << endl;
}

unsigned int Tile::CountNearbyMines() const
{
	unsigned int nearbyMineCount = 0;
	for (unsigned int i = 0; i < adjacentTiles.size(); i++) {
		if (adjacentTiles.at(i) != nullptr) {
			if (adjacentTiles.at(i)->getHasMine()) {
				nearbyMineCount++;
			}
		}
	}
	return nearbyMineCount;
}

void Tile::RevealTiles()
{
	this->isRevealed = true;

	for (unsigned int i = 0; i < adjacentTiles.size(); i++) {
			
		if (adjacentTiles.at(i) != nullptr) {
				
				if ( !(adjacentTiles.at(i)->getHasMine()) && !(adjacentTiles.at(i)->getisRevealed()) && !(adjacentTiles.at(i)->getIsFlagged())) {
					adjacentTiles.at(i)->setisRevealed(true);
					
					if (adjacentTiles.at(i)->CountNearbyMines() == 0) {
						adjacentTiles.at(i)->RevealTiles();
					}
				}
		}
	}
}
