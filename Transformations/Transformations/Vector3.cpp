#include "Vector3.h"

Vector3::Vector3() :
	m_x(0.0f),
	m_y(0.0f),
	m_z(0.0f)
{

}

Vector3::Vector3(double x1, double y1, double z1) :
	m_x(x1),
	m_y(y1),
	m_z(z1)
{ // To allow other values for X, Y and Z to be declared

}

Vector3::Vector3(Vector3& V)
{  // To allow other values for X, Y and Z to be declared
	m_x = V.m_x;
	m_y = V.m_y;
	m_z = V.m_z;
}

double Vector3::Length()
{  // A method to return the length of the vector
	return (double)sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}
double Vector3::LengthSquared()
{  // A method to return the length squared of the vector
	return (m_x * m_x + m_y * m_y + m_z * m_z);
}

Vector3 Vector3::Normalise()
{  // A method to reduce the length of the vector to 1.0 
	// keeping the direction the same
	if (this->Length() > 0.0)
	{  // Check for divide by zero
		double magnit = this->Length();
		this->m_x /= magnit;
		this->m_y /= magnit;
		this->m_z /= magnit;
	}
}

Vector3 Vector3::operator+(const Vector3 t_right)
{
	return { m_x + t_right.m_x, m_y + t_right.m_y, m_z + t_right.m_z }; // Adding two vectors together
}

Vector3 Vector3::operator-(Vector3 V1)
{ // An overloaded operator - to return the difference of 2 vectors
	return { m_x - V1.m_x, m_y - V1.m_y, m_z - V1.m_z };
}

Vector3 Vector3::operator -(Vector3 V)
{// An overloaded operator - to return the negation of a single vector
	m_x -= V.m_x;
	m_y -= V.m_y;
	m_z -= V.m_z;
	return v;
}

double Vector3::operator *(Vector3 V1)
{// An overloaded operator * to return the scalar product of 2 vectors
	return { m_x * V1.m_x + m_y * V1.m_y + m_z * V1.m_z };
}

Vector3 Vector3::operator *(double k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return { V1.m_x * (float)k, V1.m_y * (float)k, V1.m_z * (float)k };
}

Vector3 Vector3::operator *(float k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return { V1.m_x * k, V1.m_y * k, V1.m_z * k };
}

Vector3 Vector3::operator *(int k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return { (V1.m_x * k, V1.m_y * k, V1.m_z * k };
}

Vector3 Vector3::operator ^(Vector3 V1, Vector3 V2)
{// An overloaded operator ^ to return the vector product of 2 vectors
	return { V1.m_y * V2.m_z - V1.m_z * V2.m_y, V1.m_z * V2.m_x - V1.m_x * V2.m_z, V1.x * V2.m_y - V1.m_y * V2.m_x };
}

override string ToString()
{
	return "(" + x.ToString("g3") + "," + y.ToString("g3") + "," + z.ToString("g3") + ")";
}