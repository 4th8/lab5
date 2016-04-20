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
		void incode(string,string);
		void stringPrint();
};

encoder::encoder(key* k){
	rep = k;
};

void  encoder::incode(string filename,string outname){
	ifstream text;
	text.open(filename.c_str());
	char c;
	string code = "";
	while(text.get(c)){
		string s = rep->lookup(c);
		code+= s;
		genFile(s, outname);
	}
	cout<<"Coded = "<<code<<endl;
	text.close();
};
void encoder::stringPrint(){
	cout<<encodedString<<endl;
	ofstream outfile;
	outfile.open("coded.txt");
	outfile<<encodedString;
	outfile.close();
}
