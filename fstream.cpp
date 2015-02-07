#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 1024;
char clean_block[N] = { 0 };

int main(int argc, char** argv)
<%
	cout << (9 bitand 7);

	//cout << "Hello Atrem!" << endl;
	fstream fs;
	fs.open("fs", std::fstream::in | std::fstream::out | ios::binary);
	
	//for(int i = 0; i < 20; ++i)
		//fs.write(&clean_block[0], N);
	
	string name("Артем Егоров");
	
	int a = -45;
	fs.seekg(0, fs.beg);
	fs.write((char *)&a, sizeof(a));

	
	fs.seekg(1024, fs.beg);
	fs.write(name.c_str(), name.length());
	
	fs.close();

	cin.get();
	return 0;
}
