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

template <class T>
bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

bool isH(VI& a, int i) {
    return i > 0 and i < a.size() - 1 and a[i - 1] < a[i] and a[i] > a[i + 1];
}

bool isV(VI& a, int i) {
    return i > 0 and i < a.size() - 1 and a[i - 1] > a[i] and a[i] < a[i + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_test;
    cin >> n_test;
    while (n_test--) {
        int n, ans = 0;
        cin >> n;
        VI a(n);
        REP(i, n) {
            cin >> a[i];
        }
        if (n > 2) {
            int itmdt = 0;
            vector<bool> is(n);

            auto isHV = [&](int i, bool recal = false) {
                if (recal)
                    return isH(a, i) or isV(a, i);
                return (bool)is[i];
            };
            
            FOR(i, 1, n - 1, 1) {
                if (isHV(i, true)) {
                    itmdt++;
                    is[i] = true;
                }
            }

            ans = itmdt;
            FOR(i, 1, n - 1, 1) {
                int tmp = a[i];
                a[i] = a[i - 1];
                ckmin(ans, itmdt - isHV(i) - isHV(i - 1) - isHV(i + 1) + isHV(i, true) + isHV(i - 1, true) + isHV(i + 1, true));
                a[i] = a[i + 1];
                ckmin(ans, itmdt - isHV(i) - isHV(i - 1) - isHV(i + 1) + isHV(i, true) + isHV(i - 1, true) + isHV(i + 1, true));
                a[i] = tmp;
            }
        }
        cout << ans << '\n';
    }
}