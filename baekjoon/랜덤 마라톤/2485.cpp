// 수학, 유클리드 호제법
#include <iostream>
#include <vector>

using namespace std;
int N, num[100000], add;
vector<int> v;

// 유클리드호제법
int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

// 가로수
int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num[i];
        if(i == 0)
            continue;
        
        int differ = num[i] - num[i-1]; 
        v.push_back(differ);
    }

    // 공통 최대공약수 구하기
    int minMult = v[0];
    for(int i = 1; i < v.size(); i++){
        minMult = gcd(minMult, v[i]);
    }

    for(int i = 0; i < v.size(); i++){
        add += v[i]/minMult - 1;
    }

    cout << add << "\n";

    return 0;
}