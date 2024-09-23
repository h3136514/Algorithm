#include <vector>
#include <algorithm>

using namespace std;
int cnt;    // 필요한 보트 개수

// 사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 주어질 때, 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 반환(한 번에 최대 2명)
int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    cnt = 0;
    int s = 0;  // 가장 가벼운 사람을 가리키는 인덱스
    int e = people.size() - 1;  // 가장 무거운 사람을 가리키는 인덱스
    while(s <= e) {
        if(people[s] + people[e] <= limit)  // 가벼운 사람을 같이 태울 수 있으면 두 사람 모두 보트에 태움
            s++;
        e--;     // 무거운 사람만 태울 수 있으면 무거운 사람만 보트에 태움
        cnt++;
    }
    
    return cnt;
}


// 테스트 코드
#include <iostream>

int main()
{
    cout << solution({70, 50, 80, 50}, 100) << endl; //출력값 : 3
    cout << solution({70, 80, 50}, 100) << endl; //출력값 : 3
  
    return 0;
}