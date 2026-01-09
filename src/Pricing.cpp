#include "Pricing.hpp"
MarkupPricing::MarkupPricing(int p):percent_(p){}
int MarkupPricing::sellingPrice(int buy,int colorProfit) const{return buy+buy*percent_/100+colorProfit;}
std::unique_ptr<PricingStrategy> MarkupPricing::clone() const{return std::make_unique<MarkupPricing>(*this);} 
