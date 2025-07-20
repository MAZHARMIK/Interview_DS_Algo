/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/delete-duplicate-folders-in-system


/************************************************************ C++ ************************************************/
//Approach (Using trie)
//T.C : O(N * L * ClogC), N = total Paths, L = average length of each path, C is the average number of children per node
//S.C : ~O(N * L), we store all the paths in the trie, approximated value.
class Solution {
public:
    struct Node {
        string val; //name
        string subFolder; //subfolder structure
        unordered_map<string, Node*> children;
    };

    Node* getNode(string val) {
        Node* temp = new Node();
        temp->val = val;
        temp->subFolder = "";

        return temp;
    }

    void insert(Node* root, vector<string>& path) {
        for(auto& folder : path) {
            if(!root->children.count(folder)) {
                root->children[folder] = getNode(folder);
            }

            root = root->children[folder];
        }
    }

    string populateNodes(Node* root, unordered_map<string, int>& subFolderMap) {
        vector<pair<string, string>> subFolderPaths;

        for(auto &[childName, child] : root->children) {
            string subFolderResult = populateNodes(child, subFolderMap);
            subFolderPaths.push_back({childName, subFolderResult});
        }

        sort(begin(subFolderPaths), end(subFolderPaths));

        string completePath = "";//this is the subfolder of current root which we will form from children paths
        for(auto& [childName, childPath] : subFolderPaths) {
            completePath += "(" + childName + childPath + ")";
        }

        root->subFolder = completePath;

        if(!completePath.empty()) {
            subFolderMap[completePath]++;
        }

        return completePath;
    }

    void removeDuplicates(Node* root, unordered_map<string, int>& subFolderMap) {
        for(auto it = root->children.begin(); it != root->children.end(); ) {
            string childName = it->first;
            Node* child = it->second;

            if(!child->subFolder.empty() && subFolderMap[child->subFolder] > 1) {
                it = root->children.erase(it);
            } else {
                removeDuplicates(child, subFolderMap);
                it++;
            }
        }
    }

    void construstResult(Node* root, vector<string>& path, vector<vector<string>>& result) {
        for(auto& [childName, child] : root->children) {
            path.push_back(childName);
            result.push_back(path);
            construstResult(child, path, result);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = getNode("/");

        //Construct trie
        for(auto& path : paths) {
            insert(root, path);
        }

        unordered_map<string, int> subFolderMap;
        populateNodes(root, subFolderMap);

        removeDuplicates(root, subFolderMap);

        vector<vector<string>> result;
        vector<string> path;
        construstResult(root, path, result);

        return result;


    }
};




/************************************************************ JAVA ************************************************/
//Approach (Using trie)
//T.C : O(N * L * ClogC), N = total Paths, L = average length of each path, C is the average number of children per node
//S.C : ~O(N * L), we store all the paths in the trie, approximated value.
