#include <iostream>
#include "Vector3.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "Quaternion.h"

int main()
{
	Vector3 v1{ 0, 2, -5};
	Vector3 v2{ -2, -2, -5 };
	Vector3 v3{ 2, -2, -5 };

	double angle = 23.21;

	Vector3 v4 = Matrix3::RotationZ(angle) * v3;

	double quatAngle = 5.0;

	double radians = quatAngle * (acos(-1) / 180);

	Quaternion q1;
	q1.FromAxisAngle(Vector3(0, 0, 1), radians);

	Vector3 v5 = q1.Rotate(v3, quatAngle);

	std::cout << "Length of V1: " << v1.Length() << std::endl;
	std::cout << "Squared Length of V2: " << v2.LengthSquared() << std::endl;
	std::cout << "v4 rotated on z axis by 5 degrees: " << v4.ToString() << std::endl;
	std::cout << "v5 rotated by quaternion by 23.21: " << v5.ToString() << std::endl;

	system("pause");

	double angleTwo = 5.0;

	Vector3 v6 = Matrix3::RotationZ(angleTwo) * v3;

	std::cout << v6.ToString() << std::endl;

	double quatAngleTwo = 23.21;

	double radiansTwo = quatAngleTwo * (acos(-1) / 180);

	Quaternion q2;
	q2.FromAxisAngle(Vector3(0, 0, 1), radiansTwo);

	Vector3 v7 = q2.Rotate(v3, quatAngleTwo);

	std::cout << "v6 rotated on z axis by 23.21 degrees: " << v6.ToString() << std::endl;
	std::cout << "v7 rotated by quaternion by 5 degrees: " << v7.ToString() << std::endl;
}