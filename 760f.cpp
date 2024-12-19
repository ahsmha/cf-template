#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using v = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = v<int>;
using vc = v<char>;
using vs = v<string>;
using vb = v<bool>;
using vll = v<long long>;
using vpi = v<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define rep(i,a,b) for (int i = (a); i < (int)(b); ++i)
#define repr(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x,a) for (auto& x: a)

const int MOD = 1e9+7;
const db PI = acos((db)-1);

tcT> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } // set a = max(a,b)

// inline void dbg(T x) { cerr << x << endl; }

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve(int T) {
    // cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vi cat(n,0); rep(i,0,n) cin >> cat[i];
        unordered_map<int, vi>b;
        rep(i,0,n-1) {
            pi x; cin >> x.f >> x.s;
            b[x.f].pb(x.s);
            b[x.s].pb(x.f);
        }
        vi vis(n,0);
        int ans = 0, cnt = 0;
        stack<int>s;
        s.push(0);
        while (!s.empty()) {
            if (cnt >= m) continue;
            int u = s.top();
            s.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            if (cat[u-1] == 1) cnt++;
            if (b.find(u) != b.end()) {
                for (auto v: b[u]) {
                    if (!vis[v]) s.push(v);
                }
            } else {
                cout << u << " - " << endl;
                ans++;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    solve(T);
    return 0;
}


