#pragma once
#include <iostream>
#include <cmath>
#include "Number.h"

namespace field_transfer
{
class Vector{
public:
    Vector(Number x, Number y) : x(x), y(y){}

	auto X()const -> Number {
		return x;	
	}

	auto Y()const -> Number {
		return y;	
	}

private:
	Number x, y;
};

auto operator<<(std::ostream& os, const Vector& coord) -> std::ostream& {
	os << "(" << coord.X() << ", " << coord.Y() << ")";
	return os;
}

auto operator+(const Vector& left, const Vector& right) -> Vector {
	return Vector(left.X()+right.X(), left.Y()+right.Y());
}

auto operator*(const Number ratio, const Vector& coord) -> Vector {
	return Vector(ratio*coord.X(), ratio*coord.Y());
}

auto operator-(const Vector& left, const Vector& right) -> Vector {
	return left + (Number(-1.0)*right);
}

auto InnerProduct(const Vector& left, const Vector& right) -> Number {
	return left.X()*right.X() + left.Y()*right.Y();
}

auto SquareLength(const Vector& coord) -> Number {
	return InnerProduct(coord, coord);
}


}
