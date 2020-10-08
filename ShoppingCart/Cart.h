#pragma once

#include <string>
#include <map>

class Cart
{
public:
	Cart();
	virtual ~Cart();

	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	void addDiscount(std::string item, int numItems, int discountPrice);
	int calculateTotal();

protected:
	struct Discount {
		int numItems;
		int discountPrice;
	};

	std::map<std::string, int> prices;
	std::map<std::string, int> items;
	std::map<std::string, Discount> discounts;
	int total;

	void calculateItem(std::string item, int count);
	void calculateDiscount(std::string item, int count, Discount discount);
};