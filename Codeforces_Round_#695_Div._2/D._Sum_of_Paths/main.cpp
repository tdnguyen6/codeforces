#include <bits/stdc++.h>

using namespace std;
// using std::cout
// namespace chrono = std::chrono;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FE(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_test = 1;
    while (n_test--) {
        int n, k, q;
        cin >> n >> k >> q;
        VLL a(n);
        // r, rn are no. of robots per index
        VVLL r(k + 1, VLL(n));
        r[0] = VLL(n, 1);
        
        // x ia no. of times an idx appears in good paths
        VLL c(n);
        REP(i, n) {
            cin >> a[i];
        }
        FOR(i, 1, k + 1, 1) {
            REP(j, n) {
                if (j - 1 >= 0) {
                    r[i][j] += r[i - 1][j - 1];
                }
                if (j + 1 < n) {
                    r[i][j] += r[i - 1][j + 1];
                }
                r[i][j] %= MOD;
            }
        }
        REP(i, k + 1) {
            REP(j, n) {
                c[j] += r[i][j] * r[k - i][j], c[j] %= MOD;
            }
        }

        ll ans = 0;
        REP(i, n) {
            ans += a[i] * c[i], ans %= MOD;
        }

        while (q--) {
            int idx, val;
            cin >> idx >> val;
            idx--;
            ans += ((val - a[idx]) * c[idx]), ans %= MOD;
            if (ans < 0) ans += MOD;
            a[idx] = val;
            cout << ans << '\n';
        }
    }
}
