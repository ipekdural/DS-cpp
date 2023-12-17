#include <iostream>
#include "Liste.hpp"
#include "Dugum.hpp"
using namespace std;
int main(){
    Liste* liste=new Liste();
    liste->ekle(11);
    liste->ekle(12);
    liste->ekle(13);
    liste->ekle(14);
    cout<<*liste;
    cout<<"**************************************"<<endl;
    liste->arayaEkle(1,23);
    // liste->cikar(2);//3. dugumu cikarir
    //liste->cikar(45);//ilk dugumu cikartir
    
    cout<<*liste;
    delete liste;
    
}