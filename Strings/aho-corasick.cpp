struct node{
 unordered_map<int,int>m; deque<int>occ;
 int link=0, link_to_leaf=0, len=0;
 bool leaf=false; };
vector<node>trie(1);
void add(string &s){
 int which=0; for(auto &x:s) {
  int c=x-'a';
  if (!trie[which].m.count(c)) {
    trie.emplace_back();
    trie[which].m[c] = sz(trie) - 1; }
  which = trie[which].m[c]; }
 trie[which].leaf=true;
 trie[which].len=s.length(); }
void make_suffix_link() {
 queue<int> q;
 for(auto &c: trie[0].m) { q.push(c.second);}
 while (!q.empty()) {
  int node = q.front(); q.pop();
  for (auto &c: trie[node].m) { // fi - first
   int ch=c.fi,child=c.se,k=trie[node].link;
   while (k != 0 && !trie[k].m.count(ch)) {
    k = trie[k].link; }
   if (trie[k].m.count(ch)) {
    k = trie[k].m[ch]; }
   trie[child].link = k;
   if (trie[k].leaf) { // LTL - link_to_leaf
    trie[child].LTL = k; } else {
    trie[child].LTL=trie[k].LTL;}
      q.push(child); } }}