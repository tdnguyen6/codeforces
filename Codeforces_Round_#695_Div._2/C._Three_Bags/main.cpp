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

    int N[3];
    REP(i, 3) {
        cin >> N[i];
    }
    VVI b(3);
    VI min(3);
    vector<ll> sum(4);
    ll ans = 0;
    REP(i, 3) {
        VI tmp(N[i]);
        REP(j, N[i]) {
            cin >> tmp[j];
            sum[i] += tmp[j];
            if (tmp[j] < tmp[min[i]]) {
                min[i] = j;
            }
        }
        ans += sum[i];
        b[i] = tmp;
    }
    int max = 0;
    FOR(i, 1, 3, 1) {
        if (b[i][min[i]] > b[max][min[max]]) {
            max = i;
        }
    }
    REP(i, 3) {
        if (i != max) {
            sum[3] += b[i][min[i]];
        }
    }
    cout << ans - 2 * *min_element(all(sum)) << '\n';
}