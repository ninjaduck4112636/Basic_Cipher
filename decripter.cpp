#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

void decripter();

int main()
{
	decripter();
	return 0;
}

void decripter(){
	int key;
	
	cout << "Enter the Key to Decript: ";
	cin >> key;
	string string_key = to_string(key);
	fstream file;
	
	file.open(string_key+"vector_keys.txt",ios::in|ios::out|ios::ate);
	
	// debugging
	
	if(file.is_open()){
		try{
		cout << "File is Open" << endl;
		
		map <int,vector<char>>m;
		
		cout << file.tellg() << endl;
		
		cout << "Size of Map: " << m.size() << endl;
		file.seekg(0);
		cout << file.tellg() << endl;
		file.read((char *)&m,sizeof(map <int,vector<char>>));
		
		
//		for(auto value : m){
//			cout << value.first << endl;
//		}
		
		cout << "Size of Map: " << m.size() << endl;
		
		}catch(...){
			cout << "Exception" << endl;
		}
		file.close();
		cout << "File is Closed" << endl;
	}
	else{
		cout << "File not Open" << endl;
	}
}
