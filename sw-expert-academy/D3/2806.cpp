#include<cstdio>
#include<vector>
using namespace std;

vector<pair<int,int>> V[11];

int T, i, j, k, l, N, num[11], result[11], cnt;
bool check[10][10];
bool checking(int n, int a, int b){
     //세로줄 확인
    for(k=0;k<n;k++)
        if(check[k][b]==true)
            return true;
    //가로줄 확인
    for(k=0;k<n;k++)
        if(check[a][k]==true)
            return true;     
    //대각선 확인(왼쪽)
    for(k=0;k<=a;k++)
        if(b-k>=0)
            if(check[a-k][b-k]==true)
                return true;
    //대각선 확인(오른쪽)
    for(k=b;k<n;k++)
        if(a+(b-k)>=0)
            if(check[a+(b-k)][k]==true)
                return true;
    return false;
}

void init(int n){
    for(k=0;k<n;k++)
        for(l=0;l<n;l++)
            check[k][l]=false;
}
int main(){
    for(i=1;i<=10;i++)  //N (1~10)까지 가능한 모든 갯수 계산 
    {
        j=0;
        V[i].push_back({-1,-1}); //맨 처음을 위하여 아무거나 하나 넣어줌
        while(!V[i].empty()){
            int row=V[i].back().second; //제일 마지막 값
            int col=V[i].back().first;
            
            //맨 처음값제거
            if(row==-1){
                V[i].pop_back();
                col=-1;
                row=0;
            }
            else//가로줄 끝까지 왔을때
            {
                V[i].pop_back();    //제일 마지막 값을 지운다.
                check[row][col]=false;
                j--;
            }
            cnt=row;
            j=row;
            //놓을 곳 정하기
            while(true){
                if(j!=cnt)
                    break;
                for(l=col+1;l<i;l++){
                    if(j>=i)
                        break;
                    if(checking(i,j,l))
                       continue;
                    else{
                        check[j][l]=true;
                        V[i].push_back({l,j});
                        col=-1;
                        j+=1;
                        break;
                    }
                }
                cnt++;
                if(j==i)
                {   j--;
                    result[i] +=1;
                    break;
                }
                if(cnt>=i)
                    break;
            }

        }
        init(i);
    }
    //입력
    scanf("%d", &T);
    for(i=1;i<=T;i++)  
        scanf("%d",&num[i]);
    //출력
    for(i=1;i<=T;i++)
        printf("#%d %d\n",i,result[num[i]]);  
    return 0;
}