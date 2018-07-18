#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>

Particle::Particle() {
	m_x = ((double) rand() / RAND_MAX);
	m_y = ((double) rand() / RAND_MAX);
}

void Particle::update() {
	//const double x_speed = 0.01 * ((2.0 * rand()) / RAND_MAX) - 1;
	//const double y_speed = 0.01 * ((2.0 * rand()) / RAND_MAX) - 1;

	//m_x += x_speed;
//	m_y += y_speed;
}


Particle::~Particle() {
}
