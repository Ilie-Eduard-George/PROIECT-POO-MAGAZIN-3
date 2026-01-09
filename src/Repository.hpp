#pragma once
#include <vector>

template <class T>
class Repository {
    std::vector<T> data_;
public:
    void add(const T& x) { data_.push_back(x); }
    std::size_t size() const { return data_.size(); }
    const T& at(std::size_t i) const { return data_.at(i); }
    T& at(std::size_t i) { return data_.at(i); }
};
