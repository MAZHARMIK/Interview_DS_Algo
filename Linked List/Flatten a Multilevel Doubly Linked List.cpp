/*
    Company Tags  : Miscrosoft
    Leetcode Link : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

//Approach-1 (Using stack)
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        
        stack<Node*> st;
        Node* curr = head;
        
        while(curr) {
            if(curr->child == NULL) {
                curr = curr->next;
            } else {
                if(curr->next)
                    st.push(curr->next);
                
                Node* temp = curr->child;
                curr->child->prev = curr;
                curr->next = curr->child;
                curr->child = NULL;
                curr = temp;
            }
        }
        curr = head;
        while(!st.empty()) {
            while(curr && curr->next) {
                curr = curr->next;
            }
            Node* temp = st.top();
            st.pop();
            curr->next = temp;
            temp->prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};

//Approach-2 (Iterative)
class Solution {
public:
    Node* flatten(Node* head) {
        if( head == NULL) 
            return head;

        Node* curr = head; 
        while( curr!= NULL) {
            
            if( curr->child == NULL ) {
                curr = curr->next;
                continue;
            }
            Node* temp = curr->child;
            while( temp->next != NULL ) 
                temp = temp->next;
            temp->next = curr->next;  
            if( curr->next != NULL )  curr->next->prev = temp;
            curr->next = curr->child; 
            curr->child->prev = curr;
            curr->child = NULL;
        }
        return head;
    }
};

//Approach-3 (DFS-1)
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        Node* curr = head;
        while(curr && curr->child == NULL)
            curr = curr->next;
        if(!curr)
            return head;
        Node* flattenedChild = flatten(curr->child);
        if(flattenedChild)
            flattenedChild->prev = curr;
        Node* temp = curr->next;
        curr->next = flattenedChild;
        curr->child = NULL;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = temp;
        if(temp)
            temp->prev = curr;
        return head;
    }
};

//Approach-4 (DFS- Just another similar way)
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        
        Node* curr = head;
        if(curr->child == NULL) {
            flatten(curr->next);
            return head;
        }
        
        Node* nextSaved = curr->next;
        curr->next = flatten(curr->child);
        curr->child = NULL;
        
        if(curr->next)
            curr->next->prev = curr;
        else
            return head;
        
        while(curr->next) {
            curr = curr->next;
        }
        
        curr->next = nextSaved;
        if(nextSaved) {
            nextSaved->prev = curr;
        }
        
        return head;
    }
};
