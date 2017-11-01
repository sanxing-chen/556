//==========================================================
// <cstring>
void *memcpy(void *dest, const void *src, std::size_t count);

//==========================================================
// std::string
substr(size_type pos = 0, size_type count = npos) const;

//==========================================================
// std::set
template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class set;

// 插入
std::pair<iterator, bool> insert(const value_type &value);

// 删除
// Removes specified elements from the container.
// 1) Removes the element at pos.
// 2) Removes the elements in the range [first; last), which must be a valid range in *this.
// 3) Removes the element (if one exists) with the key equivalent to key.
void erase(iterator pos);
erase(iterator first, iterator last);
size_type erase(const key_type &key);

// 计数
size_type count(const Key &key) const;

//==========================================================
// std::map
template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>>>
class map;

//==========================================================
// std::priority_queue <queue>
template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
class priority_queue;

//==========================================================
// std::bitset
template <std::size_t N> class bitset;

// 1) Sets all bits to true.
// 2) Sets the bit at position pos to the value value.
bitset<N> &set();
bitset<N> &set(size_t pos, bool value = true);

bool test(size_t pos) const;

bool all() const; // since c++11
bool any() const;
bool none() const;

std::size_t count() const;

// 1) Flips all bits (like operator~, but in-place)
// 2) Flips the bit at the position pos.
bitset<N> &flip();
bitset<N> &flip(size_t pos);

// output
std::bitset<8> b(42);
b.to_btring();         // 00101010
b.to_string('*');      // **1*1*1*
b.to_string('O', 'X'); // OOXOXOXO
b.to_ulong();
b.to_ullong();

// unique
std::vector<int> v{1, 2, 3, 1, 2, 3, 3, 4, 5, 4, 5, 6, 7};
std::sort(v.begin(), v.end()); // 1 1 2 2 3 3 3 4 4 5 5 6 7
auto last = std::unique(v.begin(), v.end());
// v now holds {1 2 3 4 5 6 7 x x x x x x}, where 'x' is indeterminate
v.erase(last, v.end());