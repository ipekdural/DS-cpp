#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;
class Ogrenci{
	public:
		Ogrenci()
		{
			
			this->ogrenciNo=1000*(1+rand()%3)+rand()%999;
			this->sinif=1+rand()%4;
			
		}
		
	int numaraGetir() const//const yazildiginda bu fonksiyon cagrildiginda nesnenin degistirilmeyeci anlamina gelir
	{
		return ogrenciNo;
	}
	int sinifGetir() const
	{
		return sinif;
	}
	friend ostream& operator<<(ostream& os ,const Ogrenci& ogrenci)
	{
		os<<setw(5)<<ogrenci.numaraGetir()<<"-"<<setw(4)<<std::right<<ogrenci.sinifGetir();
		return os;
	}
	~Ogrenci(){
		
	}
	private:
		int sinif;
		int ogrenciNo;
		
};
void diziSifirla(Ogrenci** dizi , int boyut)
{
	for(int i=0;i<boyut;i++)
	{
		dizi[i]=NULL;
	}

}
void menu()
{   cout<<endl<<endl;
	cout<<"******************"<<endl
	    <<"* 1-ogrenci ekle *"<<endl
		<<"* 2-ogrenci sil  *"<<endl
		<<"* 3-cikis        *"<<endl
		<<"******************"<<endl<<endl;
}

void diziYazdir(Ogrenci** dizi,int boyut)
{
		system("cls");
	
	cout<<endl<<"********************************"<<endl;
	cout<<setw(8)<<std::left<<"index"<<setw(2)<<"|"<<setw(9)<<"icerik"<<" |"<<setw(10)<<" gosterilen"<<endl;
	cout<<"********************************"<<endl;
	for(int i=0;i<boyut;i++)
	{

        cout <<setw(5) << std::left << "dizi["<<setw(1)<<std::left<<i<< "]:| ";
		if (dizi[i])
		{
			cout<<setw(10)<<std::left<< dizi[i]<<"| "<<setw(10)<<*dizi[i] << std::endl;
		}
		else
		{
			cout<<setw(10)<<std::left<< dizi[i]<<"|"<<setw(10)  << " ----------" << std::endl;
		}
	}
	cout<<endl<<"********************************"<<endl;
		menu();
}


void ogrenciEkle(Ogrenci** dizi,int ogrenciSayisi)
{
	
	int index;cout<<"index girin:";cin>>index;
	if(index<ogrenciSayisi&&index>=0)
	{
		if(dizi[index]==NULL)
		{
			dizi[index]=new Ogrenci();
		    diziYazdir(dizi,ogrenciSayisi);
		    cout<<index<<" numarali ogrenci eklendi!"<<endl;	
			
		}
		else
		{
			cout<<"bu index dolu!"<<endl;
		}
		
	}
	else
	{
		cout<<"index dizi boyutunu asiyor!"<<endl;
	}
	
}
void ogrenciSil(Ogrenci** dizi,int ogrenciSayisi)
{
	
	int index;cout<<"index girin:";cin>>index;
	if(index<ogrenciSayisi&&index>=0)
	{
		if(dizi[index]!=NULL)
		{	
	
			delete dizi[index];
			dizi[index]=NULL;
			diziYazdir(dizi,ogrenciSayisi);
			cout<<index<<" numarali ogrenci silindi"<<endl;
		}
		else
		{
			cout<<"bu index zaten bos!"<<endl;
		}
		
	}
	else
	{
		cout<<"index dizi boyutunu asiyor!"<<endl;
	}
	

}
void cikis(Ogrenci** dizi,int ogrenciSayisi)
{
	for(int i=0;i<ogrenciSayisi;i++)
	{
		if(dizi[i])
		{
			delete dizi[i];//!!ONCE DIZININ ICINDEKI NESNELER SILINMELI AKSI TAKDIRDE NESNELERIN ADRESLERI KAYBOLUR
		}
	}
		delete[] dizi;//DAHA SONRA DIZININ KENDISI SILINIR!!

}



int main()
{
	int ogrenciSayisi=10;
	Ogrenci** ogrenciListesi= new Ogrenci*[ogrenciSayisi];  
	diziSifirla(ogrenciListesi,ogrenciSayisi);
	//ogrenciListesi[3]=new Ogrenci();//ogrenciListesi[3] teki pointer artık bir Ogrenci nesnesini gosterecek
	diziYazdir(ogrenciListesi,ogrenciSayisi);
	
	while(true)
	{
		
		int choice;
		cout<<"secim:";cin>>choice;
		diziYazdir(ogrenciListesi,ogrenciSayisi);
		if(choice==1)
		{
			ogrenciEkle(ogrenciListesi,ogrenciSayisi);
		}
		else if(choice==2)
		{
			ogrenciSil(ogrenciListesi,ogrenciSayisi);
		}
		else
		{
			if (choice==3){cout<<"bye";cikis(ogrenciListesi,ogrenciSayisi);break;}
			else cout<<"gecerli bir secim girin."<<endl;
		}	
	}
	for(int i=0;i<ogrenciSayisi;i++)
	{
		delete ogrenciListesi[i];
	}

}

