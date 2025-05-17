#include<iostream>
#include<cmath>
#include<cstring>
#include <vector>
#include <iomanip>
#include <stdexcept>
using namespace std;

int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    int fact = 1;
    for (int i = n; i > 1; i--) {
        fact *= i;
    }
    return fact;
}
int permu(int a, int b) {
    return fact(a) / fact(a - b);
}
// Function to calculate aCb
int combi(int a, int b) {
    return fact(a) / (fact(b) * fact(a - b));
}
// Truth table function declarations
void menu(int n, int u, int v);
int AND(int u, int v);
int OR(int u, int v);
int NAND(int u, int v);
int NOR(int u, int v);
int NOT(int u, int v);
int EX_OR(int u, int v);
int EX_NOR(int u, int v);
void TruthTable(const char* gateName, const char* rows[]);
void displayMainMenu();

// Matrix function declarations
void addition();
void subtraction();
void multiplication();
void determinantFunc();
void transpose();
void adj();
void inverseFunc();
void matrix();

// Other function declarations
void basic();
void trigonometri();
void truthtable();

int m, n; // Global variables for matrix dimensions

void displayMainMenu() {
    system("cls");
    cout << "0. Stop/Exit Truthtable\n";
    cout << "1. Conjunction (AND)\n";
    cout << "2. Disjunction (OR)\n";
    cout << "3. NAND\n";
    cout << "4. NOR\n";
    cout << "5. Negation (NOT)\n";
    cout << "6. Exclusive OR (EX_OR)\n";
    cout << "7. Exclusive NOR (EX_NOR)\n\n";
}

void TruthTable(const char* gateName, const char* rows[]) {
    cout << gateName << ") Truth Table:\n  A   |   B   |Output  \n --------------------\n";
    for (int i = 0; i < 4; i++) {
        cout << rows[i] << endl;
    }
    cout << rows[4] << endl << endl;
}

void menu(int n, int u, int v) {
    switch (n) {
        case 0: return;  
        case 1: AND(u, v); break;
        case 2: OR(u, v); break;
        case 3: NAND(u, v); break;
        case 4: NOR(u, v); break;
        case 5: NOT(u, v); break;
        case 6: EX_OR(u, v); break;
        case 7: EX_NOR(u, v); break;
        default: cout << "Invalid choice! Please select a valid option (1 to 7).\n"; break;
    }
}

int AND(int u, int v) {
    if (u == 1 && v == 1) {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nTRUE= 1\n";
    } else {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nFALSE= 0\n";
    }
    return 0;
}

int OR(int u, int v) {
    if (u == 1 || v == 1) {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nTRUE= 1\n";
    } else {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nFALSE= 0\n";
    }
    return 0;
}

int NAND(int u, int v) {
    if (!(u == 1 && v == 1)) {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nTRUE= 1\n";
    } else {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nFALSE= 0\n";
    }
    return 0;
}

int NOR(int u, int v) {
    if (!(u == 1 || v == 1)) {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nTRUE= 1\n";
    } else {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nFALSE= 0\n";
    }
    return 0;
}

int NOT(int u, int v) {
    if (u == 1) {
        cout << "The NEGATION of A is\nFALSE= 0\n";
    } else {
        cout << "The NEGATION of A is\nTRUE= 1\n";
    }
    if (v == 1) {
        cout << "The NEGATION of B is\nFALSE = 0\n";
    } else {
        cout << "The NEGATION of B is\nTRUE = 1\n";
    }
    return 0;
}

int EX_OR(int u, int v) {
    if ((u == 1 || v == 1) && !(u == 1 && v == 1)) {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nTRUE= 1\n";
    } else {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nFALSE= 0\n";
    }
    return 0;
}

int EX_NOR(int u, int v) {
    if ((u == 1 && v == 1) || !(u == 1 || v == 1)) {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nTRUE= 1\n";
    } else {
        cout << "\n\n\t*OUTPUT*\n\nLOGICAL CONCLUSION IS\nFALSE= 0\n";
    }
    return 0;
}

