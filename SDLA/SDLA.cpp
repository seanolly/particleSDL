// SDLA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SDL.h>

using namespace std;
int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL INIT FAILED" << endl;
	} else {
		cout << "GOOD TO GO." << SDL_GetError() << endl;
	}

    return 0;
}

