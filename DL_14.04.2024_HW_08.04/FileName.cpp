#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
    string name;
public:
    Item(const string& name) : name(name) {}
    string getName() const { return name; }
};

class Customer {
    string name;
    int age;
public:
    Customer(const string& name, int age) : name(name), age(age) {}
    void buyItem(const Item& item) {
        cout << name << " buying " << item.getName() << endl;
    }
};

class Shop {
    vector<Customer*> customers;
    vector<Item> items;
public:
    void addObserver(Customer* customer) {
        customers.push_back(customer);
    }
    void removeObserver(Customer* customer) {
        customers.erase(remove(customers.begin(), customers.end(), customer), customers.end());
    }
    void addItem(const Item& item) {
        items.push_back(item);
    }
    void sellItem(const Item& item) {
        for (auto& customer : customers) {
            customer->buyItem(item);
        }
    }
};

int main() {
    Shop shop;

    Customer customer1("Petro", 30);
    Customer customer2("Maria", 25);

    shop.addObserver(&customer1);
    shop.addObserver(&customer2);

    Item item1("PC");
    Item item2("ball");

    shop.addItem(item1);
    shop.addItem(item2);

    shop.sellItem(item1);

    shop.removeObserver(&customer1);

    shop.sellItem(item2);

    return 0;
}