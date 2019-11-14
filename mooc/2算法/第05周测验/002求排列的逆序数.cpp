#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[100010] , b[100010];
long long cnt =0;
void jiSuan(int s,int mid,int e){
    int p1=s,p2=mid+1,p3=0;
    while(p1<=mid&&p2<=e){
        if(a[p1]<=a[p2]){
            b[p3]=a[p1];
            p3++,p1++;
        }
        else{
            cnt+=mid-p1+1;
            b[p3]=a[p2];
            p3++,p2++;
        }
    }
    while(p1<=mid){b[p3]=a[p1]; p1++,p3++;}
    while(p2<=e){b[p3]=a[p2]; p2++,p3++;}
    for(int i=0;i<e-s+1;i++){
        a[s+i]=b[i];//注意：此处不能s++！
//因为s是参数，如果改变了参数，下面的递归就会出错！所以要在保证s不变的基础上将数组复制给原数组。
//另外，此处也不可以将a【】初始坐标设为0，因为要s才是a数组开始的位置！
    }
}
void erFen(int s,int e){
    if(s>=e) return ;
    int mid=s+(e-s)/2;
    erFen(s,mid);
    erFen(mid+1,e);
    jiSuan(s,mid,e);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    erFen(0,n-1);
    cout<<cnt<<endl;
    return 0;
}
