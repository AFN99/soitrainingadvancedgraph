#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
using namespace std;
typedef pair<int,int> point;
typedef pair<point, int> node;
int inf = 1000 * 1000 * 100;
char pos[4][4];
int conx[1010];
int cony[1010];
string s[1010];
char z[1010];
int dis[1010][1010][4];
int vis[1010][1010][4];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
bool ch(int cx, int cy) {
    return (cx < 1 || cx > n || cy < 1 || cy > m || s[cx][cy] == '*');
}
bool cant(int cx, int cy, int tx, int ty, int k) {
    char door = s[cx][cy];
    int x = conx[door], y = cony[door];
    door = pos[x][(y + k) % 4];
    if (cx + 1 == tx) {
        return (door != '+' && door != 'v' && door != '|'
        &&  door != 'L' && door != 'R' && door != 'U');
    }
    if (cx - 1 == tx) {
        return (door != '+' && door != '^' && door != '|'
        &&  door != 'L' && door != 'R' && door != 'D');
    }
    if (cy - 1 == ty) {
        return (door != '+' && door != '<' && door != '-'
        &&  door != 'U' && door != 'R' && door != 'D');
    }
    if (cy + 1 == ty) {
        return (door != '+' && door != '>' && door != '-'
        &&  door != 'U' && door != 'L' && door != 'D');
    }
}
queue <node> q;
string to() {
    scanf("%s", z);
    return string(z);
}
int main() {
    for (int i = 0; i < 4; i++) pos[0][i] = '+';
    for (int i = 0; i < 4; i += 2) pos[1][i] = '-';
    for (int i = 1; i < 4; i += 2) pos[1][i] = '|';
    pos[2][0] = '^'; pos[2][1] = '>'; pos[2][2] = 'v'; pos[2][3] = '<';
    pos[3][0] = 'L'; pos[3][1] = 'U'; pos[3][2] = 'R'; pos[3][3] = 'D';
    conx['+'] = 0; cony['+'] = 0;
    conx['-'] = 1, cony['-'] = 0;
    conx['|'] = 1, cony['|'] = 1;
    conx['^'] = 2, cony['^'] = 0;
    conx['>'] = 2, cony['>'] = 1;
    conx['v'] = 2, cony['v'] = 2;
    conx['<'] = 2, cony['<'] = 3;
    conx['L'] = 3, cony['L'] = 0;
    conx['U'] = 3, cony['U'] = 1;
    conx['R'] = 3, cony['R'] = 2;
    conx['D'] = 3, cony['D'] = 3;
    int i, j, k, it;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    point T; point M;
    cin >> T.F >> T.S;
    cin >> M.F >> M.S;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            for (k = 0; k < 4; k++) dis[i][j][k] = inf;
        }
    }
    dis[T.F][T.S][0] = 0;
    q.push({{T.F, T.S}, 0});
    int cx, cy, ck, nx, ny;
    while (!q.empty()) {
        cx = q.front().F.F, cy = q.front().F.S, ck = q.front().S;
        q.pop();
        if (dis[cx][cy][(ck + 1) % 4] == inf) {
            dis[cx][cy][(ck + 1) % 4] = dis[cx][cy][ck] + 1;
            q.push({{cx, cy}, (ck + 1) % 4});
        }
        for (it = 0; it < 4; it++) {
            nx = cx + dx[it], ny = cy + dy[it];
            if (ch(nx, ny) || cant(cx, cy, nx, ny, ck) || cant(nx, ny, cx, cy, ck)) continue;
            if (dis[nx][ny][ck] == inf) {
                dis[nx][ny][ck] = dis[cx][cy][ck] + 1;
                q.push({{nx, ny}, ck});
            }
        }
    }
    int ans = inf;
    for (k = 0; k < 4; k++) ans = min(ans, dis[M.F][M.S][k]);
    if (ans == inf) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}
