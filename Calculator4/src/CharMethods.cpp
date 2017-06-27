#include <stdexcept>
#include <string>

int digitVal(char c)
{
    int n = (c-'0');
    if (0 <= n && n <= 9)
        return n;
    else
        throw std::invalid_argument( "The char is not a digit" );
}

bool isDigit(char c)
{
    int n = (c-'0');
    return (0 <= n && n <= 9);
}

bool isWhitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

std::string int_to_string(int n)
{
	int i = 30;

	std::string s = "";

	for( ; n && i ; --i, n /= 10) s = "0123456789"[n % 10] + s;

	return s;
}
