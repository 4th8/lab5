#include "bstream.h"
#include "Binary.h"

using namespace std;

class decoder{
	private:
		string decodedString;
		int pos;
		string incodedText;
		node * root;
		key* k;
		ifbstream bin;
	public:
		decoder(string,string);
		void genText(char, node*);
		string getText();
		string getString();
};

decoder::decoder(string keyFilename, string binFilename){
	bin.open(binFilename);
	k = new key(keyFilename);
	decodedString = getString();
	cout<<decodedString<<endl;
	
};

string decoder::getString(){
	string x = genString(bin);
	int size = x.length();
	string currentdecoded;
	string currentPart = &x[0];
	for(int i=0; i<size; i++){
		if(k->checkCode(currentPart) != ""){
			currentdecoded += k->checkCode(x);
			currentPart="";
		}
		currentPart+=x[i];
	}
	return currentdecoded;
};

string decoder::getText(){
	return decodedString;
};
