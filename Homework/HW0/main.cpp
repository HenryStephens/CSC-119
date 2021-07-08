#include <iostream>

using namespace std;

void foo(const string &s){
  cout << "The string is " << s << "\n";
}

int main(int argc, char** argv) {

  for(int i = 0; i < 3; i++){
    foo("hello");
  }

}
 