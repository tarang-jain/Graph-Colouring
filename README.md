## Graph Colouring<h2>

The basic graph colouring problem is as follows. Given as input an undirected graph.  To each vertex u, we must assign a colour C[u], which must be a positive integer s.t. C[u] != C[v] if (u,v) is an edge in the graph.  In addition, it is desirable to minimize the largest colour, i.e. largest value of C[u] over all u.  If a graph can be coloured with max colour <= k, then it is said to be k colourable.

Minimizing this maximum colour value is a well known difficult problem and it is believed that no algorithm can
colour a graph in the minimum number of colours in time polynomial in n.

However, one heuristic for solving this problem is the "minimum degree heuristic". The degree of a vertex is the number of edges incident on that vertex.  The heuristic starts with all vertices uncoloured, and repeats the following step.

Pick any vertex having the fewest coloured neighbours and Assign it the smallest possible colour different from the colours of its neighbours coloured till then.

The heuristic asks you to pick any vertex having the fewest coloured
neighbours.  However, for the sake of getting a unique answer, the smallest numbered among these is picked.

The input format is given as follows.

n m
u<sub>1</sub> v<sub>1</sub>
...
u<sub>m</sub> v<sub>m</sub>

Here n, m are the numbers of vertices and edges.  u<sub>i</sub>, v<sub>i</sub> are the
endpoints of the i<sup>th</sup> edge.  The vertices are numbered 0 through n-1,
so 0 <= u<sub>i</sub>, v<sub>i</sub> <= n-1.  The output is the n colours C[u], printed
out in order, i.e

C[0] C[1] ... C[n-1]

Here is an example input

4 4
0 1
1 2
2 0
2 3

The output should be
1 2 3 1
