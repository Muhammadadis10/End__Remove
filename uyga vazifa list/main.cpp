#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int id;
    string data;
};

class Database {
private:
    vector<Element> elements;
public:

    void addElement(int id, string data) {
        elements.push_back({id, data});
    }

    void editElement(int id, string newData) {
        for (auto& elem : elements) {
            if (elem.id == id) {
                elem.data = newData;
                return;
            }
        }
        cout << "Element topilmadi!" << endl;
    }

    void removeElement(int id) {
        auto it = remove_if(elements.begin(), elements.end(), [&](const Element& elem) {
            return elem.id == id;
        });
        if (it != elements.end()) {
            elements.erase(it, elements.end());
        } else {
            cout << "Element topilmadi!" << endl;
        }
    }

    void printElements() {
        for (const auto& elem : elements) {
            cout << "ID: " << elem.id << ", Data: " << elem.data << endl;
        }
    }
};

int main() {
    Database db;

    db.addElement(1, "Data 1");
    db.addElement(2, "Data 2");
    db.addElement(3, "Data 3");

    cout << "Barcha elementlar:" << endl;
    db.printElements();

    db.editElement(2, "Yangi ma'lumot");

    cout << "Tahrirlangan elementlar:" << endl;
    db.printElements();

    db.removeElement(1);

    cout << "O'chirilgan elementlar:" << endl;
    db.printElements();

    return 0;
}
