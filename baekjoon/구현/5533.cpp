#include <iostream>
#include <vector>

using namespace std;
int N, num[101], sum[200];
vector<int> V[200];

void init(){
    for(int i = 1; i <= 100; i++)
        num[i] = 0;
}

// 유니크
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        V[i].resize(3);
        for(int j = 0; j < 3; j++){
            cin >> V[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < N; j++){
            num[V[j][i]]++;
        }
        
        for(int j = 0; j < N; j++){
            if(num[V[j][i]] == 1)
                sum[j] += V[j][i];
        }
        init();
    }

    for(int i = 0; i < N; i++){
        cout << sum[i] << "\n";
    }

    return 0;
}