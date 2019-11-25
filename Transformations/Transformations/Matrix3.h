#pragma once
#include <math.h>
#include <iostream>

class Matrix3
{// The class has nine variables, 3 rows and 3 columns
public:

	Matrix3();

	Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3);

	double A11;
	double A12;
	double A13;
	double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;
};