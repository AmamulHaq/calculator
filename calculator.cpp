#include<iostream>
#include<math.h>
#include<string.h>
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
//truth table
void menu(int n, int u, int v);
int AND(int u, int v);
int OR(int u, int v);
int NAND(int u, int v);
int NOR(int u, int v);
int NOT(int u, int v);
int EX_OR(int u, int v);
int EX_NOR(int u, int v);
void TruthTable(const char* gateName, const char* rows[]);
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
    for (int i = 0; i < 5; i++) {
        cout << rows[i] << endl;
    }
    cout << endl;
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
    cout<<"Enter any two number: "<<endl;
    cin>>a>>b;
    cout << "1.add  |2.sub  |3.multi  |4.divide\n";

    cout<<"Select operation: ";
    cin>>n;
    switch (n) {
        case 0: return;
        case 1: cout<<"add: "<<(a+b)<<endl;
                break;
        case 2: cout<<"sub: "<<(a-b)<<endl;
                break;
        case 3: cout<<"multi: "<<(a*b)<<endl;
                break;
        case 4: cout<<"div: "<<(a/b)<<endl;
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
        cout << "\nTheir sum is not possible\n";
        return;
    }
    
    cout << "\nSum of the matrices:\n";
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
void oneMatrix(){
    int m,n;
    int a[m][n];
    cout<<"Enter elements of matrix A: \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}
void transpose(){
    
}
void inverse(){
    
}
void matrix(){
    int n;
    cout << "1.addition  |2.subtraction  |3.multiplication  |4. transpose |5.inverse\n";

    cout<<"Select operation: ";
    cin>>n;
    switch (n) {
        case 1: addition();
                break;
        case 2: subtraction();
                break;
        case 3: multiplication();
                break;
        case 4: transpose();
                break;
        case 5: inverse();
                break;
        default:
                cout << "Invalid selection\n";
    }
}
void truthtable(){
int u, v;
    char g;
    int n, t;

again:
    while (1) {
        cout << "\t__--*****LOGICAL OPERATIONS*****--__" << endl;
        displayMainMenu();
        cout << "Select any operators: ";
     
        if (cin >> n) {
            if (n==0){
                return;
            }
            if (n >= 1 && n <= 7) {
                break;
            }
        } else {
            cout << "\nInvalid input! Please enter a valid operator (1 to 7).\n\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    }

    while (1) {
        cout << "\n\tBINARY VALUES FOR TWO INPUTS A & B\n";
        cout << "\nEnter '1' for true and '0' for false:\n\n";
        cin >> u >> v;

        if ((u == 1 || u == 0) && (v == 1 || v == 0)) {
            break;
        }
        cout << "\nInvalid inputs! Please enter '1' for true and '0' for false.\n\n";
    }

    menu(n, u, v);

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

    cout << "\n\n\t DO YOU WANT TO KNOW TRUTH TABLE of logic gates ?\n";
    cout << "\nEnter 'y' for yes or continue for operations.....\n\n ";
    cin >> g;

    if (g == 'y') {
        goto truth;
    } else {
        goto again;
    }

truth:

    while (1) {
        displayMainMenu();
        cout << "Select any (0-7) of the operators (0 to exit): ";

        if (cin >> n) {
            if (n == 0) {  // Exit condition
                return;     // Return to main menu
            }
            if (n >= 1 && n <= 7) {
                break;
            }
        } else {
            cout << "\nInvalid input! Please enter 0-7.\n\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    }

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

    goto again;
    

}
int main(){
    float a, b, result;
    char choice;//choice
    do {
        int n;
        cout << "\n1. Basic calculator\n";
        cout << "2. Trigonometric \n";
        cout << "3. Advanced \n";
        cout << "4. Matrix \n";
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
                matrix();
                break;
            case 5:
                cout << "Truth table\n";
                truthtable();
                break;
            case 6:
                cout << "Other calculator\n";
                break;
            default:
                cout << "Invalid selection\n";
        }

        cout << "\nEnter y/n for next calculation: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    
    return 0;
}