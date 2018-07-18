#include "stdafx.h"
#include "Screen.h"
#include <math.h>
#include <SDL.h>
#include "Particle.h"
#include "Swarm.h"

Screen::Screen() {
	quit = false;
}

bool Screen::createWindow(const char *title) {
	this->m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	bool isValid = m_window != NULL;
	if (!isValid) {
		printf("Could not create window: %s\n", SDL_GetError());
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	} return isValid;
}

bool Screen::createRenderer() {
	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	clear();

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	bool isValid = m_renderer != NULL;
	if (!isValid) {
		printf("Could not create renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	} return isValid;
}

bool Screen::createTexture() {
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	bool isValid = m_texture != NULL;
	if (!isValid) {
		printf("Could not create texture: %s\n", SDL_GetError());
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	} return isValid;
}

bool Screen::initSDL() {
	bool isValid = !(SDL_Init(SDL_INIT_EVERYTHING) < 0);
	if (!isValid) {
		printf("SDL Init FAILED! : %s\n", SDL_GetError());
	} else {
		printf("SDL Init SUCCEEDED\n");
	} return isValid;
}

void Screen::clear() {
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::render() {
	// pass buffer to renderer
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	// clear renderer
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

bool Screen::init(const char *title) {
	return initSDL() && createWindow(title) && createRenderer() && createTexture();
}

void Screen::processEvents() {
	SDL_Event event;
	// fetch events
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) quit = true; break;
	}
}

void Screen::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		//cout << "OUT OF BOUNDS" << endl;
		//cout << x << endl << y << endl;
		//printf("PIXEL OUT OF BOUNDS: %s %s", x, y);
	} else {
		Uint32 color = 0;
		// add rgba val, shift by one byte
		color += r; color <<= 8;
		color += g; color <<= 8;
		color += b; color <<= 8;
		color += a;
		m_buffer[(y * SCREEN_WIDTH) + x] = color;
	}
}

void Screen:: run() {
	Swarm swarm;
	const Particle * const particles = swarm.getParticles();
	while (!quit) {
		clear();
		int elapsed = SDL_GetTicks();
		swarm.update();
		unsigned char r = (1 + sin(elapsed * 0.0012)) * 128;
		unsigned char g = (1 + sin(elapsed * 0.0021)) * 128;
		unsigned char b = (1 + sin(elapsed * 0.005)) * 128;
		for (int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle particle = particles[i];
			int x = particle.m_x * SCREEN_WIDTH;
			int y = particle.m_y * SCREEN_HEIGHT;
			setPixel(x, y, r, g, b, 0);
		}

		render();
		processEvents();
	}
}

void Screen::cleanUp() {
	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

Screen::~Screen() {}
