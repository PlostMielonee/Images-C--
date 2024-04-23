#ifndef COLOR_H
#define COLOR_H
#include "vector3.h"

#include <iostream>


using color = vector3;

void draw_color(std::ostream& out, const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);


    out << rbyte << " " << gbyte << " " << bbyte << "\n";
}
#endif