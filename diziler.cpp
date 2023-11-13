#include <iostream>
using namespace std;
int* diziOlustur(int boyut){
	int* dizi= new int[boyut];
	for(int i=0;i<boyut;i++){
		dizi[i]=rand()%50;
	}
	return dizi;
}
void diziYazdir(int* dizi,int boyut){
		cout<<"Rastgele sayi dizisi: ";
	for (int i=0;i<boyut;i++){
		cout<<*(dizi+i)<<" ";
	}
}
int main(){
	//sabit dizi(stackte olsuturuldu)
	int dizi[]={1,2,3,4,5,6};
	int* p= dizi;
	cout<<"p: "<<p<<endl;
	cout<<"&dizi[0]: "<<&dizi[0]<<endl;//ciktilara baktigimizda olusturulan p pointeri dizinin ilk elamninin adresini gosterir
	for(int i=0;i<6;i++){
	cout<<"Dizi["<<i<<"]: "<<dizi[i]<<"\t"<<"Adres:"<<p+i<<endl;
	}
	
	
	//heap bellekte dizi olusturma
    int* ptr=diziOlustur(10);
	diziYazdir(ptr,10);
	delete ptr;
}