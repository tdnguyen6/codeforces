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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_test;
    cin >> n_test;
    while (n_test--) {
        int N;
        cin >> N;
        int tmp;
        list<int> even, odd;
        REP(i, N) {
            cin >> tmp;
            if (tmp % 2 == 0)
                even.push_front(tmp);
            else
                odd.push_front(tmp);
        }
        even.sort(greater<int>());
        odd.sort(greater<int>());

        ll aS = 0, bS = 0;
        while (N--) {
            // Alice
            if (!even.empty() && !odd.empty()) {
                if (even.front() < odd.front()) {
                    odd.pop_front();
                } else {
                    aS += even.front();
                    even.pop_front();
                }
            } else if (even.empty()) {
                odd.pop_front();
            } else {
                aS += even.front();
                even.pop_front();
            }

            if (even.empty() && odd.empty()) break;

            // bob
            if (!odd.empty() && !even.empty()) {
                if (odd.front() < even.front()) {
                    even.pop_front();
                } else {
                    bS += odd.front();
                    odd.pop_front();
                }
            } else if (odd.empty()) {
                even.pop_front();
            } else {
                bS += odd.front();
                odd.pop_front();
            }
            if (even.empty() && odd.empty()) break;
        }

        string winner;
        if (aS > bS)
            winner = "Alice";
        else if (bS > aS)
            winner = "Bob";
        else
            winner = "Tie";
        cout << winner << '\n';
    }
}