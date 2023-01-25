### Leader Election

This C++ project is an implementation of leader election algorithm from the book "Distributed Algorithms" by Jukka Suomela.

The project is written in Bosnian/Croatian/Serbian using *Codeblocks*, but the main functions are commented in English.

The project includes 5 example graphs with their own images in folder *examples* and a function that can generate a graph. The algorithm uses BFS tree with OpenMP 
library to run the BFS in parallel and select the node with the smallest identifier.

The comments are written in the language above, but can be translated for greater clarification.


#### Example 5 (4 leaders, 6 is chosen as the main one, others are connected to it with *KORIJEN* property)
![Example 5](https://github.com/namespace-irhad/bfs-leader-election/blob/main/examples/elekcija_vodje_primjer_5.png?raw=true)
