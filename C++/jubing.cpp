
class Query_base{
	friend class Query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base();
private:
	virtual std::set<line_no>
		eval( const TextQuery& ) const = 0;
	virtual std::ostream &
		display( std::ostream& = std::cout ) const = 0;
};


class Query{
	friend Query operator~( const Query & );
	friend Query operator|( const Query &, const Query & );
	friend Query operator&( const Query &, const Query & );
public:
	Query( const std::string& );
	Query( const Query &c ): q(c.q), use(c.use){ ++*use; }
	~Query() { decr_use() }
	Query& operator= (const Query& );
	std::set<TextQuery::line_no>
		eval( const TextQuery &t ) const { return q->eval(t); }
	std::ostream &display( std::ostream &os) const
		{ return q->display(os) }
private:
	Query( Query_base *query ): q(query), use( new std::size_t(1) ){}

	Query_base *q;
	std::size_t *use;
	void decr_use(){
		if ( --*use ==0 ){
			delete q;
			delete use;
		}
	}

};
