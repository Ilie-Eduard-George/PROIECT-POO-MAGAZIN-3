#pragma once
#include <exception>
#include <string>
#include <utility>

class StoreException : public std::exception {
    std::string msg_;
public:
    explicit StoreException(std::string msg) : msg_(std::move(msg)) {}
    const char* what() const noexcept override { return msg_.c_str(); }
};

class BudgetException : public StoreException {
public:
    using StoreException::StoreException;
};

class InventoryException : public StoreException {
public:
    using StoreException::StoreException;
};
