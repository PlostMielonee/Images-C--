#include <iostream>
#include <cmath>
#include <fstream>

using std::sqrt;

#ifndef VEC3_H
#define VEC3_H

class vector3 { // 3-dimensional vector class *(X Y Z) 
public:
    double p[3]; // Location of vector 

    vector3() : p{0,0,0} {}  // Constructor: xyz set to 0
    vector3(double p0, double p1, double p2) : p{p0, p1, p2} {}

    double x() const { return p[0]; }
    double y() const { return p[1]; }
    double z() const { return p[2]; }

     // Unary minus operator
    vector3 operator-() const { return vector3(-p[0], -p[1], -p[2]); }
    double operator[](int i) const { return p[i]; }

     // Compound assignment operators
    vector3& operator+=(const vector3& v) {
        p[0] += v.p[0];
        p[1] += v.p[1];
        p[2] += v.p[2];
        return *this;
    }

    vector3& operator*=(double a) {
        p[0] *= a;
        p[1] *= a;
        p[2] *= a;
        return *this;
    }

    vector3& operator/=(double a) {
        return *this *= 1/a;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return p[0]*p[0] + p[1]*p[1] + p[2]*p[2];
    }

    using point3 = vector3;


    // Binary arithmetic operators
    
    friend std::ostream& operator<<(std::ostream& out, const vector3& v) {
        return out << v.p[0] << ' ' << v.p[1] << ' ' << v.p[2];
    }

    friend vector3 operator+(const vector3& u, const vector3& v) {
        return vector3(u.p[0] + v.p[0], u.p[1] + v.p[1], u.p[2] + v.p[2]);
    }

    friend vector3 operator-(const vector3& u, const vector3& v) {
        return vector3(u.p[0] - v.p[0], u.p[1] - v.p[1], u.p[2] - v.p[2]);
    }

    friend vector3 operator*(const vector3& u, const vector3& v) {
        return vector3(u.p[0] * v.p[0], u.p[1] * v.p[1], u.p[2] * v.p[2]);
    }

    friend vector3 operator*(double a, const vector3& v) {
        return vector3(a * v.p[0], a * v.p[1], a * v.p[2]);
    }

    friend vector3 operator*(const vector3& v, double t) {
        return t * v;
    }

    friend vector3 operator/(const vector3& v, double t) {
        return (1/t) * v;
    }
};

#endif // VEC3_H
