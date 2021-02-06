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
        int n, m, sv, dv;
        cin >> n >> m;
        VVI adj(n);
        REP(i, m) {
            cin >> sv >> dv;
            adj[sv - 1].PB(dv - 1);
        }

        VI d(n, INF);
        d[0] = 0;
        {
            queue<int> q;
            q.push(0);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int i : adj[v]) {
                    if (d[i] == INF) {
                        q.push(i);
                        d[i] = d[v] + 1;
                    }
                }
            }
        }
        VI o(n);
        iota(all(o), 0);
        sort(all(o), [&](int i, int j) {
            return d[i] > d[j];
        });

        VI ans(n, INF);
        for (int i: o) {
            ans[i] = min(ans[i], d[i]);
            for (int j: adj[i]) {
                if (d[i] < d[j]) {
                    ans[i] = min(ans[i], ans[j]);
                } else {
                    ans[i] = min(ans[i], d[j]);
                }
            }
        }

        for (int i: ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}