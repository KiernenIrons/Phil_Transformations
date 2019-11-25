#pragma once
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Vector3
{
public:

	// Constructor 1
	Vector3();

	// Constructor 2
	Vector3(double x1, double y1, double z1);

	// Constructor 3
	Vector3(Vector3& V);

	double Length();
	double LengthSquared();
	Vector3 Normalise();

	Vector3 operator+(const Vector3 t_right);

	Vector3 operator-(Vector3 V1);

	double operator*(Vector3 V1);



private:

	double m_x;
	double m_y;
	double m_z;
};