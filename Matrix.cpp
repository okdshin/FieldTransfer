#ifdef MATRIX_UNIT_TEST
#include "Matrix.h"
#include <iostream>

using namespace field_transfer;

int main(int argc, char* argv[])
{
	Vector vector(2,0);
	const double theta = M_PI/3;
	Matrix rotate({cos(theta), -sin(theta)}, {sin(theta), cos(theta)});

	std::cout << (rotate*vector).Y() << std::endl;

    return 0;
}

#endif
