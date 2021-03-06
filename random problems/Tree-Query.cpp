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
         
int SZ;
vector<VI> adj, value;
LL ans = 0;
int L, R, N;
bool taken[MAXSIZE], cen[MAXSIZE];
int A[MAXSIZE], Ans[MAXSIZE], sub[MAXSIZE];
                  
void another_dfs(int x, int v, int arr[], int L, int R, int opt) { 
  int r, l;
  taken[v] = true;
  if( (L - Ans[v]-1) >= SZ)
    l = SZ-1;
  else 
    l = L-Ans[v]-1;
  if( (R -Ans[v]) >= SZ)
    r = SZ - 1;
  else 
    r = R-Ans[v];
  if(r >= 0)
    ans += arr[r];
  if(l >= 0)
    ans -= arr[l];
  if( (R - Ans[v]) >= (int)value[x].size())
    r  = (int)value[x].size()-1;
  else 
    r = R-Ans[v];
  if( (L - Ans[v] - 1) >= (int)value[x].size())
    l  = (int)value[x].size()-1;
  else 
    l = L-Ans[v]-1;
  if( opt == 0) {
    if(r >= 0)
      ans -= (LL)value[x][r];
    if( l >= 0)
      ans += (LL)value[x][l];
  }
  for(auto it : adj[v]) 
    if(!taken[it] && (!cen[it]) )
      another_dfs(x, it, arr, L, R, opt);
  taken[v] = false;
  return;
}
         

void dfs0(int v, int x, int sign, int val) {
  taken[v] = true;
  Ans[v] = val;
  value[x][Ans[v]]++;
  if(val >= L && val <= R)
    ans += 2;
  for(auto it : adj[v])
    if( (!taken[it]) && (!cen[it]) ) {
      int temp = A[it] - A[v];
      if(temp > 0)
	temp = 1;
      else if(temp < 0)
	temp = -1;
      if( (sign * temp < 0) && (A[v] > A[it]))
	dfs0(it, x, temp, val+1);
      else 
	dfs0(it, x, temp, val);
    }
  taken[v] = false;
  return;
}

//-------------Centroid Decomposition----------------//
//function to calculate the sizes of sub-trees
void dfsc1(int v, int p) { 
  sub[v] = 1;
  for(auto it : adj[v])
    if( it != p && (!cen[it]))
      dfsc1(it, v), sub[v] += sub[it];
  return;
}
//function that returns the centroid of a given sub-tree
int dfsc2(int v, int p, int size) { 
  for(auto it : adj[v]) 
    if( (!cen[it]) && (it != p) && (2*sub[it] > size) ) 
      return dfsc2(it, v, size);
  return v;
}
     
//decomposition function
void decompose(int v, int p) {
  dfsc1(v, v);
  int centroid = dfsc2(v, v, sub[v]);
  if(p == -1) p = centroid;
  cen[centroid] = true;
  dfsc1(centroid, centroid);
  if(L >= (sub[centroid]-1) )
    return;
  if(sub[centroid] > 2) {
    int i;
    for(auto it : adj[centroid]) 
      if( !cen[it] ) {
	value[it].resize(sub[it]+1);
	for(auto &it1 : value[it])
	  it1 = 0;
	int temp = A[it] - A[centroid];
	if(temp > 0)
	  temp = 1;
	else if(temp < 0)
	  temp = -1;
	dfs0(it, it, temp, 0);
      }
    int in[sub[centroid]+3], out[sub[centroid]+3];
    rep(i, 0, sub[centroid]+3)
      in[i] = out[i] = 0;
    for(auto it : adj[centroid])
      if( (!cen[it])) { 
	if(A[it] < A[centroid]) 
	  rep(i, 0, (int)value[it].size())  
	    in[i] += value[it][i];
	else 
	  rep(i, 0, (int)value[it].size())  
	    out[i] += value[it][i];
      }
    
    int j;
    SZ = sub[centroid]+3;
    rep(i, 1, SZ) { 
      out[i] += out[i-1];
      in[i] += in[i-1];
    }

    for(auto it : adj[centroid]) 
      if(!cen[it] && value[it].size() > 0)
	rep(j, 1, (int)value[it].size())
	  value[it][j] += value[it][j-1];

    for(auto it : adj[centroid]) {
      if( (A[it] >= A[centroid]) && (!cen[it]) ) {
	another_dfs(it, it, out, L, R, 0);
	another_dfs(it, it, in, L, R, 1);
      }
      else if(A[it] < A[centroid] && (!cen[it]) ) {
	another_dfs(it, it, out, L, R, 1);
	another_dfs(it, it, in, L-1, R-1, 0);
      }
    }
    
    for(auto &it : adj[centroid])  
      if(!cen[it]) 
	decompose(it, centroid);
  }
  
  return;
} 
         
int main() {
         
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
          
  int i, u, v, T;
  ans = 0;
  cin>>N>>T;
  
  adj.resize(N+1);
  value.resize(N+1);
  
  rep(i, 1, N) { 
    cin>>u>>v>>w;
    adj[u].PB(MP(v, w));
    adj[v].PB(MP(u, w));
  }
  
  decompose(1, -1);

  while(T--)
    {
      cin>>v>>l;
      
    }
  return 0;
}
