#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include "roomba.h"

int main(int argc, char **argv){
	pair<pair<int,int>, int> results;
	string filename;
	if(argc > 1){
		if (strcmp(argv[1],"-f") == 0)
			filename = argv[2];
		else{
			cout<<"Usage ./roomba -f filename\n";
			exit(0);
		}
	}
	else 
		filename = "input.txt";
	ifstream fp(filename);
	results = hoover_roomba(fp);
	cout<<results.first.first<<" "<<results.first.second<<endl;
	cout<<results.second<<endl;
	return 0;
}