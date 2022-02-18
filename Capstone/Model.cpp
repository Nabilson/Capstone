#include "Node.cpp"
#include <vector>
#include <list>
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
	
	int mnodes = grid_w/w; //16
	int nnodes = grid_h/h; //12
	
	vector<Node> nObstacles{0};
	
	void makeGrid(){
					
		for(int i =0; i<=mnodes-1; i++)
		{
			vector<Node> temp;
		for(int j =0; j<=nnodes-1; j++)
		{
			Node n((i),(j));
			temp.push_back(n);	
		}
			Grid.push_back(temp);
		}
	}	
	
	void defineObstacles(){
//					
		Grid[8][5].s = State::kObstacle;
		Grid[9][5].s = State::kObstacle;
		Grid[10][5].s = State::kObstacle;
		Grid[11][5].s = State::kObstacle;
		Grid[12][5].s = State::kObstacle;
		
		Grid[13][6].s = State::kObstacle;
		Grid[13][7].s = State::kObstacle;
		Grid[13][8].s = State::kObstacle;
		
		nObstacles.push_back(Grid[8][5]);
		nObstacles.push_back(Grid[9][5]);
		nObstacles.push_back(Grid[10][5]);
		nObstacles.push_back(Grid[11][5]);
		nObstacles.push_back(Grid[12][5]);
		
		nObstacles.push_back(Grid[13][6]);
		nObstacles.push_back(Grid[13][7]);
		nObstacles.push_back(Grid[13][8]);				
	}
	
	
};


