#include <stdio.h>

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
    int a=find(u), b=find(v);
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

    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        if(n>100000||m>100000){
            return 1;
        }
        make_set(n);
        for (int i = 1; i <=m; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            if(u==v){
                return 1;
            }
            gop(u,v);
        }
        int maxSize=size[1];
        for (int i = 2; i <=n; i++)
        {
            if(size[i]>maxSize){
                maxSize=size[i];
            }
        }
        printf("%d\n",maxSize);
        
    }

    return 0;
}