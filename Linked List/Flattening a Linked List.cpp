/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=Q05ZTiqgBtw
    Company Tags                : 24*7 Innovation Labs, Amazon, Drishti-Soft, Flipkart, Goldman Sachs, Microsoft, Paytm, Payu, Snapdeal, Visa
    Leetcode Link               : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/

//Also Watch - Merge Two Sorted Lists - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Linked%20List/Merge%20Two%20Sorted%20Lists.cpp

/********************************************************** C++ **********************************************************/
//T.C : O(N*N*M) See my detailed video above to understand this.
//S.C : Auziliary Space = O(1) and O(N*M) – because of the recursion. 

// Function to merge two linked lists in sorted order
Node* mergeTwoLists(Node* head1, Node* head2) {
    // If one of the linked lists is empty, return the other
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node* result;
    // Compare the nodes and merge them in sorted order
    if (head1->data < head2->data) {
        result = head1;
        // Recursively merge the rest of the nodes
        result->bottom = mergeTwoLists(head1->bottom, head2); //Trust
    } else {
        result = head2;
        // Recursively merge the rest of the nodes
        result->bottom = mergeTwoLists(head1, head2->bottom); //Trust
    }

    return result;
}

Node *flatten(Node *head) {
    if(!head)
        return head;

    Node* temp = flatten(head->next);
    
    return mergeTwoLists(head, temp);
}


/********************************************************** JAVA **********************************************************/
//T.C : O(N*N*M) - See my detailed video above to understand this.
//S.C : Auziliary Space = O(1) and O(N*M) – because of the recursion . N*M is the total number of elements in the flattened linked List
class GfG {
    Node mergeTwoLists(Node head1, Node head2) {
        if (head1 == null)
            return head2;

        if (head2 == null)
            return head1;

        Node result;
        if (head1.data < head2.data) {
            result = head1;
            result.bottom = mergeTwoLists(head1.bottom, head2);
        } else {
            result = head2;
            result.bottom = mergeTwoLists(head1, head2.bottom);
        }

        return result;
    }

    Node flatten(Node root) {
        if (root == null)
            return root;

        Node temp = flatten(root.next);
        return mergeTwoLists(root, temp);
    }
}
