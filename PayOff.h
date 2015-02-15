#pragma once
#ifndef PAY_OFF_H
#define PAY_OFF_H
#include <algorithm> //Pour utiliser la fonction Max

class PayOff 
{
	public:
		PayOff(); // Constructeur
		~PayOff(); // Destructeur

		// Operateur () surcharge permet de transformer le PayOff en une fonction pouvant etre appelee dans les classes filles
		// PayOff() sera alors une fonction de S pour K donne, et se transmettra aux classes filles
		virtual double operator() (const double& S) const = 0;
};

//CALL
class PayOffCall : public PayOff 
{
	private:
		double _K; // Strike prive

	public:
		PayOffCall(const double& K);// Constructeur
		~PayOffCall(); // Destructeur
		//transmission de l'operateur de la classe mere
		virtual double operator() (const double& S) const;
};

//PUT
class PayOffPut : public PayOff {
	private:
		double _K; // Strike prive

	public:
		PayOffPut(const double& K);
		~PayOffPut();
		virtual double operator() (const double& S) const;
};

//HIGHDIGITAL
class PayOffHighDigital : public PayOff
{
	private:
		double _KHaut;

	public:
		PayOffHighDigital(const double& KHaut);
		~PayOffHighDigital();
		virtual double operator() (const double& S) const;
};

//LOWDIGITAL
class PayOffLowDigital : public PayOff
{
	private:
		double _KBas;

	public:
		PayOffLowDigital(const double& KBas);
		~PayOffLowDigital();
		virtual double operator() (const double& S) const;
};

//DOUBLEDIGITAL
class PayOffDoubleDigital : public PayOff
{
	private:
		double _KBas;
		double _KHaut;

	public:
		PayOffDoubleDigital(const double& KBas, const double& KHaut);
		~PayOffDoubleDigital();
		virtual double operator() (const double& S) const;
};

#endif
