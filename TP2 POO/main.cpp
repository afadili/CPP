#include <iostream>
#include "VectorD.hpp"
#include <cstdio>

int main(int argc, char const *argv[])
{
	VectorD Vec(3);
	//Vec.V_data[0]= 10;
	//std::cout << Vec.V_size << std::endl;
	/* code */
	VectorD vec2 (Vec);
	VectorD vec3 (Vec);
	VectorD Vadd (Vec);
	//std::cout << vec2.V_size << std::endl;
	std::cout << vec2.size() << std::endl;
	vec2.setValue(1,25);
	vec3.setValue(1,10);
	std::cout << "value is : " << vec2.getValue(1) <<std::endl;
	std::cout << "norme is : " << vec2.normeV() << std::endl;
	//vec2.normalize();
	std::cout << "vector normalized !" << std::endl;
	std::cout << "addition :  vec2 + vec3 = ";
	Vadd = vec2+vec3;
	std::cout << Vadd.getValue(0) << std::endl;
	std::cout << Vadd.getValue(1) << std::endl;
	std::cout << Vadd.getValue(2) << std::endl;

	Vec.save("sortie.txt");

	return 0;
}