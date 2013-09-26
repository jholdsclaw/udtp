/* Taylor Schutt
 * 
 * getting an avarage score
 * 
 * make 5 score variables all data type double
 * make 1 for sum of variables data type double
 * make 1 for avarage of the 5 scores
 * ask for 5 decimal numbers
 * tell code to wait for 5 inputs from user
 * after 5 input have been entered, add them together
 * then diveide the sum by 5
 * then print average
 * */
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#define SPLIT_SIZE 548

using namespace std;

vector<char*> split;
vector<int> split_this_shit;

int main(int argc, char* argv[]){
	
	ifstream open_file("logo_myDog.png", ios::binary);
		char* fucking_file_data;
		int file_size;
	if(open_file.is_open()){
		open_file.seekg(0, open_file.end);
		cout << open_file.tellg() << endl;
		file_size = open_file.tellg();
		cout << file_size << endl;
		//Let's find how many files there are
		int packets = (open_file.tellg()/SPLIT_SIZE);
		cout << packets << endl;
		for(int i=0; i<=packets; i++){
			int packet_size = (SPLIT_SIZE>=(open_file.end - open_file.tellg())?SPLIT_SIZE:(open_file.end - open_file.tellg()));
			char* read_data = new char[packet_size];
			int put_this_shit = packet_size;
			open_file.read(read_data, packet_size);
			split.push_back(read_data);
			split_this_shit.push_back(put_this_shit);
		}
		/*
		if((open_file.tellg() % SPLIT_SIZE) >= 1) {
			int secret_size = (open_file.tellg() % SPLIT_SIZE);
			char* read_data = new char[secret_size];
			open_file.read(read_data, secret_size);
			split.push_back(read_data);
			
		}*/

	fucking_file_data = new char[file_size];
		for(int i=0; i<=packets; i++){
			memcpy(&fucking_file_data[i], split[i], split_this_shit[i]);
		}

	}

	ofstream out_file("finally.png", ios::binary);
	if(out_file.is_open()){
		cout << file_size << endl;
		out_file.write(fucking_file_data,file_size);
	}
	open_file.close();
	
	
}
