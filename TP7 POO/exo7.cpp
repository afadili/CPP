/* TP7 - La STL Partie 1
Amina FADILI IMAC2
*/

#include <iostream>

class Majuscule
{
public:
	std::string operator()(std::string a) // la surchage de l'operator ()
	{
		std::locale loc;
		std::string maj;
		for (std::string::size_type i =0; i<a.length(); i++)
		{
			maj += std::toupper(a[i], loc);
		}
		return maj;
	}
	
};

int main(int argc, char const *argv[])
{
	Majuscule texte;
	std::string mot = "hello world";
	std::string motMaj(mot);

	std::cout << mot << "---(en Majuscule)---->";

	std::cout << texte(motMaj) << std::endl;

	return 0;
}