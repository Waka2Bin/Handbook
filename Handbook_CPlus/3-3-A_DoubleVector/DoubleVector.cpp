#include <vector>

template <typename T> void Duplicate(std::vector<T>& v) {
    auto tmp = int(v.size());
    for (auto i = 0; i < tmp; ++i) {
        v.push_back(v[i]);
    }
}