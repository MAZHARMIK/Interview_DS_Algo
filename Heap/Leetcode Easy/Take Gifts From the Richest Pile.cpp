/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/take-gifts-from-the-richest-pile
*/


/************************************************************ C++ ************************************************/
//Approach (Using max-heap)
//T.C : O(n + k*logn)
//S.C : O(n)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        //Heapify - O(n)
        priority_queue<int> pq(begin(gifts), end(gifts)); //max-heap

        long long sum = 0;
        for(int &gift : gifts) { //O(n)
            sum += gift;
        }

        while(k--) { //O(k)
            int maxEl = pq.top(); //O(1)
            pq.pop(); //O(log(n))

            int remaining = sqrt(maxEl); //Ignoring this time complexity
            sum -= (maxEl - remaining);
            pq.push(remaining);//O(log(n))
        }

        return sum;

    }
};


/************************************************************ JAVA ************************************************/
//Approach (Using max-heap)
//T.C : O(n + k*logn)
//S.C : O(n)
public class Solution {

    public long pickGifts(int[] gifts, int k) {
        
        List<Integer> giftsList = new ArrayList<>();
        for (int gift : gifts) {
            giftsList.add(-gift);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(giftsList);
        while(k-- > 0) {
            
            int maxElement = -pq.poll();

            
            pq.offer(-(int) Math.sqrt(maxElement));
        }

        // Accumulate the sum of the elements in the heap
        long numberOfRemainingGifts = 0;
        while (!pq.isEmpty()) {
            numberOfRemainingGifts -= pq.poll(); //since it's negative, it will become positive with -ve sign
        }

        return numberOfRemainingGifts;
    }
}
