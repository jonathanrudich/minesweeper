#include <SFML/Graphics.hpp>
#include "board.h"
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper", sf::Style::Default);

	Board board;
	bool gameWon = false;
	bool gameLost = false;

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ( board.getplayGame() ) {

				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						//Check if player clicked somewhere in the board area or on one of the buttons
						sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
						cout << "Left mouse clicked, x coordinate = " << mousePosition.x << " , y coordinate = " << mousePosition.y << endl;

						if (mousePosition.y <= 512) {

							unsigned int tileNumber = board.GetTileNumber(mousePosition.x, mousePosition.y);
							cout << "Tile " << tileNumber << " has been left clicked!" << endl;

							if (!(board.getTiles().at(tileNumber).getIsFlagged())) {
								if (board.getTiles().at(tileNumber).getHasMine()) {
									board.setPlayGame(false);
									gameLost = true;
									board.ShowAllMines();
									cout << "Mine has been clicked, game over!" << endl;
								}
								else {
									board.RevealTiles(tileNumber);
								}
							}
						}

						//If player clicks reset button, reset game to default configuration
						if ((mousePosition.x > 384 && mousePosition.x < 448) && (mousePosition.y > 512 && mousePosition.y < 576)) {
							cout << "Reset button pressed!" << endl;
							board.ResetGame();
						}

						//If player clicks the debug button, reveal all tiles
						if ((mousePosition.x >= 512 && mousePosition.x < 576) && (mousePosition.y >= 512 && mousePosition.y <= 576)) {
							cout << "Debug button pressed!" << endl;
							board.ShowAllTiles();
						}

						//If player clicks on one of the test boards, load that test board
						if ((mousePosition.x > 576 && mousePosition.x < 640) && (mousePosition.y > 512 && mousePosition.y < 576)) {
							cout << "Test board 1 Pressed!" << endl;
							board.LoadBoard("boards/testboard1.brd");
						}
						if ((mousePosition.x > 640 && mousePosition.x < 704) && (mousePosition.y > 512 && mousePosition.y < 576)) {
							cout << "Test board 2 Pressed!" << endl;
							board.LoadBoard("boards/testboard2.brd");
						}
						if ((mousePosition.x > 704 && mousePosition.x < 768) && (mousePosition.y > 512 && mousePosition.y < 576)) {
							cout << "Test board 3 Pressed!" << endl;
							board.LoadBoard("boards/testboard3.brd");
						}

					}
				}


				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						//Check if player clicked on area within the tiles
						sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
						cout << "Right mouse clicked, x coordinate = " << mousePosition.x << " , y coordinate = " << mousePosition.y << endl;
						
						if (mousePosition.y <= 512) {
							unsigned int tileNumber = board.GetTileNumber(mousePosition.x, mousePosition.y);
							cout << "Tile " << tileNumber << " has been right clicked!" << endl;

							//Cannot flag a revealed tile
							if (!(board.getTiles().at(tileNumber).getisRevealed())) {

								//If tile is already flagged, unflag
								if (board.getTiles().at(tileNumber).getIsFlagged()) {
									board.FlagTile(tileNumber, false);
									cout << "Tile " << tileNumber << " has been unflagged!" << endl;
									board.setMinesDisplay((board.getMinesDisplay() + 1));

									if (board.getTiles().at(tileNumber).getHasMine()) {
										board.setMinesRemaining((board.getMinesRemaining() + 1));
									}
								}
								else {


									if (board.getTiles().at(tileNumber).getHasMine()) {
										board.FlagTile(tileNumber, true);
										board.setMinesRemaining((board.getMinesRemaining() - 1));
										board.setMinesDisplay((board.getMinesDisplay() - 1));
										cout << "Mine has been flagged, good job!" << endl;
										cout << "New mine count: " << board.getMinesRemaining() << endl;
									}

									else {
										board.FlagTile(tileNumber, true);
										board.setMinesDisplay((board.getMinesDisplay() - 1));
										cout << "Tile " << tileNumber << " has been flagged, no mine here." << endl;
									}

								}
							}
						}

					}
				}

				//Check winning conditions
				gameWon = board.CheckHasWon();
			}


			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			//Only possible mouse event is to reset game
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
					//If player clicks reset button, reset game to default configuration
					if ((mousePosition.x > 384 && mousePosition.x < 448) && (mousePosition.y > 512 && mousePosition.y < 576)) {
						cout << "Reset button pressed!" << endl;
						board.ResetGame();
						gameLost = false;
						gameWon = false;
					}
				}
			}


			//Display Cycle
			window.clear(sf::Color::White);
			board.DrawButtons(window);
			board.UpdateMineCount(window);
			board.UpdateTiles(window);
			board.DisplayGameState(window, gameWon, gameLost);
			window.display();
		}

	}

	return 0;
}