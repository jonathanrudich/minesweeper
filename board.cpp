#include "board.h"
#include <iostream>
#include <fstream>
using namespace std;

Board::Board()
{
	playGame = true;
	LoadTextures();

	for (unsigned int i = 0; i < 400; i++) {
		Tile tile;
		tiles.push_back(tile);
	}

	SetTilePositions();
	SetAdjacentTiles();
	GenerateMines();
	
}

vector<Tile> Board::getTiles() const
{
	return tiles;
}

map<string, sf::Texture> Board::getTextures() const
{
	return textures;
}

bool Board::getplayGame() const
{
	return playGame;
}

void Board::setPlayGame(bool playGame)
{
	this->playGame = playGame;
}

void Board::setMinesRemaining(int minesRemaining)
{
	this->minesRemaining = minesRemaining;
}

int Board::getMinesRemaining() const
{
	return minesRemaining;
}

void Board::setMinesDisplay(int minesDisplay)
{
	this->minesDisplay = minesDisplay;
}

int Board::getMinesDisplay() const
{
	return minesDisplay;
}

bool Board::getShowingAllTiles() const
{
	return showingAllTiles;
}

void Board::LoadTextures()
{
	sf::Texture debug;
	if (!debug.loadFromFile("images/debug.png"))
	{
		throw runtime_error("Error, debug could not be loaded.");
	}
	textures.emplace("debug", debug);

	//break digits texture up into individual digits
	sf::Texture digit0;
	if (!(digit0.loadFromFile("images/digits.png", sf::IntRect(0, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit0", digit0);

	sf::Texture digit1;
	if (!(digit1.loadFromFile("images/digits.png", sf::IntRect(21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit1", digit1);

	sf::Texture digit2;
	if (!(digit2.loadFromFile("images/digits.png", sf::IntRect(2*21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit2", digit2);

	sf::Texture digit3;
	if (!(digit3.loadFromFile("images/digits.png", sf::IntRect(3*21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit3", digit3);

	sf::Texture digit4;
	if (!(digit4.loadFromFile("images/digits.png", sf::IntRect(4*21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit4", digit4);

	sf::Texture digit5;
	if (!(digit5.loadFromFile("images/digits.png", sf::IntRect(5*21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit5", digit5);

	sf::Texture digit6;
	if (!(digit6.loadFromFile("images/digits.png", sf::IntRect(6 * 21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit6", digit6);

	sf::Texture digit7;
	if (!(digit7.loadFromFile("images/digits.png", sf::IntRect(7 * 21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit7", digit7);

	sf::Texture digit8;
	if (!(digit8.loadFromFile("images/digits.png", sf::IntRect(8 * 21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit8", digit8);

	sf::Texture digit9;
	if (!(digit9.loadFromFile("images/digits.png", sf::IntRect(9 * 21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("digit9", digit9);

	sf::Texture minusSign;
	if (!(minusSign.loadFromFile("images/digits.png", sf::IntRect(10 * 21, 0, 21, 32))))
	{
		throw runtime_error("Error, digits could not be loaded.");
	}
	textures.emplace("minusSign", minusSign);

	sf::Texture face_happy;
	if (!face_happy.loadFromFile("images/face_happy.png"))
	{
		throw runtime_error("Error, face_happy could not be loaded.");
	}
	textures.emplace("face_happy", face_happy);

	sf::Texture face_lose;
	if (!face_lose.loadFromFile("images/face_lose.png"))
	{
		throw runtime_error("Error, face_lose could not be loaded.");
	}
	textures.emplace("face_lose", face_lose);

	sf::Texture face_win;
	if (!face_win.loadFromFile("images/face_win.png"))
	{
		throw runtime_error("Error, face_win could not be loaded.");
	}
	textures.emplace("face_win", face_win);

	sf::Texture flag;
	if (!flag.loadFromFile("images/flag.png"))
	{
		throw runtime_error("Error, flag could not be loaded.");
	}
	textures.emplace("flag", flag);

	sf::Texture mine;
	if (!mine.loadFromFile("images/mine.png"))
	{
		throw runtime_error("Error, mine could not be loaded.");
	}
	textures.emplace("mine", mine);

	sf::Texture number_1;
	if (!number_1.loadFromFile("images/number_1.png"))
	{
		throw runtime_error("Error, number_1 could not be loaded.");
	}
	textures.emplace("number_1", number_1);

	sf::Texture number_2;
	if (!number_2.loadFromFile("images/number_2.png"))
	{
		throw runtime_error("Error, number_2 could not be loaded.");
	}
	textures.emplace("number_2", number_2);

	sf::Texture number_3;
	if (!number_3.loadFromFile("images/number_3.png"))
	{
		throw runtime_error("Error, number_3 could not be loaded.");
	}
	textures.emplace("number_3", number_3);

	sf::Texture number_4;
	if (!number_4.loadFromFile("images/number_4.png"))
	{
		throw runtime_error("Error, number_4 could not be loaded.");
	}
	textures.emplace("number_4", number_4);

	sf::Texture number_5;
	if (!number_5.loadFromFile("images/number_5.png"))
	{
		throw runtime_error("Error, number_5 could not be loaded.");
	}
	textures.emplace("number_5", number_5);

	sf::Texture number_6;
	if (!number_6.loadFromFile("images/number_6.png"))
	{
		throw runtime_error("Error, number_6 could not be loaded.");
	}
	textures.emplace("number_6", number_6);

	sf::Texture number_7;
	if (!number_7.loadFromFile("images/number_7.png"))
	{
		throw runtime_error("Error, number_7 could not be loaded.");
	}
	textures.emplace("number_7", number_7);

	sf::Texture number_8;
	if (!number_8.loadFromFile("images/number_8.png"))
	{
		throw runtime_error("Error, number_8 could not be loaded.");
	}
	textures.emplace("number_8", number_8);

	sf::Texture test_1;
	if (!test_1.loadFromFile("images/test_1.png"))
	{
		throw runtime_error("Error, test_1 could not be loaded.");
	}
	textures.emplace("test_1", test_1);

	sf::Texture test_2;
	if (!test_2.loadFromFile("images/test_2.png"))
	{
		throw runtime_error("Error, test_2 could not be loaded.");
	}
	textures.emplace("test_2", test_2);

	sf::Texture test_3;
	if (!test_3.loadFromFile("images/test_3.png"))
	{
		throw runtime_error("Error, test_3 could not be loaded.");
	}
	textures.emplace("test_3", test_3);

	sf::Texture tile_hidden;
	if (!tile_hidden.loadFromFile("images/tile_hidden.png"))
	{
		throw runtime_error("Error, tile_hidden could not be loaded.");
	}
	textures.emplace("tile_hidden", tile_hidden);

	sf::Texture tile_revealed;
	if (!tile_revealed.loadFromFile("images/tile_revealed.png"))
	{
		throw runtime_error("Error, tile_revealed could not be loaded.");
	}
	textures.emplace("tile_revealed", tile_revealed);

}


void Board::SetAdjacentTiles()
{
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if (i == 0) {
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(&tiles.at(1));
			tiles.at(i).AddAdjacentTile(&tiles.at(26));
			tiles.at(i).AddAdjacentTile(&tiles.at(25));
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
		}
		else if (i > 0 && i < 24) {
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(&tiles.at(i+1));
			tiles.at(i).AddAdjacentTile(&tiles.at(i+26));
			tiles.at(i).AddAdjacentTile(&tiles.at(i+25));
			tiles.at(i).AddAdjacentTile(&tiles.at(i+24));
			tiles.at(i).AddAdjacentTile(&tiles.at(i-1));

		}
		else if (i == 24) {
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(&tiles.at(49));
			tiles.at(i).AddAdjacentTile(&tiles.at(48));
			tiles.at(i).AddAdjacentTile(&tiles.at(23));

		}
		else if ((i > 0 && i < 375) && (i % 25 == 0)) {
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 25));
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 24));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 1));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 26));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 25));
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
		}
		else if ((i > 24 && i < 399) && ((i - 24) % 25 == 0)) {
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 26));
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 25));
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 25));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 24));
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 1));
		}
		else if (i == 375) {
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(&tiles.at(350));
			tiles.at(i).AddAdjacentTile(&tiles.at(351));
			tiles.at(i).AddAdjacentTile(&tiles.at(376));
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
		}
		else if (i > 375 && i < 399) {
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 26));
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 25));
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 24));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 1));
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 1));
		}
		else if (i == 399) {
			tiles.at(i).AddAdjacentTile(&tiles.at(373));
			tiles.at(i).AddAdjacentTile(&tiles.at(374));
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(nullptr);
			tiles.at(i).AddAdjacentTile(&tiles.at(398));
		}
		else {
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 26));
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 25));
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 24));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 1));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 26));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 25));
			tiles.at(i).AddAdjacentTile(&tiles.at(i + 24));
			tiles.at(i).AddAdjacentTile(&tiles.at(i - 1));
		}
	}
}

