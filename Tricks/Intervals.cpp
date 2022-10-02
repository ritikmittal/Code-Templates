struct Integerintervals
{   
set<pll> Intervals;
//* Intervals are [inclusive, exclusive).
auto addInterval(ll L, ll R) {
    if (L == R) return Intervals.end();
    auto it = Intervals.lower_bound({L, R}), before = it;
    while (it != Intervals.end() && it->first <= R) {
        R = max(R, it->second);
        before = it = Intervals.erase(it);}
    if (it != Intervals.begin() && (--it)->second >= L) {
        L = min(L, it->first);R = max(R, it->second);
        Intervals.erase(it);}
    return Intervals.insert(before, {L,R});}
void removeInterval(ll L, ll R) {
    if (L == R) return;
    auto it = addInterval(L, R);
    auto r2 = it->second;
    if (it->first == L) Intervals.erase(it);
    else (ll&)it->second = L;
    if (R != r2) Intervals.emplace(R, r2);}
auto find(ll x)
{
    auto it=Intervals.lower_bound((pll){x,INF});
    if(it==Intervals.begin())return (pll){-1,-1};
    it--;
    if(it->first<=x && it->second>x)return *it;
    return (pll){-1,-1};
}//find returns {-1,-1} if no segment in the Intervals contain x Intervals are [inclusive, exclusive).
};
