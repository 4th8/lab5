using namespace std;
class box{
	
	private:
		char c;
		string code;
		bool used;
		int codeLength;

	public:
		box(char x, string w){
			c = x;
			code = w;
		}
		char getChar(){
			return c;
		}
		int getCodeLength(){
			return codeLength;
		}
		string getcode(){
			return code;
		}
		void use(){
			used = true;
		}
		bool getused(){
			return used;
		};
		void reset(){
			used = false;
		};
};