void basic(){
    float a,b;
    int n;

    cout << "1.add  |2.sub  |3.multi  |4.divide  |5. a^b  |6. (b√a) |7.permutation (a,b) |8.combination (a,b) \n";
    cout<<"Select operation: ";
    cin>>n;
    cout<<"Enter any two number: "<<endl;
    cin>>a>>b;
    switch (n) {
        case 0: return;
        case 1: cout << a << " + " << b << " = " << (a + b) << endl;
                break;
        case 2: cout << a << " - " << b << " = " << (a - b) << endl;
                break;
        case 3: cout << a << " × " << b << " = " << (a * b) << endl;
                break;
        case 4: if (b != 0) {
                cout << a << " ÷ " << b << " = " << (a / b) << endl;
                } else {
                cout << "Error: cannot divide by 0." << endl;
                }
                break;
        case 5: cout << a << "^" << b << " = " << pow(a, b) << endl;
                break;
        case 6: if (a < 0) {
                    cout << b << "√" << a << " = -" << pow(-a, 1.0/b) << endl;
                } else {
                    cout << b << "√" << a << " = " << pow(a, 1.0/b) << endl;
                }
                break;
        case 7: if(a < 0 || b < 0 || b > a) {
                cout << "Invalid input. Make sure 0 <= b <= a.\n";
                } else {
                cout << "permutation (aPb): " << permu(a, b) << endl;
                }
                break;
        case 8: if(a < 0 || b < 0 || b > a) {
                cout << "Invalid input. Make sure 0 <= b <= a.\n";
                } else {
                cout << "combination (aCb): " << combi(a, b) << endl;
                }
                break;

        default:
                cout << "Invalid selection\n";
    }
}

void trigonometri(){
    int n = 3;
    double x;
    cout<<"Enter x degree: ";
    cin>>x;
    x = x * 3.1415 / 180;
    cout << "1. sin(x)  |2. cos(x)  |3. tan(x)  |4. cosec(x)  |5. sec(x)  |6. cot(x)\n";
    cout<<"Select operation: ";
    cin>>n;
    switch (n) {
        case 1: cout<<"1.sin(x): "<<sin(x)<<endl;
                break;
        case 2: cout<<"2.cos(x): "<<cos(x)<<endl;
                break;
        case 3: cout<<"3.tan(x): "<<tan(x)<<endl;
                break;
        case 4: if (sin(x) != 0){
                cout << "cosec(x): " << 1 / sin(x) << endl;}
                break;
        case 5: if (cos(x) != 0){
                cout << "sec(x): " << 1 / cos(x) << endl;}
                break;
        case 6: if (tan(x) != 0){
                cout << "cot(x): " << 1 / tan(x) << endl;}
                break;       
        default:
                cout << "Invalid selection\n";
    }
}

void twoMatrices(int &m, int &n, int &p, int &q, int **&M, int **&N) {
    cout << "Enter order of matrix M (rows columns): \n";
    cin >> m >> n;
    
    // Allocate memory for matrix M
    M = new int*[m];
    for(int i = 0; i < m; i++) {
        M[i] = new int[n];
    }
    
    cout << "Enter elements of matrix M: \n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    
    cout << "Enter order of matrix N (rows columns): \n";
    cin >> p >> q;
    
    // Allocate memory for matrix N
    N = new int*[p];
    for(int i = 0; i < p; i++) {
        N[i] = new int[q];
    }
    
    cout << "Enter elements of matrix N: \n";
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < q; j++) {
            cin >> N[i][j];
        }
    }
}

void addition() {
    int m, n, p, q;
    int **M, **N;
    
    twoMatrices(m, n, p, q, M, N);
    
    if (m != p || n != q) {
        cout << "\nTheir sum is not possible\n";
        return;
    }
    
    cout << "\nSum of the matrices:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << (M[i][j] + N[i][j]) << "\t";
        }
        cout << "\n";
    }
    
    // Deallocate memory
    for(int i = 0; i < m; i++) delete[] M[i];
    delete[] M;
    for(int i = 0; i < p; i++) delete[] N[i];
    delete[] N;
}

