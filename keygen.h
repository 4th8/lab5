/*
Creates and stores the key for the Huffman tree.
The key will be in the format of the character followed by a space  then the path to the character in the tree.
Example:
	e 0
	b 100
	c 101
	d 110
	a 111

The key can be retrieved with the getKey() method.
*/
class keygen{
	private:
		string key;
		node * root;
		void makeKey(node*,string);

	public:
		keygen(node*);
		string getKey();
};
keygen::keygen(node* root){
	using namespace std;
	root = root;
	key = "";
	makeKey(root,"");
};

void keygen::makeKey(node* root, string coded){
	if(root->checkLeaf() == true){
		int val = root->getVal();
		string value;
		stringstream ss;
		ss<<val;
		ss>>value;
		key = key + value + " " + coded + "\n";
		return;
	}
	if(root->hasLeft()){
		makeKey(root->getLeft(),coded+"0");
	}
	if(root->hasRight()){
		makeKey(root->getRight(),coded+"1");
	}
};

string keygen::getKey(){
	ofstream out;
	out.open("keyfile.txt");
	out<<key;
	out.close();
	return key;
};
