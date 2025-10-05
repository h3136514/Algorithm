#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
vector<string> v;
int maxNum, minNum, CNT;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    
    string num;
    while(getline(ss, num, ' ')){
        int numInt = stoi(num);
        
        if(CNT++ == 0){
            maxNum = numInt;
            minNum = numInt;
            continue;
        }
        
        maxNum = max(numInt, maxNum);
        minNum = min(numInt, minNum);
    }
    
    answer = to_string(minNum) + " " + to_string(maxNum);
    
    return answer;
}