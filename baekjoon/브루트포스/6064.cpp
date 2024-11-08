#include <iostream>

using namespace std;
int T, M, N, X, Y, maxNum, CNT;

// 최대 공약수
int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

// 최소 공배수
int lcm(int a, int b){
    return a * b / gcd(a, b);
}

// 카잉 달력이 가능하지 확인
bool check(){
    int cnt = 0;
    if(M > N){
        while(M * cnt + X <= maxNum){
            CNT = M * cnt + X;
            if(CNT == Y || CNT % N == Y || (CNT % N == 0 && N == Y))
                return true;
            
            cnt++;
        }
    }else{
        while(N * cnt + Y <= maxNum){
            CNT = N * cnt + Y;
            if(CNT == X || CNT % M == X || (CNT % M == 0 && M == X))
                return true;
            
            cnt++;
        }
    }

    return false;
}

// 카잉 달력
int main(){
    cin >> T;
    while(T--){
        cin >> M >> N >> X >> Y;
        maxNum = lcm(M, N);
       // cout << maxNum << "\n";
        
        if(!check())
            cout << "-1\n";
        else
            cout << CNT << "\n";
    }

    return 0;
}