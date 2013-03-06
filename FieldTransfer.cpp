#ifdef FIELDTRANSFER_UNIT_TEST
#include "Formula.h"
#include "Output.h"
#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace field_transfer;

int main(int argc, char* argv[])
{
	//std::cout << argc << std::endl;
	if(argc < 6){
		std::cout << "usage:<before> <after> <x_col_index> <y_col_index> <width> <height> <dst>" << std::endl;
		return 0;	
	}
	const unsigned int x_col_index = boost::lexical_cast<unsigned int>(argv[3]);
	const unsigned int y_col_index = boost::lexical_cast<unsigned int>(argv[4]);
	try {
		const auto vector_list_pair = 
			CreateVectorListPairFromFile(
				x_col_index, y_col_index,
				argv[1], 
				argv[2]);
		OutputVectorList(vector_list_pair.GetBeforeVectorList(), std::cout);
		OutputVectorList(vector_list_pair.GetAfterVectorList(), std::cout);
		std::cout << std::endl;
		const unsigned int width = boost::lexical_cast<unsigned int>(argv[5]);
		const unsigned int height = boost::lexical_cast<unsigned int>(argv[6]);
		const auto optimized = TernarySearch(
			0, 2*M_PI, 
			2*M_PI/1000, 
			[&](Number theta)->Number {
				return MakeMeMin(theta, vector_list_pair);
			});

		const auto translated_route = CalcTranslateRoute(vector_list_pair);
		std::cout << "TranslateRoute:" << translated_route << std::endl;
		std::cout << "OptimizedTheta:" << 360.0*(optimized/(2*M_PI)) << std::endl;

		const auto raw_field = CreateField(width, height, 1.0);
		const auto transfered_field = 
			TransferVectorList(raw_field, optimized, translated_route);
		/*
		for(Index i = 0; i < transfered_field.Size(); ++i){
			std::cout << transfered_field(i) << std::endl;
		}
		*/
		std::cout << "transfered" << std::endl;

		std::ofstream field_file(argv[7]);
		//OutputFieldFormat(width, height, raw_field, transfered_field, field_file);
		OutputFieldFormat(width, height, transfered_field, raw_field, field_file);
	}
	catch(const std::string& error){
		std::cout << "error!:" << error << std::endl;
		return 0;
	}
	

    return 0;
}

#endif
