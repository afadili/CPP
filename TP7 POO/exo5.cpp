/* TP7 - La STL Partie 1
Amina FADILI IMAC2
*/
#include <iostream>
#include <list>    
#include <algorithm> 


void affichelist(std::list<std::string> liste)
{
	for (std::list<std::string>::iterator i=liste.begin(); i != liste.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	std::list<std::string> l_philo;


	l_philo.push_back("Platon");
	l_philo.push_back("Aristote");
	l_philo.push_back("Descartes");
	l_philo.push_back("Kant");

	std::list<std::string> l_math;

	l_math.push_back("Gauss");
	l_math.push_back("Laplace");
	l_math.push_back("Poincaré");
	l_math.push_back("Descartes");

	std::cout << "Liste l_philo : " ;

	affichelist(l_philo);

	std::cout << "Liste l_math : " ;

	affichelist(l_math);

	std::cout << std::endl;

	l_philo.sort();
	l_math.sort();

	std::cout << "Liste l_philo triée : " ;

	affichelist(l_philo);

	std::cout << "Liste l_math triée : " ;

	affichelist(l_math);

	std::cout << std::endl;

	std::list<std::string> l_all;

	l_philo.merge(l_math);
	l_all = l_philo;
	std::cout << "Liste l_all: ";
	affichelist(l_all);

	std::cout << std::endl;

	l_all.unique();

	std::cout << "Liste l_all (sans répétitions): ";
	affichelist(l_all);

	std::cout << std::endl;

	l_all.reverse();

	std::cout << "Liste l_all inversée : ";
	affichelist(l_all);


	return 0;
}