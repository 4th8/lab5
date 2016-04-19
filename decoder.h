
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
	decodedString = getString();
	cout<<decodedString<<endl;
	
};

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
};

string decoder::getText(){
	return decodedString;
};
