#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// 10진수를 입력받아 2지수로 변환하기 (시간복잡도 : O(logN))
string solution(int n)
{
   //입력 값이  0인 경우 바로 처리
    if (n == 0) return "0"; 

    stack<int> stack;
    while (n > 0) {
        //2로 나눈 나머지를 스택에 삽입
        stack.push(n % 2);  
        n /= 2;
    }

    string answer ="";

    while (!stack.empty()) {
       //스택에서 차례대로 top()에 해당되는 값을 추가
        answer += to_string(stack.top());  
        stack.pop();
    }

    return answer;
}

#include <iostream>
int main()
{
    
    cout << solution(10) << endl;  // 1010
    cout << solution(27) << endl; // 11011 

    return 0;
}

//스택 안쓰고
/*
string solution(int n)
{
    string answer;
    while(n > 0) {
        if(n%2 == 0)
            answer += '0';
        else
            answer += '1';
        n = n/2;
    }

    // 문자열 뒤집기
    reverse(answer.begin(), answer.end());
    
    return answer;
}
*/