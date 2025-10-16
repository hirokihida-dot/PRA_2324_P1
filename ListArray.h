#pragma once

#include <ostream>
#include <stdexcept>
#include <algorithm>
#include <string>

#include "List.h"

template <typename T>
class ListArray : public List<T>{

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;

    void bounds_check(int i);

	public:
     ListArray();
		~ListArray();
		T operator[](int pos);
		void resize(int new_size);		
		void insert (int pos, T e) override;
		void append (T e) override;
		void prepend(T e) override;
		T remove (int pos) override;
		T get (int pos) override;
		int search(T e) override;
		bool empty() override;
		int size() override;

		friend std::ostream& operator <<(std::ostream &out, const ListArray &list) {
      std::cout << "[";
      for (int i=0; i<list.n; i++){
          if (i != 0)
            std::cout << ", ";
          std::cout << list.arr[i];
      }
      std::cout << "]\n";
     return std::cout;

    }
};

template <typename T>
inline void ListArray<T>::bounds_check(int pos) {
  if (pos < 0){
    throw std::out_of_range(std::string("position ") + std::to_string(pos) + " is too low for index into ListArray");
  }
  if (pos >= n){
    throw std::out_of_range(std::string("position ") + std::to_string(pos) + " is too large for index into ListArray of size " + std::to_string(n));
  }
}


template <typename T>
inline ListArray<T>::ListArray(){
  arr = new T[MINSIZE] ();
  max = MINSIZE;
  n = 0;
}
template <typename T>
inline ListArray<T>::~ListArray(){
  delete[] arr;
}

template <typename T>
inline T ListArray<T>::operator[](int pos) {
  bounds_check(pos);
  return arr[pos];
}

template <typename T>
inline void ListArray<T>::resize(int new_size) 
{
  T* arr2 = new T[new_size] ();
  int n2 = std::min(new_size, n);
  std::copy(arr, arr + n2, arr2);
  delete[] arr;
  arr = arr2;
  max = new_size;
  n= n2;

}

	template <typename T>
inline	void ListArray<T>::insert (int pos, T e) 
{
  if (pos < 0){
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

	template <typename T>
inline	void ListArray<T>::append (T e) 
{
  if (n==max)
      resize(2*max);
  arr[n++]=e;
}

	template <typename T>
inline	void ListArray<T>::prepend(T e) 
{
  if (n==max)
      resize(2*max);
  std::copy_backward(arr, arr + n, arr+n+1);
  arr[0]=e;
  n++;
}

	template <typename T>
inline	T ListArray<T>::remove (int pos) 
{
  bounds_check(pos);

  T temp=arr[pos];
  std::copy(arr+pos+1, arr+n, arr+pos);
  n--;
  return temp;
}

	template <typename T>
inline	T ListArray<T>::get (int pos) 
{
  bounds_check(pos);
  return arr[pos];
}

	template <typename T>
inline	int ListArray<T>::search(T e) 
{
  for (int i=0;i<n;i++){
      if (arr[i]==e){
            return i;
      }
  }
  return -1;
}

	template <typename T>
inline	bool ListArray<T>::empty() 
{
  return n==0;
}

	template <typename T>
inline	int ListArray<T>::size() 
{
 return n;
}
