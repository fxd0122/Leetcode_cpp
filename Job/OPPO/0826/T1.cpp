#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    double sum = 0.0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        sum += static_cast<double>(temp);
    }
    cout << fixed << setprecision(7);
    cout << sum / static_cast<double>(4*x) << endl;
    return 0;
}