#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=n; i>0; i--){
        for(int j=0; j<5*n; j++){
            if(j<i){
                cout << '.';
            }else if(j>=i && j<5*n-i){
                cout << '*';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
    for(int i=n; i>0; i--){
        for(int j=0; j<n*5; j++){
            if(j<n){
                cout << '*';
            }else if(j>=i && j<5*n-n){
                cout << '0';
            }else{
                cout << '*';
            }
        }
        cout << endl;
    }
    for(int i=n; i>0; i--){
        for(int j=0; j<5*n; j++){
            if(j<n){
                cout << '*';
            }else if(j>=n && j<2*n){
                cout << '0';
            }else if(j>=2*n && j<3*n){
                cout << '.';
            }else if(j>=3*n && j<4*n){
                cout << '0';
            }else{
                cout << '*';
            }
        }
        cout << endl;
    }
    for(int i=n; i>0; i--){
        for(int j=0; j<n*5; j++){
            if(j<n){
                cout << '*';
            }else if(j>=i && j<5*n-n){
                cout << '0';
            }else{
                cout << '*';
            }
        }
        cout << endl;
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<5*n; j++){
            if(j<i){
                cout << '.';
            }else if(j>=i && j<5*n-i){
                cout << '*';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}