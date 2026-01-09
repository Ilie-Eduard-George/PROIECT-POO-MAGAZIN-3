#include "Store.hpp"
#include <iostream>
int main(){ try{ Store store(10000,std::make_unique<MarkupPricing>(10)); store.addToCatalog({std::make_shared<Phone>("Samsung","S24",8),"negru",1200}); store.buy(0,2); store.sell(0,1); std::cout<<"Buget final: "<<store.budget()<<"\n"; }catch(const std::exception& e){ std::cout<<"Eroare: "<<e.what()<<"\n"; }}
