 #ifndef FIXED_HPP
 #define FIXED_HPP

 #include <iostream>

 class Fixed
 {
	 private:
		 int rawBits;
		 static const int fractionalBits = 8;

	 public:
		 Fixed();
		 Fixed(const int integerValue);
		 Fixed(const float floatValue);
		 Fixed(const Fixed& other);
		 Fixed& operator=(const Fixed& other);
		 ~Fixed();

		 int getRawBits(void) const;
		 void setRawBits(int const raw);

		 float toFloat(void) const;
		 int toInt(void) const;
 };

 std::ostream& operator<<(std::ostream& output, const Fixed& fixedValue);

 #endif
