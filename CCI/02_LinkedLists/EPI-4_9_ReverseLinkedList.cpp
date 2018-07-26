// Q. Give a linear time non-recursive function that reverses a singly linked list. The function
//    should use no more than constant storage beyond that needed for the list itself. The desired
//    transformation is illustrated in Figure 4.7 on page 48.

/* Check
1. The natural way of implementing the reversal is through recursion. However, this approach implicitly
uses O(n) space on the stack. The function is not tail recursive, which precludes compilers from 
automatically converting the function to an iterative one.

2. Reversal can be performed iteratively - walk the list with two pointers, and update the tailing pointer's
next field. It uses O(1) additional storage, and has O(n) time complexity.
*/

#include <memory>

using std::shared_ptr;
template <typename T> 
struct ListNode {
	T data;
	shared_ptr<ListNode<T>> next;
};

// Recursive Implementation
template<typename T>
shared_ptr<ListNode<T>> reverse_linked_listR(const shared_ptr<ListNode<T>> &head) {
	if(!head || !head->next) {
		return head;
	}

	shared_ptr<ListNode<T>> new_head = reverse_linked_list(head->next);
	head->next->next = head;
	head->next = nullptr;
	return new_head;
}

// Iterative Implementation
shared_ptr<ListNode<int>> reverse_linked_list(
    const shared_ptr<ListNode<int>>& head) {
  shared_ptr<ListNode<int>> prev = nullptr, curr = head;
  while (curr) {
    shared_ptr<ListNode<int>> temp = curr->next;	// temp storage 
    curr->next = prev;	// cur's next node is prev
    prev = curr;        // move pre to cur
    curr = temp;        // move cur to next
  }
  return prev;
}
