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

map<char, int > M;
char str[50010];
set<char> S;

bool check() { 
  
  for(auto it : M) {
    //trace(it.F, it.S);
    if(it.S > 1) 
      return false;
  }
  
  return true;
}

void answer(int i) { 
  
  int j = i-25;
  int k = 0;
  
  rep(k, j, i+1) 
    if(S.count(str[k]) == 1)
      S.erase(str[k]);
  
  // for(auto it : M)
  //   trace(it.F, it.S);

  rep(k, j, i+1) 
    if(str[k] == '?') {
      str[k] = *(S.begin());
      S.erase(str[k]);
    }
  
  int l = strlen(str);
  //cout<<l<<endl;

  rep(k, 0, l) 
    if(str[k] == '?') {
      //cout<<"hello"<<endl;
      str[k] = 'A';
    }

  cout<<str<<endl;
  
  return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  cin>>str;
  char ch = 'A';
  
  int i = 0;

  while(i < 26) {
    S.insert(ch+i);
    i++;
  }
  
  int len = strlen(str);
  
  if(len < 26) {
    cout<<"-1"<<endl;
    return 0;
  }

  i = 0;
  
  while(i < 26) { 
    if(str[i] != '?') { 
      if(M.find(str[i]) != M.end())
	M[str[i]]++;
      else M[str[i]] = 1;
    }
    i++;
  }

  // for(auto it : M) 
  //   trace(it.F, it.S);

  // cout<<"abhi tak"<<endl;

  bool flag;

  i--;
  flag = check();
  
  if(flag == true) {
    answer(i);
    return 0;
  }
  
  i++;
  
  while(i != len) {
    if(str[i] != '?')  {
      //cout<<endl;
      if(M.find(str[i-26]) != M.end())
	 M[str[i-26]]--; 
      if(M.find(str[i]) != M.end())
	M[str[i]]++;
      else 
	M[str[i]] = 1;
    }
    
    // for(auto it : M) 
    //   trace(it.F, it.S);
    
    // cout<<"abhi tak"<<endl;

    flag = check();
    
    if(flag == true) {
      answer(i);
      return 0;
    }
  
    i++;
  }
  
  cout<<"-1"<<endl;

  return 0;
}
