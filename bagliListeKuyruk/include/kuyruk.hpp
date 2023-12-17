#ifndef KUYRUK_HPP
#define KUYRUK_HPP
#include "dugum.hpp" 
#include <iostream>
using namespace std;

class Kuyruk
{
public:
    Kuyruk();
    ~Kuyruk();
    void ekle(int veri);
    void cikar();
    bool bosmu();
    int getir();
    friend ostream& operator<<(ostream& os, Kuyruk& kuyruk);

private:
    Dugum* ilk;
    Dugum* son;
};

#endif