#include <bits/stdc++.h>

using namespace std;

#define MAX 50


	int vertices;
	int matrix[MAX][MAX];
	int parent[MAX];
	int unionfind(int i);
	void Union(int i,int j);


void graph(int v)
{
	vertices=v;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			matrix[i][j]=INT8_MAX; 
		}
	}


}

void Union(int i,int j)
{
	int a = unionfind(i); 
    int b = unionfind(j); 
    parent[a] = b; 

}

int unionfind(int i)
{
	while (parent[i] != i) 
        i = parent[i]; 
    return i; 
}

void kruskals()
{
	int mincost = 0; // Cost of min MST. 
 
    for (int i = 1; i <= vertices; i++) 
        parent[i] = i; 
  

    int edges_included = 0; 
    int min,a,b;
    while (edges_included < vertices - 1)
    { 
        min = INT8_MAX;
        a = -1;
        b = -1; 
        for (int x= 1; x <=vertices; x++)
        { 
            for (int y = 1; y <= vertices; y++) 
            { 
                if (unionfind(x) != unionfind(y) && matrix[x][y] < min) 
                { 
                    min = matrix[x][y]; 
                    a = x; 
                    b = y; 
                } 
            } 
        } 
  
        Union(a,b);
        edges_included++;
        printf("Edge included=(%d, %d) ; edge_cost=%d \n",a,b,min); 
        mincost += min;
    } 
    printf("\n Minimum cost of the MST= %d \n", mincost);
} 


void addEdge(int start,int end,int weight)
{ 
	matrix[start][end]=weight;
	matrix[end][start]=weight;
}

int main()
{
	int vert,edge;
	cout<<"Please enter the number of vertices and edges in the Graph : \n";
	cin>>vert>>edge;
	cout<<"\n";

	graph (vert);

	for(int i=0;i<edge;i++)
	{
    int a,b,w;
		cout<<"\nEnter the end points of edge "<<i+1<<" : \n";
		cin>>a>>b;
    cout<<"Enter the weight : ";
    cin>>w;
		addEdge(a,b,w);

	}

		cout<<"The edges and the min cost : \n";
	kruskals();
}
