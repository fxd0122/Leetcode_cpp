#include <iostream>
#include <string>
using namespace std;

class Shoes{
public:
    virtual void Show() = 0;
    virtual ~Shoes(){}
};

class NiKeShoes : public Shoes{
public:
    void Show(){
        cout << "NiKe: Just do it!" << endl;
    }
};

class AdidasShoes : public Shoes{
public:
    void Show(){
        cout << "Adidas: Impossible is nothing!" << endl;
    }
};

class LiNingShoes : public Shoes{
public:
    void Show(){
        cout << "LiNing: Everything is possible!" << endl;
    }
};

enum SHOES_TYPE{
    NIKE, LINING, ADIDAS
};

class ShoesFactory{
public:
    Shoes* CreateShoes(SHOES_TYPE type){
        switch(type){
            case NIKE:{
                return new NiKeShoes();
                break;
            }
            case LINING:{
                return new LiNingShoes();
                break;
            }
            case ADIDAS:{
                return new AdidasShoes();
                break;
            }
            default:{
                return NULL;
                break;
            }
        }
    }
};

int main(){
    ShoesFactory shoesFactory;

    Shoes* pNiKeShoes = shoesFactory.CreateShoes(NIKE);
    if(pNiKeShoes != nullptr){
        pNiKeShoes->Show();
        delete pNiKeShoes;
        pNiKeShoes = nullptr;
    }

    Shoes* pLiNingShoes = shoesFactory.CreateShoes(LINING);
    if(pLiNingShoes != nullptr){
        pLiNingShoes->Show();
        delete pLiNingShoes;
        pLiNingShoes = nullptr;
    }

    Shoes* pAdidasShoes = shoesFactory.CreateShoes(ADIDAS);
    if(pAdidasShoes != nullptr){
        pAdidasShoes->Show();
        delete pAdidasShoes;
        pAdidasShoes = nullptr;
    }

    return 0;
}
