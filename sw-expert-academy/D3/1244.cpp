#include<cstdio>
#include<queue>
using namespace std;

priority_queue<int> iq[16];     //바꾼 애들 인덱스 저장
priority_queue<int> vq[16];     //바꾼 애들 값 저장

int T, N, cnt, v, i, j, tmp, maxi, targeti, num[16][6],result[16][6], checkNum[16][10],checkS[16][10];;
bool overlap[16]; //중복 숫자 유무
bool st[16];
bool one;
void init(){
    for(i=1;i<16;i++)
        for(j=0;j<6;j++){
            result[i][j]=-1;
            num[i][j]=-1;
        }
            
}
//최댓값 인덱스
void maxnum(int a){
    maxi= a-1;
    for(j=a-2;j>=0;j--){
        if(num[i][j] >= num[i][maxi])
            maxi=j;
    }

}
//바꾼애들 체크

//변경
void change(){
    tmp=num[i][maxi];
    num[i][maxi]=num[i][targeti];
    num[i][targeti]=tmp;

    if(checkS[i][num[i][maxi]]==1)
        st[i]=true;
    else
        checkS[i][num[i][maxi]]=1;
    if(checkS[i][num[i][targeti]]==1)
        st[i]=true;
    else
        checkS[i][num[i][targeti]]=1;
}
void q(){
    while(iq[i].size()){
        int here = iq[i].top();
        int value = vq[i].top();
        result[i][here]= value;
        iq[i].pop();
        vq[i].pop();
    }

}
int main(){
    init();
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        scanf("%d", &cnt);
        for(j=0;j<6;j++){
            if(N<=0)
                break;
            num[i][j]=N%10;
            result[i][j]=num[i][j];
            if(checkNum[i][num[i][j]]==1)   //중복 숫자 유무 확인
                overlap[i]=true;
            else
                checkNum[i][num[i][j]]=1;
            N=N/10;
        }
        v=j;// 총 숫자 갯수
        one=false;
        //교환시작
        while(cnt-->0){
            while(true){
                if(v==2)
                    break;
                maxnum(v);
                if(v-1==maxi){
                    v--;
                    continue;
                }else
                    break;
            }
            if(v==2){
                maxi=0;
                targeti=1;
                if(!one)
                {
                    change();
                }
                if(one){
                    if(overlap[i])  //중복숫자 있을시 그것끼리만 바꾸면 됨
                        continue;
                    tmp=num[i][0];
                    num[i][0]=num[i][1];
                    num[i][1]=tmp;   
                }
                one=true;
                continue;
            }
            else{
                targeti=v-1;
                change(); 
            }
            v--;
        }
        for(j=0;j<6;j++){
            if(result[i][j] != num[i][j])
            {
                iq[i].push(j);
                vq[i].push(result[i][j]);
            }   
        }
        if(st[i] && overlap[i])
            q();    //바꾼 애들 중 최적 순서
    }
    //출력
    for(i=1;i<=T;i++){
        printf("#%d ",i);
        for(j=5;j>=0;j--){
            if(result[i][j]==-1)
                continue;
            if(st[i]&& overlap[i])
                printf("%d", result[i][j]);
            else
                printf("%d", num[i][j]);

        }
        printf("\n");
    }
    return 0;
}