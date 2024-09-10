#include <iostream>
using namespace std; 

struct arcticle {
    int id;
    int prix;
    char name[50];
};


int main() {

    arcticle bug={1,15,"bug"};

    cout<<bug.name;

}