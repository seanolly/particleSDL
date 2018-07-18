#include "stdafx.h"
#include "Swarm.h"


Swarm::Swarm() {
	m_particles = new Particle[N_PARTICLES];
}

const Particle * const Swarm::getParticles() {
	return m_particles;
}

void Swarm::update() {
	for (int i = 0; i < N_PARTICLES; i++) {
		m_particles[i].update();
	}
}

Swarm::~Swarm() {
	delete[] m_particles;
}
