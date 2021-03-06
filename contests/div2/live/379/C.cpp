/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 200010
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

LL bit[MAXSIZE], x, s, n, m, k, i, a[MAXSIZE], b[MAXSIZE], c[MAXSIZE], d[MAXSIZE];
pair<LL, LL> P[MAXSIZE];

LL mmin(LL idx) { 
  LL Min = 1e16;
  while(idx > 0) { 
    Min = min(Min, bit[idx]);
    idx -= idx & -idx;
  }
  return Min;
}

void update(LL idx, LL val) { 
  while(idx <= m) { 
    bit[idx] = min(bit[idx], val);
    idx += idx & -idx;
  }
  return;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  cin>>n>>m>>k;

  rep(i, 1, m+3)
    bit[i] = 1e16;

  cin>>x>>s;
  
  rep(i, 1, m+1)
    cin>>P[i].S;
  
  rep(i, 1, m+1)
    cin>>P[i].F;
  
  rep(i, 1, k+1) 
    cin>>c[i];
  
  rep(i, 1, k+1)
    cin>>d[i];
  
  sort(P+1, P+m+1);
  
  rep(i, 1, m+1) {
    a[i] = P[i].S;
    b[i] = P[i].F;
    update(i, a[i]);
  }
  
  LL Ans = x*n;
  
  rep(i, 1, k+1)
    if(d[i] <= s && c[i] >= n)
      Ans = 0;
  
  rep(i, 1, m+1)
    if(b[i] <= s)
      Ans = min(Ans, a[i]*n);
  
  rep(i, 1, k+1) { 
    if( (s - d[i]) >= b[1]) { 
      LL U = upper_bound(b+1, b+m+1, s-d[i]) - (b+1);
      U--;
      //trace(L, s-d[i], c[i]);
      if( ((n - c[i]) >= 0) && (U <= m))    
	Ans = min(Ans, (n-c[i])*mmin(U));
    }
    else if(s - d[i] >= 0)
      Ans = min(Ans, (n-c[i])*x);
  }
  
  cout<<Ans<<endl;
  
  return 0;
}
