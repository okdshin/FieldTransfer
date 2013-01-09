#ifdef VECTORLIST_UNIT_TEST
#include "VectorList.h"
#include <iostream>

using namespace field_transfer;

int main(int argc, char* argv[])
{
	const auto list = CreateVectorListFromFile("sample_data/before.csv");
    for(Index i = 0; i < list.Size(); ++i){
		std::cout << i << list(i) << std::endl;
	}
	return 0;
}

#endif
