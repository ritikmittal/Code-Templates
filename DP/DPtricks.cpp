//Aliens Trick
/*Consider a dp[i][k] meaning cost for breaking first i elements into k parts
we binary search on lambda, and alter our cost function as Cost(l,r)+ lambda
meaning that one extra cut costs lambda , if lambda is high it is same as k=1
if lambda is low it is k=n, So when you find dp[i](cost for first i elements)
with updated cost function,also maintain how many times you have split
make check function as number of cuts <=K and find minimum lambda
in the end get the dp[n] for this lambda and subtract K*lambda
You can also do something similar if instead of cutting you have to choose exactly K items
just update the cost function*/

//Open and Close interval trick
/*maintain dp[i][j] meaning first i elements and j intervals are open*/

// 2X+1 trick
/* If you can calculate dp[2*i] from dp[i] and dp[i+1] from dp[i] , you can calculate dp[large]
just calculate till dp[small] and then use kind of binary exponentation */
//Write a few other tricks form zscoder blog