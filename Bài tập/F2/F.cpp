#include <bits/stdc++.h>
#define int long long
int n, k, m, m1, x[300005], y[300005];
signed main(){
	scanf("%lld %lld", &n, &k);
	k %= 2 * n;
	scanf("%lld %lld",&m, &m1);
	for (int i=0; i<n; i++) scanf("%lld %lld", &x[i], &y[i]);
	for (int i=1; i<=k; i++) {
		m = m - 2*(m-x[ (i-1) % n ]);
		m1 = m1 - 2*(m1-y[ (i-1) % n ]);
	}
	printf("%lld %lld",m, m1);
}
 			
