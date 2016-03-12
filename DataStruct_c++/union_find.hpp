#include <iostream>
#include <vector>


class union_find
{
public:
	union_find(int N): count(N) {
		for( int i=0; i < N; ++i )
			id.push_back(i);
		sz.assign(N,1);
	}

	int find(int p){
		while( p != id[p] )
			p = id[p];
		return p;
	}

	void do_union(int p, int q){
		int pRoot = find(p);
		int qRoot = find(q);
		if( pRoot == qRoot )
			return;
		if ( sz[pRoot] < sz[qRoot] ){
			id[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
		}
		else{
			id[qRoot] = pRoot;
			sz[pRoot] += sz[qRoot];
		}
		count--;
	}

	int get_count(){
		return count;
	}

private:
	vector<int> id;			//父链接数组
	vector<int> sz;			//
	int count;				//连通分量数量
};