void subtraction(){
    int m, n, p, q;
    int **M, **N;
    
    twoMatrices(m, n, p, q, M, N);
    
    if (m != p || n != q) {
        cout << "\nTheir subtraction is not possible\n";
        return;
    }
    
    cout << "\nSubtraction of the matrices:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << (M[i][j] - N[i][j]) << "\t";
        }
        cout << "\n";
    }
    
    // Deallocate memory
    for(int i = 0; i < m; i++) delete[] M[i];
    delete[] M;
    for(int i = 0; i < p; i++) delete[] N[i];
    delete[] N;   
}

void multiplication() {
    int m, n, p, q;
    int **M, **N;
    
    twoMatrices(m, n, p, q, M, N);
    
    if (n != p) {
        cout << "\nMatrix multiplication not possible (columns of M must match rows of N)\n";
        return;
    }
    
    // Allocate result matrix (m × q)
    int **C = new int*[m];
    for(int i = 0; i < m; i++) {
        C[i] = new int[q];
    }
    
    // Initialize result matrix to 0
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < q; j++) {
            C[i][j] = 0;
        }
    }
    
    // Perform multiplication
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < q; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] += M[i][k] * N[k][j];
            }
        }
    }
    
    cout << "\nProduct of the matrices:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << "\t";
        }
        cout << "\n";
    }
    
    // Deallocate memory
    for(int i = 0; i < m; i++) delete[] M[i];
    delete[] M;
    for(int i = 0; i < p; i++) delete[] N[i];
    delete[] N;
    for(int i = 0; i < m; i++) delete[] C[i];
    delete[] C;
}
// Global variables for matrix dimensions and data
int mat_rows, mat_cols;  // Renamed from m, n to avoid conflicts
vector<vector<float>> mat_data;  // Renamed from matrix to avoid conflicts

// Print any matrix
void printMatrix(const vector<vector<float>>& matrix) {
    for (const auto& row : matrix) {
        for (float val : row)
            cout << fixed << setprecision(1) << val << "\t";
        cout << endl;
    }
}

// Return a matrix after getting input
vector<vector<float>> oneMatrix() {
    cout << "Enter matrix dimensions (rows columns): ";
    cin >> mat_rows >> mat_cols;
    vector<vector<float>> matrix(mat_rows, vector<float>(mat_cols));
    cout << "Enter matrix elements row-wise:" << endl;
    for (int i = 0; i < mat_rows; ++i)
        for (int j = 0; j < mat_cols; ++j)
            cin >> matrix[i][j];

    cout << "\nOriginal Matrix:\n";
    printMatrix(matrix);
    return matrix;
}

// Calculate determinant of a matrix
float determinant(vector<vector<float>> matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0];

    float det = 0;
    for (int col = 0; col < n; ++col) {
        vector<vector<float>> submatrix(n - 1, vector<float>(n - 1));
        for (int i = 1; i < n; ++i) {
            int sub_col = 0;
            for (int j = 0; j < n; ++j) {
                if (j == col) continue;
                submatrix[i - 1][sub_col++] = matrix[i][j];
            }
        }
        float minor = determinant(submatrix);
        det += matrix[0][col] * minor * ((col % 2 == 0) ? 1 : -1);
    }
    return det;
}

void determinantFunc() {
    mat_data = oneMatrix();
    if (mat_rows == mat_cols) {
        float det = determinant(mat_data);
        cout << "\nDeterminant: " << det << endl;
    } else {
        cout << "\nDeterminant can only be calculated for square matrices.\n";
    }
}

// Calculate transpose of a matrix
vector<vector<float>> transposeMatrix(const vector<vector<float>>& matrix) {
    if (matrix.empty()) return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<float>> transposed(n, vector<float>(m));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            transposed[j][i] = matrix[i][j];
    return transposed;
}

