int egcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;return a;
    }
    int x1,y1;
    int d=egcd(b,a%b,x1,y1);
    x=y1;y=x1-y1*(a/b);
    return d;
}
// if(g!=1) does not exist,ainv mod b is x in egcd(a,b,x,y) % b (make +ve) 
// ax=b (mod n) is (ainv modn *b)%n (make sure to divide a,b,n by gcd first)