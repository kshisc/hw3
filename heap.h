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
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){}

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
  bool empty() const{return vec_.empty();}

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const{return vec_.size();}

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> vec_;
  int m_;
  PComparator comp_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): m_(m), comp_(c) {} //constructor

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  vec_.push_back(item);

  //trickle up
  std::size_t index = size() - 1;
  while (index != 0) {
    std::size_t parenti = (index - 1) / m_;
    T& current = vec_[index];
    T& parent = vec_[parenti];
    if (comp_(parent,current)) {
        break;
    }
    std::swap(current, parent);
    index = parenti;
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
    throw std::out_of_range("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
    return vec_[0];
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
    throw std::out_of_range("Heap is empty");
  }

  std::swap(vec_[0], vec_[size()-1]);
  vec_.pop_back();

  //trickle down
  std::size_t index = 0;
	
	while(true){
		int curri = (m_*index)+1; //left child
		if (curri >= size()){
			break;
		}
		int besti=curri;
		for(int i=1; i<m_; ++i){
			curri++;
			if(curri<size() && comp_(vec_[curri], vec_[besti])){
				besti = curri;
			}
		}

		//swap with parent
		T& parent = vec_[index];
		T& child = vec_[besti];
		if (comp_(parent,child)){
			break; //done
		}
		std::swap(parent, child);
		index = besti;
	}
}

#endif

