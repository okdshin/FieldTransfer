#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Vector.h"
#include "Index.h"

namespace field_transfer
{
class VectorList{
public:
    VectorList(){}
	VectorList(const std::vector<Vector>& vector_vect) : 
		vector_vect(vector_vect){}
	
	auto PushBack(const Vector& coord) -> void {
		this->vector_vect.push_back(coord);	
	}

	auto Size()const -> Index {
		return Index(this->vector_vect.size());	
	}
	
	auto operator()(Index index)const -> Vector {
		return vector_vect.at(index);	
	}

private:
	std::vector<Vector> vector_vect;
};

auto CreateVectorListFromFile(const std::string& file_name) -> VectorList {
	std::ifstream ifs(file_name.c_str());
	VectorList vector_list;
	Number x, y;
	while(ifs >> x >> y){
		vector_list.PushBack(Vector(x, y));
	}
	return vector_list;
}
}

