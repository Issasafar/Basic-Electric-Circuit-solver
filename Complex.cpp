//
// Created by issa on 21/04/24.
//
#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    float real, imag, angle, radius;
public:
    string toString() {
        return "real= " + to_string(this->real) + ", imag = " +
               to_string(this->imag) +
               ", radius = " + to_string(this->radius) + ", angle = " +
               to_string(this->angle);
    }

    Complex() {}

    Complex operator+(Complex &other) {
        Complex result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        result.cartesianToPolar();
        return result;
    }
    //TODO() overload other operators here :)

    void polarToCartesian() {
        this->real = this->radius * cos(angle);
        this->imag = this->radius * sin(angle);
    }

    void cartesianToPolar() {
        this->radius = sqrt(pow(real, 2) + pow(imag, 2));
    }

    Complex(float arg1, float arg2, bool isPolar) {
        if (!isPolar) {
            this->real = arg1;
            this->imag = arg2;
            cartesianToPolar();
        } else {
            this->radius = arg1;
            this->angle = arg2;
            polarToCartesian();
        }
    }

    float getReal() const {
        return real;
    }

    void setReal(float real) {
        Complex::real = real;
    }

    float getImag() const {
        return imag;
    }

    void setImag(float imag) {
        Complex::imag = imag;
    }

    float getAngle() const {
        return angle;
    }

    void setAngle(float angle) {
        Complex::angle = angle;
    }

    float getRadius() const {
        return radius;
    }

    void setRadius(float radius) {
        Complex::radius = radius;
    }
};


