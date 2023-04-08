/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=z7mPg_xT5xk
    Company Tags                : Google, Facebook, Amazon
    Leetcode Qn Link            : https://leetcode.com/problems/clone-graph/
*/

//Approach-1 (DFS) Using vector as map
class Solution {
public:
    
    void DFS(Node* node, Node* clone_node, vector<Node*>& visited) {
        visited[node->val] = clone_node;
        
        for(Node* x : node->neighbors) {
            if(visited[x->val] == NULL) {
                Node* clone = new Node(x->val);
                clone_node->neighbors.push_back(clone);
                DFS(x, clone, visited);
            } else {
                clone_node->neighbors.push_back(visited[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        //cloned the given node
        Node* clone_node = new Node(node->val);
        
        //Now, clone its neighbours and recursively their neighbours
        /*
            But if a node reappears, then we need to access that cloned node
            So, store them in a vector to access
        */
        
        vector<Node*> visited(101, NULL); //Using contraints given
        //We could use map also if constraints are not clear (i.e. unordered_map<Node*, Node*> visited;)
        visited[node->val] = clone_node;
        

        DFS(node, clone_node, visited);
 
        
        
        return clone_node;
    }
};

//Approach-2 DFS (Using unordered_map)
class Solution {
public:
    
    unordered_map<Node*, Node*> mp;
    
    void DFS(Node* node, Node* clone_node) {
        
        for(Node* n : node->neighbors) {
            
            if(mp.find(n) == mp.end()) {
                
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                
                DFS(n, clone);
                
            } else {
                
                clone_node->neighbors.push_back(mp[n]);
                
            }
            
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        mp.clear();
        
        //cloned the given node
        Node* clone_node = new Node(node->val);
        
        //Now, cloe its neighbours and recursively their newighbours
        /*
                But if a node reappears, then we need to access that cloned node
                So, store them in a map <Node*, Node*>
        */
        
        mp[node] = clone_node;
        
        DFS(node, clone_node);
        
        return clone_node;
    }
};


//Approach-3 (BFS) - Using vector as map
class Solution {
public:
    void BFS(queue<Node*>& que, vector<Node*>& visited) {
        while(!que.empty()) {
            Node* node = que.front();
            que.pop();
            
            //go for neighbors. Note that we are filling neighbors of "node"
            //if we find a neighbor, we need to push it's clone to the corresponding
            //cloned node's neighbors only(i.e. inside visited[x->val]->neighbors). See below for clarity
            for(Node* x : node->neighbors) {
                if(visited[x->val] == NULL) {
                    Node* clone = new Node(x->val);
                    visited[node->val]->neighbors.push_back(clone);
                    //i.e. adding cloned neighbors to cloned node
                    //adding this new node to visited as well for future access
                    visited[x->val] = clone;
                    que.push(x);
                } else {
                    visited[node->val]->neighbors.push_back(visited[x->val]);
                    //i.e. adding cloned neighbors to cloned node
                }
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        Node* clone_node = new Node(node->val);
        
        //similar to what we did above in DFS
        vector<Node*> visited(101, NULL);
        visited[node->val] = clone_node;
        
        queue<Node*> que;
        que.push(node);
        
        BFS(que, visited);
        
        return clone_node;
    }
};

//Approach-4 BFS (Using unordered_map)
class Solution {
public:
    
    unordered_map<Node*, Node*> mp;
    
    void DFS(Node* node, Node* clone_node) {
        
        for(Node* n : node->neighbors) {
            
            if(mp.find(n) == mp.end()) {
                
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                
                DFS(n, clone);
                
            } else {
                
                clone_node->neighbors.push_back(mp[n]);
                
            }
            
        }
        
    }
    
    void BFS(queue<Node*> &que) {
        
        while(!que.empty()) {
            
            Node* node = que.front();
            Node* clone_node = mp[node];
            que.pop();
            
            for(Node* n : node->neighbors) {
            
                if(mp.find(n) == mp.end()) {

                    Node* clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);

                    //DFS(n, clone);
                    que.push(n);

                } else {

                    clone_node->neighbors.push_back(mp[n]);

                }
            
            }
            
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        mp.clear();
        
        //cloned the given node
        Node* clone_node = new Node(node->val);
        
        //Now, cloe its neighbours and recursively their newighbours
        /*
                But if a node reappears, then we need to access that cloned node
                So, store them in a map <Node*, Node*>
        */
        
        mp[node] = clone_node;
        
        queue<Node*> que;
        que.push(node);
        BFS(que);
        
        return clone_node;
    }
};
