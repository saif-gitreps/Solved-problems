https://codeforces.com/contest/1853/problem/A
#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
  
void solve(){
   int n;cin>>n;
   vector<long long> a;
   for(int i=0;i<n;i++){
      long long x;
      cin>>x;
      a.push_back(x);
   }
   int mn = MAXN;
   int count;
   for(int i=0;i<n-1;i++){
      count = 0;
      int temp1 = a[i],temp2 = a[i+1];
      while(temp1<=temp2){
         temp1++;
         temp2--;
         count++;
      }
      mn = min(mn,count);
   }
   cout<<mn<<"\n";
}

int main(){
   
    int t; cin>>t; while(t--)
    solve(); 
}

=====================================================
  
