//SABIT YIGIN

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;
const int MAX=10;
class Yigin{
    public:
        Yigin( ){
         tepe=-1;
        
        }
        void ekle(int veri){
            if(tepe<MAX-1){
                tepe++;
                veriler[tepe]=veri;
            } 
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
    int tepe;
    int veriler[MAX];

};
int main(){
    Yigin yigin;
    yigin.ekle(10);
    yigin.ekle(20);
    yigin.ekle(30);
    yigin.ekle(40);
    yigin.ekle(50);
    cout<<yigin;
    for(int i=0;i<5;i++){
        yigin.cikar();
        cout<<yigin;
    }
    for(int i=0;i<16;i++){//16 tane eklememize ragmen max=10 old icin sadece 10 tane ekledi
        yigin.ekle(50*i);
    }
    cout<<yigin;
    cout<<"********************************"<<endl;
    try{ cout<<yigin.getir(-1);}
    catch(out_of_range& o){
        cout<<o.what();
    }
       
  
}