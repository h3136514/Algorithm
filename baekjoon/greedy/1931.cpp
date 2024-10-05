#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N, s, e, check[100001], CNT;
vector<pair<int, int>> v;

// 정렬 비교함수
bool compair(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    
    return a.first < b.first;
}

// lower_bound()에 사용할 비교함수
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

// 회의실 배정
int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), compair);  // 비교함수 안써도 되긴함(오른차순 임므로)

    pair<int, int> a;
    a.first = v[0].first;
    a.second = v[0].second;

    int cnt =1;
    for(int i =1; i < N; i++) {
        pair<int, int> b;
        b.first = v[i].first;
        b.second = v[i].second;
        // 회의시작 == 회의 끝 같은 것
        if(a.first == a.second) {
            cnt++;
            a.first = b.first;
            a.second = b.second;
            continue;
        }

        if(i != lower_bound(v.begin(), v.end(), b, comp) - v.begin()) // 처음 나오는 시작시간이 X(제일 회의시간이 짧은것) 
            continue;
       
    
        // 회의 끝(다른 회의선택)
        if(a.second <=  b.first)
        {   
            cnt++;
            a.first = b.first;
            a.second = b.second;
            continue;
        }
        if(a.second > b.second) {    //회의 변경(더 회의시간이 짧음 회의 선택)
            a.first =  b.first;
            a.second  = b.second;
        }
    }

    cout << cnt <<  "\n";

    return 0;
}