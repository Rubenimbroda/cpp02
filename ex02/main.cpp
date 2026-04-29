#include "Fixed.hpp"

int main(void)
{
    std::cout << "=== constructors ===" << std::endl;

    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(c);
    Fixed e;

    e = b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << std::endl;
    std::cout << "=== getters and conversions ===" << std::endl;

    std::cout << "c raw bits = " << c.getRawBits() << std::endl;
    std::cout << "b toInt = " << b.toInt() << std::endl;
    std::cout << "c toFloat = " << c.toFloat() << std::endl;

    Fixed raw;
    raw.setRawBits(512);

    std::cout << "raw after setRawBits(512) = " << raw << std::endl;

    std::cout << std::endl;
    std::cout << "=== comparisons ===" << std::endl;
    std::cout << std::boolalpha;

    std::cout << "b > c  = " << (b > c) << std::endl;
    std::cout << "b < c  = " << (b < c) << std::endl;
    std::cout << "b >= c = " << (b >= c) << std::endl;
    std::cout << "b <= c = " << (b <= c) << std::endl;
    std::cout << "b == e = " << (b == e) << std::endl;
    std::cout << "b != e = " << (b != e) << std::endl;

    std::cout << std::endl;
    std::cout << "=== arithmetic ===" << std::endl;

    Fixed sum = b + c;
    Fixed diff = c - b;
    Fixed prod = Fixed(5.05f) * Fixed(2);
    Fixed quot = c / Fixed(2);

    std::cout << "b + c = " << sum << std::endl;
    std::cout << "c - b = " << diff << std::endl;
    std::cout << "5.05 * 2 = " << prod << std::endl;
    std::cout << "c / 2 = " << quot << std::endl;

    std::cout << std::endl;
    std::cout << "=== increments and decrements ===" << std::endl;

    Fixed inc;

    std::cout << "inc start   = " << inc << std::endl;
    std::cout << "++inc       = " << ++inc << std::endl;
    std::cout << "inc now     = " << inc << std::endl;
    std::cout << "inc++       = " << inc++ << std::endl;
    std::cout << "inc now     = " << inc << std::endl;
    std::cout << "--inc       = " << --inc << std::endl;
    std::cout << "inc--       = " << inc-- << std::endl;
    std::cout << "inc now     = " << inc << std::endl;

    std::cout << std::endl;
    std::cout << "=== min and max ===" << std::endl;

    Fixed m1(3.5f);
    Fixed m2(7.25f);
    const Fixed cm1(2.5f);
    const Fixed cm2(9.75f);

    std::cout << "min(m1, m2)  = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max(m1, m2)  = " << Fixed::max(m1, m2) << std::endl;
    std::cout << "min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
    std::cout << "max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;

    return 0;
}