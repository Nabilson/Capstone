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
		
	vector<vector<Node*>> Grid;
	
	int mnodes = grid_w/w; //16
	int nnodes = grid_h/h; //12
	
	vector<Node*> nObstacles{};
	
	void makeGrid(){
					
		for(int i =0; i<=mnodes-1; i++)
		{
			vector<Node*> temp;
		for(int j =0; j<=nnodes-1; j++)
		{
			Node* n = new Node((i),(j));
			temp.emplace_back(n);	
		}
			Grid.emplace_back(temp);
		}
	}	
	
	void defineObstacles(){
//					
		Grid[8][5]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[8][5]);
		
		Grid[9][5]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[9][5]);
		
		Grid[10][5]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[10][5]);
		
		Grid[11][5]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[11][5]);
		
		Grid[12][5]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[12][5]);
		
		Grid[13][6]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[13][6]);
		
		Grid[13][7]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[13][7]);
		
		Grid[13][8]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[13][8]);
		
		Grid[3][3]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[3][3]);
		
		Grid[3][4]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[3][4]);
		
		Grid[3][5]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[3][5]);
		
		Grid[7][8]->s = State::kObstacle;
		nObstacles.emplace_back(Grid[7][8]);					
	}
							
};


