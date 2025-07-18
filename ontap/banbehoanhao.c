#include <stdio.h>

int parent[100000];
int size[100000];
int side[100000];

void make_set(int v){
    for (int i = 1; i <=v; i++)
    {
        parent[i]=i;
        size[i]=1;
        side[i]=0;
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
        side[a]++;
        return;
    } else {
        if(size[a]<size[b]){
            int temp =a;
            a=b;
            b=temp;
        } 
        parent[b]=a;
        size[a]+=size[b];
        side[a]+=side[b]+1;
    }
}


int main(){

    int t;
    scanf("%d",&t);
    if(t>20||t<0){
        return 1;
    }
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        if(n>100000||m>100000){
            return 1;
        }
        make_set(n);
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            if(u==v){
                return 1;
            }
            gop(u,v);
        }
        int checkSide=0;
        for (int i = 1; i <=n; i++)
        {
            if(parent[i]==i){
                if(side[i]!=((size[i]*(size[i]-1))/2)){
                    checkSide++;
                    break;
                }
            }
        }
        if(checkSide!=0){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        
    }



    return 0;
}