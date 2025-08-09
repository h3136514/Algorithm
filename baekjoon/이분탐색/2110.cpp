#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, C, startX, endX, answer, preHouse;
vector<int> house;

// 공유기 설치
int main(){
    cin >> N >> C;

    house.resize(N);
    for(int i = 0; i < N; i++){
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    startX = 1;
    endX = house[N-1] - house[0];
    while(startX <= endX){
        int mid = (startX + endX) / 2;

        int cnt = 1;
        preHouse = house[0];
        for(int i = 1; i < N; i++){
            if(house[i] - preHouse >= mid){
                cnt++;
                preHouse = house[i];
            }
        }

        if(cnt >= C){   // 공유기를 제한 갯수 이상 사용했을 경우, 설치 거리를 늘린 후 다시 설치
            answer = max(answer, mid);
            startX = mid + 1;
        }else   // 공유기를 제한 갯수 미만 사용했을 경우, 설치 거리를 좁힌 후 다시 설치
            endX = mid - 1;
    }

    cout << answer << "\n";

    return 0;
}