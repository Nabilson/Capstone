#include <iostream>
#include "Model.cpp"
#include <iostream>
#include <algorithm>
#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void drawGrid(vector<vector<Node>> &grid, vector<Node> &obs, Node &start, Node &finish, vector<Node>& path){
	
	SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "A Star Search", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        grid_w,
        grid_h,
        SDL_WINDOW_SHOWN
    );
    
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor( renderer, 220, 220, 220, 255 );
	
	// Clear winow
    SDL_RenderClear( renderer );
    SDL_RenderPresent(renderer);
    
    SDL_Rect r;
    
    //sets the color of the start Node
    SDL_SetRenderDrawColor( renderer, 0, 128, 0, 255 );
    r.x = start.x*start.w;
    r.y = start.y*start.h;
    r.w = start.w;
    r.h = start.h;
    SDL_RenderFillRect( renderer, &r );
    
    //sets the color of End start Node
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
    r.x = finish.x*finish.w;
    r.y = finish.y*finish.h;
    r.w = finish.w;
    r.h = finish.h;
    SDL_RenderFillRect( renderer, &r );
    
    //sets the color of the Obstacle Nodes
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );    
    for (Node n : obs)
    {
		
    	SDL_Rect r;
    	r.x = n.x*n.w;
    	r.y = n.y*n.h;
    	r.w = n.w;
    	r.h = n.h;
		
		SDL_RenderFillRect( renderer, &r );  	
	}
	
	//sets the color for the Path Nodes
	SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );    
    for (Node n : path)
    {
		
    	SDL_Rect r;
    	r.x = n.x*n.w;
    	r.y = n.y*n.h;
    	r.w = n.w;
    	r.h = n.h;
		
		//SDL_RenderFillRect( renderer, &r );  	
	}
	
	SDL_RenderPresent(renderer);
}

int Heuristic(int x_1, int y_1, int x_2, int y_2)
{
  
return abs(x_2 - x_1) + abs(y_2 - y_1);

}

bool CheckValidCell(int x, int y, vector<vector<Node>> &grid) {
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y].s == State::kEmpty;
  return false;
}


void AddToOpen(int x, int y, vector<Node> &openList, vector<vector<Node>> &grid){
	
	//Node& node = grid[x][y];
	
	openList.push_back(grid[x][y]);
	
	grid[x][y].s = State::kClosed;
}

bool Compare(const Node& a, const Node& b)
{
	
	int f1 = a.G + a.H; // f1 = g1 + h1
  	int f2 = b.G + b.H; // f2 = g2 + h2
  	
 	return (f1>f2);
}


void CellSort(vector<Node>* v){
		
	//cout<<(*v)[2].H<<"\n";
	sort(v->begin(), v->end(), Compare);

}


void ExpandNeighbors(Node &current, Node& finish, vector<Node> &openlist, vector<vector<Node>> &grid) {
  // Get current node's data.
  int x = current.x;
  int y = current.y;
  int g = current.G;
  
  // Loop through current node's potential neighbors.
  for (int i = 0; i < 4; i++) {
  	  	
  	int x2 = x + delta[i][0];
  	int y2 = y + delta[i][1];
  	
  	if (CheckValidCell(x2, y2, grid)) {
      // Increment g value and add neighbor to open list.
      grid[x2][y2].G = g + 1;
	  grid[x2][y2].H = Heuristic(x2, y2, finish.x, finish.y);  
    
      AddToOpen(x2, y2, openlist, grid);
     // cout<<x2 <<" "<<y2<<" "<<grid[x2][y2].G<<" "<<grid[x2][y2].H<<"\n";
    }  	
  } 
}

vector<Node> Search(vector<vector<Node>> &grid, Node& start, Node& finish, vector<Node>& path ){
  // Create the vector of open nodes.	
	vector<Node> open {};
	
	start.G = 0;
	start.H = Heuristic(start.x,start.y,finish.x,finish.y);
		
	AddToOpen(start.x,start.y,open,grid);
	
	while(open.size()>0){
		// Get the next node
		CellSort(&open);
		
		cout<<"Nodes in open vector \n";	
		for(Node n: open)
		cout<<n.x <<" "<<n.y<<" "<<n.G<<" "<<n.H<<"\n";
	
		cout<<"\n";
		Node& current = open.back();
		open.pop_back();
		current.s= State::kPath;
		
		path.push_back(current);
		
		if(current.x == finish.x  && current.y== finish.y ){	
		
			//cout<<current.x <<" "<<current.y<<"\n";
			//cout<<"path size "<<path.size()<<"\n";		
			cout<<"Path found \n";
			cout<<current.x <<" "<<current.y<<"\n";
			
			return path;
		}
		
		//cout<<current.x <<" "<<current.y<<" "<<current.G<<" "<<current.H<<" "<<"current"<<"\n";
		
		ExpandNeighbors(current, finish, open, grid);		
	}
		
	cout<<"No path found!" <<"\n";
	return path;
}

int main(int argc, char** argv) {
	
	//set the start and end nodes
	int init[2]{1,1};
  	int goal[2]{2,5};
	
	//Define the Model
	Model model;
	model.makeGrid();
	model.defineObstacles();
	
	vector<Node> path{0};

	Node startNode(model.Grid[init[0]][init[1]]);
	Node finishNode(model.Grid[goal[0]][goal[1]]);
	
	Search (model.Grid, startNode, finishNode, path);
	
//	cout<<finishNode.s<<"\n";
	
	drawGrid(model.Grid, model.nObstacles,startNode,finishNode, path);
	
//	if(model.Grid[goal[0]][goal[1]].s== State::kClosed)
//		cout<<"kClosed \n";
//	else if(model.Grid[goal[0]][goal[1]].s== State::kEmpty) 
//		cout<<"kEmpty \n";
//	else if(model.Grid[goal[0]][goal[1]].s== State::kObstacle)
//		cout<<"kObstacle \n";
//	else if(model.Grid[goal[0]][goal[1]].s== State::kPath)
//		cout<<"kPath \n";
//	
//	cout<<model.Grid[init[0]][init[1]].H<<endl;

//	if(model.Grid[5][9].s == State::kObstacle )
//		cout<<model.nObstacles.size();
//	
//	cout<<model.Grid[0].size();

//	system("pause");
	return 0;
}
