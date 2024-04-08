/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=M0lhTkhUlp4
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
*/


/********************************************************* C++ ***************************************************/
//Approach-1 (Simply simulate whatever the problem asks for)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int len = students.size();
        queue<int> que;
        stack<int> st;

        for (int i = 0; i < len; i++) {
            st.push(sandwiches[len - i - 1]);
            que.push(students[i]);
        }

        int lastServed = 0;
        while (!que.empty() && lastServed < que.size()) {
            if (st.top() == que.front()) {
                st.pop();
                que.pop();
                lastServed = 0;
            } else {
                que.push(que.front());
                que.pop();
                lastServed++;
            }
        }

        return que.size();
    }
};


//Aproach-2 (Using counter only)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        int n = stud.size();
        int arr[2] = {0};
        //arr[0] = count of student who like circular
        //arr[1] = count of student who like square
          
        for(int &x : stud)
            arr[x]++;
        
        for(int i = 0; i<n; i++) {
            if(arr[sand[i]] == 0) return n-i;
            arr[sand[i]]--;
        }
        
        return 0;
    }
};



/********************************************************* JAVA ***************************************************/
//Approach-1 (Simply simulate whatever the problem asks for)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int len = students.length;
        Queue<Integer> que = new LinkedList<>();
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < len; i++) {
            st.push(sandwiches[len - i - 1]);
            que.add(students[i]);
        }

        int lastServed = 0;
        while (!que.isEmpty() && lastServed < que.size()) {
            if (st.peek() == que.peek()) {
                st.pop();
                que.poll();
                lastServed = 0;
            } else {
                que.add(que.peek());
                que.poll();
                lastServed++;
            }
        }

        return que.size();
    }
}


//Aproach-2 (Using counter only)
class Solution {
    public int countStudents(int[] stud, int[] sand) {
        int n = stud.length;
        int[] arr = new int[2];
        //arr[0] = count of student who like circular
        //arr[1] = count of student who like square
          
        for(int x : stud)
            arr[x]++;
        
        for(int i = 0; i < n; i++) {
            if(arr[sand[i]] == 0) return n - i;
            arr[sand[i]]--;
        }
        
        return 0;
    }
}
