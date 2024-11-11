#include <iostream>
#include <vector>
#include <algorithm>    // next_permutation() 사용

#define MAX 987654321
using namespace std;
int N, num[11][11], CNT = MAX;
vector<int> v;

// 외판원 순회 2
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> num[i][j];
        }
    }

    // 이동 순서 대입
    for(int i = 1; i <= N; i++){
        v.push_back(i);
    }

    do{
        int sum = 0;
        bool check = false; // 길이 없는지 확인
        for(int i = 0; i < v.size() - 1; i++){
            int a = v[i];
            int b = v[i+1];
            if(num[a][b] == 0){
                check = true;
                break;
            }
            sum += num[a][b];   // a -> b 이동
        }
        int a = v[ v.size() - 1];
        int b = v[0];
        if(num[a][b] == 0)
            check = true;

        sum += num[a][b];   // 마지막 -> 첫 번째 이동

        if(check)
            continue;

        CNT = min(CNT, sum);
        
    }while(next_permutation(v.begin(), v.end()));   // 모든 순서들 확인

    cout << CNT << "\n";

    return 0;
}