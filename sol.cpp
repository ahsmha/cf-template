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
    return p1.f < p2.f;
}
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve(int T) {
    // cin >> T;
    while (T--) {
        int n, d; cin >> n >> d;
        vpi ms(n, {0, 0});
        rep(i,0,n) cin >> ms[i].f >> ms[i].s;
        sort(ms.begin(), ms.end(), cmp);
        int i = 0, j = 0, ans = 0, sum = 0;
        while (i<=j && j<n) {
            if (ms[j].f - ms[i].f < d) {
                j++;
                sum += ms[j].s;
                ans = max(ans,sum);
            } else {
                i++;
                sum -= ms[i].s;
            }
        }
        ans = max(sum, ans);
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


