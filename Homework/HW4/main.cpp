#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
<<<<<<< HEAD

=======
>>>>>>> save
#include "../Vector3D/Vector3D.h"

using namespace std;

<<<<<<< HEAD
=======
Color calculatePixelColor(const Point3D &rayOrigin, const Vector3D &rayDirection){
    double red = abs(rayDirection[0]) * 255 - 50;
    double green = abs(rayDirection[1]) * 255 - 50;
    double blue = abs(rayDirection[2]) * 255 - 50;

    return {red, green, blue};
}

>>>>>>> save
int main(int argc, char** argv) {

    if(argc != 3) {
        cerr << "Usage: ./a.out" << " " << "[Driver File]" << " " << "[Output File]" << '\n';
        return 1;
    }
<<<<<<< HEAD
    
    return 0;
}
=======

    int imageWidth;
    double aspectRatio;
    Vector3D eye;
    int viewportWidth;
    double focalLength;

       //Reading the File
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
    ofstream output(argv[2]); //Opens a stream to write a file

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
                Color color = calculatePixelColor(rayOrigin, rayDirection);
                //color = {red, green, blue
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
    return 0;
    }
>>>>>>> save
