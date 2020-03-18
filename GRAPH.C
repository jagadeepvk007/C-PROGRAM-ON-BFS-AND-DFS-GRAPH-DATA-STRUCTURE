#include<stdio.h>
#include<conio.h>
void bfs(int adj[10][10],int src, int n)
 {
  int q[10],r=-1,f=0;int visited[10]={0},u,v;
  q[++r]=src;
  visited[src]=1;
  printf("%d",src);
  while(f<=r)
   {
    u=q[f++];
     for(v=0;v<n;v++)
      {
       if(adj[u][v]==1&&visited[v]==0)
	{
	 q[++r]=v;
	 printf("%d",v);
	 visited[v]=1;
	 }
      }
   }
 }

 void dfs(int adj[10][10],int k,int n,int visited[10])
  {
   int src;
   visited[src]=1;
   for(k=0;k<n;k++)
    {
    if(adj[src][k]==1&&visited[k]==0)
     {
      dfs(adj,k,n,visited);
     }
    }
   }
  void main()
   {
    int adj[10][10],src,n,visited[10]={0},i,j,flag=0,ch;
    clrscr();

    printf("1.create graph\n   2.BFS traversal \n  3.DFS traversal \n  4.exit \n");
    while(1)
     {
      printf("enter choice \n");
      scanf("%d",&ch);
      switch(ch)
       {
	case 1:printf("enter the number of cities\n");
	       scanf("%d",&n);
	       printf("enter the adjacency matrix \n");
	       for(i=0;i<n;i++)
		{
		 for(j=0;j<n;j++)
		  {
		   scanf("%d",&adj[i][j]);
		  }
		}
	       break;

	case 2:printf("enter source vertex\n");
	       scanf("%d",&src);
	       printf("reachable vertices are \n");
	       bfs(adj,src,n);
	       break;

	case 3:printf("enter source vertex \n");
	       scanf("%d",&src);
	       dfs(adj,src,n,visited);
	       for(i=0;i<n;i++)
		if(visited[i]==0)
		flag=1;
		if(flag==1)
		printf("graph is not connected\n");
		else
		printf("graph is connected\n");
		break;
	case 4:exit();
	 }
      }
    }