
#include "graph.cpp"
int main()
{
	int **table=new int*[3];
	for (int i = 0; i < 3; i++) {
		table[i] = new int[3];
	}
	int table1[3][3] = { {0,1,1},{ 1,0,0 } ,{ 0,0,0 } };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			table[i][j] = table1[i][j];
		}
	}
	graph G;
	G.getGraphfromTable(table, 3);
	G.printdfs(std::cout);
	G.printnode(0);
	
    return 0;
}


