#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
int N, i, num;
char c[15];
deque <int> dq;
int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s", &c);
        if(!strcmp(c,"push_front")){
            scanf("%d", &num);
            dq.push_front(num);
        } else if(!strcmp(c,"push_back")){
            scanf("%d", &num);
            dq.push_back(num);
        }else if(!strcmp(c,"pop_front")){
            if(!dq.size())
                printf("-1\n");
            else{
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }else if(!strcmp(c,"pop_back")){
            if(!dq.size())
                printf("-1\n");
            else{
                printf("%d\n", dq.back());
                dq.pop_back();
            }
        }else if(!strcmp(c,"size")){
            printf("%d\n", dq.size());
        }else if(!strcmp(c,"empty")){
            if(dq.empty())
                printf("1\n");
            else
                printf("0\n");
        }else if(!strcmp(c,"front")){
            if(!dq.size())
                printf("-1\n");
            else{
                printf("%d\n", dq.front());
            }
        }else if(!strcmp(c,"back")){
            if(!dq.size())
                printf("-1\n");
            else{
                printf("%d\n", dq.back());
            }
        }
            
    }
    return 0;
}