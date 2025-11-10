#include <ostream>
#include <iostream>

template <typename T>

class Node{

    public:
            T data;
            Node<T>* next;
            //constructor
            Node(T data, Node<T>* next=nullptr): data(data), next(next){}
            //Operador de salida para imprirmir el nodo
            friend std::ostream& operator<<(std::ostream&out, const Node<T> &node){
                std::cout<<node.data;
                return std::cout;
            }
 };


