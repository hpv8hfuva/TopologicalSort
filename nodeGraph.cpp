//Hunter Vaccaro
//hpv8hf
//12/02/2019
//nodeGraph.cpp

#include "nodeGraph.h"
#include <string>
#include <vector>
using namespace std;

/** @brief This is the constructor for nodeGraph that takes in 1 parameters.
 *
 *
 * @param x The first string is the name parameter for the nodeGraph with an initial inSize of 0 and an empty vector<nodeGraph*> called points.
 */
nodeGraph::nodeGraph(string x){
  name = x;
  points = vector<nodeGraph*>();
  inSize = 0;
}
