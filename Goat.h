// Lab 24: GM3K2 
// COMSC-210 - Ibrahim Alatig 
// Goat.h

//       Goat
//-----------------
// - name: string 
// - age: int                         
// - color: string                     
//------------------
// + Goat()                           
// + Goat(n: string)                    
// + Goat(n: string, a: int)            
// + Goat(n: string, a: int, c: string) 
// + set_name(n: string): void          
// + get_name(): string                 
// + set_age(a: int): void              
// + get_age(): int                     
// + set_color(c: string): void         
// + get_color(): string                
// + operator<(g: Goat): bool           
// + friend operator<<(os: ostream&,    
// + goat: Goat): ostream& 

#ifndef GOAT_H
#define GOAT_H
#include <iostream>

using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat() : name(""), age(0), color("") {} // Default constructor

    Goat(string n) : name(n), age(0), color("") {} // Constructor with name

    Goat(string n, int a) : name(n), age(a), color("") {} // Constructor with name and age

    Goat(string n, int a, string c) : name(n), age(a), color(c) {} // Constructor with all parameters

    // setters and getters
    void set_name(string n) { name = n; }
    string get_name() const { return name; }
    void set_age(int a) { age = a; }
    int get_age() const { return age; }
    void set_color(string c) { color = c; }
    string get_color() const { return color; }

    // write overloaded < operator for the std::list
    bool operator<(const Goat& g) const {
        return name < g.name; // Sort based on the name
    }

    // Function to format the goat information
    friend ostream& operator<<(ostream& os, const Goat& goat) {
        os << goat.name << " (" << goat.age << ", " << goat.color << ")";
        return os;
    }
};

#endif