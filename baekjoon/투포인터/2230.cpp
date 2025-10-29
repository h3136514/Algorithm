#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000001
using namespace std;
int N, M, result = INF;
vector<int> v;

// 수 고르기
int main(){
    cin >> N >> M;

    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int s = 0, e = 0;
    while(s < N && e < N && s <= e){
        int differ = abs(v[e]-v[s]);
        
        if(differ >= M){
            result = min(result, differ);

            if(differ == M)
                break;
            s++;
        }else{
            e++;
        }
    }


    cout << result << "\n";

    return 0;
}