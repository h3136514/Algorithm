#include <string>
#include <vector>

using namespace std;
int i, j,p1_s, p1_e, p2_s, p2_e,l;
long long sum1, sum2;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    vector<int> V;
    l=queue1.size()+queue2.size()-1;
    p1_s=0;
    for(i=0;i<queue1.size();i++){
        sum1 += queue1[i];
        V.push_back(queue1[i]);
    }
    p1_e=i-1;
    p2_s=i;
    for(j=0;j<queue2.size();j++){
        sum2 += queue2[j];
        V.push_back(queue2[j]);
    }
    p2_e=l;
    if((sum1+sum2)%2 !=0)
            return -1;
    while(answer<4*queue1.size()){
        if(sum1>sum2){
            sum1 -= V[p1_s];
            sum2 += V[p1_s];
         
            if(p1_s==l){
                p1_s=0;
                p2_e=l;     
            } 
            else{
                 p2_e= p1_s;
                 p1_s++;
                
            }
        }
         else if(sum1<sum2){
            sum1 += V[p2_s];
            sum2 -= V[p2_s];
            if(p2_s==l){
                p2_s=0;
                p1_e=l;
            } 
            else{
                 p1_e= p2_s;
                 p2_s++;
                
            }
        }
        else    //(sum1==sum2)
            return answer;
        
        answer++;
    }

    return -1;

}