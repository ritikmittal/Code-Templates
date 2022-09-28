// checks if a*b will overflow
bool is(ll a,ll b){
    if(a==0 || b==0)
        return false;
    if((a>LLONG_MAX/b) or ( b>LLONG_MAX/a)) return true;
    return false;
}
