
//分离链接法
template <typename HashedObj>
class HashTable
{
public:
	explicit HashTable( int size = 101 );
	~HashTable();

	bool contains( const HashedObj &x ) const;
	void makeEmpty();
	void insert( const HashedObj &x );
	void remove( const HashedObj &x );
private:
	vector< list< HashedObj> > theLists;
	int currentSize;

	void rehash();
	int myhash( const HashedObj &x ) const;
	
};

int HashTable::myhash( const HashedObj &x ) const{
	int hashVal = hash(x);
	hashVal %= theLists.size();
	if ( hashVal <0 )
	{
		hashVal += theLists.size();
	}
	return hashVal;
}