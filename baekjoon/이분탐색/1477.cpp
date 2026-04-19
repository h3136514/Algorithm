//https://www.acmicpc.net/problem/1477
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, L, num, dist;
vector<int> v;

void binarySearch(){
    int s = 1, e = L - 1; // 고속도로 끝에는 못지음
    while(s <= e){
        int mid = (s+e)/2;

        int cnt = 0;
        for(int i = 1; i < v.size(); i++){
            int idist = v[i] - v[i-1];

            cnt += idist/mid;
            if(idist%mid == 0)  // 추가 휴계소 수(구간수 -1)
                cnt--;
        }
   
        if(cnt > M){
            s = mid + 1;
        }else{
            dist = min(dist, mid);
            e = mid - 1;
        }
    }
}

// 휴게소 세우기
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> L;

    for(int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }
    v.push_back(0); // 시작점
    v.push_back(L); // 끝점
    sort(v.begin(), v.end());
    dist = L-1;

    binarySearch();

    cout << dist << "\n";

    return 0;
}