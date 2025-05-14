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

void basic(){
    float a,b;
    int n;
    cout<<"Enter any two number: "<<endl;
    cin>>a>>b;
    cout << "1.add  |2.sub  |3.multi  |4.divide\n";

    cout<<"Select operation: ";
    cin>>n;
    switch (n) {
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
        case 6: if (tan(x) != 0){
                cout << "cot(x): " << 1 / tan(x) << endl;}       
        default:
                cout << "Invalid selection\n";
    }

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
                break;
            case 5:
                cout << "Truth table\n";
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