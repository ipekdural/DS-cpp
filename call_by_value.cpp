#include <iostream>
using namespace std;
//call by value
void degistir(int x, int y){
	int temp=x;
	x=y;
	y=temp;

}
int main(){
	int a=2, b=3;
	degistir(a,b);//derleyici fonksiyona sadece a ve b nin degerini gonderir. a ve b degismez.Degistir fonksiyonuna sadece degerler gonderilir . degiskenler gonderilmez .bu yuzden isaretcilere ihtiyac duyulur.
	cout<<a<<" "<<b; 
}