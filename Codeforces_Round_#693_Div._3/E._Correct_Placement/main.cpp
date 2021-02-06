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
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
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

    int n_test;
    cin >> n_test;
    while (n_test--) {
        int n, a1, a2, ans, oi, iwmin = 0, ihmin = 0;
        cin >> n;
        // sort by h -> w -> index
        vector<pair<VI, int>> a(n, make_pair(VI(2), 0));
        // sort by w -> h -> index
        vector<pair<VI, int>> b(n, make_pair(VI(2), 0));
        // store original array
        vector<VI> o(n, VI(2));
        REP(i, n) {
            cin >> o[i][0] >> o[i][1];
            a[i].first[0] = o[i][0];
            a[i].first[1] = o[i][1];
            b[i].first[0] = o[i][1];
            b[i].first[1] = o[i][0];
            a[i].second = i;
            b[i].second = i;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        MPII m, mm;
        m[-1] = INF;
        mm[-1] = INF;
        REP(i, n) {
            // map h -> index of smallest width with height <= h
            if (a[i].first[1] < a[iwmin].first[1]) {
                iwmin = i;
            }
            m[a[i].first[0]] = iwmin;

            // map w -> index of smallest height with width <= w
            if (b[i].first[1] < b[ihmin].first[1]) {
                ihmin = i;
            }
            mm[b[i].first[0]] = ihmin;
        }
        REP(i, n) {
            // find last index with height < height at index i
            a1 = (--m.lower_bound(o[i][0]))->second;
            // find last index with width < width at index i
            a2 = (--mm.lower_bound(o[i][0]))->second;

            // compare width
            if (a1 != INF && o[i][1] > a[a1].first[1]) {
                ans = a[a1].second + 1;
            // compare height
            } else if (a2 != INF && o[i][1] > b[a2].first[1]) {
                ans = b[a2].second + 1;
            } else {
                ans = -1;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}