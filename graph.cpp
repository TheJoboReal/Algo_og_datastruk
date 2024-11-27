#include <iostream>
#include <vector>
#include <string>
#include <array>

class Node{
    private:
        char _data;
        std::vector<Node*> children;

    public:
        Node(char val) : _data(val) {}

        void addChild(Node* child){
            children.push_back(child);
        }

        int getData(){
            return _data;
        }

        std::vector<Node*> getChildren(){
            return children;
        }
};


class AdjacencyMatrix{
    private:
        int _size;
        std::vector<std::vector<int>> _matrix;
        std::vector<Node> _nodes;

    public:
        AdjacencyMatrix(int size) : _size(size), _matrix(size, std::vector<int>(size, 0)) {}        // Constructor for AdjacencyMatrix class

        void addNode(Node node){
            _nodes.push_back(node);
        };

    void addEdge(int src, int dst){
        _matrix[src][dst] = 1;    // Set the edge between the two nodes
    };

    bool checkEdge(int src, int dst){
        // Check if there is an edge between the two nodes
        if(_matrix[src][dst] == 1){
            return true;
        }
        else{
            return false;
        }
    };

    void print(){

        std::cout<< "  ";
        for(int nodes = 0; nodes < _nodes.size(); nodes++){
            std::cout << static_cast<char>(_nodes[nodes].getData()) << " ";     // Print the nodes
        }
        std::cout << std::endl;

        for(int i = 0; i < _size; i++){
            std::cout << static_cast<char>(_nodes[i].getData()) << " ";
            for(int j = 0; j < _size; j++){
                std::cout << _matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    
    };

};

class AdjacencyList{
    private:
        std::vector<std::vector<Node>> _alist;

    public:

    void addEdge(int src, int dst){
        _alist[src].push_back(_alist[dst][0]);
    }

    void addNode(Node node){
        std::vector<Node> currentList;
        currentList.push_back(node);
        _alist.push_back(currentList);
    }

    bool checkEdge(int src, int dst){
        std::vector<Node> currentList = _alist[src];
        Node dstNode = _alist[dst][0];

        for(int node=0; node < currentList.size(); node++){
            if(currentList[node].getData() == dstNode.getData()){
                return true;
            }
        }
        return false;
    }

    void print(){
        std::cout << "hello" << std::endl;
        for(int i=0; i < _alist.size(); i++){
            std::cout << std::endl;
            for(int j=0; j < _alist[i].size(); j++){
                char current_node = _alist[i][j].getData() ;
                std::cout << static_cast<char>(current_node) << "->";
            }
        }
        std::cout << std::endl;
    }


};

int main(){
    AdjacencyMatrix g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addNode(Node('A'));
    g.addNode(Node('B'));
    g.addNode(Node('C'));
    g.addNode(Node('D'));
    g.addNode(Node('E'));
    std::cout << g.checkEdge(3, 1) << std::endl;
 
    g.print();
    
    // AdjacencyList l;
    // l.addNode(Node('A'));
    // l.addNode(Node('B'));
    // l.addNode(Node('C'));
    // l.addNode(Node('D'));
    // l.addNode(Node('E'));
    // l.addEdge(0, 1);
    // l.addEdge(0, 2);
    // l.addEdge(1, 3);
    // l.addEdge(1, 4);
    // l.addEdge(0, 4);
    // l.addEdge(4, 1);
    // std::cout << l.checkEdge(3, 1) << std::endl;
    // l.print();

    return 0;
}