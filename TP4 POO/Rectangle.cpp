#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class Figure
{
public:
	 Figure();
	~Figure();
public:
	 virtual void quiSuisJe() const ;
	 virtual double surface() const = 0;
	
};

Figure::Figure(){}
Figure::~Figure(){}

void Figure::quiSuisJe() const {
	std::cout <<  "je suis une figure" << std::endl;
}




class Ellipse : public Figure
{
protected: 
	double pRayon;
	double gRayon;
public:
	 Ellipse();
	~Ellipse();
	Ellipse(double p, double g);

	double getPrayon() const;
	double getGrayon() const;

	void setPrayon(double p);
	void setGrayon(double g);

	double surfaceE() const;
	void quiSuisJe() const;
};

Ellipse::Ellipse(){}
Ellipse::~Ellipse(){}
Ellipse::Ellipse(double p, double g)
{
	pRayon = p;
	gRayon = g;
}

double Ellipse::getPrayon() const {
	return pRayon;
}

double Ellipse::getGrayon() const {
	return gRayon;
}

void Ellipse::setPrayon(double p) {
	pRayon = p;
}

void Ellipse::setGrayon(double g) {
	gRayon = g;
}

double Ellipse::surfaceE() const {
	return (M_PI * pRayon * gRayon);
}

void Ellipse::quiSuisJe() const {
	std::cout <<  "je suis une ellipse" << std::endl;
}





class Cercle : public Ellipse
{
public:
	 Cercle();
	~Cercle();
	
};






class Rectangle : public Figure
{
protected:
	double largeur;
	double hauteur;

public:	
	Rectangle();
	~Rectangle();
	Rectangle(double l, double h);

	double getLargeur() const;
	double getHauteur() const;

	void setLargeur(double l);
	void setHauteur(double h);

	double surface() const;
	void quiSuisJe() const;
};
Rectangle::Rectangle(){}

Rectangle::~Rectangle(){}

Rectangle::Rectangle(double l, double h)
{
	largeur = l;
	hauteur = h;
}

double Rectangle::getLargeur() const {
	return largeur;
}

double Rectangle::getHauteur() const{
	return hauteur;
}

void Rectangle::setLargeur(double l){
	largeur = l;
}

void Rectangle::setHauteur(double h){
	hauteur = h;
}

double Rectangle::surface() const {
	return largeur*hauteur;
}

void Rectangle::quiSuisJe() const{
	std::cout <<  "Je suis un Rectangle" << std::endl;
}




 class Carre : public Rectangle
 {
 public:
 	Carre(double c);
 	~Carre();
 	void quiSuisJe() const;
 };

 Carre::~Carre(){};
 Carre::Carre(double c)
 {
 	largeur = c;
 	hauteur = c;
 }

 void Carre::quiSuisJe() const{
	std::cout <<  "Je suis un Carré" << std::endl;
}















void afficher (Figure *f){
	f->quiSuisJe();
	std::cout << f->surface() << std::endl;
}




int main(int argc, char const *argv[])
{
	Rectangle r1(2,4);
	Rectangle r2(3,5);
	std::cout << r1.surface() << std::endl;
	r1.setLargeur(3.9);
	std::cout << r1.surface() << std::endl;
	Carre c1(4);
	std::cout << c1.surface() << std::endl;
	r1.quiSuisJe() ;
	c1.quiSuisJe() ;

	
	/*Rectangle *r = new Rectangle(1,8);
	afficher(r);

	Ellipse *e = new Ellipse(11,1);
	afficher(e);*/

	

	std::vector<Figure*> listFig;
	listFig.push_back(&r1);
	listFig.push_back(&r2);
	listFig.push_back(&c1);

	
	std::cout << "liste des figures : "<< std::endl;
	for_each (listFig.begin(), listFig.end(), afficher);
	return 0;
}

// exo 8 : oui, une variable de type rectangle peut désigner un objet de type carre
        // non, une variable de type rectangle ne peut pas désigner un objet de type cercle
        // non, on ne peut pas affecter à un objet de type plus spécifique un objet de type plus général.

