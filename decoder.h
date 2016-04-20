
using namespace std;

class decoder{
	private:
		string decodedString;
		int pos;
		string incodedText;
		node * root;
		key* k;
		string bin;
	public:
		decoder(string,string);
		void genText(char, node*);
		string getText();
		string getString();
};

decoder::decoder(string keyFilename, string binFilename){
	bin= binFilename;
	k = new key(keyFilename);
//	decodedString = getString();
//	cout<<decodedString<<endl;
	
};

string decoder::getString(){
	string x = genString(bin);
	cout << "x is : " <<  x << endl;
	int size = x.length();
	string currentdecoded;
	string currentPart = &x[0];
	for(int i=0; i<size; i++){
		if(k->checkCode(currentPart) != ""){
			currentdecoded.append(k->checkCode(x));
			cout << currentdecoded << endl;
			currentPart="";
		}
		currentPart+=x[i];
	}
	cout << "current decoded : " << currentdecoded << endl;
	return currentdecoded;
};

string decoder::getText(){
	return decodedString;
};
