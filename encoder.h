/*
   Takes a text and the root of the Huffman tree and returns the encoded string.
   For the finial result this will need to print the encoded string to a file.
 */




using namespace std;
class encoder{
	private:
		string encodedString;
		key* rep;

	public:
		encoder(key* r);
	//	void genCode(char, node*, string);
		void incode(string);
		void stringPrint();
};

encoder::encoder(key* k){
	rep = k;
};

void  encoder::incode(string filename){
	ifstream text;
	text.open(filename.c_str());
	char c;
	while(text.get(c)){
		string s = rep->lookup(c);
		cout<<"char: "<<c<<endl;
		cout<<"code:"<<s<<endl;
		genFile(s, filename);
	}
	text.close();
};
void encoder::stringPrint(){
	cout<<encodedString<<endl;
	ofstream outfile;
	outfile.open("coded.txt");
	outfile<<encodedString;
	outfile.close();
}
