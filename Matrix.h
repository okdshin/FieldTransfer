#pragma once
//Matrix:20121219
#include <iostream>
#include <array>
#include "Vector.h"

namespace field_transfer
{
class Matrix{
public:
    Matrix(const Vector& upper, const Vector& lower) :
		upper(upper), lower(lower){}

	Matrix(const std::array<Number, 2>& upper, const std::array<Number, 2>& lower):
		Matrix(
			Vector(upper.at(0), upper.at(1)), 
			Vector(lower.at(0), lower.at(1))){}

	auto GetUpperVector()const -> Vector {
		return upper;	
	}

	auto GetLowerVector()const -> Vector {
		return lower;	
	}

private:
	Vector upper, lower;

};

auto operator*(const Matrix& matrix, const Vector& vector) -> Vector {
	return Vector(
		InnerProduct(matrix.GetUpperVector(), vector), 
		InnerProduct(matrix.GetLowerVector(), vector));
}

auto Rotate(const Vector& coord, const Vector& center_coord, Number theta) -> Vector{
	return center_coord + Matrix({cos(theta), -sin(theta)}, {sin(theta), cos(theta)})*(coord-center_coord);
}

}

