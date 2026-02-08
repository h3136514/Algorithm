#include<iostream>

using namespace std;
int T, m, n, num[101][101], cnt, result;

// 박스
int main(){
    cin >> T;
    while(T--){
        cin >> m >> n;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> num[i][j];
            }
        }
        
        result = 0;
        for(int i = 0; i < n; i++){
            cnt = 0;
            for(int j = m-1; j >= 0; j--){
                if(num[j][i] == 0){
                    cnt++;
                    continue;
                }
                
                result += cnt;
            }
        }

        cout << result << "\n";
    }

    return 0;
}