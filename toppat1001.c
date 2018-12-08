# modified by cml
# commit 2
# 3 lll

# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int u, v;
    int w, s;
}Road;

typedef struct {
    int u, v;
    int w;
}Road_destroyed;
int m, n, p[505], q[505],total[505],total1[505];
Road r[250005];
Road_destroyed rd[250005];

int kruskal(int n,int k);
int cmp(const void*x, const void*y){ 
    return (*(Road*)x).w>(*(Road*)y).w ? 1:-1;
}
int cmp1(const void*x, const void*y){ // 降序排列
    return (*(int*)x)>(*(int*)y) ? -1:1;
}
int find(int x){
    while(x!=p[x])
        x=p[x];
    return x;
} /*错误：p[x]=find(x); */

int main()
{
    int i, j, x, y,k,destroyed,max;
    int tu, tv, tw, tf;


        // 城市个数
        scanf("%d", &m);
        // 路径条数
        scanf("%d", &n);

        for (i = 1; i <= m; ++i) p[i] = i;
        for (j = 0, i = 0; i < n; ++i)
        {
            scanf("%d%d%d%d", &tu, &tv, &tw, &tf);
            if (!tf)   /*只记录被摧毁的路*/
            {// 从rd[1]开始
                ++j;
                rd[j].u = tu;
                rd[j].v = tv;
                rd[j].w = tw;
            }
            // 所有路径
            r[i].u = tu;
            r[i].v = tv;
            r[i].w = tw;
            r[i].s = tf;
        }
        destroyed=j;

        //printf("%d\n", kruskal(j));
        // 依次求摧毁每个城市的成本
        for(k=1;k<=m;k++){
            for (i = 1; i <= m; ++i) p[i] = i;
            // 摧毁k，重新生成连通分量
            for (i = 0; i < n; ++i)
            {
                if (r[i].s!=0&&r[i].u!=k&&r[i].v!=k)
                {// union
                    x = find(r[i].u);
                    y = find(r[i].v);
                    if (x != y) p[x] = y;
                }
            }
            
            total[k]=kruskal(destroyed, k);
        }
        
        for (i = 1; i <= m; ++i)
        {
            total1[i]=total[i];
        }
        qsort(total1+1, m, sizeof(total1[0]), cmp1);
        
        max=total1[1];
        if(max==0){printf("0");return 0;}
        
        for (j=0,i = 1; i <= m; ++i)
        {
            if(total[i]==max){
                if(j!=0)printf(" ");
                j++;
                printf("%d", i);
            }
        }
    //getch(); 
    //system("Pause");
    return 0;
}

int kruskal(int n, int k)
{
    int i, cost, x, y;

    // 排序rd[1,2...]
    qsort(rd+1, n, sizeof(rd[0]), cmp);

    cost = 0;
    for (i = 1; i <= n; ++i)
    {
        if (rd[i].u==k||rd[i].v==k)continue;// 跳过被摧毁的城市
        x = find(rd[i].u);
        y = find(rd[i].v);
        if (x != y)
        {
            cost += rd[i].w;
            p[x] = y;
        }
    }

    return cost;
}