void Board::GenerateMines()
{
	//Determine if tile will have mine by generating a random number between 0 and 400 for the mine index
	//Perform this operation 50 times, as map must have 50 mines
	int mineCount = 0;
	while (mineCount < 50) {
		int mineIndex = rand() % 400;
		if (!(tiles.at(mineIndex).getHasMine())) {
			tiles.at(mineIndex).setHasMine(true);
			mineCount++;
		}
	}
	this->minesRemaining = mineCount;
	this->minesDisplay = mineCount;
	this->initialMinesCount = mineCount;
}

void Board::SetTilePositions()
{
	for (unsigned int i = 0; i < 16; i++) {
		for (unsigned int j = 0; j < 25; j++) {
			tiles.at((i * 25) + j).setXPos(j * 32);
			tiles.at((i * 25) + j).setYPos(i * 32);
		}
	}
}

void Board::DrawButtons(sf::RenderWindow& window)
{
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(textures.at("debug"));
	buttonSprite.setPosition(512, 512);
	window.draw(buttonSprite);

	buttonSprite.setTexture(textures.at("test_1"));
	buttonSprite.setPosition(576, 512);
	window.draw(buttonSprite);

	buttonSprite.setTexture(textures.at("test_2"));
	buttonSprite.setPosition(640, 512);
	window.draw(buttonSprite);

	buttonSprite.setTexture(textures.at("test_3"));
	buttonSprite.setPosition(704, 512);
	window.draw(buttonSprite);
}

