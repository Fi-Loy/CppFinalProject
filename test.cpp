#include <iostream>
#include <cstring>
using namespace std;

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]){
    return strcmp(p1, p2);
}

int main(){
    cout << "Hello World\n";
    cout << compare("hi", "mom") << endl;
}