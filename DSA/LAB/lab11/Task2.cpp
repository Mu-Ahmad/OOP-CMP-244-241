// Name: Muhammad Ahmad
// Roll: BCSF19M509


#include <iostream>
#include <queue>

using namespace std;

#define NOEDGE 0
#define EDGE 1

class AMatrix{
	int **nodes, count;
public:
	AMatrix(int count){	
		this -> count = count;
		nodes = new int* [count];
		int i, j;
		for (i = 0 ; i < count ; i++){
			nodes [ i ] = new int [count];
			for ( j = 0 ; j < count ; j++ )
				nodes [ i ] [ j ] = NOEDGE;  
		}
	}
	void addEdge(int n1, int n2){
		nodes [ n1 ] [ n2 ] = EDGE;
	}
	void addUndirectedEdge(int n1, int n2){
		nodes [ n1 ] [ n2 ] = EDGE;
		nodes [ n2 ] [ n1 ] = EDGE;

	}
	void show(){
		int i, j;
		for (i = 0 ; i < count ; i++){
			cout << i << " : ";
			for ( j = 0 ; j < count ; j++ )
				if ( nodes [ i ] [ j ] == EDGE )
					cout << j << ' ';
			cout << '\n' ;  
		}
	}

	bool isConnected(int a, int b){
		return nodes[a][b]==EDGE;
	}

	bool isPathExist(int a, int b){
		return countEdges(a, b) != -1;
	}

	// We will do a breadth first dearch
	int countEdges(int a, int b){
		queue<int> q;
		bool Visited[count] = {0};
		int distance[count];

		for(int i = 0; i<count; i++)
			distance[i] = -1;

		distance[a] = 0;
		Visited[a] = true;
		q.push(a);

		while(!q.empty()){
			int curr = q.front(); q.pop();
			for(int i = 0; i<count; i++){
				if(nodes[curr][i]){
					if(Visited[i]) continue;
					Visited[i] = true;
					distance[i] = distance[curr] + 1;
					q.push(i);
				}
			}
		}
		return distance[b];
	}


};

int main(){
	AMatrix matrix(10);
	matrix.addUndirectedEdge(0,2);
	matrix.addUndirectedEdge(0,3);
	matrix.addUndirectedEdge(0,4);
	matrix.addUndirectedEdge(1,0);
	matrix.addUndirectedEdge(1,3);
	matrix.addUndirectedEdge(2,4);
	matrix.addUndirectedEdge(3,0);
	matrix.addUndirectedEdge(4,1);
	matrix.addUndirectedEdge(4,2);
	matrix.addUndirectedEdge(4,3);
	matrix.addUndirectedEdge(4,6);
	matrix.addUndirectedEdge(6,5);
	matrix.addUndirectedEdge(6,7);
	matrix.addUndirectedEdge(7,8);

	matrix.show();

	if(matrix.isConnected(1, 3))
		cout << "1-3 Are Connected" << '\n';
	else
		cout << "1-3 Are Not Connected" << '\n';

	if(matrix.isConnected(1, 7))
		cout << "1-7 Are Connected" << '\n';
	else
		cout << "1-7 Are Not Connected" << '\n';

	if(matrix.isPathExist(1, 5))
		cout << "1-5 Path Exist!" << '\n';
	else
		cout << "1-5 Path Dont exist" << '\n';

	if(matrix.isPathExist(1, 9))
		cout << "1-9 Path Exist!" << '\n';
	else
		cout << "1-9 Path Does not exist" << '\n';

	cout << "1-5 Path has " << matrix.countEdges(1, 5) << " edges.\n";
	cout << "1-2 Path has " << matrix.countEdges(1, 2) << " edges.\n";
	cout << "0-4 Path has " << matrix.countEdges(0, 4) << " edges.\n";



	return 0;
}	
