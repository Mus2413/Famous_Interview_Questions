class TreeAncestor {
public:
	int **path;
	int powers;
	TreeAncestor(int n, vector<int>& parent) {
		int p, node, ancestorNode;
		powers = log2(n)+1;

		path = new int*[powers];
		for(p=0;p<powers;p++) {
			path[p] = new int[n];
			memset(path[p],-1,n*sizeof(int));
		}

		for(node=0;node<n;node++)
			path[0][node] = parent[node];

		for(p=1;p<powers;p++) {
			for(node=0;node<n;node++){
				ancestorNode = path[p-1][node];
				if(ancestorNode != -1)
					path[p][node] = path[p-1][ancestorNode];
			}
		}

	}

	int getKthAncestor(int node, int k) {
		int bits = log2(k);
		if(bits>=powers) return -1;
		for(int p=0;p<=bits;p++){
			if(k&(1<<p)){
				node = path[p][node];
				if(node==-1) return -1;
			}
		}

		return node;
	}
};