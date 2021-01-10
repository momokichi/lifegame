#include <bits/stdc++.h>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;
typedef long double ld;

const double PI = acos(-1);
#define all(n) n.begin(), n.end()

void init() { cout << "init" << endl; }

void update() { cout << "update" << endl; }

void display() { cout << "display" << endl; }

int main() {
  int step = 5;
  init();
  while (step--) {
    update();
    display();
    sleep_for(milliseconds(100));
  }
}
