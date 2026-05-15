#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class menu {
public:
    string name;
    string details;
    double price;

    menu(string n, string d, double p) {
        name = n;
        details = d;
        price = p;
    }

    void displayfood() {
        cout << "\t" << name << "\t\t\t" << price << " tk" << endl;
        cout << "   " << details << endl;
    }
};

int main() {
    const int foodCount = 6;
    menu m[foodCount] = {
        menu("Chicken Burger", "Chicken patty, cheese, mayo", 250),
        menu("Beef Burger", "Beef patty, cheese, mayo", 350),
        menu("Spicy Pasta", "Chicken, mushroom, cheese", 280),
        menu("Spicy Ramen", "Sausage, mushroom, corn", 380),
        menu("Chicken Sandwich", "Bread, Chicken, Salad", 150),
        menu("Chicken Chowmein", "Noodles, Chicken, Egg", 200)
    };

    string rev[100];
    int revnum = 6;
    rev[0] = "Taslima: The food was awesome";
    rev[1] = "Rohan: Very delicious!!";
    rev[2] = "Shifa: Must try the spicy pasta :3";
    rev[3] = "Arina: Best food in the town";
    rev[4] = "Shafi: Try to improve the burger please -_-";
    rev[5] = "Lila: Food was good!!!";

    while (1) {
        cout << "\n\n\n\t\t\t\t  Welcome to kitty's kitchen (=^~^=)\n\t\t\t__________________________________________________" << endl;
        cout << "\nPress any key to continue...";
        cin.get();
        system("cls");

        int x;
        cout << "\n1. Restaurant Manager\n2. Customer\n3. Exit\n";
        cout << "Enter any option or press 3 to exit: ";
        cin >> x;
        system("cls");

        if (x == 1) {
            string pass;
            cout << "Enter password: ";
            cin.ignore();
            getline(cin, pass);
            if (pass == "pakipakapepekay") {
                cout << "Welcome Mr. Admin. Enter any option: \n\n";
            } else {
                cout << "Wrong password. Try again." << endl;
            }
        } else if (x == 2) {
            int cus;
            cout << "\n1. Menu\n";
            cout << "2. Review\n";
            cout << "3. Back\n";
            cout << "Enter any option or press 3 to exit: ";
            cin >> cus;
            system("cls");

            if (cus == 1) {
                char ch = 'Y';
                double total = 0;
                while (ch == 'Y' || ch == 'y') {
                    cout << "\nHello there.\nHere is the menu: \t\t\tPrice\n" << endl;
                    for (int i = 1; i <= foodCount; i++) {
                        cout << i << ". ";
                        m[i - 1].displayfood();
                        cout << endl;
                    }
                    cout << foodCount + 1 << ". Back\n" << endl;

                    int a, b;
                    cout << "Enter your choice (=^3^=)> ";
                    cin >> a;
                    if (a == foodCount + 1) break;
                    if (a < 1 || a > foodCount + 1) {
                        cout << "Invalid choice! Please select a valid menu item.\n";
                        continue;
                    }
                    cout << "Enter quantity: ";
                    cin >> b;
                    total += m[a - 1].price * b;

                    cout << "Do you want to add more? [Y/N]: ";
                    cin >> ch;
                }

                if (total > 0) {
                    string address;
                    cout << "Enter your location: ";
                    cin.ignore();
                    getline(cin, address);

                    if (address.empty()) {
                        cout << "Invalid address. Please try again.\n";
                        continue;
                    }

                    cout << "\nYour total order amount is: " << total << " tk.\n";
                    cout << "Your delivery will arrive soon at " << address << ".\n";
                    cout << "Thank you for your order!! <(=^~^=)>\n\n";
                } else {
                    cout << "No items ordered.\n";
                }
            } else if (cus == 2) {
                cout << "Here is our customer review (=^-^=)>> \n__________________________________________________\n\n";
                for (int i = 0; i < revnum; i++) {
                    cout << rev[i] << "\n\n";
                }

                cout << "Enter your comment here (First your name, then your comment): ";
                getline(cin >> ws, rev[revnum]);
                rev[revnum] = "User: " + rev[revnum];
                revnum++;

                system("cls");
                cout << "Updated Reviews:\n";
                for (int i = 0; i < revnum; i++) {
                    cout << rev[i] << "\n\n";
                }
            } else if (cus == 3) {
                continue;
            }
        } else if (x == 3) {
            cout << "See you next time ^~^\n" << endl;
            break;
        } else {
            cout << "INVALID INPUT!! Please enter again.\n";
        }
    }
    return 0;
}