void transpose() {
    mat_data = oneMatrix();
    vector<vector<float>> transposed = transposeMatrix(mat_data);
    cout << "\nTransposed Matrix:\n";
    printMatrix(transposed);
}

// Calculate cofactor matrix
vector<vector<float>> cofactor(const vector<vector<float>>& matrix) {
    int n = matrix.size();
    vector<vector<float>> cof(n, vector<float>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<vector<float>> submatrix;
            for (int k = 0; k < n; ++k) {
                if (k == i) continue;
                vector<float> row;
                for (int l = 0; l < n; ++l) {
                    if (l == j) continue;
                    row.push_back(matrix[k][l]);
                }
                submatrix.push_back(row);
            }
            float minor = determinant(submatrix);
            cof[i][j] = minor * (((i + j) % 2 == 0) ? 1 : -1);
        }
    }
    return cof;
}

// Calculate adjugate matrix
vector<vector<float>> adjugate(const vector<vector<float>>& matrix) {
    return transposeMatrix(cofactor(matrix));
}

void adj() {
    mat_data = oneMatrix();
    if (mat_rows != mat_cols) {
        cout << "\nAdjugate can only be calculated for square matrices.\n";
        return;
    }
    vector<vector<float>> cof = cofactor(mat_data);
    cout << "\nCofactor Matrix:\n";
    printMatrix(cof);
    vector<vector<float>> adj = adjugate(mat_data);
    cout << "\nAdjugate Matrix:\n";
    printMatrix(adj);
}

