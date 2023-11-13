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
	srand(time(nullptr));//srand baslangic degeri atandi rand fonksiyonu program her calistiginda farkli degerler uretir bu sayede.
	Sayi* ptr=new Sayi[10];
	writeLine();
	for(int i=0;i<10;i++){
		(ptr+i)->yazdir();// (*(ptr+i)).yazdir(); seklinde de cagrilabilir.veya p[i].yazdir(); seklinde de cagrilabilir.
	}
	
	writeLine();
	delete[] ptr;
	
}