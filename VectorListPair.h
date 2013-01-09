#pragma once
#include <iostream>
#include "VectorList.h"

namespace field_transfer
{
class VectorListPair{
public:
    VectorListPair(const VectorList& before, const VectorList& after) : 
		before(before), after(after){}

	auto GetBeforeVectorList()const -> VectorList {
		return this->before;
	}
	
	auto GetAfterVectorList()const -> VectorList {
		return this->after;
	}

private:
	VectorList before, after;
};

auto CreateVectorListPairFromFile(
		const std::string& before_file_name, 
		const std::string& after_file_name) -> VectorListPair {
	
	return VectorListPair(
		CreateVectorListFromFile(before_file_name),
		CreateVectorListFromFile(after_file_name));	
}
}

