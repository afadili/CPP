/* TP7 - La STL Partie 1
Amina FADILI IMAC2
*/

#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::vector<int> vecteur;
	std::vector<int> swap;
	if(!vecteur.empty())
	{
		std::cout << "Vecteur pas vide ! " << std::endl;
	}
	else 
	{
		std::cout << "Vecteur vide ! " << std::endl;
	}

	std::cout << "Taille du vecteur : " << vecteur.size() << std::endl;
	std::cout << "Taille maximale d'un vecteur d'entiers : " << vecteur.max_size() << std::endl;

	vecteur.push_back(1);
	vecteur.push_back(2);
	vecteur.push_back(3);

	std::cout << "Nouvelle taille du vecteur : " << vecteur.size() << std::endl;

	std::cout << "Contenu du vecteur : " << std::endl;

	for(unsigned int i=0; i<vecteur.size(); ++i)
	{
		std::cout << vecteur[i] << std::endl;
	}

	swap.push_back(4);
	swap.push_back(5);
	swap.push_back(6);
	
	vecteur.swap(swap);

	std::cout << "------Après le swap----------------- " << std::endl;
	std::cout << "Contenu du Vecteur :" << std::endl;
	
	for(unsigned int i=0; i<vecteur.size(); ++i)
	{
		std::cout << vecteur[i] << std::endl;
	}
	std::cout << "Avec le contenu du swap :" << std::endl;
	for(unsigned int j=0; j<swap.size(); ++j)
	{
		std::cout << swap[j] << std::endl;
	}


	return 0;
}