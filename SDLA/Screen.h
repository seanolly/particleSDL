#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <SDL.h>

using namespace std;
class Screen {
private:
	bool quit;
	SDL_Window *m_window;
	SDL_Texture *m_texture;
	SDL_Renderer *m_renderer;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
private:
	bool createWindow(const char* title);
	bool createRenderer();
	bool createTexture();
	bool initSDL();
	void clear();
	void render();
	void setBlurValue(int row, int col);
public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
public:
	Screen();
	bool init(const char *title);
	void setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void run();
	void boxBlur();
	void processEvents();
	void cleanUp(); // destroys SDL components
	~Screen();
};

