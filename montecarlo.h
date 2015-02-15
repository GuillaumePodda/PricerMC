#ifndef MONTECARLO_H
#define MONTECARLO_H
#include "OptionIndepChemin.h"

//Fonction retournant le prix en fonction de l'option independante du cours du sous-jacent avant maturite choisie, et des parametres
//du modele de BlackScholes pour simuler les trajectoires du sous jacent
double MonteCarlo(const OptionIndepChemin& OptionIndepChemin, const double& So, const double& r, const double& sig, const int& NombreSimulations);

#endif
