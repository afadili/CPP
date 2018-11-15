#include <iostream>

int main(int argc, char const *argv[])
{
	int a;
	std::cout << "Entrer un entier : " ;
	std::cin >> a;
	if (a == 79)
	{
		std::cout << "Parfait !" << std::endl;
	}
	else 
	{
		if (a<=0)
		{
			std::cout << "Négatif !" << std::endl;
		}
		else 
		{
			std::cout << "Strictement positif !" << std::endl;
		}
	}
	return 0;
}