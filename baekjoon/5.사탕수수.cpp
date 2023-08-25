#include<cstdio>
int A,B,C,n,i;
int input[1000001],tree[4000004];

void update(int p,int s, int e, int target,int v){
	
	if(s>target || e<target)
		return;
	if(s<=target && e>=target)
		tree[p]+=v;
	if(s !=e){
		update(p*2,s,(s+e)/2,target,v);
		update(p*2+1,(s+e)/2+1,e,target,v);
	}
	
}

int find(int p, int s, int e ,int target){
	tree[p]--;
	if(s==e)
		return s;
		
	if(tree[p*2]< target)
		return find(p*2+1,(s+e)/2+1,e,target-tree[p*2]);	
	else
		return find(p*2,s,(s+e)/2,target);
	
}

int main(){
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A);
		scanf("%d",&B);
		if(A==1)
		{
			printf("%d\n",find(1,1,1000000,B));
		}
		else
		{
			scanf("%d",&C);
			update(1,1,1000000,B,C);	
		}
	}
	return 0;
} 
