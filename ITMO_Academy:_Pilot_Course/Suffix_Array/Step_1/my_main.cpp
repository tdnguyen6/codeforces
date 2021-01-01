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
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto a = freopen("a.in", "r", stdin);
    // auto b = freopen("a.out", "w", stdout);
    // if (!a || !b)
    //     cout << "uh oh" << endl;

    using namespace chrono;
    auto start = high_resolution_clock::now();

    int n_tests = 1;
    // cin >> n_tests;
    while (n_tests--)
    {
        string s;
        cin >> s;
        s += '$';
        int l = s.length(), ec = 0, prev_sa01, count = 0;
        VI sa[l];
        REP(i, l)
        {
            sa[i] = {l - i - 1, s[l - i - 1], 0};
        }
        sort(sa + 1, sa + l, [](auto a, auto b) {
            return a[1] < b[1];
        });
        int k_lim = pow(2, ceil(log2(l))), isa[l] = {0};
        for (int k = 1; k <= k_lim; k *= 2)
        {
            ec = 0;
            prev_sa01 = sa[0][1];
            sa[0][1] = ec;
            FOR(i, 1, l, 1)
            {
                isa[sa[i][0]] = i;
                if (prev_sa01 < sa[i][1] || (prev_sa01 == sa[i][1] && sa[i - 1][2] < sa[i][2]))
                {
                    prev_sa01 = sa[i][1];
                    sa[i][1] = ++ec;
                }
                else
                {
                    prev_sa01 = sa[i][1];
                    sa[i][1] = ec;
                }
            }
            int tmp = 0;
            REP(i, l)
            {
                tmp = (sa[i][0] + k) % l;
                sa[i][2] = sa[isa[(sa[i][0] + k) % l]][1];
            }
            tmp = 0;
            sort(sa + 1, sa + l, [](VI a, VI b) {
                return (a[1] < b[1]) || (a[1] == b[1] && a[2] < b[2]);
            });
        }

        REP(i, l)
        {
            cout << s.substr(sa[i][0], l - sa[i][0]) << endl;
        }
        cout << '\n';
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "It took: " << duration.count() << "us" << endl;
}