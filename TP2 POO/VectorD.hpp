#ifndef VECTORD_HPP
#define VECTORD_HPP 

#include <string>
#include <fstream>

class VectorD
{

private: // l'encapsulation 
	int V_size;
	double *V_data;

public:

	/// \brief Constructor (truc pour avoir un lien sur la docsygène)
	VectorD(const int &size);
	VectorD(const VectorD &v);

	~VectorD();

public:

	inline int size() const { // on met le const quand la fonction ne change pas l'objet
		return V_size;
	}

	inline double getValue(const int index) const{
		return V_data[index];
	}

	inline void setValue(const int index, const double &value){
		V_data[index] = value;
	}

	double normeV();
	void normalize();

	// Surcharge d'un opérateur 
	// LE +
	VectorD operator+(const VectorD &v2) const;
	// LE =
	VectorD &operator=(const VectorD &v);
	// fstream (dernière question)
	int save(const std::string &filename) const;
};




#endif