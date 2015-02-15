#ifndef OPTION_INDEP_CHEMIN_H
#define OPTION_INDEP_CHEMIN_H

#include "PayOff.h"
//On cree cette classe permettant de creer nos objets options
class OptionIndepChemin
{
	private:
		double _Maturite;
		PayOff& _PayOff;
	public:
		OptionIndepChemin(PayOff& PayOffOption,const double& Maturite);//Constructeur
		~OptionIndepChemin();//Destructeur
		double GetMaturite() const; //Accesseur
		double GetPayOff(double S) const; //Faux accesseur renvoyant la fonction de PayOff de l'option


};

#endif
