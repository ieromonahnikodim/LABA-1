#include <iostream>
#include <bitset>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Task 1" << endl;
    cout << "type      | bytes | descriptions" << endl;
    cout << "bool        - " << sizeof(bool) << " -   true/false" << endl;
    cout << "char        - " << sizeof(char) << " -   one symbol" << endl;
    cout << "short int   - " << sizeof(short int) << " -   small integer(-32_768 <= x <=32_767)" << endl;
    cout << "int         - " << sizeof(int) << " -   integer(2_147_483_648 <= x <= 2_147_483_647)" << endl;
    cout << "long int    - " << sizeof(long int) << " -   same int" << endl;
    cout << "long long   - " << sizeof(long long) << " -   integer (–9_223_372_036_854_775_808 <= x <= –9_223_372_036_854_775_807)" << endl;
    cout << "float       - " << sizeof(float) << " -   fractional single precision" << endl;
    cout << "double      - " << sizeof(double) << " -   fractional double precision" << endl;
    cout << "long double - " << sizeof(long double) << " -   fractional double precision, extended" << endl;
    cout << endl;

    cout << "Task 2" << endl;

    int a;
    cout << "Write the number: ";
    cin >> a;

    int order_i = sizeof(int) * 8;
    unsigned int mask_i = 1u << (order_i - 1);

    for (int i = 0; i < order_i; i++) {
        cout << ((a & (mask_i >> i)) ? '1' : '0');

        if (i == 0) {   
            cout << "  ";
        }
    }
    cout << endl;

    cout << endl << "Task 3" << endl;
    union {
        float f;
        unsigned int u;
    } fu;
    cout << "Write 'float' number: ";
    cin >> fu.f;

    int order_f = sizeof(float) * 8;
    unsigned int mask_f = 1u << (order_f - 1);

    cout << "Number: " << fu.f << endl;
    cout << "Sign | BaseExponent| Mantissa" << endl;
    for (int i = 0; i < order_f; i++) {
        cout << ((fu.u & (mask_f >> i)) ? '1' : '0');
        if (i == 0 || i == 8) cout << "    | ";
    }
    cout << endl;

    cout << endl << "Task 4" << endl;

    union {
        double d;
        unsigned long long u;
    } du;
    cout << "Write 'double' number: ";
    cin >> du.d;

    int order_d = sizeof(double) * 8;
    unsigned long long mask_d = 1ULL << (order_d - 1);

    cout << "Number: " << du.d << endl;
    cout << "Sign | BaseExponent| Mantissa" << endl;
    for (int i = 0; i < order_d; i++) {
        cout << ((du.u & (mask_d >> i)) ? '1' : '0');
        if (i == 0 || i == 11) cout << "    | ";
    }
    cout << endl;

    cout << endl << "Task 5" << endl;
    int type, pos, op;

    cout << "Choose the type of your number (1 - int, 2 - float, 3 - double): ";
    cin >> type;

    cout << "Choose operation (1 - reset &=, 2 - set |=, 3 - invert ^=): ";
    cin >> op;

    if (type == 1) {
        int x;
        cout << "Write 'int': ";
        cin >> x;
        cout << "Write number of bit : ";
        cin >> pos;

        if (pos < 0 || pos > 31) {
            cout << "Impossible bit number" << endl;
        }
        else if (op < 1 || op > 3) {
            cout << "Impossible operation" << endl;
        }
        else {
            unsigned int u = x;
            unsigned int mask = 1u << pos;

            cout << "Before:    ";
            for (int i = 31; i >= 0; i--) cout << ((u & (1u << i)) ? '1' : '0');
            cout << "  = " << x << endl;

            if (op == 1)      u &= ~mask;
            else if (op == 2) u |= mask;
            else              u ^= mask;

            cout << "After: ";
            for (int i = 31; i >= 0; i--) cout << ((u & (1u << i)) ? '1' : '0');
            cout << "  = " << (int)u << endl;
        }
    }
    else if (type == 2) {
        union {
            float f;
            unsigned int u;
        } x;
        cout << "Write 'float': ";
        cin >> x.f;
        cout << "Write number of bit: ";
        cin >> pos;

        if (pos < 0 || pos > 31) {
            cout << "Impossible bit number" << endl;
        }
        else if (op < 1 || op > 3) {
            cout << "Impossible operation" << endl;
        }
        else {
            unsigned int mask = 1u << pos;

            cout << "Before:    ";
            for (int i = 31; i >= 0; i--) {
                cout << ((x.u & (1u << i)) ? '1' : '0');
                if (i == 31 || i == 23) cout << " ";
            }
            cout << "  = " << x.f << endl;

            if (op == 1)      x.u &= ~mask;
            else if (op == 2) x.u |= mask;
            else              x.u ^= mask;

            cout << "After: ";
            for (int i = 31; i >= 0; i--) {
                cout << ((x.u & (1u << i)) ? '1' : '0');
                if (i == 31 || i == 23) cout << " ";
            }
            cout << "  = " << x.f << endl;
        }
    }
    else if (type == 3) {
        union {
            double d;
            unsigned long long u;
        } x;
        cout << "Write 'double': ";
        cin >> x.d;
        cout << "Write nuber of bit: ";
        cin >> pos;

        if (pos < 0 || pos > 63) {
            cout << "Impossible bit number" << endl;
        }
        else if (op < 1 || op > 3) {
            cout << "Impossible operation" << endl;
        }
        else {
            unsigned long long mask = 1ULL << pos;

            cout << "Before:    ";
            for (int i = 63; i >= 0; i--) {
                cout << ((x.u & (1ULL << i)) ? '1' : '0');
                if (i == 63 || i == 52) cout << " ";
            }
            cout << "  = " << x.d << endl;

            if (op == 1)      x.u &= ~mask;
            else if (op == 2) x.u |= mask;
            else              x.u ^= mask;

            cout << "After: ";
            for (int i = 63; i >= 0; i--) {
                cout << ((x.u & (1ULL << i)) ? '1' : '0');
                if (i == 63 || i == 52) cout << " ";
            }
            cout << "  = " << x.d << endl;
        }
    }
    else {
        cout << "Impossible type" << endl;
    }

    cout << endl << "IDZ" << endl;
    cout << endl << "Sign inversion" << endl;

    int number;
    cout << "Write your number: ";
    cin >> number;
    int result = (~number + 1);
    cout << "Number in binary: " << bitset<32>(number) << endl;
    cout << "After inversion:    " << bitset<32>(result) << endl;
    cout << "Result: " << number << " * -1 = " << result << endl;

    return 0;
}
