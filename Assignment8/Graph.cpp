#include "Graph.hpp"
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

void Graph::addEdge(string v1, string v2){
    for(int i = 0; i<vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j<vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex adjVert;
                    adjVert.v = vertices[j];
                    vertices[i]->adj.push_back(adjVert);

                    adjVertex adjVert2;
                    adjVert2.v = vertices[i];
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

void Graph::breadthFirstTraverse(string sourceVertex){
    vertex* start = NULL;

    int verticesSize = vertices.size();
    for (int i = 0; i < verticesSize; i++){
        if(vertices[i]->name == sourceVertex){
            start =  vertices[i];
        }
    }

    cout <<"Starting vertex (root): " << sourceVertex << "-> ";

    start->visited = true;
    start->distance = 0;
    queue<vertex*> q;
    q.push(start);
    while(!q.empty()){
        vertex* current = q.front();
        q.pop();

        int currSize = current->adj.size();
        for(int i = 0; i < currSize; i++){
            if(!(current->adj[i].v)->visited){
                (current->adj[i].v)->distance = current->distance + 1;
                (current->adj[i].v)->visited = true;
                q.push(current->adj[i].v);
                cout << current->adj[i].v->name << "(" << current->adj[i].v->distance << ")" << " ";
            }
        }
        current->visited = true;
    }
}

void DFTraversal(vertex *n){
    if(!n->visited){
        n->visited = true;
        int adjSize = n->adj.size();
        for(int x = 0; x < adjSize; x++ )
        {
            DFTraversal(n->adj[x].v);
        }
    }
}
int Graph::getConnectedComponents(){
    int connComp = 0;
    int vertSize = vertices.size();
    for(int i = 0; i < vertSize; i++){
        if(vertices[i]->visited == false){
            DFTraversal(vertices[i]);
            connComp++;
        }
    }
    return connComp;
}

void DFSearch(int source, vector<vertex*> vertices, string color){
    if(color == "red"){
        color = "blue";
    }else if (color == "blue"){
        color = "red";
    }

    vertices[source]->visited = true;
    vertices[source]->color = color;

    int vertSize = vertices[source]->adj.size();
    for (int i = 0; i < vertSize; i++){
        if(vertices[source]->adj[i].v->visited == false){
            vector<vertex*>temp;
            for(int j = 0; j < vertSize; j++){
                temp.push_back(vertices[source]->adj[j].v);
            }
            DFSearch(i, temp, color);
        }
    }
}
bool Graph::checkBipartite(){
    int vertSize = vertices.size();
    for(int i = 0; i < vertSize; i++){
        if(vertices[i]->visited == false){
            DFSearch(i, vertices, "red");
        }
    }
    for(int i = 0; i < vertSize; i++){
        int vertAdjSize = vertices[i]->adj.size();
        for(int j = 0; j < vertAdjSize; j++){
            if(vertices[i]->color == vertices[i]->adj[j].v->color){
                return false;
            }
        }
    }
    return true;
}
