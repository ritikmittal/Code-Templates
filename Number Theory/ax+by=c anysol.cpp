//use egcd
//ax+by=c
bool any_sol(int a,int b,int c,int &x,int &y,int &g) {
    if(a==0 && b==0) {
        g = x = y = 0;
        return true;}
    g = egcd(abs(a), abs(b), x, y);
    if (c % g != 0) {
        return false;
    }
    x *= (c / g);y *= (c / g);
    if (a < 0) x = -x;if (b < 0) y = -y;
    return true;
}
// x+ cnt*(b/g)  , y- cnt*(a/g) (so you can generate, count solutions in some range)
