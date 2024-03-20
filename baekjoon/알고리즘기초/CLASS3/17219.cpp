#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

map <string, string> pw;
char str1[21], str2[21]; 
int N, M;

int main(){
    scanf("%d %d", &N, &M);
    while(0 < N--){
        scanf("%s %s", &str1, &str2);
        pw.insert({str1, str2});
    }
    while(0 < M--){
        scanf("%s", &str1);
        printf("%s\n",pw.at(str1).c_str() );
    }
    return 0;
}