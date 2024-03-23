#include<cstdio>
#include<cstring>
#include<string>
#include <cctype>
#include<map>
using namespace std;

map <string, int> str;
map <int, string> num;
char input[21]; 
int N, M, i;

int main(){
    scanf("%d %d", &N, &M);
    for(i=1;i<=N;i++){
        scanf("%s", &input);
        str.insert({input, i});
        num.insert({i, input});
    }
    while(0 < M--){
        scanf("%s", &input);
        if(isdigit(input[0]))
            printf("%s\n", num.at(stoi(input)).c_str());
        else
            printf("%d\n", str.at(input));
    }
    return 0;
}