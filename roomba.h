#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unordered_map>
#include <utility>

using namespace std;

//Storing data in a unordered hash map. Lookup is O(1) - constant time
struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

pair<pair<int,int>,int> hoover_roomba(ifstream &fp){
	string line;    //Buffer for reading from file
	int x, y, a, b, i = 0, dirt_count = 0; //Initialize room-size, hoover position and dirt count
	unordered_map<pair<int, int>, int, SimpleHash> dirt; // hash map to store dirt places
	if(!fp.is_open()){
		cout<<"Input file not found\n";
		exit(0);
	}
	fp >> x >> y;    //Get room Size
	fp >> a >> b;	 //Get hoover start location
	while(getline(fp, line)){
		if(isdigit(line[0])){
			dirt[make_pair(line[0] - '0', line[2] - '0')] = 1; //Make dirt place value as 1 
			if(dirt[make_pair(a,b)]){  	////To check dirt is present at the start location (if no directions are provided)
				dirt_count++;
				dirt[make_pair(a,b)] = 0;
			}
		}
		else{ 	
			//To check dirt is present at the start location (Add to the count if present, else 0)
			if(dirt[make_pair(a,b)]){
				dirt_count++;
				dirt[make_pair(a,b)] = 0;
			}
			while(line[i] != '\0'){
				int new_a = a, new_b = b;  //to ensure roomba is within the room range
					switch(line[i]){
					case 'N':
						new_b++;
						break;
					case 'S':
						new_b--;
						break;
					case 'E':
						new_a++;
						break;
					case 'W':
						new_a--;
						break;
					}
				if(new_a < x && new_b < y && new_a >= 0 && new_b >= 0){   //Roomba moves only if the new location is within the room on all extremes
					a = new_a;
					b = new_b;
					if(dirt[make_pair(a,b)]){     //Logic to add the dirt collected count and to remove the dirt.
						dirt_count++;
						dirt[make_pair(a,b)] = 0;
					}
				}
				i++;
			}
		}		
	}
	fp.close();
	dirt.clear();
	return make_pair(make_pair(a,b), dirt_count);
}
