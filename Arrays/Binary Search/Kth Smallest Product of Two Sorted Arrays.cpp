/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=pjY5KaxYVIE
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary Search on Answer)
//T.C : O(log(maxP-minP) * n * log(m)
//S.C : O(1)
class Solution {
public:

    long long findCountSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct) {
        long long productsCount = 0;

        int n = nums2.size();

        for(int i = 0; i < nums1.size(); i++) {
            //nums1[i]

            if(nums1[i] >= 0) {
                int l = 0;
                int r = n-1;
                int m = -1; //invalid index on left hand side

                while(l <= r) {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) {
                        m = mid;
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
                productsCount += (m+1); //covered by nums1[i]
            } else {
                //product will be negative and right hand side will contain smaller products and left hand side larger
                int l = 0;
                int r = n-1;
                int m = n; //invalid index on the right hand side

                while(l <= r) {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) {
                        m = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                                                    
                productsCount += (n - m);
            }
        }
        return productsCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;

        long long l = -1e10; //min product possible
        long long r = 1e10; //max product possible

        while(l <= r) {
            long long midProduct = l + (r-l)/2;

            //check if this is kth smallest or not

            long long countSmallest = findCountSmallest(nums1, nums2, midProduct);

            if(countSmallest >= k) {
                result = midProduct;
                r = midProduct-1;
            } else {
                l = midProduct+1;
            }
        }
        return result;
    }
};




/****************************************************************** JAVA ******************************************************************/
//Approach (Binary Search on Answer)
//T.C : O(log(maxP-minP) * n * log(m)
//S.C : O(1)
class Solution {
    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        long left = -1_000_000_0000L; // -1e10
        long right = 1_000_000_0000L; // 1e10
        long result = 0;

        while (left <= right) {
            long midProduct = left + (right - left) / 2;
            long count = countLessEqual(nums1, nums2, midProduct);

            if (count >= k) {
                result = midProduct;
                right = midProduct - 1;
            } else {
                left = midProduct + 1;
            }
        }

        return result;
    }

    private long countLessEqual(int[] nums1, int[] nums2, long midProduct) {
        long count = 0;
        int n = nums2.length;

        for (int a : nums1) {
            if (a >= 0) {
                int l = 0, r = n - 1, pos = -1;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    long product = 1L * a * nums2[m];
                    if (product <= midProduct) {
                        pos = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                count += (pos + 1);
            } else {
                int l = 0, r = n - 1, pos = n;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    long product = 1L * a * nums2[m];
                    if (product <= midProduct) {
                        pos = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                count += (n - pos);
            }
        }

        return count;
    }
}
