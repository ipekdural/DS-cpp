#include <iostream>
using namespace std;
class BagliListe
{
	public:
		BagliListe()
		{
			ilk=0;//kurucu fonksiyon baslangicta bir veri olmadigi icin ilk isaretcisine 0 degeri atamalidir
		}
		~BagliListe()
		{
			Dugum* temp =ilk;
			while(temp!=0)
			{
				Dugum* sil=temp;
				temp=temp->sonraki;
				delete sil;
			}
		}
		void cikar()
		{
			if(ilk==0) return;//hic dugum yoksa
			if (ilk->sonraki==0)
			{
				delete ilk;
				ilk=0;
				
			}
			else
			{
				Dugum* temp =ilk;
				while(temp->sonraki->sonraki!=0)
				{ 
					temp=temp->sonraki;
				
				}
				delete temp->sonraki;
				temp->sonraki=nullptr;
			}
		}
		void ekle(int sayi)
		{
			Dugum* yeni=new Dugum(sayi);
			if(ilk==0)
			{
				ilk=yeni;
				return;
			}
			Dugum* temp=ilk;
			while(temp->sonraki!=0)
			{
				temp=temp->sonraki;
			}
			temp->sonraki=yeni;
		}
		
		void yazdir()
		{
			
			Dugum* temp=ilk;
			while(temp!=0)
			{
				cout<<temp->veri<<",";  
				temp=temp->sonraki;
			}
		
		
		}
	private:
		Dugum* ilk;
}