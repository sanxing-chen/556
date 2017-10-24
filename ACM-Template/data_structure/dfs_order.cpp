void init(){
    mem(head,-1);
    tot=0;ti=0;
}

void add_edge(int a,int b){
    edge[tot]=(Edge){b,head[a]};
    head[a]=tot++;
}

void dfs(int u,int fa){
    p1[u]=++ti;
    dfsnum[ti]=u;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        dfs(v,u);
    }
    p2[u]=ti;
}