/*
Creates and stores the k for the Huffman tree.
The k will be in the format of the character followed by a space  then the path to the character in the tree.
Example:
	e 0
	b 100
	c 101
	d 110
	a 111

The k can be retrieved with the getKey() method.
*/
#include "key.h"
class keygen{
	private:
		string k;
		node * root;
		void makeKey(node*,string);
		string filename;

	public:
		keygen(node*,string);
		key * getKey();
};
keygen::keygen(node* root,string file){
	using namespace std;
	root = root;
	k = "";
	filename = file;
	makeKey(root,"");
};

void keygen::makeKey(node* root, string coded){
	if(root->checkLeaf() == true){
		int val = root->getVal();
		string value;
		stringstream ss;
		ss<<val;
		ss>>value;
		k = k + value + " " + coded + "\n";
		return;
	}
	if(root->hasLeft()){
		makeKey(root->getLeft(),coded+"0");
	}
	if(root->hasRight()){
		makeKey(root->getRight(),coded+"1");
	}
};

key* keygen::getKey(){
	ofstream out;
	string keyfile= filename + ".hcodes";
	out.open(keyfile.c_str());
	out<<k;
	out.close();
	return new key(keyfile);
};
