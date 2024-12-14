// 수학, 소수(에라토스테네스의 체)
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N, num[1000001];
vector<int> v;

//에라토스테네스의 체
void primeNumber(int n){
    for(int i = 2; i<= sqrt(n); i++){
        if(num[i])
            continue;
        for(int j = i+i; j<= n; j+=i){
            if(num[j])
                continue;
            num[j] = 1;  
        }
    }
}

// Prime
int main(){
    num[1] = 1;
    primeNumber(1000000);
    for(int i = 1; i <= 1000000; i++){
        if(!num[i])
            v.push_back(i);
    }
    
    cin >> N;
    cout << v[N-1] << "\n";   //첫 번째 소수는 2이므로

    return 0;
}