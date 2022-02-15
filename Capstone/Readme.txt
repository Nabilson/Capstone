The code makes use of the A* algorithm for path tracking similar to part 2 of the 
c++ program on Udacity.

It uses Nodes to represent the grid. For example, Grid[0][0] is the top left Node. In
it's current configuration there are 12x16 Nodes.(see grid.png)

In the main function the start and finish nodes are given

The Model defines the grid with the makeGrid() function and and locates the obstacles
in the grid with the defineObstacles() function.

The Search algorithm (same as in c++ A* algorithm) is implemented. It construcs a path
of nodes from the startNode to the finishNode.

The drawGrid() function draws the grid using SDL. It draws the start and finish nodes
and the obstacles in different colors.

The line of code that draws the path has been commented out on line 77 of main.cpp.

