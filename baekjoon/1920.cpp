#include<cstdio>
#include<algorithm>
int n,m,a,mid,i,num[100000];
using namespace std;		//sort()쓰기위해 필요 
 
//이진 탐색 
int b(int v,int start,int end){
	while(start <=end){
	mid=(start+end)/2;
	if(num[mid]==v) 
		return 1;
	else if(num[mid]>v)
		end=mid-1;
	else
		start=mid+1;		
	}
	return 0;
}


int main(){
	scanf("%d",&n);
	for	(i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	
	// 정렬
	sort(num,num+n);
	scanf("%d",&m);
		for	(i=0;i<m;i++){
			scanf("%d",&a);
			printf("%d\n",b(a,0,n-1));
		}
	
		
}
