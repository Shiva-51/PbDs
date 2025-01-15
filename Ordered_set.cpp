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
class ordered_set {
public:
    oset<T> s;
    int size() {
        return ssize(s);
    }
    void insert(T a) {
        s.insert(a);
    }
    bool erase(T x) {
        if(s.erase(x)) {
            return true;
        }
        return false;
    }
    oset<T>::iterator begin() {
        return s.begin();
    }
    typename oset<T>::iterator end() {
        return s.end();
    }
    void erase(typename oset<T>::iterator x) {
        s.erase(x);
    }
    const T &operator[](int n) {
        return *s.find_by_order(n);
    }
    int less(T x) {
        return s.order_of_key(x);
    }
    oset<T>::iterator upper_bound(T x) {
        return s.upper_bound(x);
    }
    oset<T>::iterator lower_bound(T x) {
        return s.lower_bound(x);
    }
};
