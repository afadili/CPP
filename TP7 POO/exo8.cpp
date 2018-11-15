/* TP7 - La STL Partie 1
Amina FADILI IMAC2
*/

#include <iostream>
#include <list>

class AjoutSiPair
{
public:
	int operator()(int n) // la surchage de l'operator ()
	{	
		if (n%2 == 0)
			{
				return n+10;
			}
		else 
		{
			return n;
		}

	}
};

void affichelist(std::list<int> liste)
{
	for (std::list<int>::iterator i=liste.begin(); i != liste.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	AjoutSiPair foncteur;

	std::list<int> liste;

	liste.push_back(1);
	liste.push_back(2);
	liste.push_back(3);
	liste.push_back(4);
	liste.push_back(5);
	liste.push_back(6);
	liste.push_back(7);
	liste.push_back(8);
	liste.push_back(9);
	liste.push_back(10);

	affichelist(liste);

	std::cout << "---------AjoutSiPair-----------" << std::endl;

	 for( std::list<int>::iterator it=liste.begin() ; it!=liste.end(); it++)
	 {	
	 	*it=foncteur(*it);
	 }

	 affichelist(liste);

	return 0;
}