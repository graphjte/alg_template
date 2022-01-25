void DFS(int u, int par = 0){
    Fi[u]= ++cnt;
    up[u][0] = par;
    d[u] = d[par] + 1;
    for(int i=1; i<=m; i++) up[u][i] = up[up[u][i-1]][i-1];
    for(int v: g[u]){
        if (v==par) continue;
        DFS(v,u);
    }
    Se[u] = ++cnt;
}

int Upper(int u, int v){
    return (Fi[u] <= Fi[v] && Se[u] >= Se[v]);
}

int LCA(int u, int v){
    if (Upper(u,v)) return u;
    if (Upper(v,u)) return v;
    for(int i=m; i>=0; i--){
        if (up[u][i] > 0 && !Upper(up[u][i],v)) u = up[u][i];
    }
    return up[u][0];
}
