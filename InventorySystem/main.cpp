#include <iostream>
#include <vector> 
#include <string>

using namespace std;

class Product {
public:
	string name;
	int amount;
	
	Product() {};
	Product(string productName, int productAmount) : name(productName), amount(productAmount) {};
};

class InventorySystem: public Product {
private:
	vector <Product> products;

public:
	InventorySystem() {};
	//Add the product in inventory
	void addProduct(string prodName, int amount) {
			products.emplace_back(prodName, amount);
	}

	void removeProduct(const std::string& productName) {
		for (auto it = products.begin(); it != products.end(); ++it) {
			if (it->name == productName) {
				products.erase(it);
				break;	
			}
		}
	}

	void displayInventory() {
		cout << "Your inventory:" << endl;
		for (const auto & product: products) {
			cout << "Item: " << product.name << ", Amount = " << product.amount << endl;
		}
	}
};

int main() {
	InventorySystem inv;
	
	inv.addProduct("Cheese", 1);
	inv.addProduct("Bread", 2);
	inv.addProduct("Dick", 100);

	inv.displayInventory();

	inv.removeProduct("Cheese");
	inv.displayInventory();
}
