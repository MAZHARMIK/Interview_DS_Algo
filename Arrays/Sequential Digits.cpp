/*                                                    Scroll below for JAVA code also                             */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=E5XFO3-6xe4
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/sequential-digits/
*/

/************************************************************ C++ ******************************************************************/
//Approach-1 (Using simple BFS)
//T.C : O(N), where N is the number of valid sequential digits in the specified range.
//S.C : O(N), where N is the number of valid sequential digits in the specified range. (queue size)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        for(int i = 1; i <= 8; i++) {
            que.push(i);
        }
        
        vector<int> result;
        
        while(!que.empty()) {
            int temp = que.front();
            que.pop();
            
            if(temp >= low && temp <= high) {
                result.push_back(temp);
            }
            
            int last_digit = temp%10;
            if(last_digit + 1 <= 9) {
                que.push(temp * 10 +(last_digit + 1));
            }
        }
        
        return result;
    }
};


//Approach-2 (Using workaround)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> allPossible = {12, 23, 34, 45, 56, 67, 78, 89,
                          123, 234, 345, 456, 567, 678, 789,
                          1234, 2345, 3456, 4567, 5678, 6789,
                          12345, 23456, 34567, 45678, 56789,
                          123456, 234567, 345678, 456789,
                          1234567, 2345678, 3456789,
                          12345678, 23456789,
                          123456789};
        
        vector<int> result;
        
        int n = allPossible.size();
        
        for (int i = 0; i < n; i++) {
            if (allPossible[i] < low) continue;
            
            if (allPossible[i] > high) break;
            
            result.push_back(allPossible[i]);
        }
        return result;
    }
};


/************************************************************ JAVA ******************************************************************/
//Approach-1 (Using simple BFS)
//T.C : O(N), where N is the number of valid sequential digits in the specified range.
//S.C : O(N), where N is the number of valid sequential digits in the specified range. (queue size)
public class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= 8; i++) {
            queue.offer(i);
        }

        List<Integer> result = new ArrayList<>();

        while (!queue.isEmpty()) {
            int temp = queue.poll();

            if (temp >= low && temp <= high) {
                result.add(temp);
            }

            int lastDigit = temp % 10;
            if (lastDigit + 1 <= 9) {
                queue.offer(temp * 10 + (lastDigit + 1));
            }
        }

        return result;
    }
}


//Approach-2 (Using workaround)
//T.C : O(1)
//S.C : O(1)
public class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> allPossible = List.of(12, 23, 34, 45, 56, 67, 78, 89,
                                           123, 234, 345, 456, 567, 678, 789,
                                           1234, 2345, 3456, 4567, 5678, 6789,
                                           12345, 23456, 34567, 45678, 56789,
                                           123456, 234567, 345678, 456789,
                                           1234567, 2345678, 3456789,
                                           12345678, 23456789,
                                           123456789);

        List<Integer> result = new ArrayList<>();

        int n = allPossible.size();

        for (int i = 0; i < n; i++) {
            if (allPossible.get(i) < low) continue;

            if (allPossible.get(i) > high) break;

            result.add(allPossible.get(i));
        }
        return result;
    }
}
