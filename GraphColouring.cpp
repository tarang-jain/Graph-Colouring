#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
struct point{
    int position;
    int n_colored;
    bool operator<(const point &b) const{
    if(n_colored==b.n_colored)return position<b.position;
    return n_colored<b.n_colored;
    }
    bool operator==(const int &b) const{
    return position==b;
  }
    point(const int & a){
        position= a;
        n_colored= 0;
    }
    point(){};
};
struct V{
    int pos;
    int col;
    V(){};
    bool operator<(const V &b) const{
    return pos<b.pos;
}
};
struct vertex{
    int color;
    int max_color;
    vector<const point*> nbrs;
    vertex(){};
    vertex(const int & a){
        color= 0;
        max_color= 0;
    }
};

int main() {
    int n, m;
    cin>>n>>m;
    map<point, vertex> S;
    set<V> S1;
    for(int i= 0; i<n; i++){
        S.insert(S.end(), pair<point, vertex> (point(i), vertex(i)));
    }
    for(int i= 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        map<point, vertex>::iterator it1 = S.find(a);
        map<point, vertex>::iterator it2 = S.find(b);
        (it1->second).nbrs.push_back(&(it2->first));
        (it2->second).nbrs.push_back(&(it1->first));
    }

    while(!S.empty()){
    map<point, vertex>::iterator it= S.begin();
    (it->second).color = (it->second).max_color+1;
    for(size_t j= 0; j!= (it->second).nbrs.size(); j++ ){
        if(S.find(*((it->second).nbrs[j]))!= S.end()){
        point p;
        vertex v;
        v.max_color= (it->second).color;
        p.n_colored= ((it->second).nbrs[j])->n_colored+1;
        p.position= ((it->second).nbrs[j])->position;
        v.color= 0;
        v.nbrs= S[*((it->second).nbrs[j])].nbrs;
        S.erase(*((it->second).nbrs[j]));
        S[p]= v;
    }
    }
    V r;
    r.pos= (it->first).position;
    r.col= (it->second).color;
    S1.insert(r);
    S.erase(it->first);

}
    while(!S1.empty()){
        cout<<S1.begin()->col<<' ';
        S1.erase(S1.begin());
    }
    return 0;

}
