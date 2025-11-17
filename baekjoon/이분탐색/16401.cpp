#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000000001
using namespace std;
int N, M, result;
vector<int> v;

void binarySearch(){
    int s = 1, e = MAX;
    while(s <= e){
        int mid = (s+e)/2;
        int cnt = 0;
        for(int i = N-1; i >= 0; i--){
            if(v[i] < mid)
                break;
            cnt += v[i]/mid;
        }

        if(M <= cnt){
            result = max(result, mid);
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    } 
}

// 과자 나눠주기
int main(){
    cin >> M >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    binarySearch();

    result = (result == MAX) ? 0 : result;

    cout << result << "\n";

    return 0;
}