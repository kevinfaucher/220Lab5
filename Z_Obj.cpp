#include "Z_Obj.hpp"
#include <string>
#include <cstdlib>
using namespace std;
Z_Obj::Z_Obj(int z, string ct, string st, string ab, string cnty, float la,
		float lo){
	zip = z;
	city = ct;
	state = st;
	abbr = ab;
	county = cnty;
	lat = la;
	lon = lo;
}
void Z_Obj::printZ(){
	cout << zip << ": " << city << ", "
                << state << ", " << abbr << ", " << county 
                << ", " << lat << ", " << lon << endl;
}

bool Z_Obj::lessThan(Z_Obj *z){
	return(z->zip < zip);
}