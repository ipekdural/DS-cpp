#include <iostream>
#include <cstdlib>//srand icin gerekli baslik dosyasi
#include <ctime> //time fonk icin gerekli baslik dosyasi
using namespace std;
class Sayi{
	public:
	 Sayi(){
		 s1=rand()%100;
		 s2=rand()%100;
		 cout<<this<<" adresindeki nesne olusturuldu."<<endl;//this nesnenin adresini yazdirir.fakat hafizada yer tutmaz.
		 
	 }
	 ~Sayi(){
		 cout<<this<<" adresindeki nesne yok edildi."<<endl;//en son olusturulan nesneden baslanip ilk olusturulan nesneye dogru silinme islemi uygulanir
		 
	 }
	 void yazdir()
	 {
		cout<<"sayi1: "<<s1<<"\t"<<"sayi2: "<<s2<<endl;
	 }
	private:
		int s1;
		int s2;
};
void writeLine(){
	cout<<"***************************************************************************"<<endl;
}

int main(){
	//STACKTE OLUSTURULAN STATIK POINTER DIZISI
	srand(time(nullptr));//srand baslangic degeri atandi rand fonksiyonu program her calistiginda farkli degerler uretir bu sayede.
	Sayi* ptr[10];//Sayi classindan 10 elemanli isaretci nesne dizisi olustu.Yani stack de 10 tane pointer var.
	ptr[0]=new Sayi;//bu isaretci dizisinin ilk elemani heapte olusturulan bir Sayi nesnesini isaret ediyor.Kurucu fonk cagrilir.
	writeLine();
	ptr[1]=new Sayi[10];//isaretci dizisinin ikinci elemani ise 10 elemanli bir sayi nesnesi dizisini isaret ediyor.
	ptr[0]->yazdir();//eristigimiz yere pointer araciligyla eristigimiz icin -> kullanilir
	ptr[1][1].yazdir();//eristigimiz yere nesne araciligyla oldugu icin . kullanilir
	writeLine();
	for(int i=0;i<10;i++){//ptr isaretci dizisinin 1. indexindeki pointer 10 elemanli bir sayi nesne dizisinden olusuyordu.For dongusuyle bu nesneler yazdirilabilir 
		cout<<"PTR[1]"<<"["<<i<<"]: ";ptr[1][i].yazdir();
	}
	delete ptr[0];//p[0] daki isaretci bir nesneyi gosteriyor
	writeLine();
	delete[] ptr[1];//p[1] deki isaretci bir nesne dizisini gosteriyor
	
}