// cipher which will change key every minute

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

fstream file;
fstream file1;
void cipher();
int main()
{
	cipher();
	return 0;
}

void cipher(){
	char a=65;
	char z=90;
	srand(time(0));
	string message;
	file.open("G:/Dev c++ files/Ciper_1/encription_logs.txt",ios::in|ios::out|ios::ate); // file is open
	file1.open("G:/Dev c++ files/Ciper_1/cipher_key.txt",ios::in|ios::out|ios::ate); // cipher file is open
	cout << "Enter the Message to Encript: ";
	getline(cin,message);
	
	for(int i=0;i<=message.length();i++){
		message[i]=message[i]-32;
	}
	file << "Orginal Message: " << message << endl;
	int temp=rand(); // generates random numbers
	temp=temp%25;
	for(int i=0;i<=message.length();i++){
		message[i]=temp+(65+(message[i]%25));
	}
	cout << "Your Encripted Message is: " << message << endl;
	
	file << "Encripted Message: " << message << endl;
	file << "***************************************" << endl;
	file << endl;
	
	
	for(a;a<=z;a++){
		file1 << a << " is:  " << char(temp+(65+(a%25))) << endl;
	}
	file1 << "------------------------------" << endl;
}
