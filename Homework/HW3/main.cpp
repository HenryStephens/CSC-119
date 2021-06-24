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
        int ImageHeight;


        for(string line, token; getLine(in, line);){
            stringstream ss(line);
            getLine(ss, token, ' '); //Grab first part of line
            cout << "First: " << token << "\n";
            getLine(ss, token); //Go to second thing in token
            cout << "Second: " << token << "\n";
            if(token == "imageWidth"){
                getLine(ss, token);
                cout << token << "\n";
                imageWidth = stoi(token); //String to Int
                double imageHeight = stod(token); //String to Double
            }

            if(token == "aspectRatio"){ //Token = aspectRatio
                getLine(ss, token);
                cout << "ai:" << token << "\n";
                getLine(ss, token);
                cout << "ai:" << token << "\n";
                double imageHeight = stod(token); //String to Double
                double aspectRatio = widthRatio / heightRatio;
            }
            
        }
    //Output file
    //output.ppm
    ofstream output(argv[2]); //Opens a stream to write a file

        output << "P3\n";

        output << imageWidth << ' ' << ImageHeight << ' ' << 255 << "\n";


    }
    
    return 0;
}
