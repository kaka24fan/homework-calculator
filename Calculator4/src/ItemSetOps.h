#pragma once
#include "Item.h"

#include<set>

std::set<Item> getClosure(std::set<Item> s, std::vector<Production> prods);

std::string isetToString(std::set<Item> s);
