#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// included here to avoid switching tabs back and forth, ignore for graders
/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  // base case when list is empty
  if(head == nullptr){
    return;
  }

  // might need this? not super sure
  // make Node ptr to maintain list order
  //Node* tmp = head;

  // place current item in correct list
  if(head->val <= pivot){
    if(smaller == nullptr){
      smaller = head;
    }
    else{
      smaller->next = head;
    }
  }
  else if (head->val > pivot){
    if(larger == nullptr){
      larger = head;
    }
    else{
      larger->next = head;
    }
  }

  // done processing, time to go back 
  return llpivot(head->next, smaller, larger, pivot);
  head = nullptr;
}

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */

 template<typename Comp>
Node* llfilter(Node* head, Comp pred){
  if(head == nullptr){
    return nullptr;
  }

  Node* tmp = head->next;
  if(pred(head->val) == true){
    delete head;
    head = tmp;
  }
  else{
    return head;
  }

  return llfilter(head, pred);
}