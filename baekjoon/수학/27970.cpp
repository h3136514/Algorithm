// 수학
#include <iostream>
#include <string>

#define MAX 1000000007
using namespace std;
long long sum, mul = 1;
string s;

// OX
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'O'){
            sum += mul;
            sum %= MAX;
        }

        mul *= 2;
        mul %= MAX;
    }

    cout << sum << "\n";

    return 0;
}
