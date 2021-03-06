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

LL LorE(LL x, LL n, LL m) { 
  
  LL sum = 0;
  LL i;
  
  rep(i, 1, n+1) 
    sum += min((LL)(x/i), m);;
  
  return sum;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n, m, k;

  LL i, j;

  cin>>n>>m>>k;

  LL l = 1, u = n*m;
  LL mid= 1;

  while(mid >= 1 && l < u) { 
    mid = ( l + u) >> 1;
    LL x = LorE(mid, n, m);
    LL y = LorE(mid-1, n, m);
    trace(l, u, mid, x, y, k);
    if( (x == k) || ((x > k) && (y < k))) {
      //cout<<"hello "<<y<<endl;
      break;
    }
    else if( x < k)
      l = mid + 1;
    else 
      u = mid;
  }
  
  trace(mid);

  while(LorE(mid, n, m) < k)
    mid++;
  
  LL ans = -1;

  rep(i, 1, n+1) { 
    if((i*m) >= mid && mid % i == 0) {
      ans = mid;
      break;
    }
    else if(i*m > mid) ans = max(ans, i*(mid/i));
    trace(i, ans, i*(mid/i));
  }
  
  cout<<ans<<endl;
  return 0;
}
