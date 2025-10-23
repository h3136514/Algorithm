#include <iostream>
#include <vector>
#include <algorithm>

#define INF 3000000001
using namespace std;
int N;
long long differ = INF, result[3];
vector<long long> v;

void binarySearch(int idx){
    int s = 0, e = N-1;

    while(s < e){
        long long sum = v[idx] + v[s] + v[e];
        if(abs(sum) < differ && (s != idx && e != idx)){
            differ = abs(sum);
            result[0] = v[idx];
            result[1] = v[s];
            result[2] = v[e];

            if(sum == 0)
                break;
        }

        if(s == idx || sum < 0){
            s++;
        }else
            e--;
    }
}

// 세 용액
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        binarySearch(i);
    }
    
    for(int i = 0; i < 3; i++){
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}