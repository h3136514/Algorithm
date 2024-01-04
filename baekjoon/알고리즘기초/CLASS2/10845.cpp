#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int N, i, num;
char c[6];
queue <int> q;
int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s", &c);
        if(!strcmp(c,"push")){
            scanf("%d", &num);
            q.push(num);
        } else if(!strcmp(c,"pop")){
            if(!q.size())
                printf("-1\n");
            else{
                printf("%d\n", q.front());
                q.pop();
            }
        }else if(!strcmp(c,"size")){
            printf("%d\n", q.size());
        }else if(!strcmp(c,"empty")){
            if(q.empty())
                printf("1\n");
            else
                printf("0\n");
        }else if(!strcmp(c,"front")){
            if(!q.size())
                printf("-1\n");
            else{
                printf("%d\n", q.front());
            }
        }else if(!strcmp(c,"back")){
            if(!q.size())
                printf("-1\n");
            else{
                printf("%d\n", q.back());
            }
        }
            
    }
    return 0;
}