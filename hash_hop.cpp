#include <iostream>
#include <vector>



class HashtableHop {
    private:
        int _size;
        std::vector<char> _table;   
        std::vector<int> _hop;
    public:
        HashtableHop(int size) : _size(size), _table(size, 0), _hop(size, 0) {}
        void hashHop(char k, int r){
            int hash1 = k % _table.size();
            int hash2 = r - (k % r);
            for(int i = 0; i < _table.size(); i++){
                int probeIndex = (hash1 + i * hash2) % _table.size();
                if(_table[probeIndex] == 0){
                    _table[probeIndex] = k;
                    _hop[probeIndex] = i;
                    return;
                }
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

        int getHop(int N){
            return _hop[N];
        }

        void printHop(){
            for (int i = 0; i < _table.size(); i++) {
                if (_table[i] != 0) {
                    std::cout << i << "[" << _hop[i] << "], " << std::endl;
                } else {
                    std::cout << i << "[ ], " << std::endl;
                }
            }
            std::cout << std::endl;

        }
};

int main() {
    HashtableHop ht(13);
    ht.hashHop('a', 3);
    ht.hashHop('b', 7);
    ht.hashHop('c', 11);
    ht.hashHop('d', 7);
    ht.hashHop('e', 2);
    ht.hashHop('f', 7);
    ht.hashHop('g', 5);
    ht.hashHop('h', 9);
    ht.hashHop('i', 6);
    ht.hashHop('j', 7);
    ht.print();
    ht.printHop();
}