#include <iostream>
#include <string>
#include "PayOff.h"
#include "OptionIndepChemin.h"
#include "MonteCarlo.h"


int main()
{
	std::cout << "Bienvenue dans le pricer PerretPodda!" << std::endl;
	//Boucle infinie
	int l = 0;
	while (l < 10)
	{
		std::cout << "Options disponibles : Call, Put, BinaryCall, BinaryPut, Boundary. (Majuscule importante)" << std::endl;
		std::cout << "Quelle option souhaitez vous pricer?" << std::endl;
		std::string option("vide");
		std::cin >> option;
	
	

		//Enumeration des possibilites
		if (option == "Call")
		{

			double Maturite;
			double Strike;
			double So;
			double Volatilite;
			double r;
			unsigned long NombreSimulations;


			std::cout << "Quelle maturite? ";
			std::cin >> Maturite;

			std::cout << "Quel strike? ";
			std::cin >> Strike;

			PayOffCall POCall(Strike);// creation du PayOff du call
			OptionIndepChemin Call(POCall, Maturite);//creation de l'option Call a partir de la maturite et du payoff

			//Implementation des parametres du modele de BS
			std::cout << "Quelle valeur initiale du sous jacent? ";
			std::cin >> So;

			std::cout << "Quelle volatilite? ";
			std::cin >> Volatilite;

			std::cout << "Quel taux d'interet? ";
			std::cin >> r;

			std::cout << "Combien de simulations du sous jacent? ";
			std::cin >> NombreSimulations;

			double prix = MonteCarlo(Call, So, r, Volatilite, NombreSimulations);

			std::cout << "Le prix est : " << prix << std::endl;
		}
		else if (option == "Put")
		{
			double Maturite;
			double Strike;
			double So;
			double Volatilite;
			double r;
			unsigned long NombreSimulations;


			std::cout << "Quelle maturite? ";
			std::cin >> Maturite;

			std::cout << "Quel strike? ";
			std::cin >> Strike;

			PayOffPut POPut(Strike);// creation du PayOff du put
			OptionIndepChemin Put(POPut, Maturite);//creation de l'option put a partir de la maturite et du payoff

			std::cout << "Quelle valeur initiale du sous jacent? ";
			std::cin >> So;

			std::cout << "Quelle volatilite? ";
			std::cin >> Volatilite;

			std::cout << "Quel taux d'interet? ";
			std::cin >> r;

			std::cout << "Combien de simulations du sous jacent? ";
			std::cin >> NombreSimulations;

			double prix = MonteCarlo(Put, So, r, Volatilite, NombreSimulations);

			std::cout << "Le prix est : " << prix << std::endl;
		}
		else if (option == "BinaryCall")
		{
			double Maturite;
			double StrikeHaut;
			double So;
			double Volatilite;
			double r;
			unsigned long NombreSimulations;


			std::cout << "Quelle maturite? ";
			std::cin >> Maturite;

			std::cout << "Quel strike haut? ";
			std::cin >> StrikeHaut;

			PayOffHighDigital POHD(StrikeHaut);// creation du PayOff du BinaryCall
			OptionIndepChemin HD(POHD, Maturite);//creation de l'option BinaryCall a partir de la maturite et du payoff

			std::cout << "Quelle valeur initiale du sous jacent? ";
			std::cin >> So;

			std::cout << "Quelle volatilite? ";
			std::cin >> Volatilite;

			std::cout << "Quel taux d'interet? ";
			std::cin >> r;

			std::cout << "Combien de simulations du sous jacent? ";
			std::cin >> NombreSimulations;

			double prix = MonteCarlo(HD, So, r, Volatilite, NombreSimulations);

			std::cout << "Le prix est : " << prix << std::endl;
		}
		else if (option == "BinaryPut")
		{
			double Maturite;
			double StrikeBas;
			double So;
			double Volatilite;
			double r;
			unsigned long NombreSimulations;


			std::cout << "Quelle maturite? ";
			std::cin >> Maturite;

			std::cout << "Quel strike haut? ";
			std::cin >> StrikeBas;

			PayOffLowDigital POLD(StrikeBas);// creation du PayOff du BinaryPut
			OptionIndepChemin LD(POLD, Maturite);//creation de l'option BinaryPut a partir de la maturite et du payoff

			std::cout << "Quelle valeur initiale du sous jacent? ";
			std::cin >> So;

			std::cout << "Quelle volatilite? ";
			std::cin >> Volatilite;

			std::cout << "Quel taux d'interet? ";
			std::cin >> r;

			std::cout << "Combien de simulations du sous jacent? ";
			std::cin >> NombreSimulations;

			double prix = MonteCarlo(LD, So, r, Volatilite, NombreSimulations);

			std::cout << "Le prix est : " << prix << std::endl;
		}
		else if (option == "Boundary")
		{
			double Maturite;
			double StrikeHaut;
			double StrikeBas;
			double So;
			double Volatilite;
			double r;
			unsigned long NombreSimulations;


			std::cout << "Quelle maturite? ";
			std::cin >> Maturite;

			std::cout << "Quel strike haut? ";
			std::cin >> StrikeHaut;

			std::cout << "Quel strike bas? ";
			std::cin >> StrikeBas;

			PayOffDoubleDigital PODD(StrikeBas, StrikeHaut);// creation du PayOff du Boundary
			OptionIndepChemin DD(PODD, Maturite);//creation de l'option Boundary a partir de la maturite et du payoff

			std::cout << "Quelle valeur initiale du sous jacent? ";
			std::cin >> So;

			std::cout << "Quelle volatilite? ";
			std::cin >> Volatilite;

			std::cout << "Quel taux d'interet? ";
			std::cin >> r;

			std::cout << "Combien de simulations du sous jacent? ";
			std::cin >> NombreSimulations;

			double prix = MonteCarlo(DD, So, r, Volatilite, NombreSimulations);

			std::cout << "Le prix est : " << prix << std::endl;
		}
		else
		{
			std::cout << "Erreur, veuillez taper le nom d'une option disponible!" << std::endl;
		}
	}
	system("PAUSE");
	return 0;
}
