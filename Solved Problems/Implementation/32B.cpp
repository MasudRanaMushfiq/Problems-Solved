#include <bits/stdc++.h>
#define endl "\n";
#define ll long long
using namespace std;

int main() 
{
    string s;
    cin>>s;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '.') {
        cout<<0;
      }
      else {
        if(s[i+1] == '.') {
          cout<<1;
        }
        else{
          cout<<2;
        }
        i++;
      }
    }
    cout<<endl
    return 0;
}