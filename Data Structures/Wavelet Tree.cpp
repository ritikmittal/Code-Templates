struct wavelet_tree{ // 1 indexed -> Tree(arr+1, arr+n+1, lo, hi);
	#define vi vector<int> #define pb push_back
	int lo, hi;
	wavelet_tree *l, *r;
	vi b;
	wavelet_tree(int *from, int *to, int x, int y){
		lo = x, hi = y;
		if(lo == hi or from >= to) return;
		int mid = (lo+hi)/2;
		auto f = [mid](int x){ return x <= mid; };
		b.reserve(to-from+1); b.pb(0);
		for(auto it = from; it != to; it++)
			b.pb(b.back() + f(*it));	
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid+1, hi); }
	int kth(int l, int r, int k){ //kth smallest in [l, r]
		if(l > r) return 0; if(lo == hi) return lo;
		int inLeft = b[r] - b[l-1], lb = b[l-1], rb = b[r];
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft); }
	int LTE(int l, int r, int k) { // nos in [l, r] <= k
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l-1], rb = b[r];
		return this->l->LTE(lb+1, rb, k) + this->r->LTE(l-lb, r-rb, k); }
	int count(int l, int r, int k) { // nos in [l, r] == k
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k); }
	~wavelet_tree(){ delete l; delete r; }
};