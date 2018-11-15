#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class Vehicule
{
public:
	std::string marque;
	int date_achat;
	int prix_achat;
	 Vehicule(std::string m, int d, int p) 
	 : marque(m),
	 date_achat(d),
	 prix_achat(p){}
	~Vehicule();
public:
	 virtual void afficher_infos() const = 0;
	 std::string getMarque();
	int getDate_achat();
	int getPrix_achat();
	
};

std::string Vehicule::getMarque()
{
	return marque;
}

int Vehicule::getDate_achat()
{
	return date_achat;
}

int Vehicule::getPrix_achat()
{
	return prix_achat;
}

Vehicule ::~Vehicule(){}






class Voiture : public Vehicule 
{

public:
	~Voiture();
	Voiture(std::string m_V, int d_V, int p_V) : Vehicule(m_V,d_V,p_V){}

	void afficher_infos() const override;
};

Voiture::~Voiture(){}



void Voiture::afficher_infos() const
{
	std::cout <<  "La marque de la voiture : " << marque << std::endl;
	std::cout <<  "La date d'achat de la voiture : " << date_achat << std::endl;
	std::cout <<  "Le prix d'achat de la voiture : " << prix_achat << std::endl;
}


class Bus : public Vehicule 
{

public:
	~Bus();
	Bus(std::string mB, int dB, int pB) : Vehicule(mB,dB,pB){}

	void afficher_infos() const override;
};

Bus::~Bus(){}

void Bus::afficher_infos() const 
{
	std::cout <<  "La marque du bus : " << marque << std::endl;
	std::cout <<  "La date d'achat du bus : " << date_achat << std::endl;
	std::cout <<  "Le prix d'achat du bus: " << prix_achat << std::endl;
}


void afficher (Vehicule  *v){
	v->afficher_infos();
}




int main(int argc, char const *argv[])
{
	Voiture v1("BM", 2010, 10000);
	//v1.afficher_infos();
	Voiture v2("Opel", 2004, 4100);
	Bus b1("Mercedes-Benz", 1999,42300);
	Bus b2("Renault",2016,55699);

	std::vector<Vehicule*> garage;

	garage.push_back(&v1);
	garage.push_back(&v2);
	garage.push_back(&b1);
	garage.push_back(&b2);

	


	for (unsigned int i = 0; i < garage.size(); ++i)
	{
		garage[i]->afficher_infos();
		std::cout << "\n"<< std::endl;
	}
	

	garage.clear();
	return 0;
}

