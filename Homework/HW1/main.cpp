#include <iostream>

#include "../Vector3D/Vector3D.h"

using namespace std;

bool hitSphere(const Point3D &sphereCenter, double radius, const Point3D &rayOrigin, const Vector3D &rayDirection) {
    // Add your HW1 code here, replacing the return statement
    auto a = rayDirection.dot(rayDirection);
    auto aMinusC = rayOrigin-sphereCenter;
    auto b = 2*aMinusC.dot(rayDirection);
    auto c = aMinusC.dot(aMinusC)-(radius*radius);
    auto result = b*b-4*a*c;
    return result > 0;
}

int main(int argc, char** argv) {
    
    // IO Stream Setup

    cout << boolalpha;
    cout << "Testing hitSphere Function" << '\n';

    const Point3D rayOrigin = {0, 0, 0};
    const Vector3D rayDirection = {0, 0, -1};

    // Test One

    const Point3D testOneSphereCenter = {0, 0, -1};
    const double testOneSphereRadius = 0.5;

    const auto testOne = hitSphere(testOneSphereCenter, testOneSphereRadius, rayOrigin, rayDirection);

    cout << "Test One: " << '\n';
    cout << '\t' << "Expected: " << true << '\n';
    cout << '\t' << "Actual: " << testOne << '\n';

    // Test Two

    const Point3D testTwoSphereCenter = {0, 0.50, -1};
    const double testTwoSphereRadius = 0.50;

    const auto testTwo = hitSphere(testTwoSphereCenter, testTwoSphereRadius, rayOrigin, rayDirection);

    cout << "Test Two: " << '\n';
    cout << '\t' << "Expected: " << false << '\n';
    cout << '\t' << "Actual: " << testTwo << '\n';

    // Test Three

    const Point3D testThreeSphereCenter = {0.50, 0.50, -1};
    const double testThreeSphereRadius = 0.50;

    const auto testThree = hitSphere(testThreeSphereCenter, testThreeSphereRadius, rayOrigin, rayDirection);

    cout << "Test Three: " << '\n';
    cout << '\t' << "Expected: " << false << '\n';
    cout << '\t' << "Actual: " << testThree << '\n';

    // Test Four

    const Point3D testFourSphereCenter = {2, 0.50, -2};
    const double testFourSphereRadius = 0.49;

    const auto testFour = hitSphere(testFourSphereCenter, testFourSphereRadius, rayOrigin, rayDirection);

    cout << "Test Four: " << '\n';
    cout << '\t' << "Expected: " << false << '\n';
    cout << '\t' << "Actual: " << testFour << '\n';

    // Test Five

    const Point3D testFiveSphereCenter = {1000, 0.50, -100};
    const double testFiveSphereRadius = 0.50;

    const auto testFive = hitSphere(testFiveSphereCenter, testFiveSphereRadius, rayOrigin, rayDirection);

    cout << "Test Five: " << '\n';
    cout << '\t' << "Expected: " << false << '\n';
    cout << '\t' << "Actual: " << testFive << '\n';

    return 0;
}
