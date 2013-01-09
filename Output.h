#pragma once
//Output:20130109
#include <iostream>
#include <boost/format.hpp>
#include "VectorList.h"

namespace field_transfer
{
auto OutputFieldFormat(const VectorList& vector_list, std::ostream& os) -> void {
	for(Index i = 0; i < vector_list.Size(); ++i){
		os << boost::format("%1%\t%2%") 
			% vector_list(i).X() 
			% vector_list(i).Y()
		<< std::endl;
	}	
}

}

