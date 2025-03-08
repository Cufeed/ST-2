// Copyright 2022 UNN-CS
#include <utility>
#include "circle.h"
#include "tasks.h"
double calculateRopeGap() {
    const double earthRadiusKm = 6378.1;
    const double earthRadiusMeters = earthRadiusKm * 1000;
    Circle earth(earthRadiusMeters);
    earth.setFerence(earth.getFerence() + 1.0);
    return earth.getRadius() - earthRadiusMeters;
}

std::pair<double, double> calculatePoolCosts() {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;
    const double outerRadius = poolRadius + pathWidth;

    Circle inner(poolRadius);
    Circle outer(outerRadius);

    double concreteCost = (outer.getArea() - inner.getArea()) * 1000.0;
    double fenceCost = outer.getFerence() * 2000.0;

    return { concreteCost, fenceCost };
}
