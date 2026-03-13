// Copyright 2022 UNN-CS

#include <gtest/gtest.h>

#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
const double kPi = 3.14159265358979323846;
const double kEps = 1e-9;
}  // namespace

TEST(CircleTest, ConstructorWithZeroRadius) {
  Circle c(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleTest, ConstructorWithPositiveRadius) {
  Circle c(1.0);
  EXPECT_NEAR(c.getRadius(), 1.0, kEps);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi, kEps);
  EXPECT_NEAR(c.getArea(), kPi, kEps);
}

TEST(CircleTest, ConstructorWithLargeRadius) {
  Circle c(10.0);
  EXPECT_NEAR(c.getRadius(), 10.0, kEps);
  EXPECT_NEAR(c.getFerence(), 20.0 * kPi, kEps);
  EXPECT_NEAR(c.getArea(), 100.0 * kPi, kEps);
}

TEST(CircleTest, ConstructorThrowsOnNegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusChangesFerence) {
  Circle c(1.0);
  c.setRadius(2.0);
  EXPECT_NEAR(c.getFerence(), 4.0 * kPi, kEps);
}

TEST(CircleTest, SetRadiusChangesArea) {
  Circle c(1.0);
  c.setRadius(2.0);
  EXPECT_NEAR(c.getArea(), 4.0 * kPi, kEps);
}

TEST(CircleTest, SetRadiusToZero) {
  Circle c(5.0);
  c.setRadius(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleTest, SetRadiusThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setRadius(-2.0), std::invalid_argument);
}

TEST(CircleTest, SetFerenceChangesRadius) {
  Circle c(1.0);
  c.setFerence(2.0 * kPi * 3.0);
  EXPECT_NEAR(c.getRadius(), 3.0, kEps);
}

TEST(CircleTest, SetFerenceChangesArea) {
  Circle c(1.0);
  c.setFerence(2.0 * kPi * 3.0);
  EXPECT_NEAR(c.getArea(), 9.0 * kPi, kEps);
}

TEST(CircleTest, SetFerenceToZero) {
  Circle c(5.0);
  c.setFerence(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleTest, SetFerenceThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaChangesRadius) {
  Circle c(1.0);
  c.setArea(16.0 * kPi);
  EXPECT_NEAR(c.getRadius(), 4.0, kEps);
}

TEST(CircleTest, SetAreaChangesFerence) {
  Circle c(1.0);
  c.setArea(16.0 * kPi);
  EXPECT_NEAR(c.getFerence(), 8.0 * kPi, kEps);
}

TEST(CircleTest, SetAreaToZero) {
  Circle c(5.0);
  c.setArea(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleTest, SetAreaThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setArea(-10.0), std::invalid_argument);
}

TEST(CircleTest, GettersReturnCorrectValuesAfterSeveralChanges) {
  Circle c(2.0);
  c.setFerence(10.0 * kPi);
  EXPECT_NEAR(c.getRadius(), 5.0, kEps);
  EXPECT_NEAR(c.getFerence(), 10.0 * kPi, kEps);
  EXPECT_NEAR(c.getArea(), 25.0 * kPi, kEps);
}

TEST(CircleTest, SettersAreConsistentBetweenEachOther) {
  Circle c(0.0);
  c.setRadius(6.0);

  Circle other(0.0);
  other.setArea(c.getArea());

  EXPECT_NEAR(other.getRadius(), c.getRadius(), kEps);
  EXPECT_NEAR(other.getFerence(), c.getFerence(), kEps);
  EXPECT_NEAR(other.getArea(), c.getArea(), kEps);
}

TEST(TasksTest, EarthRopeGapIsCorrect) {
  const double expected = 1.0 / (2.0 * kPi);
  EXPECT_NEAR(getEarthRopeGap(), expected, kEps);
}

TEST(TasksTest, EarthRopeGapIsBetweenFifteenAndSixteenCentimeters) {
  EXPECT_GT(getEarthRopeGap(), 0.15);
  EXPECT_LT(getEarthRopeGap(), 0.16);
}

TEST(TasksTest, PoolConcreteCostIsCorrect) {
  const double expected = ((16.0 * kPi) - (9.0 * kPi)) * 1000.0;
  EXPECT_NEAR(getPoolConcreteCost(), expected, kEps);
}

TEST(TasksTest, PoolFenceCostIsCorrect) {
  const double expected = 2.0 * kPi * 4.0 * 2000.0;
  EXPECT_NEAR(getPoolFenceCost(), expected, kEps);
}

TEST(TasksTest, PoolConcreteCostIsPositive) {
  EXPECT_GT(getPoolConcreteCost(), 0.0);
}

TEST(TasksTest, PoolFenceCostIsPositive) {
  EXPECT_GT(getPoolFenceCost(), 0.0);
}
