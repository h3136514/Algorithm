#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
//want를 키, number를 값으로 하는 해시맵
unordered_map<string, int> wantMap;

// 회원등록시 원하는 제품을 모두 할인 받을 수 있는 회원등록 날짜의 총 일수를 반환(시간복잡도 : O(N))
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    // want, number를 해시맵에 저장
    for(int i = 0; i < want.size(); i++){
        wantMap[want[i]] = number[i];
    }
    
    for(int i = 0; i < discount.size() - 9; i++){
        // i일 회원가입 시, 할인받을 수 있는 품목을 키로, 개수를 값으로 하는 해시맵 선언
        unordered_map<string, int> discountMap;

        // 각 할인하는 품목을 키로 개수를 저장
        for(int j = i; j < 10 + i; j++)
            discountMap[discount[j]]++;

        // 할인하는 상품의 품목및 개수가 원하는 상품의 품목 및 개수와 일치하면 카운트 증가
        if(wantMap == discountMap)
            answer++;
    }

    return answer;
}

#include <iostream>

int main()
{
  cout << solution( {"banana", "apple", "rice", "pork", "pot"}, 
                    {3, 2, 2, 2, 1}, 
                    {"chicken", "apple", "apple", "banana", "rice","apple", "pork", "banana", "pork", "rice", "pot","banana", "apple", "banana"}) << endl; // 3
                      
  cout << solution( {"apple"}, 
                    {10}, 
                    {"banana", "banana", "banana", "banana","banana", "banana", "banana", "banana", "banana","banana"}) << endl; // 0
  return 0;
}

// 10개의 품목을 업데이트 하는 대신 가장 오래된 정보를 제거하고 최신정보를 추가하는 풀이(성능이 좀 더 우수, 시간복잡도 : O(N))
/*
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    // want, number를 해시맵에 저장
    for(int i = 0; i < want.size(); i++){
        wantMap[want[i]] = number[i];
    }

    unordered_map<string, int> discountMap;
    // 9일치 정보를 미리 할당
    for(int i = 0; i < 9; i++)
        discountMap[discount[i]]++;
    
    // discountMap에 최근의 정보를 추가하고, 가장 오래된 정보를 제거
    for(int i = 9; i < discount.size(); i++){
        discountMap[discount[i]]++;
        // 할인하는 상품의 품목및 개수가 원하는 상품의 품목 및 개수와 일치하면 카운트 증가
        if(wantMap == discountMap)
            answer++;
        
        if(--discountMap[discount[i - 9]] == 0)
            discountMap.erase(discount[i - 9]);
    }

    return answer;
}
*/