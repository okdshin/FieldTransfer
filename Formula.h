#pragma once
#include <iostream>
#include <functional>
#include "Index.h"
#include "Number.h"
#include "Vector.h"
#include "VectorList.h"
#include "VectorListPair.h"
#include "Matrix.h"

namespace field_transfer
{

template<class Type>
inline auto Sigma(Index end, std::function<Type(Index)> func) -> Type {
	Type sum = func(0);
	for(Index i = 1; i < end; ++i){
		sum = sum + func(i);
	}
	return sum;
}

inline auto GravityPoint(const VectorList& vector_list) -> Vector {
	const auto num = vector_list.Size();
	return (1.0/Number(num))*Sigma<Vector>(num, 
		[&](Index i) -> Vector { return vector_list(i); });
}

inline auto CalcTranslateRoute(const VectorListPair& pair) -> Vector {
	return GravityPoint(pair.GetAfterVectorList())
		- GravityPoint(pair.GetBeforeVectorList());
}

inline auto MakeMeMin(Number theta, 
		const VectorListPair& vector_list_pair) -> Number {
	const auto befores = vector_list_pair.GetBeforeVectorList();
	const auto afters = vector_list_pair.GetAfterVectorList();
	const auto size = befores.Size();
	auto befores_gp = GravityPoint(befores);
	auto afters_gp = GravityPoint(afters);
	//std::cout << "BeforeGP:" << befores_gp << std::endl;
	//std::cout << "AfterGP:" << afters_gp << std::endl;
	return Sigma<Number>(size, [&](Index i){
			return SquareLength(
				afters(i)-afters_gp - Rotate(befores(i), befores_gp, theta));
		});
}

inline auto TernarySearch(Number min, Number max, Number delta, std::function<Number(Number)> func) -> Number {
	while((max-min) > delta){
		const auto unit_range = (max-min)/3.0;
		const auto smaller = min + unit_range;
		const auto bigger = smaller + unit_range;
		if(func(smaller) < func(bigger)){
			max = bigger;	
		}
		else {
			min = smaller;	
		}
	}
	return (max+min)/2.0;
}

inline auto CreateField(Number width, Number height, Number edge_length) -> VectorList {
	VectorList vector_list;
	for(Number w = 0.0; w < width; w=w+edge_length){
		for(Number h = 0.0; h < height; h=h+edge_length){
			vector_list.PushBack(Vector(w, h));
		}	
	}	
	return vector_list;
}

inline auto TransferVectorList(
		const VectorList& vector_list, 
		Number theta, 
		const Vector& translate_route,
		std::function<void (unsigned int)> indicator) -> VectorList {
	auto transfered_list = VectorList();
	std::cout << "size:" << vector_list.Size() << std::endl;
	for(Index i = 0; i < vector_list.Size(); ++i){
		transfered_list.PushBack(
			Rotate(vector_list(i), GravityPoint(vector_list), theta)
			+translate_route);
		indicator(i);
	}
	return transfered_list;
}

}

