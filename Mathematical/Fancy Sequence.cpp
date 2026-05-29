/*             SCROLL BELOW TO SEE JAVA CODE                */
/*
	    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=O306K1S7A8U
    	Company Tags  		          : will update later
    	Leetcode Link 		          : https://leetcode.com/problems/fancy-sequence/description/
*/



/****************************************************** C++ **************************************************************/
//Approach - Simple maths + Binary Exponentiation and Fermat's Little Theorem
//T.C : O(log(M)) for Binary Exponentiation power(mult, M-2)
//S.C : O(1)
class Fancy {
public:
    typedef long long ll;

    ll M = 1e9+7;

    vector<ll> seq;
    ll add = 0;
    ll mult = 1;

    //Binary Exponentiation for Fermat's Little Theorem -> power(mult, M-2);
    long long power(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half   = power(a, b/2);
        long long result = (half * half) % M;

        if(b%2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    Fancy() {
        
    }
    
    void append(int val) {
        long long x = ((val - add) % M + M) * power(mult, M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % M;
    }
    
    void multAll(int m) {
        mult = (mult * m) % M;
        add  = (add * m) % M;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())
            return -1;

        return (seq[idx]*mult + add) % M;
    }
};



/****************************************************** JAVA **************************************************************/
//Approach - Simple maths + Binary Exponentiation and Fermat's Little Theorem
//T.C : O(log(M)) for Binary Exponentiation power(mult, M-2)
//S.C : O(1)
class Fancy {
    long M = 1_000_000_007;

    List<Long> seq = new ArrayList<>();
    long add = 0;
    long mult = 1;

    long power(long a, long b) {
        if (b == 0)
            return 1;

        long half   = power(a, b / 2);
        long result = (half * half) % M;

        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    public Fancy() {

    }

    public void append(int val) {
        long x = ((val - add) % M + M) * power(mult, M - 2) % M;
        seq.add(x);
    }

    public void addAll(int inc) {
        add = (add + inc) % M;
    }

    public void multAll(int m) {
        mult = (mult * m) % M;
        add  = (add * m) % M;
    }

    public int getIndex(int idx) {
        if (idx >= seq.size())
            return -1;

        return (int) ((seq.get(idx) * mult + add) % M);
    }
}
