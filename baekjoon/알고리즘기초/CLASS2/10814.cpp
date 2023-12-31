#include<cstdio>
#include<queue>
#include<string>
using namespace std;
priority_queue <pair<int, int>> q;
int N, i, num, idx;
char inputName[101];
string names[100001];
string name;
int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d %s", &num, &inputName);
        name = inputName;
        q.push({-num, -i});
        names[i] = name;
    }
    int len =q.size();
    for(i=0;i<len;i++){
        num =-q.top().first;
        idx =-q.top().second;
        q.pop();
        printf("%d %s\n", num,names[idx].c_str());
    }
    return 0;
}