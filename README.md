#A* in 3D

Commonly, Astar works on Graph data structure that contains vertices and edges. We see vertices as a point or state in a conceptual space and edges are either distance or the difference between two states. In this project, I tried to implement Astar in 2D plane of real numbers. 

The challenge here is to map the vertices and edges into a real numbered 2d plane. You may imagine this problem as a video game in which a character can move with in 2D space that contains obstacles. One common way to do this is to allocate polygons in this 2d plane where you allocate polygons to specify where the character can or cannot walk within that space. I use euclidean distance for solve path between polygons.

Another problem here is that if you use less number of polygons in the plane, you will get jagged paths or paths that which won't feel natural for a game character to use. There are two ways to solve or minimize this, either you divide the space into large number of polygons, the more polygons you have in the plane, the less jagged the path will look. But this can be quite laborious and can only work if the polygons do not change while execution.

Or, We may do this dynamically by using Spline Interpolation (it used in mathematics to approximate curves given a set of points in cartesian place) but I have yet to program this out.
