#include<stdio.h>
struct node
{
    int vertex;
    struct node*next;
};
int v,e;
struct node**adj,**adj1;
int*que,*visited,*ft;
int f=-1,r=-1,t=0;
void dfs();
void dfsvisit(int);
void dfs1();
void dfsvisit1(int);
void adjlisRep(struct node**adj,int s,int en)
{
    struct node*ne=(struct node*)malloc(sizeof(struct node));
    ne->vertex=en;
    ne->next=adj[s];
    adj[s]=ne;
}
void main()
{
    int s,i,en;
    struct node*ptr;
    printf("Enter number of vertices:");
    scanf("%d",&v);
    adj=(struct node**)malloc((v+1)*sizeof(struct node*));
    adj1=(struct node**)malloc((v+1)*sizeof(struct node*));
    for(i=0;i<=v;i++)
        adj[i]=adj1[i]=NULL;
    printf("Enter number of edges:");
    scanf("%d",&e);
    printf("Enter the edges:");
    printf("Start End\n");
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&s,&en);
        adjlisRep(adj,s,en);
        adjlisRep(adj1,en,s);
    }
    dfs();
    dfs1();
    getch();
}
void dfs()
{
    int i;
    visited=(int*)malloc((v+1)*sizeof(int));
    ft=(int*)malloc((v+1)*sizeof(int));
    for(i=0;i<=v;i++)
        visited[i]=0;
    printf("dfs");
    for(i=1;i<=v;i++)
        if(visited[i]==0)
            dfsvisit(i);
}
void dfsvisit(int u)
{
    int w;
    struct node*ptr;
    visited[u]=1;
    printf("%d",u);
    ptr=adj[u];
    while(ptr!=NULL)
    {
        w=ptr->vertex;
        if(visited[w]==0)
            dfsvisit(w);
        ptr=ptr->next;
    }
    t++;
    ft[u]=t;
}
void dfsvisit1(int u)
{
    int w;
    struct node*ptr;
    visited[u]=1;
    printf("%d",u);
    ptr=adj1[u];
    while(ptr!=NULL)
    {
        w=ptr->vertex;
        if(visited[w]==0)
        dfsvisit1(w);
        ptr=ptr->next;
    }
}
int visitedAll()
{
    int i,flag=1;
    for(i=1;i<=v;i++)
        if(visited[i]==0)
        {
            flag=0;
            break;
        }
    return flag;
}
void dfs1()
{
    int i,max=0,ver;
    printf("\nComponents\n");
    for(i=0;i<=v;i++)
        visited[i]=0;
    while(!visitedAll())
    {
        max=0;
        for(i=1;i<=v;i++)
        {
            if(visited[i]==0&&ft[i]>max)
            {
                ver=i;
                max=ft[i];
            }
        }
        printf("{");
        dfsvisit1(ver);
        printf("}\n");
    }
}