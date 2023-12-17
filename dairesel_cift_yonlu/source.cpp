#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Dugum{
    public:
    Dugum(int veri){
        this->veri=veri;
        onceki=sonraki=0;
    }
    int veri;
    Dugum* onceki;
    Dugum* sonraki;
};

class DaireseListe{
    public:
        DaireseListe(){
            ilk=0;
            dugumSayisi=0;
        };
        ~DaireseListe();
        void ekle(int veri){
            Dugum* yeni=new Dugum(veri);
            if(ilk==0){ilk=yeni;ilk->sonraki=ilk;ilk->onceki=ilk;}
            else{
                Dugum* tmp=ilk;
                while(tmp->sonraki!=ilk){
                    tmp=tmp->sonraki;
                }//whike dongusu yerine Dugum* gec=dugumGetir(dugumSayisi-1); yazilirsa ayni sonuca ulasilir;
                tmp->sonraki=yeni;
                yeni->sonraki=ilk;
                yeni->onceki=tmp;
                ilk->onceki=yeni;
            }
            dugumSayisi++;
        }
        void cikar(){
            if(ilk==0) return;//dugum yok
            if(ilk->sonraki==ilk){delete ilk;ilk=0;}//tek bi dugum var
            else{
                Dugum* gec=ilk;
                while(gec->sonraki->sonraki!=ilk){
                    gec=gec->sonraki;
                }
                delete gec->sonraki;
                gec->sonraki=ilk;
                ilk->onceki=gec;
            
                
            }
            dugumSayisi--;

        }
        void cikar(int index){
            Dugum* gec=dugumGetir(index);
            if(gec){
                Dugum* onceki=gec->onceki;
                Dugum* sonraki=gec->sonraki;
                onceki->sonraki=sonraki;
                sonraki->onceki=onceki;
                if(ilk->onceki==ilk){//tek dugum varsa
                    ilk=0;
                }
                if(gec==ilk)//ilk dugumu silersek
                {
                    ilk=sonraki;
                }
                delete gec;
            dugumSayisi--;
            }
            
        }
        void ekle(int index,int veri){
            Dugum* gec=dugumGetir(index);
           if(gec){ Dugum* yeni =new Dugum(veri);
            Dugum* onceki=gec->onceki;
            if(gec==ilk){
                ilk=yeni;

            }
            gec->onceki=yeni;
            onceki->sonraki=yeni;
            yeni->sonraki=gec;
            yeni->onceki=onceki;

            dugumSayisi++;}
            ;
        }
        
        Dugum* dugumGetir(int index){
            Dugum* tmp=ilk;
            if(tmp==0||index>=dugumSayisi||index<0){
                return 0;
            }
            for(int i=0;i<index;i++){
                tmp=tmp->sonraki;
            }
            return tmp;            
        }
        friend ostream& operator<<(ostream& os,DaireseListe& liste){
            os<<setw(15)<<"dugum adresi"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;
            Dugum* gec =liste.ilk;//ostream disardan gelen bir fonk oldugu icin ilke . ile erisilir
            for(int i=0;i<liste.dugumSayisi;i++){
                os<<setw(15)<<gec<<setw(15)<<gec->veri<<setw(15)<<gec->onceki<<setw(15)<<gec->sonraki<<endl;
                gec=gec->sonraki;
                
            }
            os<<"********************************************************************************"<<endl;
            return os;
            }
        private:
        Dugum* ilk;
        int dugumSayisi;
};
int main(){
    DaireseListe* liste=new DaireseListe();
    liste->ekle(12);
    liste->ekle(15);
    liste->ekle(18);
    liste->ekle(21);
    cout<<*liste;
    liste->cikar(0);

  
    
    cout<<*liste;
}