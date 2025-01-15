#include <iostream>
#include <string>

using namespace std;
int k;
string str1, str2;

// 스키테일 암호
int main() {
    cin >> k;
    cin >> str1;

    str2 += str1[0];
     for(int i = 1; i < str1.size(); i++){
         if(i % k == 0)
             str2 += str1[i];
     }

    cout << str2 << "\n";
    
    return 0;
}