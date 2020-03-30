#pragma once
#include "tile.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Board {
public:
	/* ==== Constructors/Destructor ==== */

	Board();

	/* ==== Get/Set Methods ==== */

	vector<Tile> getTiles() const;

	map<string, sf::Texture> getTextures() const;

	bool getplayGame() const;

	void setPlayGame(bool playGame);

	void setMinesRemaining(int minesRemaining);

	int getMinesRemaining() const;

	void setMinesDisplay(int minesDisplay);

	int getMinesDisplay() const;

	bool getShowingAllTiles() const;

	/* ==== Initialization methods ==== */

	void LoadTextures();

	void SetAdjacentTiles();

	void GenerateMines();

	void SetTilePositions();

	/* ==== Draw to screen methods ==== */

	//Draws test buttons to screen
	void DrawButtons(sf::RenderWindow& window);

	//Display current game state: won, lost, or still playing. Update smiley face accordingly
	void DisplayGameState(sf::RenderWindow& window, bool gameWon, bool gameLost) const;

	//Updates the digit display to represent the current value of minesDisplay
	void UpdateMineCount(sf::RenderWindow& window);

	//Checks the state of each tile, assigns it the proper texture based on its state, then prints it to the screen
	void UpdateTiles(sf::RenderWindow& window);

	/* ==== Other Operations ==== */

	//Resets current game, loads a test board given its name as a string, uses data to generate mines
	void LoadBoard(string filename);

	//Flags a tile on the board given its number in the tiles vector
	void FlagTile(unsigned int tileNumber, bool isFlagged);

	//Reveals appropriate tiles and displays number of mines nearby on revealed tiles
	void RevealTiles(unsigned int tileNumber);

	//Given a set of mouse coordinates, return which tile these coordinates correspond to
	unsigned int GetTileNumber(int x, int y) const;

	//Sets all tiles on board to revelaed 
	void ShowAllTiles();

	//Sets all the mines on board to revealed 
	void ShowAllMines();

	//Clears game, regenerates mines
	void ResetGame();

	//Resets all conditions of the game to default
	void ClearGame();

	//Checks winning conditions
	bool CheckHasWon();

private:
	vector<Tile> tiles;
	int minesRemaining;
	int minesDisplay;
	int initialMinesCount;
	map<string, sf::Texture> textures;
	bool playGame;
	bool showingAllTiles;
};