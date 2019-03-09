#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct S
{
    int x, y;
};

int main()
{
    int n;
    int x, y, a, b, c, d;
    int ans;
    S p[500 + 10];
    bool vis[400 + 10][400 + 10];    /// ????????
    while(~scanf("%d", &n))
    {
        memset(p, 0, sizeof(p));
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            x += 100;
            y += 100;
            p[i].x = x;
            p[i].y = y;
            vis[x][y] = 1;
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                x = p[i].x - p[j].x;
                y = p[i].y - p[j].y;
                /// ????? >=0 ?????????????
                /// ????????????????,??????????
                if((a = p[i].x + y) >= 0 && (b = p[i].y - x) >= 0 && (c = p[j].x + y) >= 0 && (d = p[j].y - x) >= 0 && vis[a][b]&& vis[c][d]) 
                {
                    ++ans;
                }
                if((a = p[i].x - y) >= 0 && (b = p[i].y + x) >= 0 && (c = p[j].x - y) >= 0 && (d = p[j].y + x) >= 0 && vis[a][b] && vis[c][d])
                {
                    ++ans;
                }
            }
        }
        cout << (ans / 4) << endl;
    }
    return 0;
}

