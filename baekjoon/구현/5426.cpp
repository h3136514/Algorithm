#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int T, N, idx;
char c[101][101], tmp[101][101];
string s;

void copyBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tmp[i][j] = c[i][j];
        } 
    }

}

void rotate(){
    copyBoard();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            c[N-j-1][i] = tmp[i][j];
        } 
    }
}

// 비밀 편지
int main(){
    cin >> T;
    while(T--){
        cin >> s;
        N = sqrt(s.size());
        idx = 0;
        for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
                c[i][j] = s[idx++];
           } 
        }

        rotate();

        for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
                cout << c[i][j];
           } 
        }
        cout <<"\n";
    }

    return 0;
}