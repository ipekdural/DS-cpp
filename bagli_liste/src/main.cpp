#include <iostream>
#include "Dugum.hpp"
#include "BagliListe.hpp"
using namespace std;
int main()
{
		Dugum* d1=new Dugum(15);//bir tane dugum olusturuldu
		Dugum* d2=new Dugum(14);
		
		d1->sonraki=d2;
		
		cout<<d1->veri;//cikti 15
		cout<<endl;
		cout<<d1->sonraki->veri;//cikti 14
		cout<<endl;
		cout<<d2->veri;//cikti 14
		cout<<endl;
		cout<<d2->sonraki<<endl;//cikti 0 cunku son dugume her zaman default olarak null degeri atanir
		delete d1;
		delete d2;
//FONKSIYONLARLA DUGUM EKLEME VE YAZDIRMA
	BagliListe* b= new BagliListe();//bir tane bagli liste nesnesi olsuturuldu
	b->ekle(25);
	b->ekle(48);
	b->ekle(56);
	b->ekle(34);
	b->yazdir();
	
	delete b;//b nin yokedici fonksiyonu cagrilir
}