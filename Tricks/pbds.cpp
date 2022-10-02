#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// RB Tree
template<class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc>
struct my_node_update {
	typedef pr metadata_type;
	int order_of_key(pair<int, int> x){ 
		while (it != node_end()) {
		if (l != node_end()) {} } return 1;}
	void operator()(Node_Itr it, Node_CItr end_it){
		auto l = it.get_l_child(); if (l != end_it) left = l.get_metadata();
		const_cast<pr&>(it.get_metadata()) = {(**it).first + left.first}; }
	virtual Node_CItr node_begin() const = 0;
	virtual Node_CItr node_end() const = 0; };
tree < pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, my_node_update > me;
// Ordered Set :
typedef tree< int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set X; end(X)==X.find_by_order(k) // find iterator to the k-th largest element
*X.order_of_key(y) // return #count of ele less than y
// Hash table
struct chash {
    const uint64_t C = ll(4e18 * acos(0)) | 71;
    ll operator()(ll x) const { return __builtin_bswap64(x*C); }};
__gnu_pbds::gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});
