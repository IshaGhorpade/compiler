#include<bits/stdc++.h>
using namespace std;
#define V 6 //No of vertices
int selectMinVertex(vector<int>& value,vector<bool>& setMST)
{
int minimum = INT_MAX;
int vertex;
for(int i=0;i<V;++i)
{
if(setMST[i]==false && value[i]<minimum)
{
vertex = i;
minimum = value[i];
}
}
return vertex;
}
void findMST(int graph[V][V])
{
int parent[V]; //Stores MST
vector<int> value(V,INT_MAX); //Used for edge relaxation
vector<bool> setMST(V,false); //TRUE->Vertex is included in MST
//Assuming start point as Node-0
parent[0] = -1; //Start node has no parent
value[0] = 0; //start node has value=0 to get picked 1st
//Form MST with (V-1) edges
for(int i=0;i<V-1;++i)
{
//Select best Vertex by applying greedy method
int U = selectMinVertex(value,setMST);
setMST[U] = true; //Include new Vertex in MST
//Relax adjacent vertices (not yet included in MST)
for(int j=0;j<V;++j)
{
if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j])
{
value[j] = graph[U][j];
parent[j] = U;
}
}
}
//Print MST
int mstWeight = 0;
for(int i=1;i<V;++i){
cout<<"U->V: "<<parent[i]<<"->"<<i<<" wt = "<<graph[parent[i]][i]<<"\n";
mstWeight += graph[parent[i]][i];
}
cout<<"Weight of MST: "<<mstWeight;
}
int main()
{
int graph[V][V] = { {0, 4, 6, 0, 0, 0},
{4, 0, 6, 3, 4, 0},
{6, 6, 0, 1, 8, 0},
{0, 3, 1, 0, 2, 3},
{0, 4, 8, 2, 0, 7},
{0, 0, 0, 3, 7, 0} };
findMST(graph); 
return 0;}
