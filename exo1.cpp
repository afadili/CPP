#include <iostream>
//------------------------Véhicule--------------------------------------
class Vehicule 
{
public: 
	// 3 attributs 
	std::string marque;
	int date_achat;
	int prix_achat;
public:
	Vehicule(std::string _marque, int date, int prix); // Constructeur 
	virtual void afficher_infos() = 0;
	std::string getMarque();
	int getDate_achat();
	int getPrix_achat();
	~Vehicule(){};
};

Vehicule::Vehicule(std::string _marque, int date, int prix)
{
	_marque = marque;
	date = date_achat;
	prix = prix_achat;
}
void Vehicule::afficher_infos()
{
	std::cout << marque << date_achat << prix_achat << std::endl;
}

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

//------------------------Voiture--------------------------------------

class Voiture : public Vehicule
{
protected:
	std::string marqueV;
	int dateV;
	int prixV;
public:
	void afficher_infos() override;
	Voiture();
	~Voiture();
};

Voiture::Voiture(){};
Voiture::~Voiture(){};

void Voiture::afficher_infos()
{
	std::cout << marqueV << dateV << prixV << std::endl;
}

//------------------------Bus-------------------------------------------

class Bus : public Vehicule
{
protected:
	std::string marqueB;
	int dateB;
	int prixB;
public:
	void afficher_infos() override;
	Bus(){};
	~Bus(){};
};

void Bus::afficher_infos()
{
	std::cout << marqueB << dateB << prixB << std::endl;
}

void afficher(Vehicule *v)
{
	v->afficher_infos();
}

//------------------------Main------------------------------------------

int main(int argc, char const *argv[])
{
	Voiture v1("BM", 2010, 10000);
	Bus b1("OPEL", 2004, 4100);
	std::vector<Vehicule*> garage;

	Vehicule.push_back(&v1);
	Vehicule.push_back(&b1);

	std::cout << "liste des véhicules : "<< std::endl;
	for_each (garage.begin(), garage.end(), afficher_infos);
	return 0;
}