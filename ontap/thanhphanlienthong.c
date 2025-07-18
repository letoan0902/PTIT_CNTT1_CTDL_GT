#include <stdio.h>

int parent[10000];
int size[10000];

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
    }
    if(size[a]<size[b]){
        int temp =a;
        a = b;
        b=temp;
    }
    parent[b]=a;
    size[a]+=size[b];
}

int main() {
    int t;
    scanf("%d",&t);
    if(t<1||t>100){
        return 1;
    }
    while(t--){
        int v, e;
        scanf("%d %d",&v,&e);
        if(v<1||v>1000||e<1||e>(v*(v-1)/2)){
            return 1;
        }
        make_set(v);
        for (int i = 1; i <= e; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            gop(a,b);        
        }
        int count=0;
        for (int i = 1; i <= v; i++)
        {
            if(find(i)==i){
                count++;
            }
        }
        printf("%d\n",count);
    }
    
    return 0;
}