#include<cstdio>
#include<string>    //atoi()사용
#include<iostream>  //string문 출력
using namespace std;

int T, i, num, month, day;
bool check[6];     //해당 날짜의 유효성 판단(false:유효)
char input[10];

string result[6];
int main(){
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%s",input);
        num =atoi(input); //문자열 => 정수 변환
        day = num%100;
        num = num/100;
        month = num%100;
        switch(month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(day<=0 || day>31)
                    check[i] = true;
                break;
            case 2:
                if(day<=0 || day>28)
                    check[i] = true;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(day<=0 || day>30)
                    check[i] = true;
                break;
            default: 
                check[i] =true;
                break;
        }
        result[i]=input;
        result[i].insert(4,"/");
        result[i].insert(7,"/");
    
    }
     for(i=1;i<=T;i++){
        if(check[i])
        {
            printf("#%d %d\n",i, -1);
            continue;
        }
        cout << "#"<< i << " "<<result[i] << endl;  // <iostream> =>string 출력
     }

    return 0;
}