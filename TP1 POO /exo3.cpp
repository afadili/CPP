#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string chaine;
	std::cout << "Entrer une chaine de caractère : " << std::endl ; 
	std::cin >> chaine;
	std::cout << "String size : " << chaine.size() << "\nLast element : " << chaine.back() << std::endl;
	chaine.pop_back();
	std::cout << chaine << std::endl;
	chaine = "IMAC " + chaine;
	std::cout << chaine << std::endl;
	return 0;
}