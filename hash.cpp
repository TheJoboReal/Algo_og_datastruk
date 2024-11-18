#include <iostream>
#include <array>
#include <cmath>
#include <vector>

class Hashtable {
private:
    int _size;
    std::vector<char> _table;        // Change type to char or int for differen scenarios.

public:
    Hashtable(int size) : _size(size), _table(size, 0) {}

    int loadFactor() {
        int count = 0;
        for (int i = 0; i < _table.size(); i++) {
            if (_table[i] != 0) {
                count++;
            }
        }
        return static_cast<int>(static_cast<double>(count) / _table.size() * 100);
    }

    void hashQuad(char k) {
        // Using quadratic probing
        int index = k % _table.size(); // Hash function
        int i = 0;
        while (_table[(index + i) % _table.size()] != 0) { // Quadratic probing
            i++;
            i += i * i;
        }
        _table[(index + i) % _table.size()] = k; // Push the key to the table
        std::cout << "Loadfactor now at :" << loadFactor() << "%" << std::endl;
    }

    void hashQuadPlace(char k, int index) {
        // Using quadratic probing
        int i = 0;
        while (_table[(index + i) % _table.size()] != 0) { // Quadratic probing
            i++;
            i += i * i;
        }
        _table[(index + i) % _table.size()] = k; // Push the key to the table
        std::cout << "Loadfactor now at :" << loadFactor() << "%" << std::endl;
    }

    void place(char k, int index){
        _table[index] = k;
    }

    void hashLin(char k){
        // Using Linear Probing
        int index = k % _table.size(); // Hash function
        for(int i = 0; i < _table.size(); i++){
            int probeIndex = (index + i) % _table.size();
            if(_table[probeIndex] == 0){
                _table[probeIndex] = k;
                std::cout << "Loadfactor now at :" << loadFactor() << "%" << std::endl;
                return;
            }
        }
    }

    void hashDouble(char k, int r){
        // Using Double Hashing
        int hash1 = k % _table.size();
        int hash2 = r - (k % r);
        for(int i = 0; i < _table.size(); i++){
            int probeIndex = (hash1 + i * hash2) % _table.size();
            if(_table[probeIndex] == 0){
                _table[probeIndex] = k;
                std::cout << "Loadfactor now at :" << loadFactor() << "%" << std::endl;
                return;
            }
        }
    }

    void hashSep(char k){
        // Using Separate Chaining.
        int index = k % _table.size();
        if(_table[index] == 0){
            _table[index] = k;
        } else {
            std::vector<char> chain;
            chain.push_back(_table[index]);
            chain.push_back(k);
            _table[index] = chain[0];
            std::cout << "Loadfactor now at :" << loadFactor() << "%" << std::endl;
        }
    }

    void print() {
        for (int i = 0; i < _table.size(); i++) {
            if (_table[i] != 0) {
                if (std::isprint(_table[i])) {      // Check if the character is printable
                    std::cout << i << "[" << _table[i] << "], " << std::endl;
                } else {
                    std::cout << i << "[" << static_cast<int>(_table[i]) << "], " << std::endl;     // Print the ASCII value
                }
            } else {
                std::cout << i << "[ ], " << std::endl;
            }
        }
        std::cout << std::endl;
    }
};

int main(){
    Hashtable h(11);
    h.print();
    h.place('V', 2);
    h.print();
    h.place('R', 3);
    h.print();
    h.place('P', 6);
    h.print();
    h.place('E', 8);
    h.print();
    h.place('F', 10);
    h.print();
    h.hashQuadPlace('Q', 7);
    h.print();
    h.hashQuadPlace('C', 8);
    h.print();
    h.hashQuadPlace('H', 2);
    h.print();

    return 0;
}
