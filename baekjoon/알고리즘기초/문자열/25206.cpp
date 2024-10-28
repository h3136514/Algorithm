#include <iostream>
#include <string>

using namespace std;
double score, sum, CNT;
string subject, grade;

// 과목평점 계산
double checkGrade(string str){
    if(str == "A+")
        return 4.5;
    else if(str == "A0")
        return 4.0;
    else if(str == "B+")
        return 3.5;
    else if(str == "B0")
        return 3.0;
    else if(str == "C+")
        return 2.5;
    else if(str == "C0")
        return 2.0;
    else if(str == "D+")
        return 1.5;
    else if(str == "D0")
        return 1.0;
    else if(str == "F")
        return 0;
    else
        return -1;
}

// 너의 평점은
int main(){
    for(int i = 0; i < 20; i++){
        cin >> subject >> score >> grade;

        double gradeDouble = checkGrade(grade);
        if(gradeDouble == -1)   //'P'인 과목은 계산에서 제외
            continue;

        CNT += score;
        sum += score*gradeDouble;
    }
    
    if(CNT == 0)
        cout << CNT << "\n";
    else
        cout << sum/CNT << "\n";

    return 0;
}