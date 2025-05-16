/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=gX8KaRlkoN0
    Company Tags                : will soon update
*/

//This is an example code for Matrix Exponentiaon of Degree-2 recurrence relation. For example : F(n) = F(n-1) + F(n-2)

/****************************************************** C++ **************************************************************/
//T.C : O(log(n))
//S.C : O(1)
const int MOD = 1e9 + 7;
typedef vector<vector<long long>> Matrix;

// Function to multiply two matrices
Matrix matrixMultiplication(Matrix &A, Matrix &B) {
    Matrix result(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
    return result;
}

// Function to raise matrix base to the power exponent (Just like Binary exponentiation)
Matrix matrixExponentiation(const Matrix& base, int exponent) {
    if (exponent == 0) {
        Matrix identity{};
        for (int i = 0; i < 2; ++i) //making an Identity matrix
            identity[i][i] = 1;
        return identity;
    }

    Matrix half   = matrixExponentiation(base, exponent / 2);
    Matrix result = matrixMultiplication(half, half);

    if (exponent % 2 == 1)
        result = matrixMultiplication(result, base);

    return result;
}


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n == 0) {
        cout << "Fibonacci(" << n << ") = 0" << endl;
        return 0;
    }

    Matrix T = {{1, 1}, {1, 0}};
    Matrix mat = {{1}, {0}}; // Base case matrix: F(1) = 1, F(0) = 0

    Matrix Tn = matrixExponentiation(T, n - 1);
    Matrix result = multiplyMatrix(Tn, mat);

    cout << "Fibonacci(" << n << ") = " << result[0][0] << endl;
    return 0;
}



/****************************************************** JAVA **************************************************************/
//T.C : O(log(n))
//S.C : O(1)
public class FibonacciMatrixExponentiation {

    static final int MOD = 1_000_000_007;

    // Function to multiply two 2x2 matrices
    public static long[][] matrixMultiplication(long[][] A, long[][] B) {
        long[][] result = new long[2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
        return result;
    }

    // Function to perform matrix exponentiation
    public static long[][] matrixExponentiation(long[][] base, int exponent) {
        if (exponent == 0) {
            long[][] identity = new long[2][2];
            identity[0][0] = identity[1][1] = 1;
            identity[0][1] = identity[1][0] = 0;
            return identity;
        }

        long[][] half = matrixExponentiation(base, exponent / 2);
        long[][] result = matrixMultiplication(half, half);

        if (exponent % 2 == 1) {
            result = matrixMultiplication(result, base);
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = scanner.nextInt();

        if (n == 0) {
            System.out.println("Fibonacci(0) = 0");
            return;
        }

        long[][] T = {{1, 1}, {1, 0}};
        long[][] mat = {{1}, {0}};

        long[][] Tn = matrixExponentiation(T, n - 1);

        // Multiply Tn with base case matrix mat
        long result = (Tn[0][0] * mat[0][0] + Tn[0][1] * mat[1][0]) % MOD; //or you could call matrixMultiplication() as well

        System.out.println("Fibonacci(" + n + ") = " + result);
    }
}
