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

const int N = 1e5+10;
const int mod = 1e9+7;

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  LL n, m, k, x, y;

  cin >> n >> m >> k >> x >> y;

  if(n == 1) {
  	LL x = k/(n*m);
  	if(k % m) {
  		LL t;
  		if(y <= k % m) {
  			 t = x + 1;
  		}
  		else 
  			t = x;

  		cout << x + 1 << ' ' << x << ' ' << t << endl; 
  	}
  	else {
  		cout << x << ' ' << x << ' ' << x << endl;
  	}
  	return 0;
  }

  LL s;
  if(n == 2) {
 		LL t = k/(n*m);
	 	LL g = k/(n*m);
  		if(k % (n*m) ) {
  			LL x1 = k % (n*m);

  			if(x1 <= m) {
  				if(x == 1 && y <= x1) {
  					g++;
  				}
  			}
  			else if(x1 > m) {
  				if(x == 1 || y <= x1)
  					g++;
  			}

  			cout << t + 1 << ' ' << t << ' ' << g << endl; 
  		}
  		else {
  			cout << x << ' ' << x << ' ' << x << endl;
  	}
  	return 0; 
  }

  else if(n == 3) {
  	s = n*m + m;
  	// LL t = k/s;
  	// LL ans;
  	// if(k % s) {
  	// 	LL left = k % s;

  	// 	if(left )
  	// }

  	// else {
  	// 	if(x == 1 || x == n) ans = t;
  	// 	else ans = 2*t;
  	// 	cout <<2*t << ' ' << t << ' ' << ans << endl; 
  	// }
  	// return 0;
  }
  else {
  	s = n*m + (n-2)*m;
  }

  LL left = k % s;
  LL Max = (k/s)*2;
  LL Min = k/s;
  LL ans = (x == 1 || x == n) ? (k/s) : ((k/s)*2);

  if(left <= m) {
    Max++;
  }
  else if(left <= n*m) {
  	//cout << 1 << endl;
  	if(left > m)
  		Max++;
  	if(left == n*m)
  		Min++;
  	if( (x-1)*m + y <= left) {
  		ans++;
  	}
  }
  else if(left > n*m ) {
  	//cout << 2 << endl;
  	Max += 2;
  	Min++;
  	ans++;
  	if(x != 1 && x != n) {
  		if( (n-x-1)*m + y <= left - n*m) {
  			ans++;
  		}
  	}
  }

  cout << Max << ' ' << Min << ' ' << ans << endl;
  return 0; 
}
