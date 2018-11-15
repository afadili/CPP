/* TP6 - les exceptions 
Amina FADILI IMAC2
*/

#include <iostream>
#include <exception>
#include <string>

class Erreur : public std::exception
{
private:
	int _niveau;
	int _code;
	std::string _message;
public:
	Erreur(int niveau, int code, std::string message) : _niveau(niveau), _code(code), _message(message) {} ;
	int getNiveau();
	int getCode();
	const char* what() const noexcept override ;
	virtual ~Erreur(){};
	
};

int Erreur::getNiveau()
{
	return _niveau; 
}

int Erreur::getCode()
{
	return _code;
}

const char* Erreur::what() const noexcept
{

	std::cout << "Niveau : " << _niveau << std::endl;
	std::cout << "Code : " << _code << std::endl;
	std::cout << "Message : ";
	return _message.c_str();
}


int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 0;

	std::cout << "a/2 = " << a/2 << std::endl;
	std::cout << "-------------------------------------------"<< std::endl;
	std::cout << "Exception lancée : "<< std::endl;
	try {
		if (b==0)
		{
			throw Erreur(1,1,"Dénominateur nul !! ");
		}
		else
		{
			return a/b;
		}
	}
	catch (Erreur &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------"<< std::endl;
	std::cout << "a/5 = " << a/5 << std::endl;
	std::cout << "Terminé !! " << std::endl;


	return 0;
}

/* Exercice 1:
 2) le programme ne plante pas au niveau de la compilation mais au niveau de l'execution à la ligne *

Exercice 2:

5) Le programme termine son excécution malgré la division car il fait un try et un catch qui gère l'exception et permet de passer à l'instruction suivante.
6) Un try doit toujours etre suivi d'au moins un catch, donc si on n'a pas de catch après le try, on aura une erreur à la compilation.
*/