#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector <pair<int, string>> v;
int N, i, len;
char word[51];
string sword;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s", &word);
        sword =word;
        len= sword.length();
        v.push_back({len, sword});
    }
    sort(v.begin(), v.end());
    sword ="";
    for(i=0;i<N;i++){
        if(sword.compare(v[i].second))
            sword =v[i].second;
        else
            continue;
        printf("%s\n", v[i].second.c_str()); //string문.c_str() =>문자열 scanf출력
    }
    return 0;
}