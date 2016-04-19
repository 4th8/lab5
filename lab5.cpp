#include "my_da_array.cpp"
#include "encoder.h"
#include <sstream> // Needed for stringstream
#include <stdlib.h>
#include "keygen.h"
#include "decoder.h"
#include "calculateWeights.h"
#include "key.h"
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
	calculateWeights();//tested works
	my_da_array<node*>* weights = readWeights();
	//int size = weights->get_size();
	//for(int i =0; i<size; i++){
	//	cout<<weights->get_elem(i)->getVal()<<endl;;
	//}
	//cout<<"done"<<endl;
	node * root = buildTree(weights);//tested works
	encoder encode = encoder();
	keygen k = keygen(root);
	string key = k.getKey();
	cout<<"Key:\n"<<key<<endl;
	string encoded = encode.incode(root);
	//cout<<encoded<<endl;
	decoder d = decoder(root);
	string decoded = d.getText();
	cout<<decoded<<endl;
	
	return 0;

}