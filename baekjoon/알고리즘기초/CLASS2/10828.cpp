#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int N, num, i;
char c[6];
stack<int> s;
int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s", &c);
        if(!strcmp(c, "push"))
        {
            scanf("%d", &num);
            s.push(num);
        }else if(!strcmp(c, "top")){
            if(s.size())
                printf("%d\n", s.top());
            else
                printf("-1\n");
        }else if(!strcmp(c, "size")){
            printf("%d\n", s.size());
        }else if(!strcmp(c, "pop")){
            if(s.size()){
                int top = s.top();
                printf("%d\n", top);
                s.pop();
            }else
                printf("-1\n");
        }else if(!strcmp(c, "empty")){
            if(s.empty())
                printf("1\n");
            else
                printf("0\n");
        }

    }
    return 0;
}