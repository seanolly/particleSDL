#pragma once
class Particle {
private:
	void init();
public:
	double m_x, m_y;
	double m_speed, m_direction;
public:
	Particle();
	void update(int elapsed);
	~Particle();
};

