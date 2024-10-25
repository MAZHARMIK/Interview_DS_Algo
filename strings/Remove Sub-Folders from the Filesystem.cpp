/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KNXbtg9rtLQ
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using set and substring find)
//T.C : O(n*L^2)
//S.C : O(n) //You can consider the length of each character as well - O(n*L)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder), end(folder));
        vector<string> result;

        for(string& currFolder : folder) {
            bool isSubFolder = false;
            string tempFolder = currFolder;
            while(!currFolder.empty()) {
                size_t position = currFolder.find_last_of('/');

                currFolder = currFolder.substr(0, position);

                if(st.find(currFolder) != st.end()) {
                    //it means currFolder is a sub-folder
                    isSubFolder = true;
                    break;
                }
            }

            if(!isSubFolder) {
                result.push_back(tempFolder);
            }

        }

        return result;
    }
};


//Approach-2 (Using Sorting)
//T.C : O(n*logn) //You can consider the length of each character as well - O(n*L*logn)
//S.C : O(1)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;

        result.push_back(folder[0]); //sorted hai islie folder[0] ka koi parent nahi hoga
        //so it can never be a sub-folder

        for(int i = 1; i < folder.size(); i++) {

            string currFolder = folder[i];
            string lastFolder = result.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0) {
                result.push_back(currFolder);
            }
        }

        return result;

    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Using set and substring find)
//T.C : O(n*L^2)
//S.C : O(n) //You can consider the length of each character as well - O(n*L)
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        // Create a set from the folder array
        Set<String> folderSet = new HashSet<>(Arrays.asList(folder));
        List<String> result = new ArrayList<>();

        // Iterate over each folder in the array
        for (String currFolder : folder) {
            boolean isSubFolder = false;
            String tempFolder = currFolder;

            // Continue until currFolder is empty
            while (!currFolder.isEmpty()) {
                int position = currFolder.lastIndexOf('/');  // Find the last occurrence of '/'
                if (position == -1) break;  // Exit if there are no more '/' characters

                currFolder = currFolder.substring(0, position);  // Get the parent folder

                // Check if the parent folder exists in the set
                if (folderSet.contains(currFolder)) {
                    isSubFolder = true;  // It is a sub-folder
                    break;
                }
            }

            // If it's not a sub-folder, add it to the result list
            if (!isSubFolder) {
                result.add(tempFolder);
            }
        }

        return result;
    }
}


//Approach-2 (Using Sorting)
//T.C : O(n*logn) //You can consider the length of each character as well - O(n*L*logn)
//S.C : O(1)
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        // Sort the folder array lexicographically
        Arrays.sort(folder);
        List<String> result = new ArrayList<>();
        
        // The first folder can never be a sub-folder after sorting
        result.add(folder[0]);

        // Iterate through the sorted folders
        for (int i = 1; i < folder.length; i++) {
            String currFolder = folder[i];
            String lastFolder = result.get(result.size() - 1);
            lastFolder += "/";  // Add '/' to the last folder to check for sub-folder

            // If the current folder does not start with the last folder, it is not a sub-folder
            if (!currFolder.startsWith(lastFolder)) {
                result.add(currFolder);
            }
        }

        return result;
    }
}
