
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
	int size = x.length();
	int start= 0;
	int end = 1;
	int d=0;
	string currentdecoded;
	string currentPart = x.substr(start,end);
	while(d<size+1){
		if((k->checkCode(currentPart).compare(""))!=0){
			currentdecoded.append(k->checkCode(currentPart));
			currentPart="";
			start = end;
			d+=end;
			end=0;

		}
		end= end+1;
		currentPart= x.substr(start,end);
	}
	cout << "current decoded : " << currentdecoded << endl;
	return currentdecoded;
};

string decoder::getText(){
	return decodedString;
};
