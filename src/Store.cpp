#include "Store.hpp"

Store::Store(int b, std::unique_ptr < PricingStrategy > p): budget_(b), pricing_(std::move(p)) {}
void Store::addToCatalog(const CatalogItem & c) {
  catalog_.push_back(c);
}
void Store::buy(std::size_t idx, int qty) {
  if (idx >= catalog_.size()) throw StoreException("Index catalog invalid");
  auto & c = catalog_[idx];
  int total = c.buyPrice * qty;
  if (total > budget_) throw BudgetException("Buget insuficient");
  inventory_.push_back({
    c.product,
    c.color,
    c.buyPrice,
    qty
  });
  budget_ -= total;
}
int Store::sell(std::size_t idx, int qty) {
  if (idx >= inventory_.size()) throw InventoryException("Index inventar invalid");
  auto & s = inventory_[idx];
  if (qty > s.qty) throw InventoryException("Stoc insuficient");
  int unit = pricing_ -> sellingPrice(s.buyPrice, Product::profitForColor(s.color));
  s.qty -= qty;
  budget_ += unit * qty;
  return unit * qty;
}
