#include <iostream>
#include <vector>
#include "ShoppingCart.h"
using namespace std;


//constructors
ShoppingCart::ShoppingCart() {
    _customerName = "none";
    _currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string custName, string currDate) {
    _customerName = custName;
    _currentDate = currDate;
}

//overloading
bool operator==(const ItemToPurchase& lhs, const string& rhs) {
    return (lhs.name() == rhs);
}
bool operator==(const ItemToPurchase& lhs, const ItemToPurchase& rhs) {
    return (lhs.name() == rhs.name());
}
ostream& operator<<(ostream& out, const ItemToPurchase& rhs) {
        out << rhs.name();
    return out;
}

//mutators
void ShoppingCart::addItem(ItemToPurchase newItem) {
    _cartItems.push_back(newItem);
}
void ShoppingCart::removeItem(string deleteItem) {
    bool isFound = false;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        if (_cartItems.at(i) == deleteItem) {
            _cartItems.erase(_cartItems.begin()+i);
            isFound = true;
        }
    }
    if (!isFound) { 
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}
void ShoppingCart::modifyItem(ItemToPurchase modItem) {
    bool isFound = false;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        if (_cartItems.at(i) == modItem ) {
            if (_cartItems.at(i).quantity() != 0) {
                _cartItems.at(i).setQuantity(modItem.quantity());
            }
            isFound = true;
        }
    }
    if (!isFound) { 
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}


//accessors
string ShoppingCart::customerName() const {
    return _customerName;
}
string ShoppingCart::date() const {
    return _currentDate;
}
int ShoppingCart::numItemsInCart() const {
    int totalItems = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        totalItems = totalItems + _cartItems.at(i).quantity();
    }
    return totalItems;
}
int ShoppingCart::costOfCart() const {
    int totalCost = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        totalCost = totalCost + (_cartItems.at(i).price() * _cartItems.at(i).quantity());
    }
    return totalCost;
}


//display
void ShoppingCart::printTotal() const {
    cout << _customerName << "\'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    if (numItemsInCart() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        _cartItems.at(i).printItemCost();
    }
    cout << endl;
    cout << "Total: $" << costOfCart() << endl;
}
void ShoppingCart::printDescriptions() const {
    cout << _customerName << "\'s Shopping Cart - " << _currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        _cartItems.at(i).printItemDescription();
    }
}

