#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <math.h>
#include <string>

class Vector2
{
public:
	// default constructor
	Vector2() :
		m_x(0.0)
		, m_y(0.0)
	{

	}

	// To allow other values for X and Y to be declared
	Vector2(float x1, float y1) :
		m_x(x1)
		, m_y(y1)
	{
	}

	// To allow other values for X and Y to be declared
	Vector2(Vector2& t_v) :
		m_x(t_v.m_x)
		, m_y(t_v.m_y)
	{
	}


private:
	// The class has three variables x and y 
	float m_x;
	float m_y;

public:

	float getX() const { return m_x; };
	void setX(float t_x) { m_x = t_x; };

	float getY() const { return m_y; };
	void setY(float t_y) { m_y = t_y; };

	/// <summary>
	/// A method to return the length of the vector 
	/// </summary>
	/// <returns>Length of vector</returns>
	inline float length() const
	{
		return sqrt(lengthSquared());
	}

	/// <summary>
	/// A method to return the length squared of the vector
	/// </summary>
	/// <returns>Squared length of vector</returns>
	inline float lengthSquared() const
	{
		return (m_x * m_x + m_y * m_y);
	}

	/// <summary>
	/// A method to reduce the length of the vector to 1.0 
	/// keeping the direction the same 
	/// </summary>
	/// <returns>Normalised Vector2</returns>
	Vector2 normalise();
	Vector2 operator+(const Vector2 t_addVector) const;
	Vector2 operator-(const Vector2 t_subVector) const;
	void operator-();
	float operator *(Vector2 m_scalarVector);
	Vector2 operator *(float k) const;
	Vector2 operator *(int k) const;
	float operator ^(Vector2 t_vector) const;
	std::string toString();
};

#endif