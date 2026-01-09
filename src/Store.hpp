#pragma once
#include "Product.hpp"
#include "Pricing.hpp"
#include "Exceptions.hpp"
#include <vector>
#include <memory>
struct CatalogItem{std::shared_ptr<Product> product;std::string color;int buyPrice{};};
struct StockItem{std::shared_ptr<Product> product;std::string color;int buyPrice{};int qty{};};
class Store{int budget_;std::vector<CatalogItem> catalog_;std::vector<StockItem> inventory_;std::unique_ptr<PricingStrategy> pricing_;public:explicit Store(int b,std::unique_ptr<PricingStrategy> p);void addToCatalog(const CatalogItem&);void buy(std::size_t,int);int sell(std::size_t,int);int budget() const{return budget_;}};
