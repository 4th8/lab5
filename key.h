class key{
	private:
		box_array<box*> * boxes;
		int size;
	public:
		key(string);
		string lookup(char);
		string checkCode(string);
};


key::key(string filename){
	ifstream keyFile;
	keyFile.open(filename.c_str()); // This will need to be an input later.
	int num = 0;
	while(keyFile){
		stringstream ss;
		string line;
		char hh;
		double weight;
		getline(keyFile, line);
		if (line == ""){// This if statement is needed to catch when it grabs an empty string from the end of the file.
			break;
		}
		int length = line.length();
		int space;
		for(int i = 0; i <length; i++){
			if (line[i] == ' '){
				space = i;
				break;
			}
		}
		int ascii;
		string c = line.substr(0,space-1);
		string coded = line.substr(space+1,length);
		stringstream s1;
		s1 << c;
		s1 >> ascii;
		hh = char(ascii);
		box * currentbox = new box(hh,coded);
		if (num == 0){
			boxes = new box_array<box*>(currentbox);
			num = 1;
		}
		else{
			boxes->da_push(currentbox);
		}
	}
	keyFile.close();
	size = boxes->get_size();
};
string key::lookup(char c){
	for(int i = 0; i <size; i++){
		if(boxes->get_elem(i)->getChar() == c){
			return boxes->get_elem(i)->getcode();
		}
	}
};
string key::checkCode(string c){
	string ans = "";
	for(int i = 0; i <size; i++){
		if(boxes->get_elem(i)->getcode() == c){
			ans += boxes->get_elem(i)->getChar();
			return ans;
		}
	return "";
	}
	
};
