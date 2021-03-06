// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int N = 5e5+5;

int n, a[N];
ll ans;

int main() {
  scanf("%d", &n);
  int mi = INF, ma = -INF, po = 0, ne = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
    po |= a[i]>0;
    ne |= a[i]<0;
    ans += abs(a[i]);
  }

  if (n == 1) return !printf("%d\n", a[0]);

  if (po and !ne) ans -= 2*mi;
  if (!po and ne) ans += 2*ma;
  printf("%lld\n", ans);

  return 0;
}
