# a-star
Currently a work in progress C++ implementation of the A* variant of Dijkstra's Algorithm.

The A* algorithm is a Breadth (or Best) First Search variant of Dijkstra's Shortest Path algorithm. The A* algorithm employs heuristics when testing nodes backwards from the destination, which reduces
the total number of comparisons needed to find the shortest path. For a more complete explanation on the A* algorithm, [this article](http://theory.stanford.edu/~amitp/GameProgramming/AStarComparison.html) from Stanford's Computer Science department is a good start.

The primary difference between A* and Dijkstra's is that A* keeps the Heuristic and Destination Node as priorties. Dijkstra's Algorithm will test each node before returning a path. By employing heuristics and finding a path first, the algorithm removes testing nodes that don't need to be.
