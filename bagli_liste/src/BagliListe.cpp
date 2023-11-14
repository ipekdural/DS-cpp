#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
BagliListe::BagliListe()
{
	ilk=0;
}
BagliListe::~BagliListe()
{
	Dugum* temp =ilk;
	while(temp!=0)
	{
		Dugum* sil =temp;
		temp=temp->sonraki;
		delete sil;

	}
	
}
void BagliListe::ekle(int veri)//ekle fonksiyonu
{
	Dugum *yeni =new Dugum(veri);
	if(ilk==0)//hic dugum yoksa
	{
		ilk=yeni;
	}
	else
	{
		Dugum* tmp=ilk;
		while (tmp->sonraki!=0)//listenin sonuna gidicez
		{
			tmp=tmp->sonraki;
		}
		tmp->sonraki=yeni;//yeni dugum sona eklendi
	}
	
	
}
void BagliListe::yazdir()
{
	cout<<"-------------------------------------"<<endl;
	cout <<setw(8)<<std::right<<"DUGUM:"<<"|"
	    <<setw(10)<<std::right<<"ADRES:"<<"|"
	    <<setw(5)<<std::left<<"VERI:"<<"|"<<
		setw(10)<<std::right<<"SONRAKI:"<<"|"<<endl;
		
	cout<<"-------------------------------------"<<endl;
	Dugum* tmp=ilk;
	
	int i=0;
	while (tmp!=0)//listenin sonuna gidicez
		{
			i++;

			cout<<i<<". Dugum"<<"|"
			    <<setw(10)<<tmp<<"|"
			    <<setw(5)<<tmp->veri<<"|"
				<<setw(10)<<std::right<<tmp->sonraki<<"|"<<endl;
			tmp=tmp->sonraki;
		}
		cout<<"-------------------------------------"<<endl;
}