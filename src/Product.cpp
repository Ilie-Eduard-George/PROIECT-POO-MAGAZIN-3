#include "Product.hpp"
#include <utility>

static int nextId(){ static int id=1; return id++; }

std::unordered_map<std::string,int>& Product::colorProfitTable(){ static std::unordered_map<std::string,int> t{{"negru",200},{"alb",150},{"gri",250}}; return t; }
int Product::profitForColor(const std::string& color){ auto& t=colorProfitTable(); auto it=t.find(color); return it==t.end()?0:it->second; }

Product::Product():id_(nextId()){}
Product::Product(std::string b,std::string m):id_(nextId()),brand_(std::move(b)),model_(std::move(m)){}
Product::Product(const Product& o):id_(o.id_),brand_(o.brand_),model_(o.model_){}
Product& Product::operator=(const Product& o){ if(this!=&o){id_=o.id_;brand_=o.brand_;model_=o.model_;} return *this; }
void Product::read(std::istream& in){ in>>brand_>>model_; }
void Product::print(std::ostream& out) const{ out<<category()<<" "<<brand_<<" "<<model_; }
bool Product::operator==(const Product& rhs) const{ return id_==rhs.id_; }
bool operator!=(const Product& a,const Product& b){ return !(a==b); }

Phone::Phone()=default;
Phone::Phone(std::string b,std::string m,int r):Product(std::move(b),std::move(m)),ramGB_(r){}
Phone::Phone(const Phone& o):Product(o),ramGB_(o.ramGB_){}
Phone& Phone::operator=(const Phone& o){ Product::operator=(o); ramGB_=o.ramGB_; return *this; }
std::unique_ptr<Product> Phone::clone() const{ return std::make_unique<Phone>(*this); }
void Phone::read(std::istream& in){ Product::read(in); in>>ramGB_; }
void Phone::print(std::ostream& out) const{ Product::print(out); out<<" RAM="<<ramGB_; }

Tablet::Tablet()=default;
Tablet::Tablet(std::string b,std::string m,int s):Product(std::move(b),std::move(m)),storageGB_(s){}
Tablet::Tablet(const Tablet& o):Product(o),storageGB_(o.storageGB_){}
Tablet& Tablet::operator=(const Tablet& o){ Product::operator=(o); storageGB_=o.storageGB_; return *this; }
std::unique_ptr<Product> Tablet::clone() const{ return std::make_unique<Tablet>(*this); }
void Tablet::read(std::istream& in){ Product::read(in); in>>storageGB_; }
void Tablet::print(std::ostream& out) const{ Product::print(out); out<<" STO="<<storageGB_; }

Laptop::Laptop()=default;
Laptop::Laptop(std::string b,std::string m,int s,bool g):Product(std::move(b),std::move(m)),storageGB_(s),dedicatedGPU_(g){}
Laptop::Laptop(const Laptop& o):Product(o),storageGB_(o.storageGB_),dedicatedGPU_(o.dedicatedGPU_){}
Laptop& Laptop::operator=(const Laptop& o){ Product::operator=(o); storageGB_=o.storageGB_; dedicatedGPU_=o.dedicatedGPU_; return *this; }
std::unique_ptr<Product> Laptop::clone() const{ return std::make_unique<Laptop>(*this); }
void Laptop::read(std::istream& in){ Product::read(in); in>>storageGB_>>dedicatedGPU_; }
void Laptop::print(std::ostream& out) const{ Product::print(out); out<<" STO="<<storageGB_; }
