#include <bits/stdc++.h>

#include <cstdlib>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;
typedef long double ld;

const double PI = acos(-1);
#define all(n) n.begin(), n.end()

vector<vector<bool>> g;
int n;  // grid size
int step;

void init() {
  cout << "init" << endl;
  g.resize(n + 2, vector<bool>(n + 2, true));
  rep(i, n + 2) {
    rep(j, n + 2) {}
  }
}

void update() { cout << "update" << endl; }

void display() {
  cout << "display" << endl;
  for (int i = 0; i < n + 2; ++i) {
    for (int j = 0; j < n + 2; ++j) {
      if ((i == 0 || i == n + 1) && (j == 0 || j == n + 1))
        cout << "+";
      else if (i == 0 || i == n + 1)
        cout << "-";
      else if (j == 0 || j == n + 1)
        cout << "|";
      else
        cout << (g[i][j] ? "*" : " ");
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "usage: ./a.out grid_size step" << endl;
    return 0;
  }

  n = stoi(argv[1]);
  step = stoi(argv[2]);

  init();
  while (step--) {
    system("clear");  // コンソールをクリア
    update();
    display();
    cout << step << endl;
    sleep_for(milliseconds(500));
  }
}
