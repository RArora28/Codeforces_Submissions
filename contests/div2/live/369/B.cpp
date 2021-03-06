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
#define rev(i, a, b) for(i = b; i > a; i--)
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

LL A[510][510];
LL d1 = 0, d2 = 0, row[510], col[510], x;
LL n;

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  cin>>n;

  LL i, j;
  LL I, J;

  rep(i, 1, n+1) 
    rep(j, 1, n+1) {
    cin>>A[i][j];
    if(A[i][j] == 0) {
      I = i;
      J = j;
    }
  }
  
  if(n == 1) {
    cout<<"1"<<endl;
    return 0;
  }
  
  rep(i, 1, n+1) 
    rep(j, 1, n+1) 
    row[i] += A[i][j];
  
  LL sum;
  
  rep(i, 1, n+1) 
    if(i != I) {
      sum = row[i];
      break;
    }
  
  x = sum - row[I];
  A[I][J] = x;
  row[I] = sum;
  
  if(x <= 0)  {
    cout<<"-1"<<endl;
    return 0;
  }

  rep(j, 1, n+1)  
    rep(i, 1, n+1)
    col[j] += A[i][j];  
  
  rep(i, 1, n+1) 
    d1 += A[i][i];
  
  rep(i, 1, n+1)
    d2 += A[i][n-i+1];
  
  vector<LL> v;
  
  v.PB(d1);
  v.PB(d2);
  
  rep(i, 1, n+1) { 
    v.PB(row[i]);
    v.PB(col[i]);
  }
  
  sort(v.begin(), v.end());
  
  int temp = v.size();
  
  if(v[0] == v[temp-1]) 
    cout<<x<<endl;
  else 
    cout<<"-1"<<endl;
  
  return 0;
}
