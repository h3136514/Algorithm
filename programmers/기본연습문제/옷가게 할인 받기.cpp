#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int price) {
    double cal = price;
    if(price >= 500000){
        cal -= cal*0.2;
    }else if(price >= 300000){
        cal -= cal* 0.1;
    }else if(price >= 100000){
        cal -= cal*0.05;
    }
    
    answer = (int)cal;
    
    return answer;
}