#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Edge {
int destination, weight;
Edge(int dest, int w) : destination(dest), weight(w) {}
};
vector<int> dijkstra(int source, int vertices, vector<vector<Edge> >& graph) {
vector<int> distance(vertices, INT_MAX);
distance[source] = 0;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
pq.push({0, source});
while (!pq.empty()) {
int currentDistance = pq.top().first;
int currentVertex = pq.top().second;
pq.pop();
if (currentDistance > distance[currentVertex]) continue;
for (Edge& edge:graph[currentVertex]) {
int newDistance = currentDistance + edge.weight;
if (newDistance < distance[edge.destination]) {
distance[edge.destination] = newDistance;
pq.push({newDistance, edge.destination});
}
}
}
return distance;
}
int main() {
int vertices, edges;
cout << "Enter the number of intersections (vertices) and roads (edges): ";
cin >> vertices >> edges;
vector<vector<Edge>> graph(vertices);
cout << "Enter the roads (start, end, travel time considering traffic):" << endl;
for (int i = 0; i < edges; ++i) {
int start, end, weight;
cin >> start >> end >> weight;
graph[start].push_back(Edge(end, weight));
graph[end].push_back(Edge(start, weight)); // For undirected graph
}
int source, destination;
cout << "Enter the source and destination intersections: ";
cin >> source >> destination;
vector<int> shortestPaths = dijkstra(source, vertices, graph);
if (shortestPaths[destination] == INT_MAX) {
cout << "No path exists from " << source << " to " << destination << endl;
} else {
cout << "The shortest travel time from " << source << " to " << destination << " is: "<< shortestPaths[destination] << " units." << endl;
}
return 0;
}
