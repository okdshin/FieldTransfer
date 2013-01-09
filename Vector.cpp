#ifdef VECTOR_UNIT_TEST
#include "Vector.h"
#include <iostream>

using namespace field_transfer;

int main(int argc, char* argv[])
{
	Vector coord(1.2, 3.4), coord2(5.6, 7.8);
	std::cout << coord << std::endl;
	std::cout << coord2 << std::endl;
	std::cout << coord+coord2 << std::endl;
	std::cout << coord-coord2 << std::endl;
	std::cout << 2*coord << std::endl;
	std::cout << Rotate(coord, Number(M_PI/2)) << std::endl;
	std::cout << SquareLength(coord2) << std::endl;

    return 0;
}

#endif