void Board::LoadBoard(string filename)
{

	ClearGame();	
	
	ifstream file(filename);
	string line;
	vector<char> hasMine;

	if (file.is_open()) {
		while(getline(file,line)) {
			for (unsigned int i = 0; i < 25; i++) {
				char value = line.at(i);
				hasMine.push_back(value);
			}
		}

		file.close();
	}

	//Set mines based on read in values
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if (hasMine.at(i) == '1') {
			tiles.at(i).setHasMine(true);
			minesDisplay++;
			minesRemaining++;
			initialMinesCount++;
		}
	}

}

void Board::FlagTile(unsigned int tileNumber, bool isFlagged)
{
	tiles.at(tileNumber).setIsFlagged(isFlagged);
}

void Board::RevealTiles(unsigned int tileNumber)
{
	tiles.at(tileNumber).RevealTiles();
}

unsigned int Board::GetTileNumber(int x, int y) const
{
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if ((x >= tiles.at(i).getXPos() && x < (tiles.at(i).getXPos() + 32)) && (y >= tiles.at(i).getYPos() && y < (tiles.at(i).getYPos() + 32))) {
			if (i < 400) {
				return i;
			}
		}
	}
}

void Board::ShowAllTiles()
{
	showingAllTiles = !showingAllTiles;
	for (unsigned int i = 0; i < tiles.size(); i++) {
		tiles.at(i).setisRevealed(showingAllTiles);
	}
}

void Board::ShowAllMines()
{
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if (tiles.at(i).getHasMine()) {
			tiles.at(i).setisRevealed(true);
		}
	}
}

void Board::ResetGame()
{
	ClearGame();
	GenerateMines();
}

void Board::ClearGame()
{
	//Clear board of mines, set all tiles to hidden, get rid of flags
	for (unsigned int i = 0; i < tiles.size(); i++) {
		tiles.at(i).setHasMine(false);
		tiles.at(i).setIsFlagged(false);
		tiles.at(i).setisRevealed(false);
	}

	this->minesRemaining = 0;
	this->minesDisplay = 0;
	this->initialMinesCount = 0;
	this->playGame = true;

}

bool Board::CheckHasWon()
{
	//Winning condition 1:All mines have been flagged
	if ((minesRemaining == 0) && (minesDisplay == 0)) {
		playGame = false;
		return true;
	}
	
	//Winning condition 2: All tiles that do not have mines are revealed
	unsigned int revealedTiles = 0;
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if (!(tiles.at(i).getHasMine()) && (tiles.at(i).getisRevealed())) {
			revealedTiles++;
		}
	}

	//If this is the winning condition, set all the mines to flagged
	if (revealedTiles == (400 - initialMinesCount) && !showingAllTiles) {
		for (unsigned int i = 0; i < tiles.size(); i++) {
			if (tiles.at(i).getHasMine()) {
				tiles.at(i).setIsFlagged(true);
			}
		}

		//Set display count to 0 because game has been won
		minesDisplay = 0;
		playGame = false;
		return true;
	}

	return false;
}

