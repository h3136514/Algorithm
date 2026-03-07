#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, CNT = 36, targetA, targetB;
string s;
vector<vector<string>> V;

void cal(int a, int b){
    int cnt = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            if(V[a][i][j] != V[b][i][j])
                cnt++;
        }
    }

    if(CNT > cnt){
        CNT = cnt;
        targetA = a+1, targetB = b+1;
    }
}

// 그림 비교
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        vector<string> tmp;
        for(int j = 0; j < 5; j++){
            cin >> s;
            tmp.push_back(s);
        }
        V.push_back(tmp);
        tmp.clear();
    }

    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            cal(i, j);
        }
    }

    cout << targetA << " " << targetB << "\n";
    return 0;
}