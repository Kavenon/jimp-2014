#include "aghInclude.h"
// ---------------------------------------------------------

void showTestResult(int, bool);
// ---------------------------------------------------------

int main(void)
{
    cout << "main by kk. Last updated 15.04.2013\n";

    

    return 0;
}
// ---------------------------------------------------------

void showTestResult(int _ti, bool _r)
{
    if(_r)
        cout << "Test" << _ti << " PASSED\n";
    else
        cout << "Test" << _ti << " FAILED\n";
}
// ---------------------------------------------------------
