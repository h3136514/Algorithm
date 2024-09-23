#include <vector>

using namespace std;
int location, idx, cnt;

// 아파트의 개수 N, 현재 기지국이 설치된 아파트의 번호가 담긴 배열 stations, 전파의 도달 거리 W가 주어질 때, 모든 아파트에 전파를 전달하기 위해 증설해야 할 기지국 개수의 최솟값 반환
int solution(int n, vector<int> stations, int w)
{   
    location = 1;   // 현재 탐색하는 아파트의 위치
    idx = 0;    // 설치된 기지국의 인덱스
    cnt = 0;    // 추가로 설치한 기지국 수
    while(location <= n) {
        // 기지국이 설치된 위치에 도달한 경우
        if(idx < stations.size() && location >= stations[idx] - w) {
            location = stations[idx] + w + 1;
            idx++;
        } else {     // 기지국이 설치되지 않은 위치인 경우
            cnt++;  //기지국을 설치
            location += w*2 + 1;    // 해당 범위를 넘어감
        }
    }
    
    return cnt;
}


// 테스트 코드
#include <iostream>

int main()
{
    cout << solution(11, {4, 11}, 1) << endl; // 3
    cout << solution(16, {9}, 1) << endl;   // 5
    return 0;
}