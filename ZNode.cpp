#include "ZNode.hpp"
#include "Z_Obj.hpp"
#include <string>
#include <cstdlib>
using namespace std;
ZNode::ZNode(Z_Obj* z){
	zip = z;
	
	left = NULL;
	right = NULL;
	parent = NULL;
}
ZNode::ZNode(){
	zip = NULL;
	height = 0;
	left = NULL;
	right = NULL;
	parent = NULL;
}
void ZNode::printZNode(){
	zip->printZ();
}