#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
class Exception
{
	public:
		Exception(const string& yeni)
		{
			mesaj=yeni;
		}
		string mesaj;
		
		
};
class DinamikDizi
{
	public:
		DinamikDizi()
		{
			boyut=5;
			adres= new int[boyut];
			kullanilan=0;
		}
		~DinamikDizi()
		{
			delete[] adres;
		}
		int boyutGetir()const
		{
			return boyut;
		}
		int  kullanilanGetir()const
		{
			return kullanilan;
		}
		int degerGetir(int index)const
		{
			if(index<0||index>kullanilan)
			{
				throw Exception("degerGetir sinir problemi");
			}
			return adres[index];
		}
	
		void sonaEkle(int eklenecekSayi)
		{
			if(kullanilan>=boyut)
			{
				yerAc(boyut*2);
			}
			else
			{
			adres[kullanilan]=eklenecekSayi;
			kullanilan=kullanilan+1;
			}
		}
		friend ostream& operator <<(ostream& os, const DinamikDizi& dizi)
		{
			os<<"|";
			for(int i=0;i<dizi.boyutGetir();i++)
			{
				os<<setw(3)<<i<<"|";
			}
			os<<endl<<"|";
			for(int i=0;i<dizi.boyutGetir();i++)
			{
				os<<"---|";
			}
			os<<endl<<"|";
			for(int i=0;i<dizi.kullanilanGetir();i++)
			{
				os<<setw(3)<<dizi.degerGetir(i)<<"|";
			}
			for(int i=dizi.kullanilanGetir();i<dizi.boyutGetir();i++)
			{
				os<<setw(3)<<"BOS"<<"|";
			}
			os<<endl<<endl;
			
		}
		void yerAc(int yeniBoyut)
		{
			int *yeniAdres=new int[yeniBoyut];
			for(int i=0;i<kullanilan;i++)
			{
				yeniAdres[i]=adres[i];
			}
			delete[] adres;
			adres=yeniAdres;
			boyut=yeniBoyut;
		}
	private:
		int* adres;
		int kullanilan;
		int boyut;
	
};

void menu()
{
	cout<<endl<<endl;
	cout<<"******************"<<endl
	    <<"* 1-sona ekle    *"<<endl
		<<"* 2-araya ekle   *"<<endl
		<<"* 3-cikar        *"<<endl
		<<"* 4-cikis        *"<<endl
		<<"******************"<<endl<<endl;
}

int main()
{
	srand(time(NULL));
	DinamikDizi dizi;
	while(true)
	{
		system("cls");
		cout<<dizi;
		menu();
		int secim;cout<<"secim girin:";cin>>secim;
		if(secim==1)
		{
			dizi.sonaEkle(rand()%90+10);
		}
		else if (secim==2)
		{
			dizi.arayaEkle();
		}
		if(secim==3)
		{
			dizi.degerCikar();
		}
		if(secim==4)
		{
			dizi.cikis();
		}
		else
		{
			cout<<"Gecersiz islem";
		}
	}

}


//g++ -o x dinamik_dizi_uyg.cpp