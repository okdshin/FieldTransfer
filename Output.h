#pragma once
//Output:20130109
#include <iostream>
#include <boost/format.hpp>
#include "VectorList.h"

namespace field_transfer
{
auto OutputFieldInvertedFormat(
		const VectorList& before_vector_list, 
		const VectorList& after_vector_list, 
		std::ostream& os) -> void {
	assert(before_vector_list.Size() == after_vector_list.Size());
	for(Index i = 0; i < before_vector_list.Size(); ++i){
		os << boost::format("%1%\t%2%\t%3%\t%4%") 
			% before_vector_list(i).X() 
			% before_vector_list(i).Y()
			% after_vector_list(after_vector_list.Size()-i-1).X() 
			% after_vector_list(after_vector_list.Size()-i-1).Y()
		<< std::endl;
	}	
}

auto OutputFieldFormat(
		const VectorList& before_vector_list, 
		const VectorList& after_vector_list, 
		std::ostream& os) -> void {
	assert(before_vector_list.Size() == after_vector_list.Size());
	for(Index i = 0; i < before_vector_list.Size(); ++i){
		os << boost::format("%1%\t%2%\t%3%\t%4%") 
			% after_vector_list(i).X() 
			% after_vector_list(before_vector_list.Size()-i-1).Y()
			% before_vector_list(i).X() 
			% before_vector_list(i).Y()
		<< std::endl;
	}	
}
}

