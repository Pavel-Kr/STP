#include <iostream>
#include "TPNumber.h"

int main()
{
    try {
        string a = "ABC123.435DC";
        string b = "16";
        string c = "5";

        string extend = "ABC123.435D2";
        TPNumber pnum(a, b, c);
        string result = pnum.getNumberString();
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}
