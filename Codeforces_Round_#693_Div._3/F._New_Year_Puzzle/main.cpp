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
        int n, m, dis;
        cin >> n >> m;
        vector<VI> p(m, VI(2));
        REP(i, m) {
            cin >> p[i][0] >> p[i][1];
        }
        sort(p.begin(), p.end(), [](VI v1, VI v2) {
            return v1[1] < v2[1];
        });
        vector<bool> b(m, true);
        REP(i, m - 1) {
            if (p[i][1] == p[i + 1][1]) {
                b[i] = false;
            }
        }
        string ans;
        bool e = true;
        VI cur(2);
        REP(i, m) {
            if (b[i]) {
                if (e) {
                    cur = p[i];
                    e = false;
                } else {
                    if (p[i][1] != cur[1]) {
                        dis = p[i][1] - cur[1];
                        if (p[i][0] - cur[0]) {
                            if (dis & 1) {
                                break;
                            }
                        } else {
                            if (dis % 2 == 0) {
                                break;
                            }
                        }
                    }
                    e = true;
                }
            } else {
                if (!e) {
                    break;
                } else {
                    e = true;
                    i++;
                }
            }
        }
        ans = e ? "YES" : "NO";
        cout << ans << '\n';
    }
}