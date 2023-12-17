#ifndef Liste_hpp
#define Liste_hpp
#include <iostream>
#include "Dugum.hpp"
#include <exception>
class Liste{
    public:
        Liste();
        void ekle(int veri);
        void cikar();
        int ilkDegerGetir();
        void cikar(int sira);
        void arayaEkle(int index,int veri);
        ~Liste();
        friend ostream& operator<<(ostream& os,Liste& liste);
    private:
        Dugum* dugumGetir(int index);
        Dugum* ilk;//ilk dugumu isaret eden pointer gizli olmali
};

#endif
