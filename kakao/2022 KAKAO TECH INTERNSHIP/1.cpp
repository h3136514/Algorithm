#include <string>
#include <vector>

using namespace std;
int i, cnt, score[8];
void find(string s, int a){
    if(!s.compare("AN")){
        if(a==4)
            return;
        if(a>4)
            score[1] +=a-4;
        else
            score[0] +=4-a;
    }
     else if(!s.compare("NA")){
        if(a==4)
            return;
        if(a>4)
            score[0] +=a-4;
        else
            score[1] +=4-a;
    }
     else if(!s.compare("JM")){
        if(a==4)
            return;
        if(a>4)
            score[3] +=a-4;
        else
            score[2] +=4-a;
    }
    else if(!s.compare("MJ")){
        if(a==4)
            return;
        if(a>4)
            score[2] +=a-4;
        else
            score[3] +=4-a;
    }
     else if(!s.compare("CF")){
        if(a==4)
            return;
        if(a>4)
            score[5] +=a-4;
        else
            score[4] +=4-a;
    }
    else if(!s.compare("FC")){
        if(a==4)
            return;
        if(a>4)
            score[4] +=a-4;
        else
            score[5] +=4-a;
    }
    else if(!s.compare("RT")){
        if(a==4)
            return;
        if(a>4)
            score[7] +=a-4;
        else
            score[6] +=4-a;
    }
    else if(!s.compare("TR")){
        if(a==4)
            return;
        if(a>4)
            score[6] +=a-4;
        else
            score[7] +=4-a;
    }
   
}
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(i=0;i<survey.size();i++){
        find(survey[i], choices[i]);
    }
    answer += score[6] >= score[7] ? "R": "T";
    answer += score[4] >= score[5] ? "C": "F";
    answer += score[2] >= score[3] ? "J": "M";
    answer += score[0] >= score[1] ? "A": "N";
    return answer;
}