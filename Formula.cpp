#ifdef FORMULA_UNIT_TEST
#include "Formula.h"
#include <iostream>

using namespace field_transfer;

int main(int argc, char* argv[])
{
	auto befores = VectorList();
	befores.PushBack(Vector(0,0));
	befores.PushBack(Vector(1,0));
	befores.PushBack(Vector(0,2));
	//befores.PushBack(Vector(100,20));
	const double theta = (2*M_PI) / 6;
	const auto translate_route = Vector(0,0);
	
	auto afters = VectorList();
	//afters.PushBack(Rotate(befores(0), theta) + translate_route + Vector(-1,1));
	for(unsigned int i = 0; i < befores.Size(); ++i){
		afters.PushBack(Rotate(befores(i), GravityPoint(befores), theta) + translate_route);
	}

	for(unsigned int i = 0; i < afters.Size(); ++i){
		std::cout << afters(i) << std::endl;
	}


	std::cout << "MakeMeMin:" << MakeMeMin(theta, VectorListPair(befores, afters)) << std::endl;
	const auto optimized = TernarySearch(0, 2*M_PI, 0.01, 
		[&](Number theta)->Number {
			return MakeMeMin(theta, VectorListPair(befores, afters));
		});
	const auto calculated_route = CalcTranslateRoute(VectorListPair(befores, afters));
	std::cout << "TranslateRoute:" << translate_route << std::endl;
	std::cout << "Optimized:" << 360.0*(optimized/(2*M_PI)) << std::endl;
	const auto transfered_list = TransferVectorList(befores, optimized, calculated_route);
	for(unsigned int i = 0; i < transfered_list.Size(); ++i){
		std::cout << transfered_list(i) << std::endl;
	}
    return 0;
}

#endif
