// SDLA.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"

using namespace std;

int main(int argc, char *argv[]) {
	// seed random # generator
	srand(time(NULL));

	// Init screen
	Screen screen;
	if (!screen.init("Particle Fire Explosion")) {
		printf("FAILED");
		return 1;
	}

	screen.run();
	screen.cleanUp();

    return 0;
}

