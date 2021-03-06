// @subject: bitmask dp, knapsack
// @diff: med

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 10, M = 1<<N, T = 86405;

int n;
vector<piii> s[T];
int dp[T][M];

int main() {
  scanf("%d", &n);
  for (int m, i = 0; i < n; i++) {
    scanf("%d", &m);
    for (int u, v, c, j = 0; j < m; j++) {
      scanf("%d%d%d", &u, &v, &c);
      s[v].push_back({ (1<<i), { u, c } });
    }
  }

  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int j = 1; j < T; j++) for (int i = 0; i < (1<<n); i++) {
    dp[j][i] = max(dp[j][i], dp[j-1][i]);
    for (auto x : s[j]) {
      int b = x.st;
      int u = x.nd.st;
      int c = x.nd.nd;
      if (~dp[u][i]) {
        dp[j][i|b] = max(dp[j][i|b], dp[u][i] + c);
      }
    }
  }

  printf("%d\n", dp[T-1][(1<<n)-1]);

  return 0;
}
