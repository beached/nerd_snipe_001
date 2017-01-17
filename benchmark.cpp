#include <array>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "benchmark.h"

using value_t = intmax_t;


// Darrell Wright
value_t a( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		uint16_t const x1 = n % 2;
		auto const x2 = 1 - static_cast<value_t>((1u << x1) & 2u);
		result += (8 - x1) + (x2 * n) / 2;

	}
	return result;
}

// Darrell Wright
value_t b( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		uint16_t const is_odd = n & 1;
		uint16_t const x = is_odd * 2;
		int32_t const sign = 1 - (int32_t)x;
		result += (8 - is_odd) + (sign * (int32_t)n) / 2;
	}
	return result;
}

// Darrell Wright
value_t c( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		auto left = (n % 2)*(7 - n / 2);
		auto right = ((n + 1) % 2)*(8 + n / 2);
		result += left + right;
	}
	return result;
}

// Arnold Kim
value_t d( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		result += (8 + (n / 2 * 2) / 2) - (n & 1)*(n);
	}
	return result;
}

// Original
value_t e( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		if( (n % 2) == 0 ) {
			result += 8 + n / 2;
		} else {
			result += 7 - n / 2;
		}
	}
	return result;
}

// Shaun Winters - A
value_t f( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		result += (n & 1) * (-n - 1) + n / 2 + 8;
	}
	return result;
}

// Matt Bryan - A
value_t g( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		result += ((15 + (((n % 2)*(-2)) + 1) * (n + 1)) / 2) + (n % 2);
	}
	return result;
}

// Matt Bryan - B
value_t h( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		value_t Z = ((n % 2)*(-2)) + 1;
		result += ((15 + Z * (n + 1)) / 2) + (n % 2);
	}
	return result;
}

// Shaun Winters - B
value_t i( value_t N ) {
	value_t result = 0;
	for( value_t n = 0; n<N; ++n ) {
		result += (n & 1) * ((-n - 1) + 0.5) + (n>>1) + 8;
	}
	return result;
}


int main( int, char** argv ) {
	using namespace std::string_literals;
	std::vector<std::string> const names { 
		"Darrell Wright"s,
		"Darrell Wright"s, 
		"Darrell Wright"s,
		"Arnold Kim"s,
		"Original"s,
		"Shaun Winters - A"s,
		"Matt Bryan - A"s,
		"Matt Bryan - B"s,
		"Shaun Winters - B"s };

	intmax_t const count = atoi( argv[1] );
	using f_t = value_t( value_t );	
	std::array<std::function<f_t>, 9> const tests { &a, &b, &c, &d, &e, &f, &g, &h, &i };
	std::array<double, 9> results { 0 };
	std::array<size_t, 9> counts { 0 };
	std::random_device rd;
	std::mt19937 gen( rd( ) );
	std::uniform_int_distribution<> dis( 0, results.size( ) - 1 );
	for( size_t x = 0; x<count; ++x ) {
		auto m = dis( gen );
		counts[m]++;
		results[m] += daw::benchmark( [&]( ) {
				for( intmax_t n = 1; n<count; ++n ) {
				tests[m]( count );
				}
				} );
	}
	for( size_t m = 0; m<results.size( ); ++m ) {
		size_t calls = count*counts[m];
		std::cout << (char)('a' + m) << "-> '" << names[m] << "': " << results[m] * 1000.0 << "ms for " << calls << " calls " << (results[m] / (double)calls)*1000000.0 << "μs per item\n";
	}
	return EXIT_SUCCESS;
}

