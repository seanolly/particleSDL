#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

Particle::Particle() {
	//m_x = ((double) rand() / RAND_MAX);
	//m_y = ((double) rand() / RAND_MAX);
	m_x = 0.5;
	m_y = 0.5;
	m_direction = 2 * 3.14 * rand() / RAND_MAX;
	m_speed = (0.01 * rand()) / RAND_MAX;
	//x_speed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	//y_speed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
}

void Particle::update() {
	double x_speed = m_speed * cos(m_direction);
	double y_speed = m_speed * sin(m_direction);

	m_x += x_speed;
	m_y += y_speed;
}


Particle::~Particle() {
}
