#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

queue<int> q[11];
queue<int> addq[11];

int T, N, Ni, num, i, j, k,l, x, y, a[10], cnt;
char s;
bool b[11];

int main() {
	T = 10;
	for (i = 1; i <= 10; i++) {
        b[i]= true;
		scanf("%d", &N);
		for (j = 0; j < N; j++) {
			scanf("%d", &num);
			q[i].push(num);
		}
		scanf("%d", &Ni);
		for (j = 0; j < Ni; j++) {
			cin >> s;
            scanf("%d", &x);
            scanf("%d", &y);
            for (k = 0; k < y; k++){
                scanf("%d ", &a[k]);
            }
			if (b[i]) {
				for (k = 0; k < x; k++) {
					addq[i].push(q[i].front());
                    q[i].pop();
				}
				for (k = 0; k < y; k++) {
					addq[i].push(a[k]);
				}
                cnt=q[i].size();
				for (k = 0; k < cnt; k++) {
					addq[i].push(q[i].front());
                    q[i].pop();
				}
				b[i] = false;
			}
			else {
				for (k = 0; k < x; k++) {
					q[i].push(addq[i].front());
                    addq[i].pop();
				}
				for (k = 0; k < y; k++) {
					q[i].push(a[k]);
				}
                cnt=addq[i].size();
				for (k = 0; k < cnt; k++) {
					q[i].push(addq[i].front());
                    addq[i].pop();
				}
				b[i] = true;
			}
		}

	}
  
	for (i = 1; i <= 10; i++) {
		printf("#%d ", i);
		if (b[i]) {
			for (k = 0; k < 10; k++) {
				printf("%d ", q[i].front());
                q[i].pop();
			}
		}
		else {
			for (k = 0; k < 10; k++) {
				printf("%d ", addq[i].front());
                addq[i].pop();
			}
		}
		printf("\n");
	}
	return 0;
}