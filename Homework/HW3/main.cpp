#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "../Vector3D/Vector3D.h"

using namespace std;

int main(int argc, char** argv) {

    if(argc != 3) {
        cerr << "Usage: ./a.out" << " " << "[Driver File]" << " " << "[Output File]" << '\n';
        return 1;
    }

    //Reading the File
    ifstream in(argv[1]);
        if(!in){
            cerr << "Input stream broken\n";
        }

        int imageWidth;
        int imageHeight;
        double aspectRatio; 

        for(string line, token; getline(in, line);){
            stringstream ss(line);
            getline(ss, token, ' '); //Grab first part of line
            cout << "First: " << token << "\n";
            getline(ss, token); //Go to second thing in token
            cout << "Second: " << token << "\n";


            if(token == "imageWidth"){
                getline(ss, token);
                cout << token << "\n";
                imageWidth = stoi(token); //String to Int
                imageHeight = stod(token); //String to Double
            }else if(token == "aspectRatio"){ //Token = aspectRatio
                getline(ss, token);
                cout << "ai:" << token << "\n";
                getline(ss, token);
                cout << "ai:" << token << "\n";
                imageHeight = stod(token); //String to Double
                double aspectRatio = imageHeight / imageWidth;
            }else {
                continue;
            }
            
        }
        
    //Output file
    ofstream output(argv[2]); //Opens a stream to write a file

        output << "P3\n";

        output << imageWidth << ' ' << imageHeight << ' ' << 255;
        
        const int imageHeight = imageWidth*aspectRatio;
        double row = 0;
        double column = 0;
    
    for(int i = 0; i < imageHeight; i++){
        output << "\n";
        for (int j = 0; j < imageWidth; j++){
        //cout << "red" << "green" << "blue";
                double red = (row/256)*255;
                double green = (column/256)*255;
                double blue = 64;
                output << static_cast<int>(red) << ' ' << static_cast<int>(green) << ' ' << static_cast<int>(blue) << ' ' ;
                }
            }
    return 0;
    }