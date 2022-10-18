#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapVector;
  int _m;
  PComparator _c;
  void trickleUp(int loc);
  void heapify(int loc);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c):
  _m(m),
  _c(c)
{

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  heapVector.push_back(item);
  trickleUp(Heap<T,PComparator>::size()-1);	
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc){
	if (loc==0){
		return;
	}
  int parent=(loc+_m-1)/_m-1;
	
  while (_c(heapVector[loc],heapVector[parent]) && parent>=0) {		
		std::swap(heapVector[loc],heapVector[parent]);
		int temp=parent;
    loc=parent;
    parent=(temp+_m-1)/_m-1;    
		if (parent<0 || parent>=(int)heapVector.size()){
			break;
		}
	}
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("tried to get top of empty set");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapVector[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("tried to pop on empty set");
  }
	std::swap(heapVector[0],heapVector[Heap<T,PComparator>::size()-1]);
  heapVector.pop_back();
  heapify(0);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int loc) {
  int child=(loc+1)*_m-_m+1;
  if (child>(int)(Heap<T,PComparator>::size()-1)) {
    return;
  }
  int smallestChild=child;
  for (int i=0; i<_m;i++){
		if ((child+i)<(int)Heap<T,PComparator>::size())
		{
			if (_c(heapVector[child+i],heapVector[smallestChild])){
      	smallestChild=child+i;
    	}
		}
  }
  if (_c(heapVector[smallestChild],heapVector[loc])) {
    std::swap(heapVector[smallestChild],heapVector[loc]);
    heapify(smallestChild);
  }
}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  if (heapVector.size()==0){
    return true;
  } else {
    return false;
  }
}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return heapVector.size();
}

#endif