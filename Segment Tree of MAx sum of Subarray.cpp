//Segment Tree of MAx sum of Subarray for given range
//build tree
#include<bits/stdc++.h>
using namespace  std;
struct node{
    int s,ms,bps,bss;
};
void build(int a[],struct node * t,int s,int e,int ind){
    if(s==e){
        t[ind].s=a[s];
        t[ind].ms=a[s];
        t[ind].bps=a[s];
        t[ind].bss=a[s];
        return;
    }
    int mid=(s+e)/2;
    build(a,t,s,mid,2*ind);
    build(a,t,mid+1,e,2*ind+1);
    int lt=2*ind;
    int rt=2*ind+1;
    t[ind].s=t[lt].s+t[rt].s;
    t[ind].ms=max(t[lt].ms,max(t[rt].ms,max(t[lt].s+t[rt].bps,max(t[rt].s+t[lt].bss,t[lt].bss+t[rt].bps))));
    t[ind].bps=max(t[lt].bps,t[lt].s+t[rt].bps);
    t[ind].bss=max(t[rt].bss,t[lt].bss+t[rt].s);
    return;
}
int main(){
    int a[]={1,2,-3,4,5};
    struct node * t=new struct node [20];
    build(a,t,0,4,1);
    for(int i=1;i<15;i++){
        cout<<t[i].s<<" ";
    }
    return 0;
}


