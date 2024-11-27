#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    unordered_map<string, list<string>> adjList;

public:
    // Add flight path between two cities
    void addFlightPath(const string& cityA, const string& cityB) {
        adjList[cityA].push_back(cityB);
        adjList[cityB].push_back(cityA); // For undirected graph (bi-directional flight)
    }

    // Display the graph (Adjacency List Representation)
    void displayGraph() {
        if (adjList.empty()) {
            cout << "The graph is empty. No flight paths available.\n";
            return;
        }
        cout << "Flight Paths (Graph Representation):" << endl;
        for (const auto& city : adjList) {
            cout << city.first << " -> ";
            for (const auto& neighbor : city.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Check if the graph is connected using BFS
    bool isConnected() {
        if (adjList.empty()) return true;

        // Start BFS from any node (Take the first city from adjList)
        string startCity = adjList.begin()->first;
        unordered_map<string, bool> visited;
        bfs(startCity, visited);

        // After BFS, check if all cities are visited
        for (const auto& city : adjList) {
            if (!visited[city.first]) {
                return false; // If any city is not visited, graph is not connected
            }
        }
        return true;
    }

private:
    // BFS to visit all cities starting from the given city
    void bfs(const string& startCity, unordered_map<string, bool>& visited) {
        queue<string> q;
        visited[startCity] = true;
        q.push(startCity);

        while (!q.empty()) {
            string currentCity = q.front();
            q.pop();

            // Visit all neighbors of the current city
            for (const auto& neighbor : adjList[currentCity]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;
    int choice;

    do {
        cout << "\n--- Flight Path Graph Menu ---\n";
        cout << "1. Add a flight path between two cities\n";
        cout << "2. Display all flight paths (Graph Representation)\n";
        cout << "3. Check if all cities are connected\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string cityA, cityB;
                cout << "Enter the name of the first city: ";
                cin >> cityA;
                cout << "Enter the name of the second city: ";
                cin >> cityB;
                g.addFlightPath(cityA, cityB);
                cout << "Flight path added between " << cityA << " and " << cityB << ".\n";
                break;
            }
            case 2: {
                g.displayGraph();
                break;
            }
            case 3: {
                if (g.isConnected()) {
                    cout << "The graph is connected. All cities are reachable from each other.\n";
                } else {
                    cout << "The graph is not connected. Some cities are unreachable.\n";
                }
                break;
            }
            case 4: {
                cout << "Exiting the program. Goodbye!\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

