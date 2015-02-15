#ifndef MONTECARLO_CPP
#define MONTECARLO_CPP
#include <cmath>
#include <algorithm>
#include "Gauss.h"
#include "MonteCarlo.h"

double MonteCarlo(const OptionIndepChemin& OptionIndepChemin, const double& So, const double& r, const double& sig, const int& NombreSimulations)
{
	//On recupere la maturite de l'option
	double T = OptionIndepChemin.GetMaturite();
	double temp = So*exp((r-sig*sig/2)*T);
	//On applique notre methode de Monte Carlo
	double sum = 0;
	for (int i = 0; i<NombreSimulations; i++) 
	{
		double simu = gauss();
		//On recupere le PayOff de notre option
		sum += OptionIndepChemin.GetPayOff(temp*exp(sig*sqrt(T)*simu));
	}

	return exp(-r*T)*(sum / NombreSimulations);
}

#endif
