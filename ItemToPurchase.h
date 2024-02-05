#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

using namespace std;

class ItemToPurchase {
    public:
    ItemToPurchase();
    ItemToPurchase(string , string , int , int);


    void setName(string userName);
    void setPrice(int userPrice);
    void setQuantity(int userQuantity);
    void setDescription(string userDescription);
    

    string name() const;
    int price() const;
    int quantity() const;
    string description() const;
    

    
    void printItemCost() const;
    void printItemDescription() const;
   

    private:
    string _name;
    int _price;
    int _quantity;
    string _description;
};

#endif