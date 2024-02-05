#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <vector>

class ShoppingCart {
    public:
    ShoppingCart();
    ShoppingCart(string, string);


    void addItem(ItemToPurchase newItem);
    void removeItem(string deleteItem);
    void modifyItem(ItemToPurchase modItem);


    string customerName() const;
    string date() const;
    int numItemsInCart() const;
    int costOfCart() const;

    
    void printTotal() const;
    void printDescriptions() const;

    friend ostream& operator<<(ostream& , const ItemToPurchase&);


    private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
};

bool operator==(const ItemToPurchase&, const string&);
bool operator==(const ItemToPurchase&, const ItemToPurchase&);

#endif