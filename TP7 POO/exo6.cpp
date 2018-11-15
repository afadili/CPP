/* TP7 - La STL Partie 1
Amina FADILI IMAC2
*/

#include <iostream>
#include <map>
#include <iterator>

int main(int argc, char const *argv[])
{
	std::map<std::string,int> etudiants; 

	etudiants.insert(std::pair<std::string,int> ("Ali", 25));
	etudiants.insert(std::pair<std::string,int> ("Jean", 22));
	etudiants.insert(std::pair<std::string,int> ("Pierre", 20));
	etudiants.insert(std::pair<std::string,int> ("Sara", 19));
	etudiants.insert(std::pair<std::string,int> ("Sofia", 18));


	std::cout << "La liste des étudiants et leurs âges : " << "\n" << std::endl;

	

	for (std::map<std::string,int>::iterator it = etudiants.begin(); it != etudiants.end(); it++)
	{
		std::cout << it->first << " a " << it->second << " ans." << "\n";
	}

	std::cout << std::endl;

	std::string personne = "Marie";

	if (etudiants.find(personne) != etudiants.end())
	{
		std::cout << "L'âge de " << personne << " est " << etudiants.find(personne)->second << " ans." << "\n" ; 
	}
	else 
	{
		std::cout << "L'âge de " << personne << " n'existe pas!" << "\n";
	}

	std::cout << std::endl;

	return 0;
}