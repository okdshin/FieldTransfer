#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
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
		//return vector_vect.at(index);	
		return vector_vect[index];
	}

private:
	std::vector<Vector> vector_vect;
};

auto CreateVectorListFromFile(
		unsigned int x_col_index, unsigned int y_col_index,
		const std::string& file_name) -> VectorList {
	std::ifstream ifs(file_name.c_str());
	VectorList vector_list;
	std::string line;
	while(ifs && getline(ifs, line)){
		std::vector<std::string> item_list;
		boost::regex_split(std::back_inserter(item_list), line, boost::regex("\\s+"));
		/*
		for(const auto str : item_list){
			std::cout << str << std::endl;
		}
		std::cout << item_list.size() << std::endl;
		*/
		if(x_col_index >= item_list.size() || y_col_index >= item_list.size()){
			throw "invalid x and y column index.";
		}
		const Number x = boost::lexical_cast<Number>(item_list[x_col_index]);
		const Number y = boost::lexical_cast<Number>(item_list[y_col_index]);
		vector_list.PushBack(Vector(x, y));
	}

	return vector_list;
}
}

