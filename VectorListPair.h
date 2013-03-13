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

inline auto CreateVectorListPairFromFile(
		unsigned int x_col_index,
		unsigned int y_col_index,
		const std::string& before_file_name, 
		const std::string& after_file_name) -> VectorListPair {
	
	return VectorListPair(
		CreateVectorListFromFile(x_col_index, y_col_index, before_file_name),
		CreateVectorListFromFile(x_col_index, y_col_index, after_file_name));	
}
}

