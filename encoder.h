/*
   Takes a text and the root of the Huffman tree and returns the encoded string.
   For the finial result this will need to print the encoded string to a file.
 */


#include "node.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class encoder{
	private:
		string encodedString;

	public:
		encoder();
		void genCode(char, node*, string);
		string incode(node*);
		void stringPrint();
};

encoder::encoder(){
	encodedString = "";
};
void encoder::genCode(char cur, node * n, string coded){// This will generate the code recursively.

	using namespace std;
	if(n->checkLeaf() == true){
		if(n->getVal() == cur){
			encodedString += coded;
			int i = cur;
			cout<<"found the leaf:"<<endl;
			cout<<"Current: "<<i<<endl;
			cout<<"n get value: "<<n->getVal()<<endl;
			cout<<"code: "<<coded<<endl;
			return;
		}
	}
	if(n->hasLeft()){
		genCode(cur,n->getLeft(),coded+"0");
	}
	if(n->hasRight()){
		genCode(cur,n->getRight(),coded+"1");
	}

};
using namespace std;
string encoder::incode(node *root){
	using namespace std;
	ifstream text;
	text.open("TextFile.txt");// this needs to be overwritten with a prompt.
	char c;
	while(text.get(c)){
		cout<<"\nencoding: "<<c<<endl;
		cout<<root->getWeight()<<endl;
		genCode(c,root,"");
		stringPrint();//This will be replaced when you get the binary printer working.
	}
	text.close();
	return encodedString;
};
void encoder::stringPrint(){
	ofstream outfile;
	outfile.open("coded.txt");
	outfile<<encodedString;
	outfile.close();
}
