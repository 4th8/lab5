class calculateWeights{
	struct character{
		char c;
		double count;
	};
	private:
	int curLen;
	double total;

	character * characters;
	public:
	calculateWeights(string);
	void print();
	void checkCharacters(char);
};

calculateWeights::calculateWeights(string filename){
	curLen = 0;
	total = 0;
	characters = new character[127];//One slot for each of the 127 characters in ascii.
	ifstream text;
	cout<<"Filename: "<<filename<<endl;
	text.open(filename.c_str());// this needs to be overwritten with a prompt.
	char c;
	while(text.get(c)){
		checkCharacters(c);	
		total++;
	}
	print();
};
void calculateWeights::checkCharacters(char x){
	if (curLen == 0)
		curLen = 1;
	bool found = false;
	for(int i = 0; i<curLen; i++){
		if (x == characters[i].c){
			characters[i].count++;
			found = true;
		}
	}
	if(!found){
		characters[curLen-1].c = x;
		characters[curLen-1].count = 1;
		curLen++;
	}
};
void calculateWeights::print(){
	ofstream weightfile;
	weightfile.open("weights.txt");
	for(int i = 0; i < curLen-1; i++){
		int ch = int(characters[i].c);
		double z = characters[i].count/total;
		weightfile<<ch<<" "<<z<<endl;
	}
	weightfile.close();
};
