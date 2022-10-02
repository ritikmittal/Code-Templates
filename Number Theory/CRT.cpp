//!!! define egcd()here
int mod(int a, int b) {return ((a%b) + b) % b;}
// fz % m1 = r1, z % m2 = r2. Here, z is unique modulo M = lcm(m1, m2).Return (z, M). On failure, M = -1.
pair<int,int> chinese_remainder_theorem(int m1, int r1, int m2, int r2) {
 int s, t;int g = egcd(m1, m2, s, t);
 if (r1%g != r2%g) return make_pair(0, -1);
 return make_pair(mod(s*r2*m1 + t*r1*m2, m1*m2) / g, m1*m2 / g);}
// z % m[i] = r[i] for all i. solution is unique modulo M = lcm_i (m[i]).Return (z, M). Onfailure, M = -1. Note that we do not require the a[i]’sto be relatively prime.
pair<int,int> chinese_remainder_theorem(const VI &m, const VI &r) {
 pair<int,int> ret = make_pair(r[0], m[0]);
 for (int i = 1; i < m.size(); i++) {
  ret = chinese_remainder_theorem(ret.second, ret.first, m[i], r[i]);
  if (ret.second == -1) break;} return ret;}