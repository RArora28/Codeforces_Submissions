#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> pii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pii> vpii;
typedef long long int ll;
typedef unsigned long long int ull;

#define mi 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)
#define repv(i,a,b) for(i=b-1;i>=a;i--)
#define inf INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define first fi
#define second se
#define SET(a,b) memset(a,b,sizeof(a))
#define MAX 500005
#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

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

int mult(int x,int y)
{
  ll ans,x1=(ll)x,y1=(ll)y;
  ans=(x1*y1)%mi;
  return (int)ans;
}
int gcd(int a,int b) { return b==0 ? a : gcd (b,a%b);}
int lcm(int a,int b) { return a*(b/gcd(a,b));}

int pow1(int a,int b)
{
  int ans=1;
  while(b>0)
    {
      if(b&1) ans=mult(ans,a);	
      a=mult(a,a); b>>=1;
    }	
  return ans;
}
int mina(int arr[],int n)
{
  int x=arr[0],i,pos=0;
  rep(i,1,n){ if(arr[i]<x) { x=arr[i]; pos=i; } }
  return x;
}
int maxa(int arr[],int n)
{
  int x=arr[0],i,pos=0;
  rep(i,1,n){ if(arr[i]>x) { x=arr[i]; pos=i; } }
  return x;
}
int main()
{
  int a[500005],b[500005],n,m,i,z[500005],l=0,r=0;
  si(n); si(m);
  string s;
  cin>>s;
  z[0]=s.size();
  rep(i,1,s.size())
    {
      if(r<=i)
	{
	  l=r=i;
	  while(r<n && s[r-l]==s[r])
	    r++;
	  z[i]=r-l;
	}
      else
	{
	  int k=i-l;
	  if(z[k] < r-i)
	    z[i]=z[k];
	  else
	    {
	      l=i;
	      while(r<n && s[r-l]==s[r])
		r++;
	      z[i]=r-l;
	    }
	}
    }
  SET(b,0);
  rep(i,0,m)
    {
      si(a[i]); a[i]--;
      b[a[i]]++;
      b[a[i]+s.size()]--;
    }
  //rep(i,0,n)
  //cout<<b[i]<<" ";
  //cout<<endl;
  rep(i,1,m)
    {
      int x=a[i-1]+s.size()-a[i];
      if(x<=0)
	continue;
      if(z[s.size()-x]<x)
	{
	  cout<<"0"<<endl;
	  return 0;
	}
    }
  rep(i,1,n)
    b[i]+=b[i-1];
  ll ans=1;
  rep(i,0,n)
    {
      if(b[i]==0)
	ans=(ans*26)%mi;
    }
  lldout(ans%mi);
  return 0;
}
