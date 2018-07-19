#include "stdafx.h"
#include "Swarm.h"


Swarm::Swarm() {
	m_particles = new Particle[N_PARTICLES];
	time = 0;
}

const Particle * const Swarm::getParticles() {
	return m_particles;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - time;
	for (int i = 0; i < N_PARTICLES; i++) {
		m_particles[i].update(interval);
	}
	time = elapsed;
}

Swarm::~Swarm() {
	delete[] m_particles;
}
