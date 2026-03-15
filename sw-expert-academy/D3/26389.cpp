// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AZyNUDmaATzHBIRj&categoryId=AZyNUDmaATzHBIRj&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1
#include <iostream>
#include <string>

using namespace std;
int T; 
string s, result;

// 여행
int main(){
    cin >> T;
    while(T--){
        cin >> s;
        bool N = false, S = false, W = false, E = false;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'N')
                N = true;
            else if(s[i] == 'S')
                S = true;
            else if(s[i] == 'W')
                W = true;
            else
                E = true;
        }

        if(((N && S)|| (!N && !S))&&((W && E)|| (!W && !E)))
            result = "Yes";
        else
            result = "No";

        cout << result << "\n";
    }

    return 0;
}