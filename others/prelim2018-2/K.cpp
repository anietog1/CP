#include <bits/stdc++.h>

using namespace std;

int const D = 10;

struct node {
  node* children[D];
  bool terminal;

  node() : terminal(false) {
    for(int i = 0; i < D; ++i) {
      children[i] = nullptr;
    }
  }

  ~node() {
    for(int i = 0; i < D; ++i) {
      delete children[i];
      children[i] = nullptr;
    }
  }

  bool insert(string const& num) {
    node* traveler = this;

    for(int i = 0; i < num.length(); ++i) {
      int index =  num[i] - '0';

      if(traveler->children[index] == nullptr) {
	traveler->children[index] = new node;
      }

      traveler = traveler->children[index];
    }

    bool result = false;

    for(int i = 0; i < D; ++i) {
      result = result || (traveler->children[i] != nullptr);
    }

    result = result || traveler->terminal;
    traveler->terminal = true;

    return result;
  }
};

int main() {
  int tc;
  cin >> tc;

  while(tc--) {
    int n;
    cin >> n;

    string nums[n];

    for(int i = 0; i < n; ++i) {
      cin >> nums[i];
    }

    sort(nums, nums + n, [](string& a, string& b) -> bool {
        return a.size() < b.size();
      });

    node root;
    bool wrong = false;

    for(int i = n - 1; i >= 0; --i) {
      if(root.insert(nums[i])) {
        wrong = true;
        break;
      }
    }

    cout << (wrong? "NO" : "YES") << endl;
  }
}
