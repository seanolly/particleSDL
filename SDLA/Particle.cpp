#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

Particle::Particle() {
	init();
}

void Particle::init() {
	m_x = 0.5;
	m_y = 0.5;
	m_direction = 2 * 3.14 * rand() / RAND_MAX;
	m_speed = (0.05 * rand()) / RAND_MAX;
	m_speed *= m_speed;
}

void Particle::update(int interval) {
	m_direction += interval * 0.00015;
	double x_speed = m_speed * cos(m_direction);
	double y_speed = m_speed * sin(m_direction);
	m_x += x_speed;
	m_y += y_speed;
	if (m_x < 0 || m_x > 1 || m_y < 0 || m_y > 1) {
		init();
	}
}


Particle::~Particle() {
}
