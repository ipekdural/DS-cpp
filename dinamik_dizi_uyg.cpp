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
			arayaEkle(kullanilan,eklenecekSayi);
		}
		void degerCikar(int index)
		{
			if(index>=0 && index<kullanilan &&kullanilan>0)
			{
				for(int i=index;i<=kullanilan;i++)
				{
					adres[i]=adres[i+1];
				}
				kullanilan--;
			}
			else
			{
				throw Exception("gecersiz index");
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
		void arayaEkle(int index,int sayi)
		{
			if(index>=0&&index<=kullanilan)
			{
				if(kullanilan>=boyut)
				{
					yerAc(boyut*2);
				}
				
				for(int i=kullanilan-1;i>=index;i--)
				{
					adres[i+1]=adres[i];
				}
				adres[index]=sayi;
				kullanilan++;
			
			}
			else
			{
				throw Exception("hatali sira ");
			}
			
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
		void sil()
		{
			kullanilan=0;
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
			
			int secim;cout<<"index girin:";cin>>secim;
			dizi.arayaEkle(secim,rand()%90+10);
		}
		else if(secim==3)
		{
			int secim;cout<<"index girin:";cin>>secim;
			dizi.degerCikar(secim);
		}
		else if(secim==4)
		{
			cout<<"bye";
			dizi.sil();
		}
		else
		{
			cout<<"Gecersiz islem";
		}
	}

}


//g++ -o x dinamik_dizi_uyg.cpp