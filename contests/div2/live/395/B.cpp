/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

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

const int N = 2e5+10;
const int mod = 1e9+7;

LL a[N], pre[N];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n;
  cin >> n;
  LL i;
  rep(i, 1, n+1) {
  	cin >> a[i];
  }
  i = 1;
  while(i <= n-i+1) {
  	pre[i]++;
  	pre[n-i+2]--;
  	i++;
  }

  rep(i, 2, n+1) {
  	pre[i] += pre[i-1];
  }

  rep(i, 1, n+1) {
  	if(pre[i] % 2) {
  		cout << a[n-i+1] << ' ';
  	}
  	else {
  		cout << a[i] << ' ';
  	}
  }
  
  cout << endl;
  return 0;
}
