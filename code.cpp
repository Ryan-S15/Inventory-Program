#include <iostream>
#include <vector>
using namespace std;

struct Resistor {
    string id;
    string resistance;
    string tolerance;
    string power;
    int quantity;
    int minLevel;
};

vector<Resistor> inventory;

// Function to add a resistor
void addResistor() {
    Resistor r;
    cout << "Enter ID: ";
    cin >> r.id;
    cout << "Enter Resistance (ex: 1kΩ): ";
    cin >> r.resistance;
    cout << "Enter Tolerance (ex: ±5%): ";
    cin >> r.tolerance;
    cout << "Enter Power Rating (ex: 1/4W): ";
    cin >> r.power;
    cout << "Enter Quantity: ";
    cin >> r.quantity;
    cout << "Enter Minimum Level: ";
    cin >> r.minLevel;

    inventory.push_back(r);
    cout << "Resistor added!\n";
}

// Function to display inventory
void displayInventory() {
    cout << "\n--- Inventory ---\n";
    for (auto &r : inventory) {
        cout << "ID: " << r.id
             << " | " << r.resistance
             << " | Qty: " << r.quantity;

        if (r.quantity <= r.minLevel) {
            cout << " ⚠ LOW STOCK";
        }
        cout << endl;
    }
}

// Function to update quantity
void updateQuantity() {
    string id;
    int change;
    cout << "Enter ID to update: ";
    cin >> id;

    for (auto &r : inventory) {
        if (r.id == id) {
            cout << "Enter quantity change (+add, -remove): ";
            cin >> change;
            r.quantity += change;
            cout << "Updated! New quantity: " << r.quantity << endl;
            return;
        }
    }
    cout << "Item not found.\n";
}

// Function to show low stock
void showLowStock() {
    cout << "\n--- Low Stock Items ---\n";
    for (auto &r : inventory) {
        if (r.quantity <= r.minLevel) {
            cout << r.id << " (" << r.resistance << ") Qty: " << r.quantity << endl;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. Add Resistor\n";
        cout << "2. View Inventory\n";
        cout << "3. Update Quantity\n";
        cout << "4. Show Low Stock\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addResistor(); break;
            case 2: displayInventory(); break;
            case 3: updateQuantity(); break;
            case 4: showLowStock(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
