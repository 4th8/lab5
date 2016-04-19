
using namespace std;

class decoder{
	private:
		string decodedString;
		int pos;
		string incodedText;
		node * root;
		key* k;
		ifbstream bin;
		string s;
	public:
		decoder(string,string);
		void genText(char, node*);
		string getText();
		string getString();
};

decoder::decoder(string keyFilename, string binFilename){
	bin.open(binFilename);
	k = new key(keyFilename);
} 

string decoder::getString(){
	s = genString(bin);
	string currentCode;
	const char* cs = s.c_str();
	for(int i=0; i<strlen(cs); i++){
		char x = cs[i];
		if(k->checkCode(x) != ""){
			currentCode += k->checkCode(x);
		} else{
			break;
		}
	}
	return currentCode;
}
/*
	decodedString="";
	incodedText = "";
	root = root;
	pos = 0;
	ifstream text;
	text.open("coded.txt");// this needs to be overwritten with a prompt.
	string coded;
	while(text){
		string line;
		getline(text, line);
		incodedText += line;
	}
	while(pos<=incodedText.length()){
		char c = incodedText[pos];
		genText(c,root);
		pos--;
	}
};

void decoder::genText(char c, node* n){
	pos = pos +1;
	if (n->checkLeaf()){
		decodedString += n->getVal();
	}
	else if(c == '0'){
		c=incodedText[pos];
		genText(c, n->getLeft());
	}
	else if(c == '1'){
		c=incodedText[pos];
		genText(c, n->getRight());
	}
	else{
		pos = 99999;
	}
}; */

string decoder::getText(){
	return decodedString;
};