// Calculate inverse matrix
vector<vector<float>> inverse(const vector<vector<float>>& matrix) {
    float det = determinant(matrix);
    if (det == 0) throw runtime_error("Matrix is singular and cannot be inverted.");
    vector<vector<float>> adj = adjugate(matrix);
    int n = matrix.size();
    vector<vector<float>> inv(n, vector<float>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            inv[i][j] = adj[i][j] / det;
    return inv;
}

void inverseFunc() {
    mat_data = oneMatrix();
    if (mat_rows != mat_cols) {
        cout << "\nInverse can only be calculated for square matrices.\n";
        return;
    }
    try {
        vector<vector<float>> inv = inverse(mat_data);
        cout << "\nInverse Matrix:\n";
        printMatrix(inv);
    } catch (const runtime_error& e) {
        cout << "\nError: " << e.what() << endl;
    }
}


void Matrix() {
    int choice;
    cout << "1.addition  |2.subtraction  |3.multiplication  |4.determinant |5.transpose |6.adjugate |7.inverse\n";
    cout << "Select operation: ";
    cin >> choice;
    switch (choice) {
        case 1: addition();
                break;
        case 2: subtraction();
                break;
        case 3: multiplication();
                break;
        case 4: determinantFunc();
                break;
        case 5: transpose();
                break;
        case 6: adj();
                break;
        case 7: inverseFunc();
                break;
        default:
                cout << "Invalid selection\n";
    }
}

void truthtable(){
    int u, v;
    char g;
    int choice, t;

    const char* andRows[] = {
        "  0   |   0   |   0   ",
        "  0   |   1   |   0   ",
        "  1   |   0   |   0   ",
        "  1   |   1   |   1   ",
        " ___________________  "
    };

    const char* orRows[] = {
        "  0   |   0   |   0   ",
        "  0   |   1   |   1   ",
        "  1   |   0   |   1   ",
        "  1   |   1   |   1   ",
        " ___________________  "
    };

    const char* nandRows[] = {
        "  0   |   0   |   1   ",
        "  0   |   1   |   1   ",
        "  1   |   0   |   1   ",
        "  1   |   1   |   0   ",
        " ___________________  "
    };

    const char* norRows[] = {
        "  0   |   0   |   1   ",
        "  0   |   1   |   0   ",
        "  1   |   0   |   0   ",
        "  1   |   1   |   0   ",
        " ___________________  "
    };

    const char* notRows[] = {
        " -------- |   A` |  B`",
        " 0  |  0  |   1  |  1 ",
        " 0  |  1  |   1  |  0 ",
        " 1  |  0  |   0  |  1 ",
        " 1  |  1  |   0  |  0 "       
    };

    const char* xorRows[] = {
        "  0   |   0   |   0   ",
        "  0   |   1   |   1   ",
        "  1   |   0   |   1   ",
        "  1   |   1   |   0   ",
        " ___________________  "
    };

    const char* xnorRows[] = {
        "  0   |   0   |   1   ",
        "  0   |   1   |   0   ",
        "  1   |   0   |   0   ",
        "  1   |   1   |   1   ",
        " ___________________  "
    };

    while (true) {
        cout << "\t__--*****LOGICAL OPERATIONS*****--__" << endl;
        displayMainMenu();
        cout << "Select any operators (0 to exit): ";
     
        if (cin >> choice) {
            if (choice == 0) {
                return;
            }
            if (choice >= 1 && choice <= 7) {
                break;
            }
        } else {
            cout << "\nInvalid input! Please enter a valid operator (1 to 7).\n\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    }

    while (true) {
        cout << "\n\tBINARY VALUES FOR TWO INPUTS A & B\n";
        cout << "\nEnter '1' for true and '0' for false:\n\n";
        cin >> u >> v;

        if ((u == 1 || u == 0) && (v == 1 || v == 0)) {
            break;
        }
        cout << "\nInvalid inputs! Please enter '1' for true and '0' for false.\n\n";
    }

    menu(choice, u, v);

    cout << "\n\n\tDO YOU WANT TO KNOW TRUTH TABLE of logic gates?\n";
    cout << "\nEnter 'y' for yes or any other key to continue...\n";
    cin >> g;

    if (g == 'y' || g == 'Y') {
        displayMainMenu();
        cout << "Select operation for truth table (0 to exit): ";
        cin >> t;

        if (t == 1) {
            TruthTable("\nAND", andRows);
        } else if (t == 2) {
            TruthTable("\nOR", orRows);
        } else if (t == 3) {
            TruthTable("\nNAND", nandRows);
        } else if (t == 4) {
            TruthTable("\nNOR", norRows);
        } else if (t == 5) {
            TruthTable("\nNOT", notRows);
        } else if (t == 6) {
            TruthTable("\nEX-OR", xorRows);
        } else if (t == 7) {
            TruthTable("\nEX-NOR", xnorRows);
        }
    }
}

void other(){
    float x;
    int n;

    cout << "1.e^x  |2.ln x  |3.log x  |4. √x square root of x\n";
    cout<<"Select operation: ";
    cin>>n;
    cout<<"Enter any number: "<<endl;
    cin>>x;
    switch (n) {
        case 0: return;
        case 1: cout<<"e^x: "<<exp(x)<<endl;
                break;
        case 2: cout<<"ln x: "<<log(x)<<endl;
                break;
        case 3: cout<<"log x: "<<log10(x)<<endl;
                break;
        case 4: cout<<"√x square root: "<<sqrt(x)<<endl;
                break;
        default:
                cout << "Invalid selection\n";
    }
}
int main(){
    char choice;
    do {
        int n;
        cout << "\n1. Basic calculator\n";
        cout << "2. Trigonometric\n";
        cout << "3. Advanced\n";
        cout << "4. Matrix\n";
        cout << "5. Truth table\n";
        cout << "6. Other\n";
        cout << "Select calculator type: ";
        cin >> n;

        switch (n) {
            case 1:
                cout << "Basic calculator\n";
                basic();
                break;
            case 2:
                cout << "Trigonometric\n";
                trigonometri();
                break;
            case 3:
                cout << "Advanced\n";
                break;
            case 4:
                cout << "Matrix\n";
                Matrix();
                break;
            case 5:
                cout << "Truth table\n";
                truthtable();
                break;
            case 6:
                cout << "Other calculator\n";
                other();
                break;
            default:
                cout << "Invalid selection\n";
        }

        cout << "\nEnter y/n for next calculation: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
