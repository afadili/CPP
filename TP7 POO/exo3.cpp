/* TP7 - La STL Partie 1
Amina FADILI IMAC2
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::vector<int> vecteur;

	for(unsigned int i=0; i<20; ++i)
	{
		vecteur.push_back(rand()%20);
	}

	std::cout << "Vecteur avec des valeurs aléatoires de 0 à 20 :" << std::endl;

	for(unsigned int i=0; i<20; ++i)
	{
		std::cout << vecteur[i] << "  " ;
	}

	std::cout << std::endl;

	std::cout << "Vecteur après le tri des valeurs  :" << std::endl;
	std::sort(vecteur.begin(),vecteur.end());

	for(unsigned int i=0; i<20; ++i)
	{
		std::cout << vecteur[i] << "  " ;
	}
	std::cout << std::endl;
	int mycount = std::count(vecteur.begin(), vecteur.end(), 7);

	std::cout << "Le nombre 7 apparaît : " << mycount << " fois." << std::endl;

	return 0;
}