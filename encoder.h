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
		key* rep;

	public:
		encoder(key r);
	//	void genCode(char, node*, string);
		string incode(string filename);
		void stringPrint();
};

encoder::encoder(key k){
	rep = k;
};
/*void encoder::genCode(char cur, node * n, string coded){// This will generate the code recursively.

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

};*/

void  encoder::incode(filename){
	ifstream text;
	text.open(filename);
	char c;
	while(text.get(c)){
		cout<<"\nencoding: "<<c<<endl;
		string s = rep.keyLookup(c);
		genFile(s, filename);
	}
	text.close();
};
void encoder::stringPrint(){
	ofstream outfile;
	outfile.open("coded.txt");
	outfile<<encodedString;
	outfile.close();
}
