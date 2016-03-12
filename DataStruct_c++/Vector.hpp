#define NULL 0

template <typename Object>
class Vector
{
public:

	explicit Vector( int initSize = 0 )
		: theSize_( initSize ), theCapacity_( initSize + SPARE_CAPACITY ){
			objects_ = new Object[ theCapacity_ ];
		}

	Vector( const Vector &rhs ): objects_( NULL ){
		operator= ( rhs );
	}

	~Vector(){
		delete [] objects_;
	}

	const Vector& operator= ( const Vector& rhs ){
		if ( this != rhs )
		{
			delete []objects_;
			theSize_ = rhs.size();
			theCapacity_ = rhs.theCapacity_;
			for (int i = 0; i < rhs.size() ; ++i)
			{
				objects_[i] = rhs.objects_[i];
			}
		}
		return *this;
	}

	void resize( int newSize ){
		if ( newSize > theCapacity_ )
		{
			reserve( newSize * 2 + 1 );
		}
		theSize_ = newSize;
	}

	void reserve( int newCapacity ){
		if ( newCapacity < theCapacity_ )
			return;
		Object *oldArry = objects_;
		objects_ = new Object[ newCapacity ];
		for (int i = 0; i < theSize_ ; ++i)
		{
			objects_[i] = oldArry[i];
		}
		theCapacity_ = newCapacity;
		delete[] oldArry;
	}

	Object& operator[] ( int index ){
		return objects_[index];
	}

	const Object& operator[] (int index )const {
		return objects_[index];
	}

	bool empty() const{
		return size() ==0 ;
	}

	int size() const{
		return theSize_ ;
	}

	int capacity() const{
		return theCapacity_;
	}

	void push_back( const Object &x ){
		if ( theSize_ == theCapacity_ )
		{
			reserve( 2*theCapacity_ +1 );
		}
		objects_[ theSize_++ ] = x;
	}

	void pop_back(){
		theSize_--;
	}

	const Object& back() const{
		return objects_[ theSize_ -1 ];
	}

	typedef Object* iterator;
	typedef const Object*  const_iterator;

	iterator begin(){
		return &objects_[ 0 ];
	}

	const_iterator begin() const{
		return &objects_[ 0 ];
	}

	iterator end(){
		return &objects_[ size() ];
	}

	const_iterator end() const{
		return &objects_[ size() ];
	}

	enum 
	{
		SPARE_CAPACITY = 16
	};

private:
	int theSize_;
	int theCapacity_;
	Object *objects_;
};