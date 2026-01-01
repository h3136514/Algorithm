#include <iostream>
#include <cmath>

using namespace std;
int T;
double a, b, bmi;

int cal(){
    int result;
    bmi = b/pow((a/100), 2);

    if(a < 140.1){
        result = 6;
    }else if(a < 146){
        result = 5;
    }else if(a < 159){
        result = 4;
    }else if(a < 161){
        if(bmi >= 16.0 && bmi < 35.0){
            result = 3;
        }else{
            result = 4;
        }
    }else if(a < 204){
        if(bmi >= 20.0 && bmi < 25.0){
            result = 1;
        }else if((bmi >= 18.5 && bmi < 20.0) ||(bmi >= 25.0 && bmi < 30.0) ){
            result = 2;
        }else if((bmi >= 16 && bmi < 18.5) ||(bmi >= 30.0 && bmi < 35.0) ){
            result = 3;
        }else{
            result = 4;
        }
    }else{
        result = 4;
    }

    return result;
}

// 심준의 병역판정검사
int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> a >> b;

        cout << cal() << "\n";
    }

    return 0;
}