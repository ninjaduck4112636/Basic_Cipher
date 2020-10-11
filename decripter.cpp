#include <iostream>
#include <fstream>
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
	
	if(file.is_open()){
		cout << "File is Open" << endl;
	}
	else{
		cout << "File not Open" << endl;
	}
}
