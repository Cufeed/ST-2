// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <corecrt_math_defines.h>
#include "circle.h"
#include "tasks.h"
#include <cstdint>


TEST(CircleTest, ConstructorInitialization) {
    Circle c(2.0);
    EXPECT_DOUBLE_EQ(2.0, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * M_PI * 2.0, c.getFerence());
    EXPECT_DOUBLE_EQ(M_PI * 4.0, c.getArea());
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(3.0, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * M_PI * 3.0, c.getFerence());
    EXPECT_DOUBLE_EQ(M_PI * 9.0, c.getArea());
}

TEST(CircleTest, SetFerence) {
    Circle c(0.0);
    c.setFerence(2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(5.0, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * M_PI * 5.0, c.getFerence());
    EXPECT_DOUBLE_EQ(M_PI * 25.0, c.getArea());
}

TEST(CircleTest, SetArea) {
    Circle c(0.0);
    c.setArea(M_PI * 36.0);
    EXPECT_DOUBLE_EQ(6.0, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * M_PI * 6.0, c.getFerence());
    EXPECT_DOUBLE_EQ(M_PI * 36.0, c.getArea());
}

TEST(CircleTest, SetRadiusNegative) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetFerenceNegative) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaNegative) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusZero) {
    Circle c(1.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(1.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetAreaZero) {
    Circle c(1.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetRadiusPrecision) {
    Circle c(1.0);
    c.setRadius(1.23456789);
    EXPECT_NEAR(1.23456789, c.getRadius(), 1e-9);
    EXPECT_NEAR(2 * M_PI * 1.23456789, c.getFerence(), 1e-9);
    EXPECT_NEAR(M_PI * 1.23456789 * 1.23456789, c.getArea(), 1e-9);
}

TEST(CircleTest, SetFerencePrecision) {
    Circle c(1.0);
    c.setFerence(6.283185307);
    EXPECT_NEAR(1.0, c.getRadius(), 1e-9);
    EXPECT_NEAR(6.283185307, c.getFerence(), 1e-9);
    EXPECT_NEAR(M_PI * 1.0 * 1.0, c.getArea(), 1e-9);
}

TEST(CircleTest, SetAreaPrecision) {
    Circle c(1.0);
    c.setArea(3.141592654);
    EXPECT_NEAR(1.0, c.getRadius(), 1e-9);
    EXPECT_NEAR(2 * M_PI * 1.0, c.getFerence(), 1e-9);
    EXPECT_NEAR(3.141592654, c.getArea(), 1e-9);
}

TEST(TasksTest, RopeGap) {
    double gap = calculateRopeGap();
    EXPECT_NEAR(1.0 / (2 * M_PI), gap, 1e-6);
}

TEST(TasksTest, RopeGapPrecision) {
    double gap = calculateRopeGap();
    EXPECT_NEAR(0.159154943, gap, 1e-9);
}

TEST(TasksTest, PoolCostsConcrete) {
    auto [concrete, fence] = calculatePoolCosts();
    double expectedConcrete = M_PI * 7.0 * 1000.0;
    EXPECT_NEAR(expectedConcrete, concrete, 1e-6);
}

TEST(TasksTest, PoolCostsFence) {
    auto [concrete, fence] = calculatePoolCosts();
    double expectedFence = 8 * M_PI * 2000.0;
    EXPECT_NEAR(expectedFence, fence, 1e-6);
}

TEST(TasksTest, PoolCostsTotal) {
    auto [concrete, fence] = calculatePoolCosts();
    double expectedTotal = M_PI * 7.0 * 1000.0 + 8 * M_PI * 2000.0;
    EXPECT_NEAR(expectedTotal, concrete + fence, 1e-6);
}

TEST(TasksTest, PoolCostsZeroWidth) {
    const double poolRadius = 3.0;
    const double pathWidth = 0.0;
    const double outerRadius = poolRadius + pathWidth;

    Circle inner(poolRadius);
    Circle outer(outerRadius);

    double concreteCost = (outer.getArea() - inner.getArea()) * 1000.0;
    double fenceCost = outer.getFerence() * 2000.0;

    EXPECT_DOUBLE_EQ(0.0, concreteCost);
    EXPECT_DOUBLE_EQ(2 * M_PI * 3.0 * 2000.0, fenceCost);
}

TEST(TasksTest, PoolCostsLargeWidth) {
    const double poolRadius = 3.0;
    const double pathWidth = 10.0;
    const double outerRadius = poolRadius + pathWidth;

    Circle inner(poolRadius);
    Circle outer(outerRadius);

    double concreteCost = (outer.getArea() - inner.getArea()) * 1000.0;
    double fenceCost = outer.getFerence() * 2000.0;

    EXPECT_NEAR(M_PI * (169.0 - 9.0) * 1000.0, concreteCost, 1e-6);
    EXPECT_NEAR(2 * M_PI * 13.0 * 2000.0, fenceCost, 1e-6);
}
