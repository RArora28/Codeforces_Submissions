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

const int N = 1e3+10;
const int mod = 1e9+7;

int g1[N], g2[N], c1[10], c2[10];

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
  	cin >> g1[i];
  	c1[g1[i]]++;
  }
  for(int i = 1; i <= n; i++) {
  	cin >> g2[i];
  	c2[g2[i]]++;
  }

  for(int i = 1; i <= 5; i++) {
  	if( (c1[i] + c2[i]) % 2) {
  		cout << -1 << '\n';
  		return 0;
  	}
  }  

  int ans = 0;
  for(int i = 1; i <= 5; i++) {
  	ans += abs( (c1[i] + c2[i])/2 - c1[i]);
  }

  cout << ans / 2 << '\n';
  return 0;
}
