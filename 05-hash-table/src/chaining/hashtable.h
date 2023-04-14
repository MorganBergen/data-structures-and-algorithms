#ifndef __HASHTABLE__
#define __HASHTABLE__

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>

template <typename hashobj>

class hashtable {
    public:
        explicit hashtable(int size = 101);
        bool contains(const hashobj &x);
        void makeempty();
        bool insert(const hashobj &x);
        bool insert(hashobj &&x);
        bool remove(const hashobj &x);

    private:
        vector<list<hashobj>> theLists;
        int currentSize;
        void rehash();
        bool remove(const hashobj &x);
        size_t myhash(const hashobj &x) const;
};
#endif
