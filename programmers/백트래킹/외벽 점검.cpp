#include <string>
#include <vector>
#include <algorithm>

#define MAX_DIST 20
using namespace std;
int length, result = MAX_DIST;
vector<int> weaks, dists;

int solution(int n, vector<int> weak, vector<int> dist) {
    int length = weak.size();
    
    // Weak 리스트 확장(원형 문제 해결을 위해 weak 배열 2배 확장)
    for(int i = 0; i <  length; i++) {
        weak.push_back(weak[i] + n);
    }
    
    // 시작점 설정 및 친구 순열 생성
    for(int start = 0; start < length; start++) {
        do {
            // 친구 배치 및 수 계산
            int cnt = 1;
            int position = weak[start] + dist[cnt - 1];
            
            //그 다음 weak 지점 확인
            for(int i = start; i < start + length; i++) {
                // 범위 밖이므로 추가로 친구를 배치해야 함
                if(position < weak[i]) {
                    cnt += 1;
                    
                    //친구 수 초과 확인
                    if(cnt > dist.size())
                        break;
                    
                    position = weak[i] + dist[cnt - 1];
                }
            }
            
            // 최소 친구 수 업데이트
            result = min(result, cnt);
            
        } while(next_permutation(dist.begin(), dist.end()));    // 순열 생성
    }
    
    if(result > dist.size())
        return -1;
    
    return result;
}

#include <iostream>

using namespace std;

int main()
{
   cout << solution(12, {1, 5, 6, 10},{1, 2, 3, 4}) << endl; //출력값 : 2
   cout << solution(12, {1, 3, 4, 9, 10},{3, 5, 7}) << endl; //출력값 : 1   
   
   return 0;
}