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
extern const int MOD = 1000000007;
// extern const int MOD = 998244353;
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;
typedef vector<VB> VVB;
typedef vector<PII> VII;
typedef map<int, int> MPII;
typedef map<int, PII> MIPII;
typedef unordered_map<int, int> UMPII;
typedef set<int> SETI;
typedef unordered_set<int> USETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}

template <const int &MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_int &operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _m_int &operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a"(quot), "=d"(rem)
            : "d"(x_high), "a"(x_low), "r"(m));
        return rem;
    }

    _m_int &operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _m_int &operator/=(const _m_int &other) {
        return *this *= other.inv();
    }

    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

    _m_int &operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int &operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int) {
        _m_int before = *this;
        ++*this;
        return before;
    }
    _m_int operator--(int) {
        _m_int before = *this;
        --*this;
        return before;
    }

    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }

    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];

    static void prepare_inv() {
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        _m_int product = 1;
        int v = val;

        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }

        return product * save_inv[v];
    }

    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream &operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};

template <const int &MOD>
_m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];

using mod_int = _m_int<MOD>;

vector<mod_int> _factorial = {1, 1}, _inv_factorial = {1, 1};

void prepare_factorials(int64_t maximum) {
    static int prepared_maximum = 1;

    if (maximum <= prepared_maximum)
        return;

    // Prevent increasing maximum by only 1 each time.
    maximum += maximum / 16;
    _factorial.resize(maximum + 1);
    _inv_factorial.resize(maximum + 1);

    for (int i = prepared_maximum + 1; i <= maximum; i++) {
        _factorial[i] = i * _factorial[i - 1];
        _inv_factorial[i] = _inv_factorial[i - 1] / i;
    }

    prepared_maximum = int(maximum);
}

mod_int factorial(int n) {
    if (n < 0) return 0;
    prepare_factorials(n);
    return _factorial[n];
}

mod_int inv_factorial(int n) {
    if (n < 0) return 0;
    prepare_factorials(n);
    return _inv_factorial[n];
}

mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return _factorial[n] * _inv_factorial[r] * _inv_factorial[n - r];
}

mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return _factorial[n] * _inv_factorial[n - r];
}

mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return _inv_factorial[n] * _factorial[r] * _factorial[n - r];
}

mod_int inv_permute(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return _inv_factorial[n] * _factorial[n - r];
}

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}

// void dfs(int size, VI W, VVI adj, VB &bad, MPII freq, VI path = {0}, int par = -1, int node = 0) {
//     freq[node]++;
//     for (auto i : adj[node]) {
//         if (i - par) {
//             dfs(size, W, adj, bad, freq, path, i);
//         }
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_test = 2;
    // cin >> n_test;
    while (n_test--) {
        int N;
        cin >> N;
        VI A(N);
        REP(i, N) {
            cin >> A[i];
        }
        VVI E(N);
        int u, v;
        REP(i, N - 1) {
            cin >> u >> v;
            u--, v--;
            E[u].PB(v);
            E[v].PB(u);
        }
        MPII freq;

        // check if there are 3 times a value
        {
            bool stop = false;
            stack<int> s;
            stack<int> pars;
            pars.push(-1);
            s.push(0);
            while (!s.empty()) {
                int node = s.top();
                s.pop();
                int par = pars.top();
                for (auto i : E[node]) {
                    if (i - par) {
                        pars.push(node);
                        s.push(i);
                        if (freq[A[i]] == 2) {
                            cout << 0 << '\n';
                            stop = true;
                            break;
                        }
                        freq[A[i]]++;
                    }
                }
                if (stop) break;
            }
            pars.pop();
            if (stop) continue;
            freq.clear();
        }

        stack<int> pars;
        pars.push(-1);
        deque<int> path;
        VB bad(N);
        bool isBad = false;
        function<void(int)> dfs = [&](int node) {
            path.PB(node);
            if (freq[A[node]] == 1) {
                for (auto i = path.begin(); i != path.end(); i++) {
                    bad[*i] = true;
                    if (i != path.begin() and A[*i] == A[node]) break;
                }
                isBad = true;
            }
            if (isBad)
                bad[node] = false;
            cout << "node: " << node << '\n';
            freq[A[node]]++;
            int count = 0;
            int par = pars.top();
            for (auto i : E[node]) {
                if (par - i) {
                    dfs(i);
                    count++;
                }
            }
            if (!count) {
                isBad = false;
            }
            pars.pop();
            freq[A[node]]--;
            path.pop_back();
        };
        dfs(0);
        int ans = 0;
        REP(i, N) {
            ans += !bad[i];
        }
        cout << ans << '\n';
    }
}