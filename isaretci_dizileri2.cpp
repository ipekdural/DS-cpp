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

	//HEAPTE OLUSTURULAN DINAMİK POINTER DIZISI
	Sayi** p= new Sayi*[10];//heapte olusturulan p adinda Bir işaretçi dizisi oluşturuluyor. İşaretçi dizisi, bellekte başka nesnelerin adreslerini tutan bir dizi işaretçidir. p, Sayi türündeki nesnelerin adreslerini tutacak bir işaretçi dizisidir.
	//ustteki olusturma isleminde hicbir sayi nesnesi olusturulmuyor . Sadece dinamik isaretci dizisi olusturuluyor.Bu isaretciler nesnelerin adresi tutulmasi icin kullanilir 
	p[0]=new Sayi;//p[0]daki isaretci bir Sayi nesnesini isaret ediyor.hem p[0] hem de isaret ettigi nesne heapte bulunuyor.
	p[1]=new Sayi[10];//p[1] deki isaretci de 10 tane dinamik sayi nesnesini isaret ediyor 
	//silme islemine sondan baslanmali .yoksa adresler kaybedilir.Once en son olusturulan nesneler silinmeli daha sonra sirayla ilk olusturulan nesneye kadar silinmeli
	delete[] p[1];
	delete  p[0];
	delete[] p;
	
}