#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m;
int p[100100], sz[100100];
struct edge {
    int u;
    int v;
    ll w;
};
vector <edge> E;
int a[100100];
vector <int> milkmen;
bool mys(edge x, edge y) {
    return x.w < y.w;
}
int root(int x) {
    if (x == p[x]) return x;
    return p[x] = root(p[x]);
}
bool con(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return true;
    if (sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    sz[u] = 0;
    p[u] = v;
    return false;
}
int main() {
    int t, i, x, c, ui, vi;
    ll wi;
    cin >> t;
    ll ans = 0;
    bool pt = false;
    while (t--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            p[i] = i, sz[i] = 1;
            cin >> a[i];
            if (a[i]) milkmen.push_back(i);
        }
        for (i = 0; i < m; i++) {
            cin >> ui >> vi >> wi;
            E.push_back({ui, vi, wi});
        }
        x = milkmen.size();
        for (c = 0; c < x; c++) {
            E.push_back({0, milkmen[c], 0});
        }
        sort(E.begin(), E.end(),  mys);
        ans = 0;
        for (i = 0; i < E.size(); i++) {
            ui = E[i].u, vi = E[i].v, wi = E[i].w;
            if (con(ui, vi)) continue;
            ans += wi;
        }
        pt = false;
        for (i = 1; i <= n; i++) {
            if (!con(i, 0)) {
                pt = true;
                cout << "impossible\n";
                break;
            }
        }
        if (!pt) cout << ans << '\n';
        milkmen.clear();
        E.clear();
        memset(p, 0, sizeof p);
        memset(sz, 0, sizeof sz);
        memset(a, 0, sizeof a);
    }
    return 0;
}
