#pragma once
#include "Particle.h"

class Swarm {
private:
	Particle * m_particles;
	int time;
public:
	static const int N_PARTICLES = 4000;
public:
	Swarm();
	const Particle * const getParticles();
	void update(int elapsed);
	~Swarm();
};

