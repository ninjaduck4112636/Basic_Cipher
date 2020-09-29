#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

vector <char>v;
map <int,vector<char>>m;

int main()
{
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
			cout << *ptr << endl;
			*ptr+=1;
			cout << *ptr << endl;
			file1.open("Master_tracker.txt",ios::out|ios::in|ios::trunc);
			file1 << *ptr;
			for(int i=65;i<=90;i++)
				v.push_back(char(i));
				
			m.insert({*ptr,v});
			file2.open("vector_keys.txt",ios::out|ios::in|ios::trunc);
			file2.write((char *)&m,sizeof(map<int,vector<char>>));
		}	
	}
	else
		cout << "File not Open" << endl;



//	for(int i=65;i<=90;i++){
//		v.push_back(char(i));
//	}
//	
//	m.insert({*ptr,v});
	
//	for(auto x: m){
//		cout << x.first << endl;
//		for(auto y : v)
//			cout << y << endl;
//	}
	
	return 0;
}
