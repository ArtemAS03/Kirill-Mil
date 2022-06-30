#include <iostream>
#include "math.h"

using namespace std;
int main()
{
    double a, h, t, b;
    const int z = 1;
    cout << "Enter strat point";
    cin >> a;
    cout << "Enter end point";
    cin >> b;
    cout << "Enter step";
    cin >> h;
    for (double i = a; i <= b; i += h)
    {
        try
        {
            if (pow(i, a) == 0)throw "none";
            bool aa = (2 * i) <= 0;
            if (aa)throw "none";
            t = (pow(i, 2) / pow(i, a)) + (1.0 / 3) * pow(sin(z), 2) - log(sqrt(2 * i));
            cout << t << "=f(" << i << ")\n";
        }
        catch (const char* s) { cout << s << "=f(" << i << ")\n"; }

    }
    system("pause");
}
