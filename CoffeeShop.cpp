// CoffeeShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;
using std::cout;
using std::cin;
#include <cctype>
using std::tolower;
using std::endl;

enum Name { Coffee, Tea, Sandwich, Burger };


class Product
{
public:
	
	float price;
	Name daName;
	string name;

	Product(Name lename)
	{
		daName = lename;
		if (daName == Coffee)
		{
			name = "coffee";
			price = 2.15;
		}
		else if (daName == Tea)
		{
			price = 2.75;
			name = "tea";
		}
		else if (daName == Sandwich)
		{
			name = "sandwich";
			price = 2.50;
		}
		else
		{
			name = "burger";
			price = 5.25;
		}
	}
};

string getInput()
{
	string input = " ";
	cout << "Please type what product you'd like." << endl;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	if (input != "coffee" && input != "tea" && input != "sandwich" && input != "burger")
	{
		cout << "That is not a valid input, please trying again." << endl;
		getInput();
	}
	return input;
}

Product addToCart(string input, vector<Product> theProducts)
{
	Product product = Product(Coffee);
	if (input == "coffee")
	{
		product = Product(Coffee);
	}
	else if (input == "tea")
	{
		product = Product(Tea);
	}
	else if (input == "sandwich")
	{
		product = Product(Sandwich);
	}
	else 
	{
		product = Product(Burger);
	}
	return product;
	
}

float AddTotal(vector<Product> shoppingCart)
{
	float total = 0;
	for (int i = 0; i < shoppingCart.size(); i++)
	{
		total += shoppingCart[i].price;
	}
	return total;
}

bool determineZero(int val)
{
	if (val == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void listShoppingCart(vector<Product> shoppingCart)
{
	int coffeeCount = 0;
	int sandwichCount = 0;
	int teaCount = 0;
	int burgerCount = 0;
	cout << "Your shopping cart: " << endl;
	for (int i = 0; i < shoppingCart.size(); i++)
	{
		if (shoppingCart[i].daName == Coffee)
		{
			coffeeCount++;
		}
		else if (shoppingCart[i].daName == Tea)
		{
			teaCount++;
		}
		else if (shoppingCart[i].daName == Sandwich)
		{
			sandwichCount++;
		}
		else
		{
			burgerCount++;
		}
	}
	if (!determineZero(burgerCount))
	{
		cout << "Burger(s) " << burgerCount << endl;
	}
	if (!determineZero(sandwichCount))
	{
		cout << "Sandwich(es) " << sandwichCount << endl;
	}
	if (!determineZero(teaCount))
	{
		cout << "Tea(s) " << teaCount << endl;
	}
	if (!determineZero(coffeeCount))
	{
		cout << "Coffee(s) " << coffeeCount << endl;
	}
}


void listInventory(vector<Product> theProducts)
{
	for (int i = 0; i < theProducts.size(); i++)
	{
		cout << "We have " << theProducts[i].name << " for $" << theProducts[i].price << endl;
	}
}


int main()
{
	float total = 0;
	vector<Product> products = vector<Product>();
	Product exSandwich = Product(Sandwich);
	Product exTea = Product(Tea);
	Product exCoffee = Product(Coffee);
	Product exBurger = Product(Burger);

	products.push_back(exCoffee);
	products.push_back(exTea);
	products.push_back(exBurger);
	products.push_back(exSandwich);

	vector<Product> shoppingCart = vector<Product>();

	string input = " ";
	string cont = " ";
	
	while (cont != "n")
	{
		listInventory(products);
		input = getInput();
		shoppingCart.push_back(addToCart(input, products));
		cout << "Would you like to continue? (y/n)" << endl;;
		cin >> cont;
	}

	listShoppingCart(shoppingCart);
	total = AddTotal(shoppingCart);
	cout << "Your total is " << total << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
