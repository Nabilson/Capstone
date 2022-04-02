
enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

// A node consists of x and y coordinates and the width and height of the square.

class Node
{
	public:
	
	explicit Node(){};	
	explicit Node(int a, int b){
		x=a;
		y=b;
		s= State::kEmpty;
		G=0;
		H=0;
	}	
	
	 Node operator=(Node other){
		return *this;
	}
	
	int x{0};
	int y{0};
	
	int G{0};
	int H{0};
	
	const int w=40;
	const int h=40 ;
	
	State s;
	
};
