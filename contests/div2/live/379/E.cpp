/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

int color[2*MAXSIZE], par[2*MAXSIZE], SZ[2*MAXSIZE];
bool taken[2*MAXSIZE];
vector<VI> adj;
LL dp[2*MAXSIZE][2];

int find(int x) {
  if(x == par[x])
    return x;
  else return par[x] = find(par[x]);
}

void Union(int a, int b) {
  
  int A = find(a);
  int B = find(b);
  
  if(A == B)
    return;
  
  if( SZ[A] > SZ[B] )
    {
      par[B] = A;
      SZ[A] += SZ[B];
    }
  else
    {
      par[A] = B;
      SZ[B] += SZ[A];
    }
  
  return;
}

void dfs(int v)
{
  LL c = 0;
  LL c1 = 0;
  taken[v] = true;
  bool inside = false;
 
  for(auto it : adj[v])
    if( !taken[it] )
      {
	dfs(it);
        c += (LL)min(dp[it][color[v]], 1+dp[it][1-color[v]]);
	c1 += (LL)min(dp[it][1-color[v]], 1+dp[it][color[v]]);
	inside = true;
      }
  
  if( !inside )
    { 
      dp[v][color[v]] = 0;
      dp[v][1-color[v]] = 1;
    }
  else
    {
      dp[v][color[v]] = c;
      dp[v][1-color[v]] = 1 + c1;
    }
  return;
}

int main()
{
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  int n, i;
  cin>>n;
  adj.resize(n+1);
  
  rep(i, 1, n+1)
    cin>>color[i];
  
  int u[n+1], v[n+1];
  
  rep(i, 1, n+1)
    { 
      SZ[i] = 1, par[i] = i;
      dp[i][0] = INT_MAX/10;
      dp[i][1] = INT_MAX/10;
    }
  
  rep(i, 1, n)
    {
      cin>>u[i]>>v[i];
      if(color[u[i]] == color[v[i]] ) 
	Union(u[i], v[i]);
    }
  
  rep(i, 1, n)
    {
      int U = find(u[i]);
      int V = find(v[i]);
      
      if( U != V )
	{
	  adj[U].PB(V);
	  adj[V].PB(U);
	}
    }
  
  int I = find(1);
  dfs(I);
  cout<<min(dp[I][0], dp[I][1])<<endl;
  
  return 0;
}

