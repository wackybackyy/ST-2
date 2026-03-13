// Copyright 2022 UNN-CS

#include "tasks.h"

#include "circle.h"

namespace {
const double kEarthRadiusMeters = 6378100.0;
const double kAddedRopeLength = 1.0;

const double kPoolRadius = 3.0;
const double kPathWidth = 1.0;
const double kConcreteCostPerSquareMeter = 1000.0;
const double kFenceCostPerMeter = 2000.0;
}  // namespace

double getEarthRopeGap() {
  Circle earth(kEarthRadiusMeters);
  const double old_ference = earth.getFerence();

  Circle bigger_earth(0.0);
  bigger_earth.setFerence(old_ference + kAddedRopeLength);

  return bigger_earth.getRadius() - earth.getRadius();
}

double getPoolConcreteCost() {
  Circle pool(kPoolRadius);
  Circle pool_with_path(kPoolRadius + kPathWidth);

  const double path_area = pool_with_path.getArea() - pool.getArea();
  return path_area * kConcreteCostPerSquareMeter;
}

double getPoolFenceCost() {
  Circle pool_with_path(kPoolRadius + kPathWidth);
  return pool_with_path.getFerence() * kFenceCostPerMeter;
}
