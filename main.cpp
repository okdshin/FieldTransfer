#ifdef MAIN_UNIT_TEST
#include "Formula.h"
#include "Output.h"
#include <iostream>

using namespace field_transfer;

int main(int argc, char* argv[])
{
	const auto vector_list_pair = 
		CreateVectorListPairFromFile(
			"sample_data/before.csv", 
			"sample_data/after.csv");

	const auto optimized = TernarySearch(
		0, 2*M_PI, 
		2*M_PI/360000000, 
		[&](Number theta)->Number {
			return MakeMeMin(theta, vector_list_pair);
		});

	const auto translated_route = CalcTranslateRoute(vector_list_pair);
	std::cout << "TranslateRoute:" << translated_route << std::endl;
	std::cout << "OptimizedTheta:" << 360.0*(optimized/(2*M_PI)) << std::endl;

	const auto raw_field = CreateField(532, 419, 1);
	const auto transfered_field = 
		TransferVectorList(raw_field, optimized, translated_route);
	for(Index i = 0; i < transfered_field.Size(); ++i){
		std::cout << transfered_field(i) << std::endl;
	}

	std::ofstream field_file("result.csv");
	OutputFieldFormat(transfered_field, field_file);

    return 0;
}

#endif
