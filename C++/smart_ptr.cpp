class U_ptr
{
	friend class HasPtr;
	int *ip;
	size_t use;

	U_ptr(int *p): ip(p), use(1) {};
	~U_ptr(){
		delete ip;
	}
	
};


class HasPtr{
public:
	int *get_ptr() const{
		return ptr->ip;
	}
	int get_int() const{
		return val;
	}
	HasPtr(int *p, int i): ptr(new U_ptr(p)), val(i) {}

	HasPtr(const HasPtr &orig):
		ptr(orig.ptr), val(orig.val) {
			++ptr->use;
		}
	HasPtr& operator=(const HasPtr&);

	HasPtr(const HasPtr& orig): ptr(new int (*orig.ptr)), val(orig.val){}

	~HasPtr() {
		if( --ptr->use == 0)
			delete ptr;
	}
private:
	U_ptr *ptr;
	int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
	++rhs.ptr->use;
	if( --ptr->use == 0 )
		delete ptr;
	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}

