#include <string>
#include <vector>
#include <stack>

using namespace std;
// 스택에는 이전 가격과 현재 가격을 비교하기 위한 용도로 prices의 인덱스가 들어감 (시간복잡도 : O(N))
stack<int> st;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    for(int i = 0; i < prices.size(); i++) {
        // 가격이 떨어졌으므로 이전 가격의 기간 계산 
        while(!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();   
        }
        st.push(i);
    }
    // 가격이 떨어지지 않은 경우(기간 계산후 지정)
    while(!st.empty()) {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }
    
    return answer;
}

#include<iostream>

int main() {
    vector<int> arr = solution({1, 2, 3, 2, 3});
    for(int i =0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
    return 0;
}