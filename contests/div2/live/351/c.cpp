#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define adjList vector<vector<int> >
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, z, q) for(i = z; i < q; i++)
#define rev(i, z, q) for(i = z; i > q; i--)

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll a,ll b) {
  ll ans = 1;  
  while(b > 0){
    if(b & 1)
      ans = ((ans % mod) *(a % mod)) % mod;
    a=((a % mod)*(a % mod)) % mod;
    b >>= 1;
  }
  return ans;
}

int arr[10000], cnt[10000];

int main() {

  int m, i, n, j, t[10000], ans, temp, count;

  cin>>n;
  
  rep(i, 1, n+1) {
    si(t[i]);
  }

  rep(i, 1, n+1) {
    rep(m , 0, n+1)
      cnt[m] = 0;
    
    count = 1;
    ans = 0;
    rep(j, i, n+1) {
      if(cnt[t[j]] == 0) { 
        cnt[t[j]] = 1;
	if(ans == 0 || t[j] < ans && count == 1)
	  ans = t[j];
      }
      
      else {
	temp = cnt[t[j]]++;
	temp++;
	if(temp == count && t[j] < ans || temp > count) {
	  ans = t[j];
	  count = temp;
	}
      }
      
      arr[ans]++;
    }
    
  }

  rep(i, 1, n+1)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}

