#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

#define INF 20001
using namespace std;
int dp[20001];  // t(타겟 문자열)의 각 위치에서 필요한 strs(문자열 원소)의 최소 조각수를 저장
unordered_set<int> sizes;   // strs 조각들의 길이를 저장한 집합

// 단어 조각들을 담고 있는 배열 strs와 완성해야 하는 문자열 t가 주어질 때, 주어진 문장을 완성하기 위해 사용해야 하는 단어조각 개수의 최솟값을 반환(불가능하면 -1)
int solution(vector<string> strs, string t)
{
    int n = t.length();
    
    //dp 초기화
    dp[0] = 0; // 빈 문자열을 얻기 위한 최소 조각수는 0
    for(int i = 1; i <= n; i++)
        dp[i] = INF;
    
    for(int i = 0; i < strs.size(); i++)
        sizes.insert(strs[i].length());
    
    // count()함수를 사용하기 위해 strs(벡터) => set으로 할당
    unordered_set<string> setStrs(strs.begin(), strs.end());
    
    for(int i = 1; i <= n; i++) {
        for(int size : sizes) {  // 각 str 조각의 문자열 길이에 대하여
            // 이미 구한 해와 str 조각을 추가해서 문자열을 만들 수 있다면
            if(size <= i && setStrs.count(t.substr(i-size, size)))
                dp[i] = min(dp[i], dp[i - size] + 1);
        }
    }
    
    // 최소 조각수(만들 수 없으면 -1)
    int result = (dp[n] == INF) ? -1 : dp[n];

    return result;
}


// 테스트 코드
#include <iostream>


void init() {
    sizes.clear();
}

int main()
{
    cout << solution({"ba", "na", "n", "a"}, "banana") << endl; //출력값 : 3
    init();
    cout << solution({"app", "ap", "p", "l", "e", "ple", "pp"}, "apple") << endl; //출력값 : 2  
    init();
    cout << solution({"ba", "an", "nan", "ban", "n"}, "banana") << endl; //출력값 : -1 
  
    return 0;
}