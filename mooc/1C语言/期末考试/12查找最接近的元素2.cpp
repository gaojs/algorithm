#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
#define N 100005
int n,m,x,l,r,mid;
long long a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    while(m--){
        scanf("%d",&x);
        l=0,r=n+1;
        if(x<=a[1]) {printf("%d\n",a[1]);continue;}
        if(x>=a[n]) {printf("%d\n",a[n]);continue;}
        while(l<r){
            mid=(l+r)>>1;
            if(a[mid]<x)
                l=mid;
            else if(a[mid]>x)
                r=mid;
            else {l=mid;break;}
            if(l==r-1&&a[l]<x&&a[r]>x) break;
        }
        if(abs(a[l]-x)<=abs(a[r]-x))
            printf("%d\n",a[l]);
        else printf("%d\n",a[r]);
    }
    return 0;
}