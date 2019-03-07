#include<iostream>
#include<climits>
using namespace std;
int findMinVertex(int* distance,bool* visited,int n){
	int minVertex=-1;
	for (int i=0; i < n; i++){
		if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
			minVertex=i;
		}
	}
	return minVertex;
}
/*
//    main logic of Dijkstra
*/
void Dijkstra(int **edges, int n){
	int *distance=new int[n];
	bool* visited=new bool[n];
	for (int i = 0; i < n; ++i){
		distance[i]=INT_MAX;  // instead of infinity
		visited[i]=false;
	}
	distance[0]=0;
	int minVertex,dist;
	for (int i = 0; i < n-1; i++){
		minVertex = findMinVertex(distance,visited,n);
		visited[minVertex]=true;
		for(int j=0; j<n; j++){
			if (edges[minVertex][j] != 0 && !visited[j]){
				dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}		
			}
		}
	}
	for (int i = 0; i < n; ++i){
		cout<<"Vertex : "<<i<<" || Distance : "<<distance[i]<<endl;
	}
	delete [] visited;
	delete [] distance;
} 
/*
//    main function
*/
int main(){
	int n;
	int e;
	cout<<"Enter number of nodes: ";
	cin>>n;
	cout<<"Enter number of edges: ";
	cin>>e;
	int** edges = new int* [n];	// decalaring matrix
	for (int i = 0; i < n; i++){
		edges[i]=new int[n];
		for (int j=0; j<n; j++){  // loop for initialization
			edges[i][j]=0;			
		}			
	}
	for (int i = 0; i < e; i++){
		int f,s,weight;
		cin>> f >> s >> weight;
		edges[f][s]=weight;
		edges[s][f]=weight;		
	}		
	Dijkstra(edges,n);

	for(int i=0; i<n; i++){
		delete [] edges[i];
	}
	delete [] edges;
	return 0;
}
