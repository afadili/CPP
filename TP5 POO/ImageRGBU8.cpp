#include <algorithm> // min

#include "ImageRGBU8.hpp"


ImageRGBU8::ImageRGBU8() : _width(0), _height(0)
{
}


ImageRGBU8::ImageRGBU8(const unsigned int w, const unsigned int h)
 : _width(w), _height(h), _data(std::vector<unsigned char>(w*h*3))
{
    // fill with the default color
    std::fill(_data.begin(), _data.end(), 255);
}


ImageRGBU8::ImageRGBU8(const unsigned int w,const unsigned int h, const std::vector<unsigned char> data) 
: _width(w), _height(h), _data(data)
{
    if(_width*_height*3 != _data.size())
        std::cerr << "ImageRGBU8 : error : constuctor from vector : invalide vector size." << std::endl; 
}


ImageRGBU8::~ImageRGBU8() 
{
}


void ImageRGBU8::toGreyScale() {
    for(unsigned int i=0; i<_width*_height*3; i+=3) {
        unsigned char moy = (int(_data[i])+int(_data[i+1])+int(_data[i+2]))/3;
        _data[i] = _data[i+1] = _data[i+2] = moy;
    }
}


void ImageRGBU8::drawCircle(const unsigned char r, const unsigned char g, const unsigned char b)
{
    int radius = std::min(_width,_height) / 2;
    int squaredRadius = radius * radius;
    int centerX = _width / 2;
    int centerY = _height / 2;

    // fill the circle
    for(int x=0; x<(int)_width; ++x)
        for(int y=0; y<(int)_height; ++y)
            if( (x-centerX)*(x-centerX) + (y-centerY)*(y-centerY) < squaredRadius ){
                (*this)(x,y,0) = r;
                (*this)(x,y,1) = g;
                (*this)(x,y,2) = b;
            }
}


void ImageRGBU8::removeChannel(const unsigned int channel)
{
    for(int x=0; x<(int)_width; ++x)
        for(int y=0; y<(int)_height; ++y)
            (*this)(x,y,channel) = 0;
}


void ImageRGBU8::threshold(const unsigned char threshold)
{
    for(unsigned int i=0; i<_width*_height*3; i+=3){
        unsigned char value = (int(_data[i]) + int(_data[i+1]) + int(_data[i+2])) / 3;
        if(value < threshold)
            _data[i] = _data[i+1] = _data[i+2] = 0;
        else
            _data[i] = _data[i+1] = _data[i+2] = 255;
    }
}

Threshold::Threshold(unsigned char t) : threshold(t) {} 
Threshold::~Threshold(){}

void Threshold::applyFilter(ImageRGBU8 &image) const 
{
    image.threshold(threshold);
}

void Filters::addFilter(Filter &filter)
{
    f[nbFilters] = &filter;
    nbFilters++;
}


void Filters::applyFilters(ImageRGBU8 &image)
{
    for (unsigned int i=0; i<nbFilters; i++)
    {
        f[i]->applyFilter(image);

    }

}

Filters::Filters(unsigned int taille)
{
    f = new Filter*[taille];
    size = taille;
    nbFilters = 0;
}

Filters::~Filters()
{
    delete[] f;
}

void RemoveChannel::applyFilter(ImageRGBU8 &image) const
{
    image.removeChannel(channel);
}
    
RemoveChannel::RemoveChannel(unsigned int c) : channel(c) {}

RemoveChannel::~RemoveChannel(){}
