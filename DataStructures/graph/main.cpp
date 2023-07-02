//
//  main.cpp
//  Graph_Algorithm
//
//  Created by fxd on 2023/7/1.
//

#include <iostream>
#include "graph.hpp"

/* graph
 0 1 1
 0 3 4
 0 4 4
 1 3 2
 2 5 1
 3 2 2
 3 4 3
 4 5 3
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    char s,v;
    int w;
    matrix::Graph<char> graph(false);
    graph.get();
    for(int i=0; i<8; i++){
        std::cin>>s>>v>>w;
        graph.addEdge(s, v, w);
    }
//    graph.DFSTrava();
    graph.getShortPath('0', '3');
    graph.floyd('0', '3');
    return 0;
}
