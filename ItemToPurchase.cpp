#include <iostream>
#include "ItemToPurchase.h"
using namespace std;

//name;
//price;
//quantity;


//constructors
ItemToPurchase::ItemToPurchase() {
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}
ItemToPurchase::ItemToPurchase(string n, string d, int p, int q) {
    _name = n;
    _price = p;
    _quantity = q;
    _description = d;
}

//mutators
void ItemToPurchase::setName(string userName) {
    _name = userName;
}
void ItemToPurchase::setPrice(int userPrice) {
    _price = userPrice;
}
void ItemToPurchase::setQuantity(int userQuantity) {
    _quantity = userQuantity;
}
void ItemToPurchase::setDescription(string userDescription) {
    _description = userDescription;
}




//accessors
string ItemToPurchase::name() const {
    return _name;
}
int ItemToPurchase::price() const{
    return _price;
}
int ItemToPurchase::quantity() const{
    return _quantity;
}
string ItemToPurchase::description() const {
    return _description;
}



//display functions
void ItemToPurchase::printItemCost() const {
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << (_price * _quantity) << endl;
}
void ItemToPurchase::printItemDescription() const {
    cout << _name << ": " << _description << endl;
}