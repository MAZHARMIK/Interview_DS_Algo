/*                           Scroll below to see JAVA code also                  /*
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4eEWCQveqk8
    Company Tags                : VMWare, Amazon, Microsoft, Samsung, Hike, Ola Cabs, Goldman Sachs, Adobe, SAP Labs, Qualcomm, HSBC, Grofers, Target Corporation
    GFG Link                    : https://www.geeksforgeeks.org/problems/quick-sort/1
*/

/********************************************************************** C++ ******************************************************************************/
//T.C : O(nlogn) in Average case, O(n^2) in worst case
//S.C : O(1) Auxiliary space
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high) {
        if(low >= high) {
            return;
        }
        
        int pivotIndex = partition(arr, low, high);
        
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high) {
        int pivot      = arr[high];
        int pivotIndex = low;
        
        for(int i = low; i < high; i++) {
            if(arr[i] <= pivot) {
                swap(arr[i], arr[pivotIndex]);
                pivotIndex++;
            }
        }
        
        swap(arr[pivotIndex], arr[high]);
        
        return pivotIndex;
    }
};



/********************************************************************** JAVA ******************************************************************************/
//T.C : O(nlogn) in Average case, O(n^2) in worst case
//S.C : O(1) Auxiliary space
class Solution {
    // Function to sort an array using quick sort algorithm.
    static void quickSort(int arr[], int low, int high) {
        if (low >= high) {
            return;
        }

        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }

    static int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int pivotIndex = low;

        for (int i = low; i < high; i++) {
            if (arr[i] <= pivot) {
                swap(arr, i, pivotIndex);
                pivotIndex++;
            }
        }

        swap(arr, pivotIndex, high);

        return pivotIndex;
    }

    static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
