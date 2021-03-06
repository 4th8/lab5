//Nathanael Woodhead && Mikaela Goldrich
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream> // Needed for stringstream
#include "bstream.h"
#include "Binary.h"
#include "data.h"
#include "node.h"
#include "box.h"
#include "box_array.h"
#include "keygen.h"
#include "calculateWeights.h"
#include "encoder.h"
#include "decoder.h"
#include "my_da_array.cpp"

using namespace std;

my_da_array<node*>* readWeights(){
	my_da_array<node*>* array;
	ifstream weightsFile;
	weightsFile.open("weights.txt"); // This will need to be an input later.
	int num = 0;
	while(weightsFile){
		stringstream ss;
		string line;
		char hh;
		double weight;
		getline(weightsFile, line);
		if (line == ""){// This if statement is needed to catch when it grabs an empty string from the end of the file.
			break;
		}
		int length = line.length();
		int space;
		for(int i = 0; i <length; i++){
			if (line[i] == ' '){
				space = i;
				break;
			}
		}
		int ascii;
		string c = line.substr(0,space);
		string weightString = line.substr(space,length);

		ss << weightString; //gives the string to the stringstream
		ss >> weight; //gets the double out of the stringstream
		stringstream s1;
		s1 << c;
		s1 >> ascii;
		hh = char(ascii);
		node * currentNode = new node(hh,weight);
		if (num == 0){
			array = new my_da_array<node*>(currentNode);
			num = 1;
		}
		else{
			array->da_push(currentNode);
		}
	}
	return array;
}
node * buildTree(my_da_array<node*>* array){ //I think that we might need to deal with the nodes of the tree directly. So I am changing this
												// to return the head node. Not a tree. The binary tree class may just go away...
	while(array->getRemaining()!=1){
		node * min1 = array->find_maxmin(false);// finds the 2 lowest weighted nodes
		node * min2 = array->find_maxmin(false);
		double weight;
		weight = min1->getWeight() + min2->getWeight();
		node * head = new node(weight, min1, min2); //Creates a new node that connects the 2 lowest nodes that
													//has the weight of the 2 lowest nodes combined.
		array->da_push(head);// Adds the new node to the list of all of the nodes.

	}
	node * root = array->find_maxmin(false);
	return root;
}	

int main(){
	string command;

	cout << "Please choose one of the following options: " << endl;
	cout << "(C) Compress a file" << endl;
	cout << "(D) Decompress a binary file" << endl; 
	cout << "(Q) Quit " << endl;
	cout << ">> " ;
	
	cin >> command;
	cin.ignore();

	while(command != "C" && command != "D" && command != "Q"){
		cout << "Invalid command, please try again" << endl;
		cout << "Enter 'C' to compress a file" << endl;
		cout << "Enter 'D' to decompress a file" << endl;
		cout << "Enter 'Q' to quit" << endl;
		cout << ">> ";

	}
	
	if(command == "Q"){
		cout << "Program terminated" << endl;
		return 0;
	} else if(command == "D"){
		string hzipFile;
		string hcodesFile;
		cout<< "Please enter the .hzip file to be decompressed" << endl;
		cin >> hzipFile;
		cin.ignore();
		while(hzipFile.find(".hzip") == -1){
			cout << "Please enter a .hzip file or enter 'Q' to quit" << endl;
			cout << ">> ";
			cin >> hzipFile;
			if(hzipFile == "Q"){
				cout << "Program termianted" << endl;
				return 0;
			}
		}
		cout<< "Please enter the .hcodes file to be used" << endl;
		cout << ">> " ;
		cin >> hcodesFile;
		cin.ignore();
		while(hcodesFile.find(".hcodes") == -1){
			cout << "Please enter a .hcodes file or enter 'Q' to quit" << endl;
			cout << ">> ";
			cin >> hcodesFile;
			if(hcodesFile == "Q"){
				cout << "Program termianted" << endl;
				return 0;
			}
		}
		decoder* d = new decoder(hcodesFile, hzipFile);
		string decodedString = d->getString();

		cout << "decoded string is: " << decodedString << endl;	
		cout << "Your file has been decompressed" << endl;
	} else{
		string infile;
		cout << "Enter the file .txt file you would like to compress" << endl;
		cout << ">> " ;
		cin >> infile;
		int temp = infile.find(".");
		string input = infile.substr(0, temp);
		string keyFilename = input+".hcodes";
		string compFilename = input+".hzip";
		calculateWeights * calc = new calculateWeights(infile);
		my_da_array<node*>* weights = readWeights();
		node * root = buildTree(weights);//tested works
		keygen *kgen = new keygen(root, input);
		key* k = kgen->getKey();
		encoder* e = new encoder(k);
		e->incode(infile,compFilename);
		
		/* finds the number of bits in the compressed file */
		streampos start, end;
		ifstream cfile (input.c_str(), ios::binary);
		start = cfile.tellg();
		cfile.seekg(0, ios::end);
		end = cfile.tellg();
		cfile.close();
		double compressedFileBits = (end-start)*8;
	
		/* finds the number of bits in the text file */
		ifstream ufile(input.c_str(), ios::binary);
		start = ufile.tellg();
		ufile.seekg(0, ios::end);
		end = ufile.tellg();
		ufile.close();
		double uncompressedFileBits = (end-start)*8;

		cout << "Your file has been compressed" << endl;
		cout << "The compression ratio between your files is: " << uncompressedFileBits/compressedFileBits << ":1" << endl;
		cout << "You saved: " << (1-(compressedFileBits/uncompressedFileBits))*100 << "%" << " of the space you would have used" << endl;
}

/*	//int size = weights->get_size();
	//for(int i =0; i<size; i++){
	//	cout<<weights->get_elem(i)->getVal()<<endl;;
	//}
	//cout<<"done"<<endl;
	encoder encode = encoder();
	cout<<"Key:\n"<<key<<endl;
	string encoded = encode.incode(root);
	//cout<<encoded<<endl;
	decoder d = decoder(root);
	string decoded = d.getText();
	cout<<decoded<<endl; */
	
	return 0;

}

