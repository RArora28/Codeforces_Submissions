#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mi 1000000007

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
      ans = ((ans % mi) *(a % mi)) % mi;
    a=((a % mi)*(a % mi)) % mi;
    b >>= 1;
  }
  
  return ans;
}

int counter;
int parent[1000], ran[1000];

int find(int x) {
  if(parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void combine (int a, int b) {
  int temp1 = find(a);
  int temp2 = find(b);
  
  if(temp1 != temp2) {
    if(ran[temp1] > ran[temp2]) {
      parent[temp2] = temp1;
      ran[temp1] += ran[temp2];
    }
    
    else { 
      parent[temp1] = temp2;
      ran[temp2] += ran[temp1];
    }
    
    counter--;
  }
  return ;
}

int main() {
  
  int n, i;
  
  cin>>n;
  
  pair<ii, int> p[n+1];
  
  rep(i, 0, n) {
    cin>>p[i].fi.fi>>p[i].fi.se;
    p[i].se = parent[i] = i;
    ran[i] = 1;
  }

  sort(p, p + n);
  
  counter = n-1;
  
  rep(i, 1, n)
    if(p[i].fi.fi == p[i-1].fi.fi) 
      combine(p[i-1].se, p[i].se);
  
  rep(i, 0, n)
    swap(p[i].fi.fi, p[i].fi.se);
  
  sort(p, p+n);
  
  rep(i, 1, n)
    if(p[i].fi.fi == p[i-1].fi.fi) 
      combine(p[i-1].se, p[i].se);
  
  cout<<counter<<endl;

  return 0;
}
