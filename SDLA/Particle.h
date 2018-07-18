#pragma once
class Particle {
public:
	double m_x, m_y;
	double m_speed, m_direction;
public:
	Particle();
	void update();
	~Particle();
};