void Board::UpdateMineCount(sf::RenderWindow& window)
{
	sf::Sprite digitSprite;

	//First check if is negative or positive
	if (minesDisplay >= 0) {
		digitSprite.setTexture(textures.at("digit0"));
		digitSprite.setPosition(100, 512);
		window.draw(digitSprite);
	}
	else {
		digitSprite.setTexture(textures.at("minusSign"));
		digitSprite.setPosition(100, 512);
		window.draw(digitSprite);
	}

	//Check if minesDisplay is 10 or greater
	if (abs(minesDisplay) >= 10) {

		string digit = "digit";

		char tens = to_string(abs(minesDisplay)).at(0);
		string tensDigit = digit + tens;
		digitSprite.setTexture(textures.at(tensDigit));
		digitSprite.setPosition(121, 512);
		window.draw(digitSprite);

		char ones = to_string(abs(minesDisplay)).at(1);
		string onesDigit = digit + ones;
		digitSprite.setTexture(textures.at(onesDigit));
		digitSprite.setPosition(142, 512);
		window.draw(digitSprite);
	}

	else {
		digitSprite.setTexture(textures.at("digit0"));
		digitSprite.setPosition(121, 512);
		window.draw(digitSprite);

		string ones = to_string(abs(minesDisplay));
		digitSprite.setTexture(textures.at("digit" + ones));
		digitSprite.setPosition(142, 512);
		window.draw(digitSprite);
	}

}

void Board::UpdateTiles(sf::RenderWindow& window)
{
	//Iterate through all tiles in board

	//Performing seperate iterations through the tiles vectpr for each type of tile texture
	//is likely faster than assigning a new texture for each tile

	sf::Sprite tileSprite;

	//If tile is hidden, display hidden texture
	tileSprite.setTexture(textures.at("tile_hidden"));
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if (!tiles.at(i).getisRevealed()) {
			tileSprite.setPosition(tiles.at(i).getXPos(), tiles.at(i).getYPos());
			window.draw(tileSprite);
		}
	}

	//If tile is flagged, display flagged texture
	tileSprite.setTexture(textures.at("flag"));
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if (tiles.at(i).getIsFlagged()) {
			tileSprite.setPosition(tiles.at(i).getXPos(), tiles.at(i).getYPos());
			window.draw(tileSprite);
		}
	}
	
	//Display all tiles that are revealed but do not have any nearby mines
	tileSprite.setTexture(textures.at("tile_revealed"));
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if ( (tiles.at(i).getisRevealed()) && (tiles.at(i).CountNearbyMines() == 0) && !(tiles.at(i).getHasMine()) ) {
			tileSprite.setPosition(tiles.at(i).getXPos(), tiles.at(i).getYPos());
			window.draw(tileSprite);
		}
	}

	//Iterate through all tiles that have nearby mines. This will involve some texture switching
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if ((tiles.at(i).getisRevealed()) && (tiles.at(i).CountNearbyMines() > 0) && !(tiles.at(i).getHasMine())) {
			int nearbyMines = tiles.at(i).CountNearbyMines();
			tileSprite.setTexture(textures.at("number_" + to_string(nearbyMines)));
			tileSprite.setPosition(tiles.at(i).getXPos(), tiles.at(i).getYPos());
			window.draw(tileSprite);
		}
	}

	//Finally, show all mines if the game is over
		tileSprite.setTexture(textures.at("mine"));
		for (unsigned int i = 0; i < tiles.size(); i++) {
			if ((tiles.at(i).getisRevealed()) && (tiles.at(i).getHasMine())) {
				tileSprite.setPosition(tiles.at(i).getXPos(), tiles.at(i).getYPos());
				window.draw(tileSprite);
			}
		}
}
	

void Board::DisplayGameState(sf::RenderWindow& window, bool gameWon, bool gameLost) const
{
	sf::Sprite buttonSprite;
	if (gameWon) {
		buttonSprite.setTexture(textures.at("face_win"));
	}
	else if (gameLost) {
		buttonSprite.setTexture(textures.at("face_lose"));
	}
	else {
		buttonSprite.setTexture(textures.at("face_happy"));
	}
	buttonSprite.setPosition(384, 512);
	window.draw(buttonSprite);
}

