// Q. Find first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a 
//    data structure. NOTE: This is not necessariliy a binary search tree.

/* Check:
	1. With Links to Parent: Trace p and q's paths up until they intersect.
		But, it requres
			(a) being able to mark nodes as isVisited 	-> Additional storage
			(b) being able to store some data like Hash	-> Additional storage
	2. Without Links to Parent: follow a chain in which p and q are on the same side
		(a) if p and q are both on the left of the node, branch left to look for common ancestor
		(a) if p and q are both on the right of the node, branch right to look for common ancestor
*/
#include <map>
#include "BST_parent.h"

using namespace std;

// Simple version using hashTable
Node* first_ancestor(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    map<Node*, bool> m;
    while(n1){
        m[n1] = true;
        n1 = n1->parent;
    }
    while(n2 && !m[n2]){
        n2 = n2->parent;
    }
    return n2;
}

bool father(Node* n1, Node* n2){
    if(n1 == NULL) return false;
    else if(n1 == n2) return true;
    else return father(n1->lchild, n2) || father(n1->rchild, n2);
}

Node* first_ancestor1(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    while(n1){
        if(father(n1, n2)) return n1;
        n1 = n1->parent;
    }
    return NULL;
}

void first_ancestor2(Node* head, Node* n1, Node* n2, Node* &ans){
    if(head==NULL || n1==NULL || n2==NULL) return;
    if(head && father(head, n1) && father(head, n2)){
        ans = head;
        first_ancestor2(head->lchild, n1, n2, ans);
        first_ancestor2(head->rchild, n1, n2, ans);
    }
}

int main(){
    init();
    int a[] = {
        0, 1, 2, 3, 4, 5, 6
    };
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 6);
    Node *n1 = search(head, 0);
    Node *n2 = search(head, 4);
    cout<<n1->key<<" "<<n2->key<<endl;

    Node *ans = first_ancestor(n1, n2);
    cout<<ans->key<<endl;

    Node *ans1= first_ancestor1(n1, n2);
    cout<<ans1->key<<endl;
    
	Node *ans2 = NULL;
    first_ancestor2(head, n1, n2, ans2);
    cout<<ans2->key<<endl;
    return 0;
}
