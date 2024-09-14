#include <iostream>
#include <algorithm>

using namespace std;
char alp[16], password[16];
int L, C, visitied[16];

// 자음 체크
bool check(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;

    return false;
}

// a: 모음 갯수, b: 자음 갯수 
void dfs(int cnt, int ago, int a, int b) {
    if(cnt == L) {
        if(a >= 1 && b >= 2) {
            for(int i = 0; i < L; i++)
                cout << password[i];
            cout << "\n";
        }

        return;
    }

    for(int i = ago; i < C; i++) {
        if(!visitied[i]) {
            visitied[i] = 1;
            password[cnt] = alp[i];
            if(check(password[cnt]))
                dfs(cnt + 1, i, a + 1, b);
            else
                dfs(cnt + 1, i, a, b + 1); 

            visitied[i] = 0;
        }
    }
}  

// 암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있다(알파벳이 암호에서 증가하는 순서, 중복X)
int main() {
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> alp[i];
    }
    
    sort(alp, alp + C);

    dfs(0, 0, 0, 0);

    return 0;
}