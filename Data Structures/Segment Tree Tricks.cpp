// index of first element >=x in [ql,n-1]
int first_greater(int index, int ss, int se, int x, int ql) {
    if (ql > se) return -1;
    if (tree[index].max_val < x) return -1;
    if (ss == se) {
        return ss;
    }
    int m = (ss + se) / 2;
    int temp = first_greater(2 * index, ss, m, x, ql);
    if (temp != -1) return temp;
    return first_greater(2 * index + 1, m + 1, se, x, ql);
}
// change every element in [qs,qe] with value <=p to INT_MAX
// return the count of element changed
// complexity is (number_of_element<=p in [qs,qe])*log(n)
int change(int index, int ss, int se, int qs, int qe, int p) {
    if (tree[index].min_val > p) return 0;
    if (qs > se || qe < ss) return 0;
    if (ss == se) {
        a[ss] = INT_MAX;
        single(tree[index], ss);
        return 1;
    }
    int m = (ss + se) / 2;
    int left = change(2 * index, ss, m, qs, qe, p);
    int right = change(2 * index + 1, m + 1, se, qs, qe, p);
    merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    return left + right;
}
// kth one
int get_kth(int index, int ss, int se, int k) {
    if (ss == se) {
        return ss;
    }
    int m = (ss + se) / 2;
    if (tree[2 * index].one_cnt >= k) return get_kth(2 * index, ss, m, k);
    else return get_kth(2 * index + 1, m + 1, se, k - tree[2 * index].one_cnt);
}