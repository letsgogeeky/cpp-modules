#include <stack>
#include <string>
#include <sstream>
#include <exception>
#include <iostream>

enum Error {
	NoError,
	InvalidFormat,
	NotSupported,
	ResultTooLarge,
	DivisionByZero
};

class RPN
{
private:
	std::stack<float> _stack;
	float _result;
	std::string issue;
	bool hasError;
	void _destroy(const char *p);
	bool _calculate(char op);
	bool _isOperator(char c);
	Error _parse(const char *expression);
	float	_convertToFloat(std::string str) const;
	void handleError(Error error);

public:
	RPN(const char *expression);
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);
	
	float compute(const char *expression);
	std::string getIssue();
	class IllegalFormatException: public std::exception
	{
	public:
        virtual const char *what() const throw();
	};
	class NotSupportedException: public std::exception
	{
	public:
        virtual const char *what() const throw();
	};
	class DivisionByZeroException: public std::exception
	{
	public:
        virtual const char *what() const throw();
	};
};