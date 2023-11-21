#include<cstdio>
#include<vector>
using namespace std;

vector<pair<int,int>> V;

int i, j, k, l, N, result, cnt;
bool check[16][16];
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

int main(){
    //입력
    scanf("%d", &N); 
    j=0;
    V.push_back({-1,-1}); //맨 처음을 위하여 아무거나 하나 넣어줌
    while(!V.empty()){
        int row=V.back().second; //제일 마지막 값
        int col=V.back().first;
            
        //맨 처음값제거
        if(row==-1){
            V.pop_back();
            col=-1;
            row=0;
        }
        else//가로줄 끝까지 왔을때
        {
            V.pop_back();    //제일 마지막 값을 지운다.
            check[row][col]=false;
            j--;
        }
        cnt=row;
        j=row;
        //놓을 곳 정하기
        while(true){
            if(j!=cnt)
                break;
            for(l=col+1;l<N;l++){
                if(j>=N)
                    break;
                if(checking(N,j,l))
                    continue;
                else{
                    check[j][l]=true;
                    V.push_back({l,j});
                    col=-1;
                    j+=1;
                    break;
                }
            }
            cnt++;
            if(j==N)
            {   j--;
                result +=1;
                break;
            }
            if(cnt>=N)
                break;
        }
    }
    //출력
    printf("%d\n",result);  
    return 0;
}