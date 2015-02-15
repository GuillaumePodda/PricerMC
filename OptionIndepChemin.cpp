#ifndef OPTION_INDEP_CHEMIN_CPP
#define OPTION_INDEP_CHEMIN_CPP

#include "OptionIndepChemin.h"

OptionIndepChemin::OptionIndepChemin(PayOff& PayOffOption, const double& Maturite) : _PayOff(PayOffOption), _Maturite(Maturite) {}
OptionIndepChemin::~OptionIndepChemin(){}
//Accessseur Maturite
double OptionIndepChemin::GetMaturite() const
{
	return _Maturite;
}

double OptionIndepChemin::GetPayOff(double S) const
{
	return _PayOff(S);
}

#endif
