// Lab 24: GM3K2 
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <limits>
#include <cstdlib>
#include <set>
#include "Goat.h"

using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(const set<Goat> &trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string names[], string colors[]);
void display_trip(const set<Goat> &trip);
int main_menu();

// main method
int main() {
    srand(static_cast<unsigned>(time(0)));
    bool again = true; 

    // read & populate arrays for names and colors
    fstream fin("names.txt");
    string names[SZ_NAMES];
    if (!fin.is_open()) { // Check if file opens successfully
        cerr << "Error opening names.txt" << endl;
        return 1; // Exit or handle error accordingly
    }
    
    int i = 0;
    while (fin >> names[i] && i < SZ_NAMES) {
        i++;
    }
    fin.close();
    
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    if (!fin1.is_open()) { // Check if file opens successfully
        cerr << "Error opening colors.txt" << endl;
        return 1; // Exit or handle error accordingly
    }
    
    i = 0;
    while (fin1 >> colors[i] && i < SZ_COLORS) { // Use fin1 for reading colors
        i++;
    }
    fin1.close();

    set<Goat> trip; // Changed from list to set to manage goats
    do {
        int choice = main_menu();
        switch (choice) {
            case 1: 
                add_goat(trip, names, colors); 
                break;
            case 2: 
                delete_goat(trip); 
                break;
            case 3: 
                display_trip(trip); 
                break;
            case 4: 
                cout << "Goodbye!" << endl;
                again = false;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (again);

    return 0;
}

int main_menu() {
    int choice;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;

    // Validate the user input
    while(cin.fail() || choice < 1 || choice > 4) {
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid choice! Please try again: ";
        cin >> choice;
    }
    
    return choice;
}

void add_goat(set<Goat> &trip, string names[], string colors[]) {
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    int age = rand() % (MAX_AGE + 1);

    Goat newGoat(name, age, color);
    auto result = trip.insert(newGoat); // Try to insert and check if it was successful
    if (result.second) { // Insert was successful
        cout << "Added goat: " << newGoat << endl;
    } else {
        cout << "Goat already exists and was not added: " << newGoat << endl;
    }
}

void delete_goat(set<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats to delete!" << endl;
        return;
    }
    
    display_trip(trip);
    cout << "Select the name of the goat to delete: ";
    string name;
    cin.ignore();
    getline(cin, name); // Use getline to get entire line including spaces

    for (auto it = trip.begin(); it != trip.end(); ++it) {
        if (it->get_name() == name) { // Find goat by name
            trip.erase(it);
            cout << "Goat deleted!" << endl;
            return;
        }
    }
    
    cout << "No goat found with the name: " << name << endl;
}

void display_trip(const set<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats in trip!" << endl;
        return;
    }

    cout << "Current goats in the trip:" << endl;
    for (const Goat& goat : trip) {
        cout << goat << endl;
    }
}