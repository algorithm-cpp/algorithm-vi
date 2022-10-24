#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, m, m1, x[300005], y[300005];
signed main(){
	int n = 99999;
	int k = 999999999999999900;
	int m =  797 ;
	int m1 = 526;
	freopen("15.in","w",stdout);
	printf("%lld %lld\n", n, k);
	printf("%lld %lld\n",m, m1);
	
	for (int i = 1;i<=n ; i++){
		int x = 1000 - rand()%2001;
		int y = 1000 - rand()%2001;
		cout << x << ' ' << y<< endl; 
	}
	
}
 			
