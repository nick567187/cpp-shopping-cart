
#include "Cart.h"

Cart::Cart():total(0)
{

}

Cart::~Cart()
{

}

void Cart::addItemPrice(std::string item, int num) 
{
	prices[item] = num;
}


void Cart::addItem(std::string item) 
{
	std::map<std::string, int>::iterator priceItr = prices.find(item);
	if (priceItr == prices.end()) {
		throw std::exception("Invalid item. No price");
	}

	items[item] += 1;
}

int Cart::calculateTotal()
{
	total = 0;

	for (std::map<std::string, int>::iterator itemItr = items.begin(); itemItr != items.end(); itemItr++)
	{
		std::string item = itemItr->first;
		int count = itemItr->second;

		calculateItem(item, count);
	}

	return total;
}

void Cart::addDiscount(std::string item, int numItems, int discountPrice)
{
	discounts[item] = Discount{ numItems, discountPrice };
}

void Cart::calculateItem(std::string item, int count) 
{
	std::map<std::string, Discount>::iterator discountItr;
	discountItr = discounts.find(item);
	if (discountItr != discounts.end())
	{
		Discount discount = discountItr->second;
		calculateDiscount(item, count, discount);
	}
	else {
		total += count * prices[item];
	}
}

void Cart::calculateDiscount(std::string item, int count, Discount discount)
{
	if (count >= discount.numItems)
	{
		int numDiscounts = count / discount.numItems;
		total += numDiscounts * discount.discountPrice;
		int remainingItems = count % discount.numItems;
		total += remainingItems * prices[item];
	}
	else {
		total += count * prices[item];
	}
}

