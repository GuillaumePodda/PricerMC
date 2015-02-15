


#ifndef GAUSS_CPP
#define GAUSS_CPP
#include "Gauss.h"
#include <iostream>


double gauss()
{
	//on cree une seed comptant le nombre de secondes depuis une date fixee jusqu'a maintenant
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//on tire un nombre aleatoire dans la liste default_random_engine_generator a partir de la seed
	std::default_random_engine generator(seed);
	// on simule notre gaussienne centree reduite
	std::normal_distribution<double> distribution(0,1);
	return distribution(generator);
}

#endif
