//카카오
// https://school.programmers.co.kr/learn/courses/30/lessons/258712
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;
map<string,int> fri; 
vector<string> human(2);
int answer = 0, CNT = 1;
int dp[51][51], sum[51], giftScore[51];

int solution(vector<string> friends, vector<string> gifts) {
    for(string s : friends){
        fri[s] = CNT++;
    }
    
    for(string s : gifts){
        int idx = 0;
        stringstream ss(s);
        string word = "";
        
        while(getline(ss, word, ' ')){
            human[idx++] = word; 
        }
        int a = fri[human[0]];
        int b = fri[human[1]];
        
        giftScore[a]++;
        giftScore[b]--;
        dp[a][b]++;
    }
    
    CNT--;
    for(int i =1; i < CNT;i++){
        for(int j =i+1; j <= CNT;j++){
            if(dp[i][j] < dp[j][i]){
                sum[j]++;
            }else if(dp[i][j] > dp[j][i]){
                sum[i]++;
            }else{
                if(giftScore[i] > giftScore[j]){
                    sum[i]++;
                }else if(giftScore[i] < giftScore[j]){
                    sum[j]++;
                }
            }
        }
    }
    
    for(int i =1; i <= CNT;i++){
        answer = max(answer, sum[i]);
    }
    
    return answer;
}