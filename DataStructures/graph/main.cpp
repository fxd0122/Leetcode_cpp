//
//  main.cpp
//  Graph_Algorithm
//
//  Created by fxd on 2023/7/1.
//

#include <iostream>
#include "graph.hpp"

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
    return 0;
}
