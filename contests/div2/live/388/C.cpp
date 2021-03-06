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

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int n;

  string str;

  cin>>n;
  cin>>str;

  int l = str.size();

  set<int>s1, s2, s3;

  int i;
  rep(i, 0, l)
    {
      if(str[i] == 'D')
	s1.insert(i);
      else
	s2.insert(i);
      s3.insert(i);
    }

  while( (s3.size() > 0) && (s2.size() > 0) && (s1.size() > 0))
    {
      cout<<"iteration begins"<<endl;
      for(auto it : s3)
	trace(str[it]);
      
      for(auto &it : s3)
	{
	  if(str[it] == 'D')
	    {
	      int m = *s2.begin();
	      s2.erase(m);
	      s3.erase(m);
	    }
	  else
	    {
	      int m = *s1.begin();
	      s1.erase(m);
	      s3.erase(m);
	    }
	}
    }

  int m = *s3.begin();

  cout<<str[m]<<endl;
  
  return 0;
}
