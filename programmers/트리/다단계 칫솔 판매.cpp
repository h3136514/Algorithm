#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, string> parent;   // 판매원 - 추천인(판매원을 참여시킨)
unordered_map<string, int> total;   // 판매원 - 판매원의 수익(돈)

// 각각은 자신을 추천인과 연결되어 피라미드 식의 구조를 이루고 있습니다. 판매에 의하여 발생하는 이익에서 10% 를 계산하여 자신을 조직에 참여시킨 추천인에게 배분하고 나머지는 자신이 가질 때 각 판매원이 득한 이익금을 반환(enroll 길이: N,  seller 길이: M, 시간복잡도 : O(N*M))
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    // 판매원 - 추천인 구성, 수익을 0으로 초기화
    for(int i = 0; i < enroll.size(); i++){
        parent[enroll[i]] = referral[i];
        total[enroll[i]] = 0;
    }
    // 
    for(int i = 0; i < seller.size(); i++) {
        int money = amount[i] * 100;    // 현재 판매원의 수익금
        string name = seller[i];    // 실제 문걸을 판 사람
        
        // 추천인을 계속 추적하며 남은 수익의 10%를 분배
        while(money > 0 && name != "-"){
            int plus = money / 10; // 10% 추천인 이익금
            total[name] += money - plus;
            //현재 이름의 추천인이있으면, 현재이름은 추천인으로 변경, 그렇지 않으면 종료 
            if(parent.find(name) != parent.end())
                name = parent[name];
            else
                break;
            
            money = plus;   // 추천인으로 변경되었으므로, 수익금도 이에 맞춰서 업데이트
        }
    }
    
    // 수익금을 answer에 업데이트 해서 반환
    vector<int> answer;
    for(int i = 0; i < enroll.size(); i++)
        answer.push_back(total[enroll[i]]);
    
    return answer;
}


#include <iostream>

using namespace std;

void print(vector<int> vec)
{
    cout << vec[0];
    for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
    cout << endl;
}

int main()
{
    print(solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, 
                   {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                   {"young", "john", "tod", "emily", "mary"},
                   {12, 4, 2, 5, 10}
                  )); //출력값 : 360 958 108 0 450 18 180 1080
                  
        print(solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, 
                       {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                       {"sam", "emily", "jaimie", "edward"},
                        {2, 3, 5, 4}
                      )); //출력값 : 0 110 378 180 270 450 0 0 
    return 0;
}