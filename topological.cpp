// This program shows how C-based file I/O works.  It will open a
// file, read in the first two strings, and print them to the screen.

// included so we can use cout
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "nodeGraph.h"
#include <vector>
#include <string>

using namespace std;

/** @brief This is the main function that performs all the topological sortsusing two arguements 
 *
 *
 * @param argc is the size of the array (number of command line parameters that will be coming in)
 * @param argv is the character array that will take in argc to determine the necessary length of the character array
 * @return type is int which is 0 when the main finishes
 */
// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in two strings
    string s1, s2;
    vector<nodeGraph*> storage = vector<nodeGraph*>();
    std::vector<nodeGraph*>:: iterator first;
    std::vector<nodeGraph*>:: iterator second;
    file >> s1;
    file >> s2;
    while(s1 != "0" && s2 != "0"){ 
      nodeGraph* firstClass = new nodeGraph(s1);
      nodeGraph* secondClass = new nodeGraph(s2);
      if(storage.size() == 0){ //no classes, firstclass points to second class and second class' size++
	storage.push_back(firstClass);
	secondClass -> inSize++;
	firstClass -> points.push_back(secondClass);
	storage.push_back(secondClass);
      }
      else{ 
	first = storage.begin();
	for(;first!=storage.end();first++){ 
	  if((*first)-> name == s2){ //class' size++
	    (*first)-> inSize++;
	    break;
	  }
	}
	if(first == storage.end()){
	  secondClass -> inSize++; 
	  storage.push_back(secondClass);
	  (*first) = storage.back();
	}
	second = storage.begin();
	for(;second!=storage.end();second++){
	  if((*second)->name == s1){
	    (*second)-> points.push_back((*first));
	    break;
	  }
	}
	if(second == storage.end()){
	  firstClass -> points.push_back((*first));
	  storage.push_back(firstClass);
	}
      }
      file >> s1;
      file >> s2;
    }
    for(int a = 0 ; a < storage.size(); a++){
      cout << storage[a]->name << " " << storage[a]->inSize << " ";
      for(int b = 0 ; b < storage[a]->points.size(); b++){
	cout << storage[a] -> points[b]-> name << " ";
      }
      cout << endl;
      }
    nodeGraph* temp;
    int i =0;
    while(storage.size()!=0){
      for(i = 0; i < storage.size(); i ++){
	if(storage[i]->inSize == 0){
	  temp = storage[i];
	  cout << temp->name << " ";
	  break;
	}
      }
      for(int k = 0 ; k < temp->points.size();k++){
	temp->points[k]->inSize--;
      }
      storage.erase(storage.begin()+i);
    }
    cout << endl;
    // string comparison done with ==, but not shown here
    // close the file before exiting
    file.close();
}
