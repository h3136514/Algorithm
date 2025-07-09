#include<iostream>
#include<string>
#include<stack>

using namespace std;
string N, answer;
stack<int> s;

// 8진수 => 2진수
string eightToTwo(int num){
    string tmp = "";
    if(num == 0)
        return "0";

    while(num > 0){
        if(num % 2 == 1)
            s.push('1');
        else
            s.push('0');
        
        num /= 2;
    }

    while(!s.empty()){
        tmp += s.top();
        s.pop();
    }

    return tmp;
}

// 8진수 2진수
int main(){
    cin >> N;
    for(int i = 0; i < N.size(); i++){
        int num = N[i] - '0'; // string => int
        if(i == 0){
            answer += eightToTwo(num);
        }else{
            string two = eightToTwo(num);
            for(int j = two.size(); j < 3; j++) // 남은 공백 처리('0')
                answer += '0';
            answer += two;
        }
    }

    cout << answer << "\n";

    return 0;
}
