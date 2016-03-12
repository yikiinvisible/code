#include "Vector.hpp"
#include <iostream>
using namespace std;

int main(){
	Vector<int> v1;
	v1.push_back( 4 );
	v1.push_back( 5 );
	//cout<< v1.size() << endl;

	for ( Vector<int>::iterator i = v1.begin(); i != v1.end(); ++i )
		cout<< *i <<endl;

	return 0;
}