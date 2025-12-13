#include <ostream>
#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:

            Node<T>* first;
            int n;

    public:

            ListLinked() override{
              first= nullptr;
              null=0;
            }

            ~ListLinked() override{
             while (first != nullptr){
              Node<T>* aux = first -> next;
              delete first;
              first=aux;
              }
             n=0;
            }

            T operator [](int pos) override{
              if (pos < 0 || pos >=n){
                throw std::out_of_range("operator[]: indice fuera de rango");
              }
              Node<T>* cur = first;
              for (int i=0; i<pos; i++)
                  cur = cur -> next;
              return cur -> data;
            }
          
            friend ostream& operator<<(ostream&out, const Listlinked<T>&list) override {
              out << list->first->data;
	            return out;
            }
}
            void insert(int pos, T e) override {
              if( pos < 0){
                     throw std::out_of_range(std::string("position ") + std::to_string(pos) + " is too low for index into ListArray");
              }
              if (pos > n){
                     throw std::out_of_range(std::string("position ") + std::to_string(pos) + " is too large for index into ListArray of size " + std::to_string(n));
              }
              if (n==max){
                 resize(2*max);
              }
              std::copy_backward(arr+pos,arr+n,arr+1);
              arr[pos]=e;
              n++;
            }

            void append(T e) override{
             insert (n, e);
            }

            void prepend(T e) override{
              insert (0, e);
            }
            
            T remove(int pos) override{
              if (pos < 0 || pos >= n){
          			throw std::out_of_range("Posición fuera de rango");
	          	}
	          	T removed_value = arr[pos];
		          for (int i = pos; i < n - 1; ++i){
			          arr[i] = arr[i + 1];
		          }
		          --n;
	          	if (n < max / 4 && max > MINSIZE){
			          resize(max / 2);
	          	}
		          return removed_value;
	          } 

            T get(int pos) override	{
	          	if (pos < 0 || pos >= n){
			          throw std::out_of_range("Posición fuera de rango");
		          }
		          return arr[pos];
	         }

           int search (T e) override{
            for (int i=0; i<n; ++i){
              if (arr[i] == e)
                return i;
            }  
           }

           bool empty() override{
	          return n == 0;
           }

           int size() override{
		        return n;
           }

           T operator[](int pos){
       		  if (pos < 0 || pos >= n){    {
			        throw out_of_range("Posición fuera de rango");
	        	}
	        	return arr[pos];
        	}
    
          void resize (int new_size){
            T* arr2 = new T[new_size] ();
            int n2 = std::min(new_size, n);
            std::copy(arr, arr + n2, arr2);
            delete[] arr;
            arr = arr2;
            max = new_size;
            n= n2;
          }

};
