/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Dw10MLHBkuE
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
class Solution {
    
    static class Node {
        String val;
        String subFolder;
        Map<String, Node> children;

        Node(String val) {
            this.val = val;
            this.subFolder = "";
            this.children = new HashMap<>();
        }
    }

    private Node getNode(String val) {
        return new Node(val);
    }

    private void insert(Node root, List<String> path) {
        for (String folder : path) {
            root.children.putIfAbsent(folder, getNode(folder));
            root = root.children.get(folder);
        }
    }

    private String populateNodes(Node root, Map<String, Integer> subFolderMap) {
        List<Map.Entry<String, String>> subFolderPaths = new ArrayList<>();

        for (Map.Entry<String, Node> entry : root.children.entrySet()) {
            String subFolderResult = populateNodes(entry.getValue(), subFolderMap);
            subFolderPaths.add(new AbstractMap.SimpleEntry<>(entry.getKey(), subFolderResult));
        }

        subFolderPaths.sort(Comparator.comparing(Map.Entry::getKey));

        StringBuilder completePath = new StringBuilder();
        for (Map.Entry<String, String> entry : subFolderPaths) {
            completePath.append("(").append(entry.getKey()).append(entry.getValue()).append(")");
        }

        root.subFolder = completePath.toString();

        if (!completePath.toString().isEmpty()) {
            subFolderMap.put(completePath.toString(), subFolderMap.getOrDefault(completePath.toString(), 0) + 1);
        }

        return completePath.toString();
    }

    private void removeDuplicates(Node root, Map<String, Integer> subFolderMap) {
        Iterator<Map.Entry<String, Node>> it = root.children.entrySet().iterator();

        while (it.hasNext()) {
            Map.Entry<String, Node> entry = it.next();
            Node child = entry.getValue();

            if (!child.subFolder.isEmpty() && subFolderMap.get(child.subFolder) > 1) {
                it.remove();
            } else {
                removeDuplicates(child, subFolderMap);
            }
        }
    }

    private void construstResult(Node root, List<String> path, List<List<String>> result) {
        for (Map.Entry<String, Node> entry : root.children.entrySet()) {
            path.add(entry.getKey());
            result.add(new ArrayList<>(path));
            construstResult(entry.getValue(), path, result);
            path.remove(path.size() - 1);
        }
    }

    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        Node root = getNode("/");

        // Construct trie
        for (List<String> path : paths) {
            insert(root, path);
        }

        Map<String, Integer> subFolderMap = new HashMap<>();
        populateNodes(root, subFolderMap);

        removeDuplicates(root, subFolderMap);

        List<List<String>> result = new ArrayList<>();
        List<String> path = new ArrayList<>();
        construstResult(root, path, result);

        return result;
    }
}
