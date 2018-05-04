//Yunqi Shen
//HW6 - Dijkstra’s shortest path algorithm
#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
struct edge { int to, length; };

    
int shortest(const vector< vector<edge> > &graph, int source, int target) {
    vector<int> min_distance( graph.size(), INT_MAX );
    min_distance[ source ] = 0;
    set< pair<int,int> > active_vertices;
    active_vertices.insert( {0,source} );
        
    while (!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if (where == target) return min_distance[where];
        active_vertices.erase( active_vertices.begin() );
        for (auto ed : graph[where]) 
            if (min_distance[ed.to] > min_distance[where] + ed.length) {
                active_vertices.erase( { min_distance[ed.to], ed.to } );
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert( { min_distance[ed.to], ed.to } );
            }
    }
    return INT_MAX;}

int main(){
	cout<< "Implement the algorithm using the ajacent matrix of the graph in Figure 20-39:\n";
	cout<< "Enter the index of the vertex:\n";
	int i;
	if ((i<0)||(i>6)){
		cout<< "Invalid index number.\n";
		return 0;
		}
	vector<vector<int> > graph={
		{0,2,4,6,0,0,0},
		{0,0,5,0,3,0,0},
		{0,0,0,2,2,0,0},
		{0,0,1,0,5,3,0},
		{0,0,3,0,0,5,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,0,2,0}
		};
	//cout<< "The shortest path is "<<shortest(graph,0,i)<<endl;
	cout<<"Could find a easy way to input all the lengths and directions.\n";
	return 0;
	}

















