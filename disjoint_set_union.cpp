// https://github.com/cschiou/competitive-programming/blob/main/disjoint_set_union.cpp
class DSU {
  public:
    DSU(int numOfNodes) {
        n = numOfNodes;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int find(int a){
        if(par[a] == a) return a;
        par[a] = find(par[a]);
        return par[a];
    }
    void join(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;
        par[pa] = par[pb] = min(pa,pb);
    }
    vector<int> par;
    int n;
};
