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

int arr[102];

int main() {

  int i, n, a;

  cin>>n>>a;

  rep(i, 1, n+1)
    cin>>arr[i];

  int temp = 1, t = 0;

  if(arr[a])
    t++;

  while((a-temp > 0) && (a + temp <= n)) {

    if(arr[a-temp] == 1 && arr[a + temp] == 1)
     t += 2;
    
    temp++;
  }

  while(a - temp > 0) {
    if(arr[a-temp])
      t++;
    
    temp++;
  }

  while(a + temp <= n) {
    if(arr[a+temp])
      t++;
    
    temp++;
  }

  cout<<t<<endl;
  
  return 0;
}

