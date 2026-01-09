#pragma once
#include <memory>
class PricingStrategy{public:virtual ~PricingStrategy()=default;virtual int sellingPrice(int,int) const=0;virtual std::unique_ptr<PricingStrategy> clone() const=0;};
class MarkupPricing:public PricingStrategy{int percent_;public:explicit MarkupPricing(int p=10);int sellingPrice(int,int) const override;std::unique_ptr<PricingStrategy> clone() const override;};
