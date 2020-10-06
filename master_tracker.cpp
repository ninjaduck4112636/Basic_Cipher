#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

//Here the Master_tracker keeps a track of the count of a number so that by providing that specific number
//we can access the key of the encripted message in alphabatically order

//Here vector_keys serialize's the map that stores the unique key and the specific key in alphabatical
//order





void key_keeper(vector <char>v, map <int,vector<char>>m){

	fstream file;
	fstream file1;
	fstream file2;

	file.open("Master_tracker.txt",ios::out|ios::in);
	int master_key_x;

	if(file.is_open()){
		cout << "File is Open" << endl;
		
		if(file.tellg()==-1)
			cout << "Nothing in the File" << endl;
		else{	
			while(file.good()){
				file >> master_key_x;
			}
			int *ptr = new int(master_key_x);
			
			*ptr+=1;
			
			file1.open("Master_tracker.txt",ios::out|ios::in|ios::trunc);
			file1 << *ptr;
			file1.close();
			file.close();
			
			
			
//			for(int i=65;i<=90;i++)
//				v.push_back(char(i));
				
			m.insert({*ptr,v});
			file2.open("vector_keys.txt",ios::out|ios::in|ios::trunc);
			file2.write((char *)&m,sizeof(map <int,vector<char>>));
			
			
//			file2.seekg(0);
//			
//			map <int,vector<char>>m1;
//			file2.read((char *)&m1,sizeof(map <int,vector<char>>));
//			
//			
//			for(auto x : m1){
//				cout << x.first << endl;
//				for(auto y : x.second){
//					cout << y << endl;
//				}
//			}
//			file2.close();
		}	
	}
	else
		cout << "File not Open" << endl;

}
