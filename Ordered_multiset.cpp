#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


//*find_by_order
//order_of_key
template <typename T> using oset =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using omset =
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


template<class T>
class ordered_multiset {
public:
    omset<T> s;
    int size() {
        return ssize(s);
    }
    void insert(T a) {
        s.insert(a);
    }
    const T operator[](int n) {
        return *s.find_by_order(n);
    }
    int less(T x) {
        return s.order_of_key(x);
    }
    bool erase(T x) {
        int l = s.order_of_key(x);
        if(l + 1 <= ssize(s)) {
            auto it = s.find_by_order(l);
            if(*it == x) {
                s.erase(it);
                return true;
            }
        }
        return false;
    }
    void erase(omset<T>::iterator x) {
        s.erase(x);
    }
    omset<T>::iterator begin() {
        return s.begin();
    }
    omset<T>::iterator end() {
        return s.end();
    }
    omset<T>::iterator lower_bound(T x) {
        int l = s.order_of_key(x);
        if(l + 1 <= ssize(s)) {
            return s.find_by_order(l);
        }
        return s.end();
    }
    omset<T>::iterator upper_bound(T x) {
        int l = s.order_of_key(x + 1);
        if(l + 1 <= ssize(s)) {
            return s.find_by_order(l);
        }
        return s.end();
    }
};
