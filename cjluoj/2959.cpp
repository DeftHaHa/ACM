const int MAX_N = 10000;
const int MAX_M = 100000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, w, next;
} e[MAX_M];
int p[MAX_N], eid, n;
void mapinit() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int w) {
    e[eid].v = v;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void insert2(int u, int v, int w) {  // 插入带权双向边
    insert(u, v, w);
    insert(v, u, w);
}

int dist[MAX_N];  // 存储单源最短路的结果
bool vst[MAX_N];  // 标记每个顶点是否在集合 U 中
bool dijkstra(int s) {
    memset(vst, 0, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_w = inf;  // 记录 dist 最小的顶点编号和 dist 值
        for (int j = 0; j < n; ++j) {
            if (!vst[j] && dist[j] < min_w) {
                min_w = dist[j];
                v = j;
            }
        }
        if (min_w == inf) {  // 没有可用的顶点，算法结束，说明有顶点无法从源点到达
            return false;
        }
        vst[v] = true;  // 将顶点 v 加入集合 U 中
        for (int j = p[v]; j != -1; j = e[j].next) {
            // 如果和 v 相邻的顶点 x 满足 dist[v] + w(v, x) < dist[x] 则更新 dist[x]，这一般被称作“松弛”操作
            int x = e[j].v;
            if (!vst[x] && dist[v] + e[j].w < dist[x]) {
                dist[x] = dist[v] + e[j].w;
            }
        }
    }
    return true;  // 源点可以到达所有顶点，算法正常结束
}
