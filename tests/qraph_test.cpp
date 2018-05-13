#include <catch.hpp>
#include <sstream>

#include "graph.cpp"

TEST_CASE("graph")
{
    std::string input{"1 2 3 \n"};
    
    int **table=new int*[3];
	for (int i = 0; i < 3; i++) {
		table[i] = new int[3];
	}
	int table1[3][3] = { {0,0,0},{ 0,1,0 } ,{ 0,0,0 } };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			table[i][j] = table1[i][j];
		}
	}
    std::ostringstream ostream;
    
	graph G;
	G.getGraphfromTable(table, 3);
	G.printdfs(ostream);
	G.printnode(0);
    REQUIRE(input==ostream.str());
	
}


