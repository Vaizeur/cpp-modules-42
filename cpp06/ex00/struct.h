#ifndef STRUCT_H
# define STRUCT_H
# include <iostream>

enum TokenType {
	CHAR,
	INT,
	DOUBLE,
	FLOAT
};

struct TokenResult
{
	TokenType	type;
	double		value;
};

#endif