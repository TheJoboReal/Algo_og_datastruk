#include <iostream>
#include <array>
#include <string>
#include <vector>

class Stack{
    private:
        std::vector<char> stack;
    public:
        void push(char c){
            stack.push_back(c);
        };
        char pop(){
            char c = stack.back();
            stack.pop_back();
            return c;
        };
        bool isEmpty(){
            if(stack.size() == 0){
                return true;
            }
            else return false;
        };
};


class CircularQueue {
    private:
        std::array<char, 5> queue;
        int front = 0;
        int rear = 0;
        int count = 0;

    public:
        void enqueue(char c) {
            if (count == queue.size()) {
                std::cout << "Queue is full. Cannot enqueue." << std::endl;
                return;
            }
            queue[rear] = c;
            rear = (rear + 1) % queue.size();
            count++;
        }

        char dequeue() {
            if (count == 0) {
                std::cout << "Queue is empty. Cannot dequeue." << std::endl;
                return '\0';
            }
            char c = queue[front];
            front = (front + 1) % queue.size();
            count--;
            return c;
        }

        bool isEmpty() {
            return count == 0;
        }

        bool isFull() {
            return count == queue.size();
        }
};

bool balPar(std::string text){
    // Returns true if paranthese are balanced.
    Stack s;
    for(int i = 0; i < text.size(); i++){
        if (text[i] == '('){
            s.push(text[i]);
        }
        else if(text[i] == ')'){
            if(s.isEmpty()){
                return false;
            }
            else{
                s.pop();
            }
        }
    }

    return true;
}



int main(){
    std::string text = "(()))";
    std::cout << balPar(text) << std::endl;
    return 0;
}