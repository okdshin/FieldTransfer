#ifdef MAIN_UNIT_TEST
#include "Formula.h"
#include "Output.h"
#include <iostream>

using namespace field_transfer;

int main(int argc, char* argv[])
{
	std::cout << argc << std::endl;
	if(argc < 4){
		std::cout << "usage" << std::endl;
		return 0;	
	}
	const auto vector_list_pair = 
		CreateVectorListPairFromFile(
			argv[1], 
			argv[2]);

	const unsigned int width = 532;
	const unsigned int height = 419;
	const auto optimized = TernarySearch(
		0, 2*M_PI, 
		2*M_PI/1000, 
		[&](Number theta)->Number {
			return MakeMeMin(theta, vector_list_pair);
		});

	const auto translated_route = CalcTranslateRoute(vector_list_pair);
	std::cout << "TranslateRoute:" << translated_route << std::endl;
	std::cout << "OptimizedTheta:" << 360.0*(optimized/(2*M_PI)) << std::endl;

	const auto raw_field = CreateField(532, 419, 1.0);
	const auto transfered_field = 
		TransferVectorList(raw_field, optimized, translated_route);
	for(Index i = 0; i < transfered_field.Size(); ++i){
		std::cout << transfered_field(i) << std::endl;
	}
	std::cout << "transfered" << std::endl;

	std::ofstream field_file(argv[3]);
	OutputFieldFormat(width, height, raw_field, transfered_field, field_file);

    return 0;
}

#endif
