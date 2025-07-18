#include <stdio.h>

int parent[10000];
int size[10000];

void make_set(int v)
{
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    else
    {
        parent[v] = find(parent[v]);
        return parent[v];
    }
}

void gop(int u, int v)
{
    int a = find(u), b = find(v);
    if (a == b)
    {
        return;
    }
    else
    {
        if (size[a] < size[b])
        {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int t;
    
    scanf("%d", &t);
    if (t > 20 || t < 1)
    {
        return 1;
    }
    int t1=0;
    int arra[t];
    int arrb[t];
    while (t--)
    {
        int n;
        arra[t1] = 0;
        scanf("%d", &n);
        if (n < 1 || n > 1000)
        {
            return 1;
        }
        make_set(n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            if (find(u) == find(v))
            {
                arra[t1]++;
            }
            else
            {
                gop(u, v);
            }
        }
        arrb[t1] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (find(i) == i)
            {
                arrb[t1]++;
            }
        }
        t1++;
    }
    for (int i = 0; i < t1; i++)
    {
        if (arra[i] != 0 || arrb[i] != 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    
    return 0;
}