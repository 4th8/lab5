using namespace std;

template<class T>
class box_array{
	private:
		T * arr;
		int size;
		int unused;

	public:
		box_array();
		box_array(T num);
//		~box_array();
		void print();
		int da_push(T num);
		int getRemaining();
		T da_pop();
		int da_insert(int pos, T element);
		T get_elem(int index);
		int get_size();
		T find_maxmin(bool b);
		int is_elem(T index);
};
// default constructor
template<class T>
box_array<T>::box_array(){
	arr = new T[1];
	size = 0;
	unused = 0;
}
template<class T>
int box_array<T>::getRemaining(){
	return unused;
}

// non-default constructor
template<class T>
box_array<T>::box_array(T num){
	size = 1;
	unused = 1;
	arr = new T[size];
	arr[0] = num;
	}

// destructor
/*box_array<T>::~box_array(){
	delete arr;
}*/


template<class T>
void box_array<T>::print(){
	for(int i=0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
int box_array<T>::da_push(T num){
	try{
		T *newArr = new T[size+1];
		for (int i=0; i < size; i++){
			newArr[i] = arr[i];
			}
		newArr[size] = num;
		size++;
		unused++;
		delete[] arr;
		arr = newArr;
		return 0;
	} catch(std::bad_alloc){
		return -1;
	}
}

template<class T>
T box_array<T>::da_pop(){
	try{
		int tempSize = get_size();
		if (tempSize == 1){
			T val = arr[0];
			arr[0] = 0;
			return val;
		}
		T *newArr = new T[tempSize-1];
		T val = arr[size];
		for(int i=0; i < tempSize-1; i++){
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		size--;
		return val;
	} catch(std::bad_alloc){
		return -1;
	}
}

template<class T>
int box_array<T>::da_insert(int pos, T element){
	if(size < pos){
		return -1;
	}
	try{
		T *newArr = new T [size+1];
		for (int i=0; i < pos; i++){
			newArr[i] = arr[i];
		}
		newArr[pos] = element;
		for (int i=pos; i < size; i++){
			newArr[i+1] = arr[i];
		}
		size++;
		delete[] arr;
		arr = newArr;
		return 0;
	} catch(std::bad_alloc){
		return -1;
	}	
}

template<class T>
T box_array<T>::get_elem(int index){
	if(index > size){
		T bob;
		return bob;
	}
	return arr[index];
}

template<class T>
int box_array<T>::get_size(){
	return size;
}


template<class T>
int box_array<T>::is_elem(T val){
	for(int i=0; i < size; i++){
		if (arr[i] == val){
			return i;
		}
	}
	return -1;
}

