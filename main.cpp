#include <iostream>


#include <cmath>
#include <fstream>

using std::sqrt;
/*
#ifndef VEC3_H
#define VEC3_H
class vector3{
public:
    double p[3];

    vector3() : p{0,0,0} {}
    vector3(double p0,double p1,double p2) : p{p0, p1, p2} {}

    double x() const { return p[0]; }
    double y() const { return p[1]; }
    double z() const { return p[2]; }

    vector3 operator-() const { return vector3(-p[0], -p[1], -p[2]);}
    double operator[](int i) const { return p[i]; }


    double& operator+=(const vector3& v){
        p[0] += v.p[0];
        p[1] += v.p[1];
        p[2] += v.p[2];
    }

    vector3 operator*=(double a){
            p[0] *= v.p[0];
            p[1] *= v.p[1];
            p[2] *= v.p[2];
            return *this;
    }

    vector3 operator*=(double a){
        return *this *= 1/a;
    }


    double length_squared() const {
        return p[0]*p[0] + p[1]*p[1] + p[2]*p[2];
    }
    
    
 //   double lenght() const {
   //     return sqrt(lenght_squared());
   // }


    using point3 = vector3;
    

   // inline std::ostream& operator<<(std::ostream& out, const vector3 v){
   //     return out << v.p[0] << ' ' << v.p[1] << " " << v.p[2] << ' ';
//


    //}
/


};

#endif // VEC3_H closes this conditional inclusion block.
*/
int main() {

    int image_width = 1256;
    int image_height = 1256;

 
    std::string filename = "result.ppm";

    std::ofstream ppm_file(filename);
    
    ppm_file << "P3\n" << image_width << ' ' << image_height << "\n255\n";
     for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            ppm_file << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
     std::clog << "\rDone.                 \n";

    ppm_file.close();
    
    std::cout << "PPM file generated successfully: " << filename << std::endl;

    return 0;
}
