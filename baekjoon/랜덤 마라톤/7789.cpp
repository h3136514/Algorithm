// 수학, 소수
#include <iostream>
#include <string>
#include <cmath>

#define INF 9999999
using namespace std;
string a, b;
bool num[10000000];

//에라토스테네스의 체
void primeNumber(){
    num[1] = true;
    for(int i = 2; i <= sqrt(INF); i++){
        if(num[i])
            continue;
        for(int j = i+i; j <= INF; j+=i){
            if(num[j])
                continue;

            num[j] = true;
        }
    }
}

// 텔레프라임
int main(){
    primeNumber();
    cin >> a >> b;
    int aNum = stoi(a);
    int bNum = stoi(b+a);

    if(!num[aNum] && !num[bNum])
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}