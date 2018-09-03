#include <iostream>

using namespace std;

int main() {
  int W, N;
  cin >> W >> N;

  long long area = 0;

  while(N--) {
    int wi, li;
    cin >> wi >> li;
    area += wi * li;
  }

  cout << area / W << endl;
}
