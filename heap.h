#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
  Heap(int m=2, PComparator c = PComparator()) : m_(m), comp_(c) {};

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

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
  std::vector<T> heap;
  int m_;
  PComparator comp_;
  
  // have to use two different member fxns, can't figure out how to make it in one
  void heapifyPush(size_t idx);
  void heapifyPop(size_t idx);


};

// Add implementation of member functions here
template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  heap.push_back(item); // slap item on back and we can sort after
  heapifyPush(heap.size()-1); // need special member fxn for this operation
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
    throw std::underflow_error("empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap.front();


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
    throw std::underflow_error("empty heap");

  }
  
  // follow heap algorithm and slap worst/bottom to the top after popping the top
  heap[0] = heap.back();
  heap.pop_back(); // can use vector fxn here 

  if(!empty()){
    heapifyPop(0); // start at top and work our way down to maintain heap prop
  }

}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return heap.empty(); // easy to use vector
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return heap.size(); // easy to use vector 
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyPush(){
  // just gonna walk through the whole thing
  while(idx > 0){
    size_t parent = (idx-1)/m_;
    if(comp_(heap[idx], heap[parent])){
      std::swap(heap[idx], heap[parent]); // swap if idx is better than its parent
      idx = parent;
    }
    else{
      break; // catch when child is not better, then we can stop
    }
  }
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyPop(){
  size_t first = m_ * idx+1;
  while(first < heap.size()){
    size_t best = first;
    for(size_t i = 1; i<m_ && first+i<heap.size(); ++i){
      size_t curr = first + i;
      if(comp_(heap[curr], heap[best])){
        best = curr;
      }
    }

    // mostly the same as heapifyPush but i can't abstract this i don't think?
    if(comp_(heap[best], heap[idx])){
      std::swap(heap[idx], heap[best]); // swap if idx is better than best
      idx = best;
      first = m_*idx+1; // walk forward
    }
    else{
      break; // catch when child is not better, then we can stop
    }
  }
}


#endif

