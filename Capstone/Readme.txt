The code makes use of the A* algorithm for path tracking similar to part 2 of the 
c++ program on Udacity.

The code contains 2 classes. Node which contains the attributes for the nodes, and Model
which builds the grid. (Rubric point) 

It uses Nodes to represent the grid. For example, Grid[0][0] is the top left Node. In
it's current configuration there are 16x12 Nodes.(see grid.png)

In the main function the start and finish nodes are given by the user on lines 228 and 230
(Rubric point)

The Model defines the grid with the makeGrid() function and and locates the obstacles
in the grid with the defineObstacles() function. (Rubric point)

The Search algorithm (same as in c++ A* algorithm) is implemented. It constructs a path
of nodes from the startNode to the finishNode.

The drawGrid() function (line 241) draws the grid using SDL. It draws the start and finish nodes
and the obstacles in different colors. The drawgrid function also traces a path from the
start node to the end node.

*****************************************************************************
Instructions on compiling the code
*****************************************************************************
SDL is the only external library required by the code.

The project is compiled using cmake. To compile the code simply run the make command in
the 'build' folder.