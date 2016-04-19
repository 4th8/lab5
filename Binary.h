#include "bstream.h"

void genFile(string coded, string filename){
		string name = filename + ".hzip";
		ofbstream bin;
		bin.open(name);
		const char* cstr = coded.c_str();
		if(bin.is_open()){
				for(int i =0; i<strlen(cstr); i++){
						if(coded[i] == '1'){
								bin.writeBit(1);
						//		cout << "jsut wrote a 1" << endl;
						}else if(coded[i] == '0'){
								bin.writeBit(0);
						}
				}
		}
		bin.close();
}


string genString(ifbstream &input){
		string str = "";
		while(!input.eof()){
				if(input.readBit()){
						str += "1";
				} else{
						str += "0";
				}
		}
		return str;
}
