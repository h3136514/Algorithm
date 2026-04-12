// https://www.acmicpc.net/problem/25632
#include <iostream>
#include <cmath>

using namespace std;
int A, B, C, D, yt, yj, y2, num[1001];

void prime(){
    num[1] = 1;
    for(int i = 2; i <= sqrt(1000); i++){
        if(num[i])
            continue;
        for(int j = i + i; j <= 1000; j+= i){
            if(num[j])
                continue;
            num[j] = 1;
        }
    }

}

// 소수 부르기 게임
int main(){
    cin >> A >> B;
    cin >> C >> D;

    prime();
    for(int i = A; i <= B; i++){
        if(!num[i])
            yt++;
    }
    for(int i = C; i <= D; i++){
        if(!num[i])
            yj++;
    }
    // 공통 소수
    if(A <= C && C <= B){
        if(B <= D){
            for(int i = C; i <= B; i++){
                if(!num[i])
                    y2++;
            }
        }else{
            for(int i = C; i <= D; i++){
                if(!num[i])
                    y2++;
            }
        }
    }else if(C <= A && A <= D){
        if(D <= B){
            for(int i = A; i <= D; i++){
                if(!num[i])
                    y2++;
            }
        }else{
            for(int i = A; i <= B; i++){
                if(!num[i])
                    y2++;
            }
        }
    }

    yt -= y2, yj -= y2;

    if(yt > yj){
        cout << "yt\n";
    }else if(yt < yj){
        cout << "yj\n";
    }else{
        if(y2 % 2 == 1)
            cout << "yt\n";
        else
            cout << "yj\n";
    }


    return 0;
}