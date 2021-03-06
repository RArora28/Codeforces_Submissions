#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<long long int, long long int>
#define vi vector<long long int>
#define vii vector<pair<long long int, long long int> >
#define adjList vector<vector<pair<long long int, long long int> > >
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, z, q) for(i = z; i < q; i++)
#define rev(i, z, q) for(i = z; i > q; i--)

adjList adj;
ll dis[200010], U[200010], V[200010], W[200010];

void shortest(ll source, ll n) { 
  
  ll i;
  
  rep(i, 1, n+1)
    dis[i] = LLONG_MAX;
  
  dis[source] = 0;
  
  priority_queue<ii, vector<ii>, greater<ii> > p;
  
  p.push(mp(0, source));
  
  while(!p.empty()) { 
    
    ii T = p.top();
    p.pop();
    ll d = T.fi;
    ll curr = T.se;

    if(d > dis[curr]) continue;
    
    for(auto it : adj[curr])
      if(dis[curr] + it.fi < dis[it.se]) { 
	dis[it.se] = dis[curr] + it.fi;
	p.push(mp(dis[it.se], it.se));
      }
  }

  return;
}

int main() {

  ll n, m;
  ll i, s;

  cin>>n>>m>>s;
  
  adj.resize(n+1);

  ll a, b, w, L;
  ll ind = 1;

  rep(i, 1, m+1) { 
    cin>>a>>b>>w;
    adj[a].pb(mp(w, b));
    adj[b].pb(mp(w, a));
    U[i] = a;
    V[i] = b;
    W[i] = w;
  } 
  
  cin>>L;
  
  shortest(s, n);
  
  ll C = 0;
  
  rep(i, 1, n+1)
    if(dis[i] == L)
      C++;
  
  cout<<C<<endl;

  rep(i, 1, n+1)
    cout<<i<<" "<<dis[i]<<endl;

  rep(i, 1, m+1) {
    if(dis[U[i] < L) { 
	if(dis[V[i]] < L)
  }

  cout<<C<<endl;

  return 0;
}

