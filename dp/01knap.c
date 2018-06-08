#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d ",x)

int knapsack_dp(int n, int M, int w[], int v[]) {

		int knapsack[n+1][M+1], j, k;

		for(j=0;j<=n;j++)
			knapsack[j][0] = 0;

		for(k=0;k<=M;k++)
			knapsack[0][k] = 0;

		for(j=1;j<=n;j++) {

			for(k=1;k<=M;k++) {

				if(w[j-1] <= k) {

					knapsack[j][k] = max(knapsack[j-1][k], v[j-1] + knapsack[j-1][k - w[j-1]]);

				}
				else {

					knapsack[j][k] = knapsack[j-1][k];
				}
			}
		}

		return knapsack[n][M];
}

int main()
{
	int n,M;
	s(n); s(M);
	int i;
	int w[n], v[n];
	for(i=0;i<n;i++) {
		s(w[i]); s(v[i]);
	}
	p(knapsack_dp(n,M,w,v));
	return 0;
}
