#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(string username) {
    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p) {
        if (u == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "❌ Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "✅ Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    bool found = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
        cout << "✅ Login successful!\n";
    else
        cout << "❌ Invalid username or password!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
