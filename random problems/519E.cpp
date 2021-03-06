/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<VI> adjList;

#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define REP(i, n) for(i = 1; i <= n; i++)
#define pr0(arr, n) rep(i, 0, n) cout<<arr[i]<<" "; cout<<endl;
#define pr1(arr, n) rep(i, 1, n+1) cout<<arr[i]<<" "; cout<<endl;
#define INF INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))
#define gu getchar
#define pu putchar
#define SI(n) scanf("%d",&n)
#define PI(n) printf("%d\n",n)
#define SLL(n) scanf("%lld",&n)
#define PLL(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//fast io using cin/cout
//ios::sync_with_stdio(false);	cin.tie(NULL);

const int S = 1e5 + 10;

bool taken[S];
int T[S], L[S], P[S][30], sub[S];
adjList adj;


int dfs(int v) { 

  sub[v] = 1;
  taken[v] = true;
  
  for( auto it : adj[v]) 
    if(!taken[it]) 
      T[it] = v, L[it] = L[v] + 1, sub[v] += dfs(it);
  
  return sub[v];
}

void process(int N) { 
  
  int i, j;

  SET(P, -1);
  
  REP(i, N) 
    P[i][0] = T[i];

  for(j = 1; (1 << j) < N; j++) 
    REP(i, N)
      if(P[i][j-1] != -1)
	P[i][j] = P[P[i][j-1]][j-1];
  
  return;
}

int LCA(int a, int b) { 

  int i;

  if(L[a] < L[b]) 
    swap(a, b);

  int log;
  
  for(log = 1; (1 << log) <= L[a]; log++);
  log--;
  
  rev(i, log, -1)
    if(L[a] - (1 << i) >= L[b])
      a = P[a][i];

  if(a == b)
    return a;
  
  rev(i, log, -1)
    if(P[a][i] != -1 && P[a][i] != P[b][i])
      a = P[a][i], b = P[b][i];

  return T[a];
}

int Ancestor(int A, int K) {
  
  int i, log;
  
  for(log = 1; (1 << log) <= L[A]; log++);
  log--;
  
  //cout<<"log:"<<log<<endl;
  
  rev(i, log, -1)
    if((1 << i) <= K && K > 0) {
      A = P[A][i];
      K -= (1 << i);
    }
  
  return A;
}

int main() { 

  int N, i;
  
  cin>>N;

  adj.resize(N+1);
  
  int u, v;

  rep(i, 1, N) {
    cin>>u>>v;
    adj[v].PB(u);
    adj[u].PB(v);
  }
  
  T[1] = -1;
  L[1] = 1;
  dfs(1);
  process(N);
  
  int m, L1;
  int K;
  int sum;
  
  cin>>m;
  
  while(m--) { 
    
    sum = 0;
    cin>>u>>v;
    
    L1 = LCA(u, v);
    //cout<<L1<<endl;
    int temp = L[u] + L[v] - 2*L[L1];

    if(L[u] > L[v])
      swap(u, v);
    
    
    if(v == u)
      sum = N;
    
    else if(L[u] == L[v]) {  
      //cout<<"H"<<endl;
      K = L[v] - L[L1] - 1;
      sum = sub[L1] - sub[Ancestor(u, K)] - sub[Ancestor(v, K)];
      
      if(L1 != 1) 
	sum += sub[1] - sub[L1];
    }
    
    else if(L1 == u || L1 == v)  {
      if(abs(L[u] - L[v]) % 2 == 0)  {
	//cout<<"HH"<<endl;
	K = abs(L[u] - L[v]) / 2 - 1;
	sum = sub[Ancestor(v, K+1)] -  sub[Ancestor(v, K)]; 
      }
    }

    else if(temp % 2 == 0) {
      //      cout<<"HHH"<<endl;
      K = (L[u] + L[v] - 2*L[L1])/2 - 1;
      sum = sub[Ancestor(v, K+1)] - sub[Ancestor(v, K)];
    }
    
    cout<<sum<<endl;
  }

  return 0;
}
