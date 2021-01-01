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

    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        string s;
        cin >> s;
        int l = s.length();
        int stack_ptr = 1, stack[l + 2];
        stack[0] = -1;
        stack[1] = -1;
        int ans = 0;
        REP(i, l)
        {
            if (s[i] != s[stack[stack_ptr]] && s[i] != s[stack[stack_ptr - 1]])
            {
                stack[++stack_ptr] = i;
            }
            else
            {
                stack[++stack_ptr] = -1;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}