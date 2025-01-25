#include <bits/stdc++.h>
#define endl "\n";
#define ll long long int
#define pb push_back
using namespace std;
const int mod = 1e9 + 7;
const long long int base = 26;

void fastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int rabin_karp(string pat, string txt)
{

  //pl = pattern length
  //tl = text length
  //sig_pw = significant power
  //pat_hash = hash value of pattern
  int pl = pat.size(), tl = txt.size();
  int count = 0;

  ll sig_pw = 1, pat_hash = pat[0] - 96;
  for (int i = 1; i < pl; i++)
  {
    sig_pw = (sig_pw * base) % mod;
    pat_hash = ((pat_hash * base) % mod + (pat[i] - 96)) % mod;
  }

  ll temp = 0;
  for (int i = 0; i < tl; i++)
  {
    temp = ((temp * base) % mod + (txt[i] - 96)) % mod;
    if (i + 1 >= pl)
    {
      if (temp == pat_hash)
      {
        count++;
      }
      temp = temp - ((txt[i - pl + 1] - 96) * sig_pw) % mod;
      temp = (temp + mod) % mod;
    }
  }
  return count;
}

int main()
{

  fastIO();
    string txt, pat;
    cin >> txt >> pat;
    int matched = rabin_karp(pat, txt);
    cout << matched << endl

  return 0;
}