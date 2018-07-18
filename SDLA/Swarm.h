#pragma once
#include "Particle.h"

class Swarm {
private:
	Particle * m_particles;
public:
	static const int N_PARTICLES = 2000;
public:
	Swarm();
	const Particle * const getParticles();
	void update();
	~Swarm();
};

