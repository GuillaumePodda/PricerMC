#ifndef PAY_OFF_CPP
#define PAY_OFF_CPP

#include "PayOff.h"

PayOff::PayOff() {}//Constructeur
PayOff::~PayOff() {}//Destructeur

// Pour un CALL 
PayOffCall::PayOffCall(const double& K)//Constructeur prenant en entree le strike
{ 
	_K = K; 
}
//Destructeur
PayOffCall::~PayOffCall() {}
// On se sert de l'operateur () cree dans la classe mere en lui donnant cette fois ci une vraie existence, pas simplement virtuelle
double PayOffCall::operator() (const double& S) const 
{
	return std::max(S - _K, 0.0);
}

// Pour un PUT: identique
PayOffPut::PayOffPut(const double& K) 
{
	_K = K;
}
PayOffPut::~PayOffPut() {}
double PayOffPut::operator() (const double& S) const 
{
	return std::max(_K - S, 0.0);
}

// Pour un HIGHDIGITAL
PayOffHighDigital::PayOffHighDigital(const double& KHaut)
{
	_KHaut = KHaut;
}

PayOffHighDigital::~PayOffHighDigital() {}

double PayOffHighDigital::operator()(const double& S) const
{
	if (S <= _KHaut)
		return 0;
	return 1;
}
// Pour un LOWDIGITAL
PayOffLowDigital::PayOffLowDigital(const double& KBas)
{
	_KBas = KBas;
}

PayOffLowDigital::~PayOffLowDigital() {}

double PayOffLowDigital::operator()(const double& S) const
{
	if (S >= _KBas)
		return 0;
	return 1;
}
// Pour un DOUBlEDIGITAL
PayOffDoubleDigital::PayOffDoubleDigital(const double& KBas,const double& KHaut)
{
	_KBas = KBas;
	_KHaut = KHaut;
}

PayOffDoubleDigital::~PayOffDoubleDigital() {}

double PayOffDoubleDigital::operator()(const double& S) const
{
	if ((S <= _KHaut) || (S >= _KBas))
		return 0;
	return 1;
}

#endif
