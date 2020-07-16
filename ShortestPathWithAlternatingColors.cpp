#include <vector>
#include <iostream>
using namespace std;

vector<int> shortestAlternatingPaths (int n, vector<vector<int>> red_edges, vector<vector<int>> blue_edges) 
{
    vector<bool> red(n,0);\\indicator for whether or not a vertex has been visited by a red edge
    vector<bool> blue(n,0);\\indicator for whether or not a vertex has been visited by a blue edge
    vector<int> result(n,-1);
    vector<vector<int>> current;
    vector<vector<vector<int>>> graph(n);\\adjacency list representation of graph

    int steps = 0;
    result[0] = 0;
    
    for (vector<int> i : red_edges){
        graph[i[0]].push_back({i[1],1});\\1 represent a red edge
    }
    for (vector<int> i : blue_edges){
        graph[i[0]].push_back({i[1],0});\\0 represent a red edge
    }
    
    \\initialize bfs queue to be all adjecent node to node 0
    for (vector<int> i: graph[0]){
        current.push_back(i);
        if (i[1]) red[i[0]] = 1;
        else blue[i[0]] = 1;
    }
    
    \\bfs to check all nodes that is possible to be visited by route of alternating color
    while (!current.empty()){
        steps++;
        vector<vector<int>> next;
        for (vector<int> i:current){
            int node = i[0];
            int col = i[1];
            if (result[node] == -1) result[node] = steps;
            for (vector<int> j: graph[node]){
                if (col){
                    if (!blue[j[0]] && !j[1]){
                        next.push_back(j);
                        blue[j[0]] = 1;
                    }
                }
                else{
                    if (!red[j[0]] && j[1]){
                        next.push_back(j);
                        red[j[0]] = 1;
                    }
                }
            }                
        }
        current = next;     
    }   
return result;
}
int main() {
    int n=5;
    vector<vector<int>> red_edges = {{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> blue_edges = {{1,2},{2,3},{3,1}};
    vector<int> res = shortestAlternatingPaths(n,red_edges,blue_edges);
    for (int i: res) cout<<i<<' ';
    return 0;
};
