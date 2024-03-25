#include<cstdio>
#include <algorithm>
#include<string>
#include<set>
#include<vector>
using namespace std;
vector<string> v;
set<string> s;
char str[21];
int N, M, i;

int main() {
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++){
        scanf("%s", &str);
        s.insert(str);
    }
    set<string>::iterator iter;
    for(i=0;i<M;i++){
        scanf("%s", &str);
        iter = s.find(str); //찾는 값이 있으면 해당 위치의 iterator 반환, 아니면 s.end()반환 
        if(iter != s.end()){
            v.push_back(str);
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for(i=0;i<v.size();i++){
        printf("%s\n", v[i].c_str());
    }

    return 0;
}