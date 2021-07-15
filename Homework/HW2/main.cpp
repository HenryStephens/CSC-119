#include <iostream>
#include <math.h>
#include "../Vector3D/Vector3D.h"

using namespace std;
double hitSphere(const Point3D &sphereCenter, double radius, const Point3D &rayOrigin, const Vector3D &rayDirection) {
  const auto a = rayDirection.dot(rayDirection);
  const auto aMinusC = rayOrigin-sphereCenter;
  const auto b = (2*aMinusC.dot(rayDirection));
  const auto c = aMinusC.dot(aMinusC)-radius*radius;
  const auto discriminant = (b*b)-(4*a*c);
  const auto t = (-b) - sqrt(discriminant) / (2 * a);
    if (discriminant < 0 && t < 0) {
        return t;
    } else {
        throw "Ray Missed Sphere!"s;
    }
}

Vector3D determineBounceVector(const Point3D &sphereCenter, double radius, const string& sphereMaterial, const Point3D &rayOrigin, const Vector3D &rayDirection) {
  // Add your HW2 code here, replacing the return statement  
  const double t = hitSphere(sphereCenter, radius, rayOrigin, rayDirection);
  const Vector3D P = rayOrigin + t * rayDirection;
  const Vector3D N = (P - sphereCenter) / radius;
  
  Vector3D bounce;

  if(sphereMaterial == "diffuse"){
      bounce = N + makeRandomUnitVector();
  } else if (sphereMaterial == "metal"){
      bounce = rayDirection - 2 * rayDirection.dot(N) * N;
  } else if (sphereMaterial == "glass"){
      const auto perpendicularBounce = 1.5 * (rayDirection + -rayDirection.dot(N) * N);
      bounce = perpendicularBounce + -sqrt(abs(1 - perpendicularBounce.length() * perpendicularBounce.length())) * N;
  } else {
      throw "Unrecognized Material"s;
  }
return bounce.normalize();
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

    double testOneT;
    try {
        testOneT = hitSphere(testOneSphereCenter, testOneSphereRadius, rayOrigin, rayDirection);
    } catch (...) {
        testOneT = -1;
    }

    cout << "Test One: " << '\n';
    cout << '\t' << "Expected: " << 0.5 << '\n';
    cout << '\t' << "Actual: " << testOneT << '\n';

    // Test Two

    const Point3D testTwoSphereCenter = {0, 0.50, -1};
    const double testTwoSphereRadius = 0.50;

    double testTwoT;
    try {
        testTwoT = hitSphere(testTwoSphereCenter, testTwoSphereRadius, rayOrigin, rayDirection);
    } catch (...) {
        testTwoT = -1;
    }
    
    cout << "Test Two: " << '\n';
    cout << '\t' << "Expected: " << -1 << '\n';
    cout << '\t' << "Actual: " << testTwoT << '\n';

    // Test Three
    
    const Point3D testThreeSphereCenter = {0, 0, -1};
    const double testThreeSphereRadius = 0.50;
    const string testThreeSphereMaterial = "metal";

    try {
        const Vector3D testThreeT = determineBounceVector(testThreeSphereCenter, testThreeSphereRadius, testThreeSphereMaterial, rayOrigin, rayDirection);
        cout << "Test Three: " << '\n';
        cout << '\t' << "Expected: " << "{0, 0, 1}" << '\n';
        cout << '\t' << "Actual: " << testThreeT << '\n';
    } catch (...) {
        cout << "Test Three Incorrectly Threw An Error" << '\n';
    }

    // Test Four

    const Point3D testFourSphereCenter = {0, 0, -1};
    const double testFourSphereRadius = 0.50;
    const string testFourSphereMaterial = "glass";

    try {
        const Vector3D testFourT = determineBounceVector(testFourSphereCenter, testFourSphereRadius, testFourSphereMaterial, rayOrigin, rayDirection);
        cout << "Test Four: " << '\n';
        cout << '\t' << "Expected: " << "{0, 0, -1}" << '\n';
        cout << '\t' << "Actual: " << testFourT << '\n';
    } catch (...) {
        cout << "Test Four Incorrectly Threw An Error" << '\n';
    }

    return 0;
}