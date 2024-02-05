/*
    MY YOUTUBE VIDEO ON THIS Qn : If you want it, let me know. I will make it :-)
    Company Tags                : Zoho, Amazon, Microsoft
    GfG Link                    : https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1
*/

/****************************************************************** C++ ******************************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
    public:
    Node *sortedInsert(Node* head, int data) {
       Node *newNode = new Node(data);

        // Case 1: Insert into an empty list
        if (head == NULL)
        {
            newNode->next = newNode;
            return newNode;
        }

        Node *current = head;

        // Case 2: Insert at the beginning
        if (data < head->data) {
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            return newNode;
        }

        // Case 3: Insert in the middle or at the end
        while (current->next != head && current->next->data < data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        return head;
    }
};



/****************************************************************** C++ ******************************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
    public Node sortedInsert(Node head, int data) {
        Node newNode = new Node(data);

        // Case 1: Insert into an empty list
        if (head == null) {
            newNode.next = newNode;
            return newNode;
        }

        Node current = head;

        // Case 2: Insert at the beginning
        if (data < head.data) {
            while (current.next != head) {
                current = current.next;
            }
            current.next = newNode;
            newNode.next = head;
            return newNode;
        }

        // Case 3: Insert in the middle or at the end
        while (current.next != head && current.next.data < data) {
            current = current.next;
        }

        newNode.next = current.next;
        current.next = newNode;

        return head;
    }
}
