#include <vector>
#include <unordered_map>

using namespace std;

// N마리 폰켓몬의 종류 번호가 주어질 때, N/2마리의 폰켓몬을 선택하는 방법 중, 가장 많은 종류의 폰켓몬을 선택하는 방법을 찾아, 그때의 폰켓몬 종류 번호의 개수를 반환 (시간복잡도 : O(N))
int solution(vector<int> nums)
{  
    unordered_map<int, vector<int>> pocketMon;

    for(int i = 0; i < nums.size(); i++)
        pocketMon[nums[i]].push_back(i);  
    
    if(nums.size()/2 <= pocketMon.size())
        return nums.size()/2 ;
    else //중복으로 인해 종류가 N/2마리 이하일 때
        return pocketMon.size(); 
}

#include <iostream>

int main()
{
  cout << solution({3,1,2,3}) << endl; //출력값 : 2
  cout << solution({3,3,3,2,2,4}) << endl; //출력값 : 3
  cout << solution({3,3,3,2,2,2}) << endl; //출력값 : 2
  
  return 0;
}

//set을 통한 더 간단한 풀이
/*
#include <unordered_set>

int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}


*/
