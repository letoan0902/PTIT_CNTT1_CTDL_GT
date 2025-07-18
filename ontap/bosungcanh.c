#include<stdio.h>

int parent[100000];
int size[100000];

void make_set(int v){
    for (int i = 1; i <= v; i++)
    {
        parent[i]=i;
        size[i]=1;
    }
    
}

int find(int v){
    if(parent[v]==v){
        return v;
    } else {
        parent[v]=find(parent[v]);
        return parent[v];
    }
}

void gop(int u, int v){
    int a = find(u), b=find(v);
    if(a==b){
        return;
    } else {
        if(size[a]<size[b]){
            int temp = a;
            a=b;
            b=temp;
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n>100000||n>100000||n<1||m<1){
        return 1;
    }
    make_set(n);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        gop(u,v);
    }
    int maxSet=1;
    int maxSize=0;
    int z=find(1);
    for (int i = 2; i <=n; i++)
    {
        if(z==find(i)){
            maxSet++;
        }else if(size[i]>maxSize){
            maxSize=size[i];
        }
    }
    printf("%d\n",maxSet+maxSize);
    return 0;
}