//Hunter Vaccaro
//hpv8hf
//12/02/2019
//nodeGraph.h

#ifndef NODEGRAPH_H
#define NODEGRAPH_H
#include <vector>
#include <string>

using namespace std;

class nodeGraph {
 public:
  
  nodeGraph(string x);
  /**
This is the name of the nodeGraph
   */
  string name;
  /**
this is the number of in pointers going into this node 
   */
  int inSize;
  /**
     this is the pointers that point to the nodes that this node points to
   */
  vector<nodeGraph*> points; 
  
};
#endif
