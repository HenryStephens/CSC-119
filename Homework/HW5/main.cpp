#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>
#include <chrono>

#include "../Vector3D/Vector3D.h"

using namespace std;

<<<<<<< HEAD
int main(int argc, char** argv) {
=======
struct Sphere {
    Point3D center;
    double radius;
    Color albedo;
    string material;
};

struct Ray {
    Point3D origin;
    Vector3D direction;
    Sphere closestSphere;
    double distanceToClosestSphere = std::numeric_limits<double>::max();
};

double hitSphere(const Ray &ray, const Sphere &sphere) {
  const auto a = ray.direction.dot(ray.direction);
  const auto aMinusC = ray.origin-sphere.center;
  const auto b = (2*aMinusC.dot(ray.direction));
  const auto c = aMinusC.dot(aMinusC)-sphere.radius*sphere.radius;
  const auto discriminant = (b*b)-(4*a*c);
  const auto t = (-b) - sqrt(discriminant) / (2 * a);
    if (discriminant < 0 && t < 0) {
        return t;
    } else {
        throw "Ray Missed Sphere!"s;
    }
}

Ray determineBounceRay(const Ray &ray, const Sphere &sphere) {  
  const double t = hitSphere(ray, sphere);
  const Vector3D P = ray.origin + t * ray.direction;
  const Vector3D N = (P - sphere.center) / sphere.radius;
  
  Vector3D bounce;

  if(sphere.material == "diffuse"){
      bounce = N + makeRandomUnitVector();
  } else if (sphere.material == "metal"){
      bounce = ray.direction - 2 * ray.direction.dot(N) * N;
  } else if (sphere.material == "glass"){
      const auto perpendicularBounce = 1.5 * (ray.direction + -ray.direction.dot(N) * N);
      bounce = perpendicularBounce + -sqrt(abs(1 - perpendicularBounce.length() * perpendicularBounce.length())) * N;
  } else if (sphere.material == "light"){
      throw "Light"s;
  } else {
      throw "Unrecognized Material"s;
  }
    return {P + bounce.normalize() * 0.01, bounce.normalize()};;
}

Color calculatePixelColor(const Ray &ray){
    const Sphere sphere = {{0, 0, -5}, 2, {255, 0, 0}, "diffuse"};
    
    try{
        determineBounceRay(ray, sphere);
        return sphere.albedo / 255;
    } catch(...) {
        return {0, 0, 0};
    }
}

int main(int argc, char** argv) {

if(argc != 3) {
        cerr << "Usage: ./a.out" << " " << "[Driver File]" << " " << "[Output File]" << '\n';
        return 1;
    }

    int imageWidth;
    double aspectRatio;
    Vector3D eye;
    int viewportWidth;
    double focalLength;

       ifstream in(argv[1]);
        
        if(!in){
            cerr << "Input stream broken\n"; //error check
        }
        for(string line, token; getline(in, line);){
            stringstream ss(line);
            getline(ss, token, ' ');

            if(token == "imageWidth"){ //If line starts with "imageWidth"
                getline(ss, token, ' '); imageWidth = stoi(token); //String to int
                cout << "imageWidth: " << imageWidth << "\n";
            } else if(token == "aspectRatio"){ //Token = aspectRatio
                getline(ss, token, ' '); double widthRatio = stod(token); //Pulls widthRatio from input.
                getline(ss, token, ' '); double heightRatio = stod(token); //Pulls heightRatio from input.
                aspectRatio = heightRatio / widthRatio;
                cout << "aspectRatio: " << aspectRatio << "\n"; 
            } else if (token == "eye"){
                getline(ss, token, ' '); const double xCord = stod(token);
                getline(ss, token, ' '); const double yCord = stod(token);
                getline(ss, token, ' '); const double zCord = stod(token);
                eye = {xCord, yCord, zCord};
                cout << "eye: " << eye << "\n";
            } else if (token == "viewportWidth"){
                getline(ss, token, ' '); viewportWidth = stoi(token);
                cout << "viewportWidth: " << viewportWidth << "\n";
            }  else if (token == "focalLength"){
                getline(ss, token, ' '); focalLength = stod(token);
                cout << "focalLength: " << focalLength << "\n";
            } else{
                continue;
            } 
        }
        
    //Output file
    ofstream output(argv[2]);

        const int imageHeight = imageWidth*aspectRatio;
        const double viewportHeight = viewportWidth*aspectRatio;
        Vector3D horizontal = {static_cast<double>(viewportWidth),0, 0};
        Vector3D vertical = {0, viewportHeight, 0};
        Vector3D distance = {0, 0, focalLength};
        Point3D topLeftCorner = eye - horizontal / 2 + vertical / 2 - distance;
        

        output << "P3\n";
        output << imageWidth << ' ' << imageHeight << ' ' << 255 << "\n";
        
    
    for(double i = 0; i < imageHeight; i++){
        for (double j = 0; j < imageWidth; j++){

            auto u = j / imageWidth;
            auto v = i / imageHeight;

            Point3D rayOrigin = eye;
            Vector3D rayDirection = (topLeftCorner + u * horizontal - v * vertical).normalize();
                Color color = calculatePixelColor;
                //color = {red, green, blue}
                if(color[0] > 255){ color[0] = 255;}
                if(color[1] > 255){ color[1] = 255;}
                if(color[2] > 255){ color[2] = 255;}

                if(color[0] < 0){color[0] = 0;}
                if(color[1] < 0){color[1] = 0;}
                if(color[2] < 0){color[2] = 0;}
                
                output << static_cast<int>(color[0]) << " " << static_cast<int>(color[1]) << " " << static_cast<int>(color[2]);

                if( j < imageWidth - 1){
                    output << " ";
                } else {
                    output << "\n";
                }
            }
        }
>>>>>>> 7-15-2021
    return 0;
    }

