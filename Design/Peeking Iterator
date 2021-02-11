/*
    Company Tags  : Apple
    Leetcode Link : https://leetcode.com/problems/peeking-iterator/
*/


class PeekingIterator : public Iterator {
public:
    bool has_next = false;
    int  nextVal;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        has_next = Iterator::hasNext();
        if(has_next)
            nextVal = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextVal;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int currVal = nextVal;
        
        has_next = Iterator::hasNext();
        if(has_next) {
            nextVal = Iterator::next();
        }
        
        return currVal;
	}
	
	bool hasNext() const {
	    return has_next;
	}
};
