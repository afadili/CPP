#include <iostream>
#include <cstdlib>
#include <string>

#include "ImageRGBU8.hpp"
#include "ioPPM.hpp"

int main(int argc, char **argv) {

	// load arguments
	if(argc != 2){
		std::cerr << "usage: " << argv[0] << "image.ppm" << std::endl;
		return EXIT_FAILURE;
	}

	// load image
    ImageRGBU8 image;
	readPPM(argv[1], image);

	// do something
    image.toGreyScale();
    image.drawCircle();

	// save image
	writePPM("output.ppm", image);

	// default image (white)
	writePPM("default.ppm", ImageRGBU8(50,50));
	

	// other filters
    ImageRGBU8 image2;
	readPPM(argv[1], image2);
	image2.threshold(125);
	image2.removeChannel(1);
	image2.removeChannel(2);
	writePPM("red.ppm", image2);

	// read image
	ImageRGBU8 image1;
	readPPM(argv[1], image1);

	// apply filter and save
	Threshold t(100);
	t.applyFilter(image1);
	writePPM("test1.ppm", image1);

	//load image 
	ImageRGBU8 image3;
	readPPM(argv[1], image3);

	// apply filters 
	Filters filters(2);
	Threshold t1(150);
	Threshold t2(100);
	filters.addFilter(t1);
	filters.addFilter(t2);
	filters.applyFilters(image3);

	// filtre de removechannel
	ImageRGBU8 image4;
	readPPM(argv[1], image4);
	RemoveChannel c1(1);
	c1.applyFilter(image4);
	writePPM("test_ex4.ppm", image4);


	// save image 
	writePPM("test_ex3.ppm", image3);

	return(EXIT_SUCCESS);
}
