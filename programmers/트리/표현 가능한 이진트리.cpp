//https://school.programmers.co.kr/learn/courses/30/lessons/150367?language=cpp
// 분할 정복
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> answer;

// 십진수 => 이진수(문자열)
string HexToDec(long long number)
{
    string result;
    while(number > 0)
    {
        result = to_string(number % 2) + result;
        number /= 2;
    }
    return result;
}

// 포화 이진 트리(빈칸 채우기)
string FillBinary(string num){
    string result;
    int size = 1;
    while(true){
        if(num.size() <= size-1)
            break;
        size *= 2;
    }
    
    string zero;
    for(int i = num.size(); i < size -1; i++){
        zero += '0';
    }
    result = zero + num;
    
    return result;
}

bool check(string num){
    // 모두 0 일 때
    bool isZero = true;
    for(int i = 0; i < num.size(); i++){
        if(num[i] != '0'){
            isZero = false;
            break;
        }
    }
    
    if(num.size() == 1 || isZero)
        return true;
    
    int mid = num.size()/2;
    string left = num.substr(0, mid);
    string right = num.substr(mid+1);
    
    // 분할 정복
    if(num[mid] == '1' && check(left) && check(right))
        return true;
    
    return false;
}

vector<int> solution(vector<long long> numbers) {
    for(int i = 0; i < numbers.size(); i++){
        string binaryCo = HexToDec(numbers[i]);
        string fillNum = FillBinary(binaryCo);
        if(check(fillNum))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}