#include "Node.cpp"
#include "vector"
#include <SDL2/SDL.h>

const int grid_w =   640.0;
const int grid_h =   480.0;

using namespace std;

//The model builds the grid and locates where the obstacles are.

class Model: public Node{
	
	public:
	//Model(){};
	explicit Model(): Node(){};
	
	//explicit Model(int a, int b): Node(a, b){}
		
	vector<vector<Node>> Grid;
	
	int mnodes = grid_w/w;
	int nnodes = grid_h/h;
	
	vector<Node> nObstacles{0};
	
	void makeGrid(){
					
		for(int j =0; j<=nnodes-1; j++)
		{
			vector<Node> temp;
		for(int i =0; i<=mnodes-1; i++)
		{
			Node n((i),(j));
			temp.push_back(n);	
		}
			Grid.push_back(temp);
		}
	}	
	
	void defineObstacles(){
//					
		Grid[5][8].s = State::kObstacle;
		Grid[5][9].s = State::kObstacle;
		Grid[5][10].s = State::kObstacle;
		Grid[5][11].s = State::kObstacle;
		Grid[5][12].s = State::kObstacle;
		
		Grid[6][12].s = State::kObstacle;
		Grid[7][12].s = State::kObstacle;
		Grid[8][12].s = State::kObstacle;
		
		nObstacles.push_back(Grid[5][8]);
		nObstacles.push_back(Grid[5][9]);
		nObstacles.push_back(Grid[5][10]);
		nObstacles.push_back(Grid[5][11]);
		nObstacles.push_back(Grid[5][12]);
		
		nObstacles.push_back(Grid[6][12]);
		nObstacles.push_back(Grid[7][12]);
		nObstacles.push_back(Grid[8][12]);				
	}
	
	
};


