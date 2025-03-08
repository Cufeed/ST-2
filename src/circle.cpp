// Copyright 2022 UNN-CS

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "circle.h"
#include <cmath>
#include <stdexcept>
Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    radius = r;
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    ference = 2 * M_PI * r;
    area = M_PI * r * r;
}

void Circle::setFerence(double f) {
    ference = f;
    if (f < 0) {
        throw std::invalid_argument("Ference cannot be negative");
    }
    radius = f / (2 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::setArea(double a) {
    area = a;
    if (a < 0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    radius = sqrt(a / M_PI);
    ference = 2 * M_PI * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
