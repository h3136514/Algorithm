#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N, Q, cnt, l, r, result;
string s, k1, k2;

// 문자열 접기
int main(){
    cin >> N;
    cin >> s;
    cin >> Q;
    while(Q--){
        cin >> l >> r;
        result = 0;
        l--, r--;
        int st = l;
        while(true){
            if(st == r)
                break;

            cnt = 0;
            k1 = "", k2 = "";
            for(int i = l; i <= st; i++){
                k1 += s[i];
            }
            for(int i = st+1; i <= r; i++){
                k2 += s[i];
            }
            reverse(k1.begin(), k1.end());

            for(int i = 0; i < min(k1.size(), k2.size()); i++){
                if(k1[i] == k2[i])
                    cnt++;
                
            }

            result = max(result, cnt);
            st++;
        }

        cout << result << "\n";
    }

    return 0;
}