#include "Graph.hpp"
#include<vector>
#include<iostream>
#include<queue>
#include <stack>

using namespace std;

void Graph::addEdge(string v1, string v2, int num){
    for(int i = 0; i<vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j<vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex adjVert;
                    adjVert.v = vertices[j];
                    adjVert.weight = num;
                    vertices[i]->adj.push_back(adjVert);

                    adjVertex adjVert2;
                    adjVert2.v = vertices[i];
                    adjVert2.weight = num;
                    vertices[j]->adj.push_back(adjVert2);
                }
            }
        }
    }
}

void Graph::addVertex(string name){
    bool found = false;
    for(int i = 0; i<vertices.size(); i++){
        if(vertices[i]->name == name){
            found = true;
        }
    }
    if(found == false){
        vertex* newV = new vertex;
        newV->name = name;
        vertices.push_back(newV);
    }
}

void Graph::displayEdges(){
    int vertSize = vertices.size();
    for (int i = 0; i < vertSize; i ++){
        cout << vertices[i]->name << " --> ";
        int vertAdjSize = vertices[i]->adj.size();
        for (int j = 0; j < vertAdjSize; j++){
            cout << " " << vertices[i]->adj[j].v->name;
        }
        cout << endl;
    }
}

void DFT_Helper(vertex* n){
    if(!n->visited){
        n->visited = true;
        cout << n->name << " --> ";
        int adjSize = n->adj.size();
        for(int x = 0; x < adjSize; x++ )
        {
            DFT_Helper(n->adj[x].v);
        }
    }
}
void Graph::depthFirstTraversal(string sourceVertex){
    vertex* start = NULL;
    for (unsigned i=0; i<vertices.size(); i++) {
		if (vertices[i]->name == sourceVertex) {
			start = vertices[i];
		}
	}
	DFT_Helper(start);
    cout <<"Done";
}

vertex* Graph::DijkstraAlgorithm(string start, string end){
    setAllVerticesUnvisited();
    vertex* startV = NULL;
    vertex* endV = NULL;
    for (unsigned i = 0; i < vertices.size(); i++) {
		if (vertices[i]->name == start) {
			startV = vertices[i];
		}
	}
    for (unsigned i = 0; i < vertices.size(); i++) {
		if (vertices[i]->name == end) {
			endV = vertices[i];
		}
	}

    startV->visited = true;

    vector<vertex*> solved;
    solved.push_back(startV);

    int minDistance,shortestPath = 10000;
    vertex* temp;
    int totalDist = 0;

    while(endV->visited != true){
        for (unsigned i = 0; i < solved.size(); i++){
            for (unsigned j = 0; j < solved[i]->adj.size(); j++){
                if(solved[i]->adj[j].weight < minDistance && solved[i]->adj[j].v->visited != true){
                    temp = solved[i]->adj[j].v;
                    minDistance = solved[i]->adj[j].weight;
                }

                if(solved[i]->adj[j].v->name == end && (totalDist + solved[i]->adj[j].weight)<shortestPath){
                    shortestPath = totalDist + solved[i]->adj[j].weight;
                }
            }
        }
        temp->visited = true;
        totalDist = totalDist + minDistance;
        solved.push_back(temp);
        minDistance = 10000;
        temp = NULL;
    }

    if(totalDist > shortestPath){
        totalDist = shortestPath;
    }

    endV->distance = totalDist;
    return endV;
}

void Graph::shortestpath(string start, string end){
    vertex* curr;
    for (unsigned i = 0; i < vertices.size(); i++) {
		if (vertices[i]->name == end) {
			curr = vertices[i];
		}
	}
    stack<vertex*> temp;
    temp.push(curr);
    while(curr->pred != NULL){
        temp.push(curr->pred);
        curr = curr->pred;
    }
    while(temp.size() != 0){
        cout << temp.top()->name << " ";
        temp.pop();
    }
}

void Graph::setAllVerticesUnvisited(){
  for(unsigned i=0; i<vertices.size(); i++) {
      vertices[i]->visited = false;
  }
}
