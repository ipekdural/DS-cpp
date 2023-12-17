//DINAMIK YIGIN

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Yigin{
    public:
        Yigin( ){
        tepe=-1;
        veriler=new int[kapasite];//baslangicta default olarak 5 indexlik yer acilir
        kapasite=5;
        
        
        }
        ~Yigin(){
            delete[] veriler;
        }
       
        void ekle(int veri){
           if(tepe==kapasite-1){
            genislet(kapasite);
           }
           tepe++;
           veriler[tepe]=veri;
        }
        void cikar(){
            if(tepe!=-1){
                tepe--;
            }
        }
        friend ostream& operator<<(ostream& os,Yigin& yigin){
            os<<"---->";
            for(int i=yigin.tepe;i>-1;i--){
                os<<yigin.veriler[i]<<endl<<"     ";
            }
            os<<endl;
            return os;

        }
        bool bosMu(){
            if(tepe==-1){return true;}
            else{return false;}
        }
        int getir(){
            if(tepe!=-1){
                    return veriler[tepe];
                }
                throw std::out_of_range("yigin::getir() eleman yok!");
            }
        int getir(int index){
            if(tepe!=-1){
                    for(int i=tepe;i>-1;i--){
                        if(index==tepe){return veriler[i];}
                        tepe--;
                    }
                }
                throw std::out_of_range("yigin::getir() index out of range!");
            }
        
    private:
        void genislet(int boyut){
            int* yenikapasite=new int[boyut+kapasite];
            for(int i=0;i<=tepe;i++){
                yenikapasite[i]=veriler[i];
            }
            delete[] veriler;
            veriler=yenikapasite;
            kapasite=kapasite+boyut;
        }
        int tepe;
        int kapasite;
        int* veriler;

};
int main(){
    Yigin yigin;
    // yigin.ekle(10);
    // yigin.ekle(20);
    // yigin.ekle(30);
    // yigin.ekle(40);
    // yigin.ekle(50);
    // cout<<yigin;
    // for(int i=0;i<5;i++){
    //     yigin.cikar();
    //     cout<<yigin;
    // }
    for(int i=0;i<30;i++){//16 tane eklememize ragmen max=10 old icin sadece 10 tane ekledi
        yigin.ekle(50*i);
    }
    cout<<yigin;
    cout<<"********************************"<<endl;
    // try{ cout<<yigin.getir(-1);}
    // catch(out_of_range& o){
    //     cout<<o.what();
    // }
       
  
}