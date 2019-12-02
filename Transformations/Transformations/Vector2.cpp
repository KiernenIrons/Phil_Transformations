#include "Vector2.h"

/// <summary>
/// A method to reduce the length of the vector to 1.0 
/// keeping the direction the same 
/// </summary>
/// <returns>Normalised Vector2</returns>
Vector2 Vector2::normalise()
{
	Vector2 normalised = *this;

	if (normalised.length() > 0.0)
	{  // Check for divide by zero
		double magnit = normalised.length();
		normalised.m_x /= static_cast<float>(magnit);
		normalised.m_y /= static_cast<float>(magnit);
	}
	else
	{
		std::cout << "length <= 0.0" << std::endl;
		normalised = Vector2{ 0,0 }; // return empty vector2 if length is 0 or less
	}

	return normalised;
}

std::string Vector2::toString()
{
	return "(" + std::to_string(m_x) + ","
		+ std::to_string(m_y) + ")";
}

/// <summary>
/// An overloaded operator + to return the sum of 2 vectors
/// </summary>
/// <param name="t_addVector">Vector to add to</param>
/// <returns>sum of 2 vectors</returns>
Vector2 Vector2::operator+(const Vector2 t_addVector) const
{
	return { m_x + t_addVector.getX(), m_y + t_addVector.getY() };
}

/// <summary>
/// An overloaded operator - to return the difference of 2 vectors
/// </summary>
/// <param name="t_subVector">Vector 1</param>
/// <param name="V2">Vector 2</param>
/// <returns>difference of 2 vectors</returns>
Vector2 Vector2::operator-(const Vector2 t_subVector) const
{
	return { m_x - t_subVector.getX(), m_y - t_subVector.getY() };
}



/// <summary>
/// An overloaded operator - to return the negation of a single vector
/// </summary>
/// <param name="V">Vector 1</param>
/// <returns>negation of a single vector</returns>
void Vector2::operator -()
{
	this->setX(this->getX() * -1);
	this->setY(this->getY() * -1);
}

/// <summary>
/// An overloaded operator * to return the scalar product of 2 vectors
/// </summary>
/// <param name="m_scalarVector">Vector 1</param>
/// <returns>scalar product of 2 vectors</returns>
float Vector2::operator *(Vector2 m_scalarVector)
{
	return (m_x * m_scalarVector.getX() + m_y * m_scalarVector.getY());
}

/// <summary>
/// An overloaded operator * to return the product of a scalar by a vector (using float)
/// </summary>
/// <param name="k">Scalar</param>
/// <param name="V1">Vector 1</param>
/// <returns>product of a scalar by a vector</returns>
Vector2 Vector2::operator *(float k) const
{
	return { m_x * k, m_y * k };
}

/// <summary>
/// An overloaded operator * to return the product of a scalar by a vector (using int)
/// </summary>
/// <param name="k">Scalar</param>
/// <param name="V1">Vector 1</param>
/// <returns>product of a scalar by a vector</returns>
Vector2 Vector2::operator *(int k) const
{
	return { m_x * k, m_y * k };
}

/// <summary>
/// An overloaded operator ^ to return the vector product of 2 vectors
/// </summary>
/// <param name="t_vector">Vector 2</param>
/// <returns>Vector product of 2 vectors</returns>
float Vector2::operator ^(Vector2 t_vector) const
{
	return (m_x * t_vector.m_y) - (m_y * t_vector.m_x);
}