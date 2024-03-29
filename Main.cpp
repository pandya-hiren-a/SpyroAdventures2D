/*
File: Main.cpp
Author: Alexander Richard
Modified By: Hiren Pandya (101198481)
Modified On: 08/12/2018
*/
#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "Includes.h"
#include "SDL_image.h"
using namespace std;

int main(int argc, char* args[])
{
	Game game; // Object of the Game Class
	// Start initialization
	game.init("Milestone 3 - Game Beta", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	// SDL Surface pointer for Tiles image
	SDL_Surface* tileSurf = IMG_Load("Tiles.png");
	// Create SDL texture from above SDL surface
	SDL_Texture* tileText = SDL_CreateTextureFromSurface(game.getRenderer(), tileSurf);
	// SDL Surface pointer for player image
	SDL_Surface* playerSurf = IMG_Load("Player.png");
	// Create SDL texture from above SDL Surface
	SDL_Texture* playerText = SDL_CreateTextureFromSurface(game.getRenderer(), playerSurf);
	// Create array of levels objects. Since BuildMap is being handled in Level constructor, changes will be applied to that constructor
	// which was supposed to be for BuildMap function
	Level levels[5] = { 
		Level("Level1.txt", game.getRenderer(), tileText), 
		Level("Level2.txt", game.getRenderer(), tileText),
		Level("Level3.txt", game.getRenderer(), tileText),
		Level("Level4.txt", game.getRenderer(), tileText),
		Level("Level5.txt", game.getRenderer(), tileText)};

	int currLevel = 0; // to keep track of the current level
	Player player(1024 / 2, 768 / 2, game.getRenderer(), playerText); // Creating the Player object.
	// continue the loop while game's m_bRunning property is set
	while (game.running()) {
		game.handleEvents();
		if (game.tick()) { // For every tick, we shall update the coordinates and render the changes
			game.update(levels[currLevel], player, currLevel);
			game.render(levels[currLevel], player);
		}
	}
	// Clean the game
	game.clean();
	system("pause");
	return 0;
}