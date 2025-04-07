#include <iostream>
#include <cmath>
#include <vector>

#define MAX_NUM 2000001

using namespace std;
int N, M;
bool num[MAX_NUM];
vector<int> v;

//에라토스테네스의 체(소수 판별)
void primeNumber(int n){
    num[1] = true;
    for(int i = 2; i <= sqrt(n); i++){
        if(num[i])
            continue;
        for(int j = i+i; j <= n; j+=i){
            if(num[j])
                continue;
            num[j] = true;
        }
    }
}

// 등차수열을 만들어요 
int main(){
    cin >> N >> M;
    primeNumber(MAX_NUM);

    for(int i = 1; i < MAX_NUM; i++){
        int current = i;
        if(current + (N-1)*M >= MAX_NUM)
            break;

        for(int j = 0; j < N; j++){
            current = i + j*M;

            if(!num[current]){  // 소수이면 초기화
                v.clear();
                break;
            }else
                v.push_back(current);
        }

        if(v.size() == N)
            break;

        v.clear();
    }

    if(v.size() == N){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }else{
        cout << "-1\n";
    }

    return 0;
}