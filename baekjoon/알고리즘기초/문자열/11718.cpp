#include <iostream>
#include <string>
using namespace std;
int N =100;
string str; 

int main(){
    while(0 < N--){
        getline(cin, str);
        cout << str << '\n';
    }
    return 0;
}