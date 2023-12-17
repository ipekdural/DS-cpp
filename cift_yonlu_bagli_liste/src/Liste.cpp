#include "Liste.hpp"
#include <iostream>
#include <iomanip>
#include "Dugum.hpp"
#include <exception>
using namespace std;
Liste::Liste(){
    ilk=0;
}
Liste::~Liste(){
    Dugum* tmp=ilk;
    while(tmp!=0){
        Dugum* sil =tmp;
        tmp=tmp->sonraki;
        delete sil;
    }
}
int Liste::ilkDegerGetir(){
    if(ilk==0){throw std::out_of_range("liste bos!");}
    else{
        return ilk->veri;
    }
}
void Liste::arayaEkle(int index,int veri){
    if(ilk==0){return;}//liste bos
    Dugum* dug=dugumGetir(index);
    if(dug)
    { 
        Dugum* onceki=dug->onceki;
        Dugum* yeni=new Dugum(veri);
        dug->onceki=yeni;
        yeni->sonraki=dug;
        yeni->onceki=onceki;
        if(onceki){
            onceki->sonraki=yeni;
        }
        else{//ilk dugume ekliyoruz
            ilk=yeni;
        }
    }

}
void Liste::cikar(int sira){
    if(ilk==0){return;}//bos liste
    Dugum* dug=dugumGetir(sira);
    Dugum* dug_onceki=dug->onceki;
    Dugum* dug_sonraki=dug->sonraki;
    if(dug_sonraki){
    dug_sonraki->onceki=dug_onceki;
    }
    if(dug_onceki){
        dug_onceki->sonraki=dug_sonraki;
    }
  
    else{ilk=dug_sonraki;}//ilk dugumu siliyorsak
    delete dug;
}
Dugum* Liste::dugumGetir(int index){

    Dugum* tmp=ilk;
    int sayac=0;
    while (tmp!=0){
        
        if (sayac==index){return tmp;}
        tmp=tmp->sonraki;
        sayac++;
    }

    return 0;//ya liste bos ya da istenen index listenin uzunlugundan buyuk 

}
void Liste::ekle(int veri)
{
    Dugum* yeni=new Dugum(veri);
    if(ilk==0){//hic dugum yoksa
        ilk=yeni;
    }
    else{
        Dugum* tmp=ilk;
        while(tmp->sonraki!=0){
            tmp=tmp->sonraki;
        }
        tmp->sonraki=yeni;
        yeni->onceki=tmp;


    }
}
void Liste::cikar(){
    if(ilk==0){//hic dugum olmamasi
        return;
    }
    if(ilk->sonraki==0)//tek bir dugum olmasi
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        Dugum* gec=ilk;
        while(gec->sonraki->sonraki!=0)//sondan bir onceki dugumdeyiz
        {
            gec=gec->sonraki;
        }
        delete gec->sonraki;
        gec->sonraki=0;

    }

}
ostream& operator<<(ostream& os,Liste& liste){
    os<<setw(15)<<"dugum adresi"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;
    Dugum* gec =liste.ilk;//ostream disardan gelen bir fonk oldugu icin ilke . ile erisilir
    while(gec!=0){
        os<<setw(15)<<gec<<setw(15)<<gec->veri<<setw(15)<<gec->onceki<<setw(15)<<gec->sonraki<<endl;
        gec=gec->sonraki;
    }
    return os;
}