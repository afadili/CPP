#ifndef IMAGERGBU8_HPP
#define IMAGERGBU8_HPP 

#include <iostream>
#include <vector> 


class ImageRGBU8
{
private:
	unsigned int _width;
	unsigned int _height;
	std::vector <unsigned char> _data; // tableau ou vont etre stockés le R, V, et B
	// on utilise un unsigned char parce que c un entier entre 0 et 255 (comme les couleurs)
public:
	 ImageRGBU8(const unsigned int width, const unsigned int height);
	 ImageRGBU8();
	~ ImageRGBU8();
	inline unsigned int width()const { return _width; }
	inline unsigned int height()const { return _height; }
	inline const unsigned char &operator()(const unsigned int x, const unsigned int y, const unsigned int c)const{ return _data[(y*_width+x)*3+c];}
	inline unsigned char &operator()(const unsigned int x, const unsigned int y, const unsigned int c){return _data[(y*_width+x)*3+c];}	
	ImageRGBU8(const unsigned int width, const unsigned int height, const std::vector<unsigned char> &data);
};

#endif
