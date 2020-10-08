#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Cart.h"

TEST_CASE("Cart")
{
	Cart c;
	SECTION("Can calculate total")
	{
		c.addItemPrice("a", 1);
		c.addItem("a");
		int total = c.calculateTotal();
		REQUIRE(total == 1);
	}

	SECTION("Can calculate total for multiple items")
	{
		c.addItemPrice("a", 1);
		c.addItemPrice("b", 2);
		c.addItem("a");
		c.addItem("b");
		int total = c.calculateTotal();
		REQUIRE(total == 3);
	}

	SECTION("Can add discount")
	{
		c.addDiscount("a", 3, 2);
	}

	SECTION("Can calculate total w/ discount")
	{
		c.addItemPrice("a", 1);
		c.addDiscount("a", 3, 2);
		c.addItem("a");
		c.addItem("a");
		c.addItem("a");
		int total = c.calculateTotal();
		REQUIRE(total == 2);
	}

	SECTION("Item with no price throws exception")
	{
		REQUIRE_THROWS(c.addItem("a"));
	}
}