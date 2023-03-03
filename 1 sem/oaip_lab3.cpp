#include <iostream>
#include <math.h>
#include <conio.h>

int main()
{
    double a, b, h, c, x, y, s;
    int k, n;
    std::cin >> a >> b >> h >> n;
    for (x = a; x <= b; x += h)
    {
        s = 0;
        for (k = 1; k <= n; k++)
        {
            if (k % 2 == 0)
                c = -1 * abs((pow(x, 2 * k + 1)) / (4 * pow(k, 2) - 1));
            else
                c = (pow(x, 2 * k + 1)) / (4 * pow(k, 2) - 1);
            s += c;
        }
        y = (((1 + pow(x, 2)) * atan(x)) / 2) - (x / 2);
        std::cout << x << " " << s << " " << y << " " << (abs(y - s)) << std::endl;
    }
}
