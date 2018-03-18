#include<iostream>
using namespace std;
int n;
bool isSafe(int graph[][10], int c, int color[],int v)
{
    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}
bool graphcoloring(int graph[][10], int m, int color[],int v )
{
    if(v == n)
        return true;
    else
    {
        for(int c = 1; c <= m; c++)
        {
            if( isSafe(graph,c,color,v) )
            {
                color[v] = c;
                if(graphcoloring(graph,m,color,v+1 ) == true)
                    return true;
                color[v] = 0;
            }
        }
        return false;
    }
}
int main()
{
    int m,t;
    cin>>n;
    cin>>m;
    int graph[10][10]={0};
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(i != j )
            {
                cout<<"Edge between " << i+1<<" and "<< j+1;
                cin>>t;
                graph[i][j] = t;
                graph[j][i] = t;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
           cout<<graph[i][j];
        }
        cout<<endl;
    }
    int *color = new int[n];
    for(int i = 0; i < n; i++)
        color[i] = 0;
    if(graphcoloring(graph,m,color,0) == false)
        cout<<"Not Possible.";
    else
    {
        for(int i = 0; i < n; i++)
            cout<<i+1<<' '<<color[i]<<endl;
    }
    return 0;
}
