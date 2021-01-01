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
    string s;
    cin >> s;
    s += '$';
    int l = s.length();
    int od[l], ec[l];

    {
        // k = 0
        pair<int, int> a[l];
        REP(i, l)
        {
            a[i] = {s[i], i};
        }
        sort(a, a + l);

        // order
        REP(i, l)
        {
            od[i] = a[i].second;
        }

        // equipvalent classes
        ec[od[0]] = 0;
        FOR(i, 1, l, 1)
        {
            ec[od[i]] = ec[od[i - 1]] + (a[i].first > a[i - 1].first);
        }
    }

    pair<pair<int, int>, int> a[l];
    for (int k = 0; (1 << k) < l; k++)
    {
        REP(i, l)
        {
            a[i] = {{ec[i], ec[(i + (1 << k)) % l]}, i};
        }
        sort(a, a + l);

        // order
        REP(i, l)
        {
            od[i] = a[i].second;
        }

        // equipvalent classes
        ec[od[0]] = 0;
        FOR(i, 1, l, 1)
        {
            ec[od[i]] = ec[od[i - 1]] + (a[i].first > a[i - 1].first);
        }
    }

    REP(i, l)
    {
        cout << od[i] << endl;
    }
    cout << '\n';
}