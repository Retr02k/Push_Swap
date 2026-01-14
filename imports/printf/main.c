/*
 A comprehensive test driver for your ft_printf implementation.
 Builds a set of tests that compare ft_printf output and return value
 against the system printf for the supported specifiers:
   %c %s %p %d %i %u %x %X %%
 and also includes edge cases (NULL pointers/strings, INT bounds, zero,
 unknown specifier behavior, mixed formats).
 
 Usage:
   gcc -Wall -Wextra -Werror -std=c11 main.c helpers.c ft_printf.c -o test_printf
   ./test_printf
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdarg.h>
#include "printf.h" /* must declare int ft_printf(const char *s, ...); */

/* Print the expected output using vprintf so the compiler won't
   perform format-string checks at the callsite and issue warnings
   for strings like "Unknown specifier: %q\n". Return vprintf's result. */
static int print_expected(const char *fmt, ...)
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = vprintf(fmt, ap);
	va_end(ap);
	return (r);
}

/* Macro to run a test: prints "expected" using print_expected and "actual"
   using ft_printf, then prints both return values for easy comparison. */
#define TEST(desc, fmt, ...)                                                 \
	do {                                                                     \
		printf("\n== %s ==\n", desc);                                        \
		printf("expected: ");                                                \
		int re = print_expected(fmt, ##__VA_ARGS__);                         \
		printf(" <ret=%d>\n", re);                                           \
		printf("actual:   ");                                                \
		int ra = ft_printf(fmt, ##__VA_ARGS__);                              \
		printf(" <ret=%d>\n", ra);                                           \
	} while (0)

int main(void)
{
	char ch = 'A';
	char c2 = 'z';
	char *s = "Hello, ft_printf!";
	char *empty = "";
	char *null_s = NULL;
	int i_pos = 12345;
	int i_neg = -9876;
	int i_min = INT_MIN;
	int i_max = INT_MAX;
	unsigned int u_zero = 0u;
	unsigned int u_big = 4294967295u; /* UINT_MAX for 32-bit unsigned */
	unsigned int hex_val = 0xDEADBEEFu;
	void *p = &ch;
	void *null_p = NULL;

	printf("\n\n=== ft_printf test suite ===\n");

	TEST("simple string", "Simple: %s\n", s);
	TEST("empty string", "Empty: '%s'\n", empty);
	TEST("null string", "Null string: %s\n", null_s);

	TEST("single chars", "Chars: %c %c %c\n", ch, '!', c2);
	TEST("percent literal", "Show percent: %%\n");

	TEST("pointer (non-null)", "Pointer: %p\n", p);
	TEST("pointer (null)", "Pointer NULL: %p\n", null_p);

	TEST("signed ints", "Signed: %d %i %d %i\n", i_pos, i_pos, i_neg, i_neg);
	TEST("int limits", "Limits: INT_MIN=%d INT_MAX=%d\n", i_min, i_max);

	TEST("zero values", "Zero: %d %u %x\n", 0, u_zero, 0u);

	TEST("unsigned and big", "Unsigned: %u\n", u_big);
	TEST("hex lower/upper", "Hex: %x %X\n", hex_val, hex_val);

	TEST("mixed format", "Mix: %s %c %d %x %% end\n", "mix", '!', 123, 123);

	/* This used to trigger a compiler error because printf(fmt, ...) was
	   checked at the callsite and '%q' is an invalid conversion specifier.
	   Using print_expected avoids that compile-time check. */
	TEST("unknown specifier handling", "Unknown specifier: %q\n");

	TEST("many percent signs", "Many percents: %%%%%%\n");

	/* Extra edge combinations */
	TEST("string + pointer", "Str+Ptr: %s -> %p\n", s, p);
	TEST("negatives in unsigned/hex (pass as unsigned)", "Neg as unsigned/hex: %u %x\n", (unsigned int)i_neg, (unsigned int)i_neg);

	printf("\n=== End of tests ===\n");
	return (0);
}
