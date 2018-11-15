// ================================
// POO C++ - IMAC 2
// TP 1 - Exercice 5
// ================================

#include<iostream>
#include <vector>
#include "chrono.hpp"

namespace TP_CPP_IMAC2
{
	int mean(std::vector<int> &v, int taille)
	{
		int res = 0;
		for (int i=0; i<taille; i++)
		{
			res += v[i];
		}
		return res/taille;
	}


	int meanCopy(std::vector<int> vec, int taille)
	{
		int res = 0;
		for (int i=0; i<taille; i++)
		{
			res += vec[i];
		}
		return res/taille;
	}

	int main(int argc, char *argv[])
	{
		int n;
		std::vector<int> vector;
		std::cout << "Entrer la taille du vecteur : ";
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			vector.push_back(i%10);
		}
		for (int i = 0; i < n; ++i)
		{
			std::cout << vector[i] ; 
		}
		std::cout << vector.size() << std::endl;
		std::cout << "Adresse des 3 premiers elements : " << std::endl;
		for (int k=0; k<3; k++){ std::cout << &(vector[k]); std::cout << std::endl;}
		for (int i = 0; i < n; ++i)
		{
			std::cout << vector[i] ; 
		}
		std::cout <<std::endl;

		vector.pop_back();
		for (int j = 0; j < n; ++j)
		{
			std::cout << vector[j] ; 
		}
		std::cout << std::endl;
	

		//vector.clear();
		/*if(!vector.empty())
		{
			std::cout << "Not Empty !" << std::endl;
		}
		std::cout << "Empty !! YES !!" << std::endl;*/

		Chrono chrono;
		chrono.start();
		std::cout << mean(vector,n) << std::endl;
		chrono.stop();
		std::cout << "Time : " << chrono.timeSpan() << "s" << std::endl;


		Chrono chrono2;
		chrono2.start();
		std::cout << meanCopy(vector,n) << std::endl;
		chrono2.stop();
		std::cout << "Time : " << chrono2.timeSpan() << "s" << std::endl;
		

		return 0;

	}

	
}

// Fonction main classique, point d'entr�e du programme
int main(int argc, char *argv[])
{
	// Appel de la fonction main de l'espace de nom TP_CPP_IMAC2
	return TP_CPP_IMAC2::main(argc, argv);
}


