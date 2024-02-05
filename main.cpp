#include <iostream>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void printMenu(ShoppingCart& );

int main() {

    string customerName;
    string currentDate;
    cout << "Enter customer's name: " << endl;
    getline(cin,customerName);
    cout << "Enter today's date: " << endl;
    getline(cin,currentDate);
    cout << endl;

    ShoppingCart customerCart(customerName,currentDate);

    cout << "Customer name: " << customerCart.customerName() << endl;
    cout << "Today's date: " << customerCart.date() << endl;
    cout << endl;

    printMenu(customerCart);

    return 0;
}

void printMenu(ShoppingCart& custCart) {
    char custChoice;
    do {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option: " << endl;
        cin >> custChoice;

        bool isValid;
        if (custChoice == 'a' || custChoice == 'd' || custChoice == 'c' || custChoice == 'i' || custChoice == 'o' || custChoice == 'q') {
            isValid = true;
        }
        else {
            isValid = false;
        }
        if (!isValid) {
            do {
                cout << "Choose an option: " << endl;
                cin >> custChoice;
                if (custChoice == 'a' || custChoice == 'd' || custChoice == 'c' || custChoice == 'i' || custChoice == 'o' || custChoice == 'q') {
                    isValid = true;
                }
            } while (!isValid);
        }

        if (custChoice == 'o') {
            cout << endl;
            cout << "OUTPUT SHOPPING CART" << endl;
            custCart.printTotal();
            cout << endl;
        }
        if (custChoice == 'i') {
            cout << endl;
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            custCart.printDescriptions();
            cout << endl;
        }
        if (custChoice == 'a') {
            string itemName;
            string itemDescription;
            int itemPrice;
            int itemQuantity;
            cout << endl;
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin,itemName);
            cout << "Enter the item description: " << endl;
            getline(cin,itemDescription);
            cout << "Enter the item price: " << endl;
            cin >> itemPrice;
            cout << "Enter the item quantity: " << endl;
            cin >> itemQuantity;
            cout << endl;

            ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);
            custCart.addItem(newItem);
        }
        if (custChoice == 'd') {
            string itemToRemove;
            cout << endl;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl;
            cin.ignore();
            getline(cin,itemToRemove);
             
            custCart.removeItem(itemToRemove);
            cout << endl;
        }
        if (custChoice == 'c') {
            string itemName;
            int newQuantity;
            ItemToPurchase tempItem;
            cout << endl;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin,itemName);
            cout << "Enter the new quantity: " << endl;
            cin >> newQuantity;

            tempItem.setName(itemName);
            tempItem.setQuantity(newQuantity);
            custCart.modifyItem(tempItem);
            cout << endl;
        }

    } while (custChoice != 'q');
}