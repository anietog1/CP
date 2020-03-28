#include <bits/stdc++.h>

using namespace std;
#define MAXN 100010

bool pal[MAXN] = {};
bool lucky[MAXN] = {};

int n, k;
string nums[MAXN];
int val[MAXN] = {};

bool ispal(string const& str) {
  int n = str.size();
  if(str[n - 1] == '0') return false;
  for(int i = 0; i < n / 2; ++i)
    if(str[i] != str[n - i - 1]) return false;
  return true;
}

bool islucky(string const& str) {
  int n = str.size();
  for(int i = 0; i < n; ++i)
    if(str[i] != '4' && str[i] != '7') return false;
  return true;
}

int main(int argc, char** argv, char** env) {
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin >> nums[i];
    pal[i] = ispal(nums[i]);
    lucky[i] = islucky(nums[i]);
  }

  for(int i = 0; i < n; ++i) {
    if(pal[i]) val[i] |= 1;
    if(lucky[i]) val[i] |= 2;
  }
}
