#include <iostream>
#include <cmath>
#include <fstream>
#include "vector3.h"
#include "color.h"



int main() {


    //image settings
    int image_width = 1256;
    int image_height = 1256;

 
    std::string filename = "result.ppm"; //output
    std::ofstream ppm_file(filename);
    

     for (int j = 0; j < image_height; ++j) {
      std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i)/(image_width-1),double(j)/(image_height-1),0);\
            draw_color(std::cout,pixel_color);
        }
    }
     std::clog << "\rDone.                 \n";

    ppm_file.close();
    
    std::cout << "PPM file generated successfully: " << filename << std::endl;

    return 0;
}
