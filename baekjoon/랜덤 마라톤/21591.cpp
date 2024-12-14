// 구현
#include <iostream>

using namespace std;
int Wc, Hc, Ws, Hs;

// Laptop Sticker
int main(){
    cin >> Wc >> Hc >> Ws >> Hs;
    if(Wc >= Ws+2 && Hc >= Hs+2)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}