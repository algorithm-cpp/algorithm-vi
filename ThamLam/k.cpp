#include <iostream>
#include <algorithm>
using namespace std;
struct Edge{
	int first, end, weight;
};
Edge dsc[100], mst[100];;
int parent[100]={0}, mstNum=0, m ,n;
void input(){
	//nhap do thi bang danh sach canh
	cout<<"Nhap so dinh: ";
	cin>>m;
	cout<<"Nhap so canh: ";
	cin>>n;
	for(int i=0; i<n;i++){
		cin>>dsc[i].first>>dsc[i].end>>dsc[i].weight;
	}
}
bool dk(Edge a, Edge b){
	return a.weight< b.weight;
}
void SortEdge(){
	sort(dsc, dsc+n, dk);
}

int findRoot(int u){
	while(parent[u]>0)
		u=parent[u];
	return u;
}

void unionSet(int u,int v) {
    int x = findRoot(u);
    int y = findRoot(v);
    if (parent[x] > parent[y]){
        parent[y] += parent[x];
        parent[x] = y;
    } else {
        parent[x] += parent[y];
        parent[y] = x;
    }
}
void kruskal() {
    int i, beginRoot, endRoot;
    for(i=0; i<=m; i++)
        parent[i] = 0;
    sort(dsc, dsc+n, dk);
 
    for(i = 0; i<n; i++) {
        beginRoot = findRoot(dsc[i].first);
        endRoot = findRoot(dsc[i].end);
        if(beginRoot != endRoot) {
            mst[mstNum++] = dsc[i];
            unionSet(beginRoot, endRoot);
            if(mstNum == m - 1) break; 
        }
    }
}
main(){
	input();
	kruskal();
	cout<<"cay khung nho nhat"<<endl;
	for(int i=0;i< m-1;i++){
		cout<<mst[i].first<<" "<<mst[i].end<<endl;
	}
}
