#include "VectorD.hpp"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <fstream>


VectorD::VectorD(const int &size):V_size(size)
{
	/*if (size <=0)
	{
		V_size = 0;
		return;
	}*/
	V_data = new double(size);
}

// alternative du constructor 
VectorD::VectorD(const VectorD &v) : VectorD(v.V_size)
{
	//V_data = new double(V_size);
	std::copy(V_data, V_data+V_size, V_data);
}

VectorD::~VectorD()
{
	delete[]V_data;
}

double VectorD::normeV(){
	double n=0;
	for (int i=0; i<V_size; i++)
	{
		n += V_data[i]*V_data[i];
	}
	n = sqrt(n);
	return n;
}

void VectorD::normalize(){

	for (int i=0; i<V_size; i++)
	{
		V_data[i] = V_data[i]/normeV();
	}
}

VectorD VectorD::operator+(const VectorD &v2) const{
	if (V_size != v2.V_size){
		std::cerr << "error : VectorD::operator+(const VectorD &v2) const" << std::endl;
		return *this;
	}
	VectorD Vadd(V_size);
	for (int i=0; i<V_size; i++)
	{
		Vadd.V_data[i] = V_data[i] + v2.V_data[i];
		// std::transform(V_data,V_data+V_size,v2.V_data,Vadd.V_data std::plus<double>()); avec #include<algorithm>
	}
	std::cout << Vadd.getValue(1) << std::endl;
	return Vadd;
}

VectorD &VectorD::operator=(const VectorD &v){
	if (&v == this) return *this;
	//std::cout <<"premier if ignored" << std::endl;
	if (v.V_size != V_size){
		std::cerr << "error VectorD operator=(const VectorD &v)" << std::endl;
		return *this;
	}
	//std::cout <<"deuxième if ignored" << std::endl;
	std::copy(v.V_data,v.V_data+v.V_size,V_data);
	std::cout <<"operator = " << this->getValue(0) << std::endl;
	std::cout <<"operator = " << this->getValue(1) << std::endl;
	std::cout <<"operator = " << this->getValue(2) << std::endl;
	return *this;
}

int VectorD::save(const std::string &filename) const 
{
	std::ofstream myFile;
	myFile.open(filename, std::ios::out);
	if(!myFile.is_open())
	{
		std::cerr << "Error : à l'ouverture du fichier " << filename << std::endl;
		return EXIT_FAILURE;
	}
	myFile << V_size << std::endl;
	for (int i = 0; i<V_size; ++i)
	{
		myFile << V_data[i] << " ";
	}
	myFile.close();
	return EXIT_SUCCESS;
}
