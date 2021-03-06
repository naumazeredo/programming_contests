#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int n, t;

double g[20][20];

int main() {
  scanf("%d%d", &n, &t);

  for (int i = 0; i < t; ++i) {
    g[0][0] += 1.0;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k <= j; ++k) {
        if (g[j][k] > 1.0) {
          g[j+1][k] += (g[j][k]-1.0)/2.0;
          g[j+1][k+1] += (g[j][k]-1.0)/2.0;
          g[j][k] = 1.0;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) ans += (g[i][j]>=0.9999999);

  printf("%d\n", ans);

  return 0;
}
