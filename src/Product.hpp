#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include <istream>
#include <ostream>

class Product {
    int id_{0};
    std::string brand_;
    std::string model_;
protected:
    void setId(int id) { id_ = id; }
public:
    static std::unordered_map<std::string,int>& colorProfitTable();
    static int profitForColor(const std::string& color);

    Product();
    Product(std::string brand, std::string model);
    Product(const Product& other);
    Product& operator=(const Product& other);
    virtual ~Product() = default;

    virtual std::string category() const = 0;
    virtual std::unique_ptr<Product> clone() const = 0;

    virtual void read(std::istream& in);
    virtual void print(std::ostream& out) const;

    bool operator==(const Product& rhs) const;
    friend std::ostream& operator<<(std::ostream& out, const Product& p) { p.print(out); return out; }
};

bool operator!=(const Product& a, const Product& b);

class Phone : public Product {
    int ramGB_{0};
public:
    Phone();
    Phone(std::string brand, std::string model, int ramGB);
    Phone(const Phone& o);
    Phone& operator=(const Phone& o);
    std::string category() const override { return "Telefon"; }
    std::unique_ptr<Product> clone() const override;
    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
};

class Tablet : public Product {
    int storageGB_{0};
public:
    Tablet();
    Tablet(std::string brand, std::string model, int storageGB);
    Tablet(const Tablet& o);
    Tablet& operator=(const Tablet& o);
    std::string category() const override { return "Tableta"; }
    std::unique_ptr<Product> clone() const override;
    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
};

class Laptop : public Product {
    int storageGB_{0};
    bool dedicatedGPU_{false};
public:
    Laptop();
    Laptop(std::string brand, std::string model, int storageGB, bool dedicatedGPU);
    Laptop(const Laptop& o);
    Laptop& operator=(const Laptop& o);
    std::string category() const override { return "Laptop"; }
    std::unique_ptr<Product> clone() const override;
    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
};
