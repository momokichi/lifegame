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

vector<vector<bool>> g;  // grid
int n;                   // grid size

// settings for rand
random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<int> my_rand(0, 1);

void init() {
  g.resize(n + 2, vector<bool>(n + 2, false));
  for (int i = 1; i < n + 1; ++i)
    for (int j = 1; j < n + 1; ++j) g[i][j] = my_rand(mt);
}

bool update_cell(bool current, int count) {
  if (!current && count == 3)
    return true;
  else if (current && (count == 2 || count == 3))
    return true;
  else if (current && count <= 1)
    return false;
  else if (current && count >= 4)
    return false;
  else
    return false;
}

const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int count_alive_cells(int i, int j) {
  int ret = 0;
  for (int direction = 0; direction < 8; ++direction) {
    if (g[i + dx[direction]][j + dy[direction]]) ++ret;
  }
  return ret;
}

void update() {
  vector<vector<bool>> tmp(n + 2, vector<bool>(n + 2, false));
  for (int i = 1; i < n + 1; ++i)
    for (int j = 1; j < n + 1; ++j) {
      int count = count_alive_cells(i, j);
      // cout << count << endl;
      tmp[i][j] = update_cell(g[i][j], count);
    }
  g = tmp;
}

void display() {
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

  int step;
  n = stoi(argv[1]);
  step = stoi(argv[2]);

  init();
  while (step--) {
    system("clear");  // clear console
    update();
    display();
    sleep_for(milliseconds(200));  // sleep
  }
  system("clear");
  return 0;
}
