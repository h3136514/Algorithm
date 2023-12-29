#include<cstdio>
#include<stack>
using namespace std;

int i, N, num,sum;
stack <int> st;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &num);
        if(num==0)
            st.pop();
        else
            st.push(num);

    }
    int len =st.size();
    for(i=0;i<len;i++){
        sum +=st.top();
        st.pop();
    }
    printf("%d\n",sum);
    return 0;
}

