#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> createOne(){
	return unique_ptr<int>(new int(1));
}

class Data{
public:
	void aMethod(){ cout << "method called" << endl;}
	~Data(){ cout << "data is being deleted" << endl; }
};

int main() {
  // when the program exits the block, the pointer is going to delete the data
  // automatically
	{
		unique_ptr<Data> dataPtr { new Data() };
	}
	
	// the only way to pass on the data is to release the pointer
	// so we never going to have two unique_ptr with the same data
	unique_ptr<Data> dataPtr = unique_ptr<Data>(new Data());
	unique_ptr<Data> dataPtr2 {dataPtr.release()};
	
	cout << dataPtr.get() << " and " << dataPtr2.get() << endl;
	
	// to use the object held by the unique_ptr, just use it as it were a
	// common pointer
	dataPtr2->aMethod();
	
	// the best use of a unique_ptr is to return objects created by
	// functions, that way we are guaranteed to not have a memory leak
	unique_ptr<int> one_p = createOne();
	cout << *a << endl;
	
	return 0;
}
