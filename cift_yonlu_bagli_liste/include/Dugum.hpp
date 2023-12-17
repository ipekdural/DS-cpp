#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
using namespace std;
class Dugum{
    public:
    int veri;
    Dugum(int veri);
    ~Dugum();
    Dugum* sonraki;
    Dugum* onceki;

};
#endif