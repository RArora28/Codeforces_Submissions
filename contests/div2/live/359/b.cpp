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

int main() {
  

  int i, n, a[105], b[105];

  cin>>n;

  rep(i, 0, n) {
    cin>>a[i];
    b[i] = a[i];
  }

  sort(b, b+n);

  while(1) {

    bool flag = true;
    
    rep(i, 0, n) 
      if(a[i] != b[i])
	flag = false;

    if(flag)
      return 0;

    rep(i, 0, n-1)
      if(a[i] > a[i+1]) {
	swap(a[i], a[i+1]);
	cout<<i+1<<" "<<i+2<<endl;
      }
  }
  
  return 0;
}

