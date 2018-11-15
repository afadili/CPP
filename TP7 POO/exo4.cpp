/* TP7 - La STL Partie 1
Amina FADILI IMAC2
*/

#include <iostream>
#include <deque>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::deque<int> file;

	for(unsigned int i=0; i<5; ++i)
	{
		file.push_back(rand()%10);
	}

	std::cout << "Initialisation de la deque: " << std::endl;

	for(unsigned int i=0; i<5; ++i)
	{
		std::cout << file[i] << "  " ;
	}

	for(unsigned int i=0; i<5; ++i){
		int r = rand()%10;
		std::cout << "\nIntroduction de " << r << " :";
		file.push_front(r); 
		file.pop_back();
		
		std::cout << "  " ;
	for(float j=0 ; j< 5; j++)
	{

		std::cout << file[j] << "  " ;
		
	}
	
}

	std::cout << std::endl;

	return 0;
}