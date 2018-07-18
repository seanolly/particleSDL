// SDLA.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <SDL.h>

using namespace std;
int main(int argc, char *argv[])
{
	const char* TITLE = "Particle Fire Explosion";
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) printf("SDL Init FAILED: %s\n", SDL_GetError());
	else printf("SDL Init Succeeded.");
	
	// create a window with the specified position, dimensions, and flags.
	SDL_Window *window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	} else { // enter particle loop
		SDL_Event event;
		bool quit = false;
		while (!quit) {

			// fetch events
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) quit = true;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
    return 0;
}

