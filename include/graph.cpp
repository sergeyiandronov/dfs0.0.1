#include  <iostream>
enum  tcolor { white, black };
class  graph {
	struct node {

		node **connectnodes;
		int value;
		int nodenumber;
		tcolor color;
	};
	int size;
	node *nodes;
	int nodeindex(node *versh) {
		for (int i = 0; i < size; i++) {
			if (&nodes[i] == versh) {
				return i+1;
			}
		}
		return -1;
	}
	void dfs(node *versh,int *vector,int &m) {
		if (versh->color == black) {
			return;
		}
		versh->color = black;
		vector[m] = nodeindex(versh);
		m += 1;
		for (int i=0; i < versh->nodenumber; i++) {
			dfs(versh->connectnodes[i], vector, m);
		}
	}
public:	
	graph(){
		nodes = nullptr;
	}
	~graph() {
		
        delete[]  nodes;
	
	}
	void getGraphfromTable(int **table,int n) {
		nodes = new node[n];
		
		for (int i=0; i < n;i++) {
			int numbernode = 0;
			for (int j=0; j < n; j++) {
				if (table[i][j] == 1){
					numbernode += 1;

				}
			}
			if (numbernode != 0) {
				nodes[i].connectnodes = new node*[numbernode];
				nodes[i].nodenumber = numbernode;
				
			}
			else {
				nodes[i].connectnodes = nullptr;
                nodes[i].nodenumber = numbernode;
				
			}
			nodes[i].value = i;
			nodes[i].color = white;
		}
		for (int i=0; i < n; i++) {
			int nn = 0;
			for (int j=0; j < n; j++) {
				if (table[i][j] == 1) {
					nodes[i].connectnodes[nn] = &nodes[j];
					
					nn += 1;
				}
			
			}
			
		}
		size = n;
		
	}
    int* dfs() {
		int*vector = new int[size];
		for (int i = 0; i < size; i++) {
			vector[i] = -1;
		}
		int m = 0;
		for (int i = 0; i < size; i++) {
			if (nodes[i].color == white) {
				dfs(&nodes[i], vector, m);
			}
		}
		return vector;
	}
	void printdfs(std::ostream & stream) {
		int *vector = dfs();
		for (int i = 0; i < size&&vector[i]!=-1; i++) {
			stream << vector[i] << " ";
		}
		stream << '\n';
	}
	void printnode(int f) {
		for (int i = 0; i < nodes[f].nodenumber; i++) {
			std::cout << nodes[f].connectnodes[i]->value << " ";
		}
	}
};

