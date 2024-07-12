#include "RPN.hpp"

RPN::RPN(const char *expression) : hasError(false) 
{
	Error error = _parse(expression);
	if (error != NoError)
		handleError(error);
	if (hasError)
		std::cerr << "Error: " << getIssue() << std::endl;
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &rpn)
{
	if (this == &rpn)
		return *this;
	_stack = rpn._stack;
	_result = rpn._result;
	return *this;
}

RPN::~RPN() 
{
	while(!_stack.empty())
		_stack.pop();
}

Error RPN::_parse(const char *expression)
{
	int digitCount = 0;
	int operatorCount = 0;
	int spaceCount = 0;
	for (const char *p = expression; *p; ++p)
	{
		if (!isdigit(*p) && !_isOperator(*p) && !isblank(*p))
			return NotSupported;
		if (isdigit(*p))
			digitCount++;
		if (_isOperator(*p))
			operatorCount++;
		if (isblank(*p))
			spaceCount++;
		if (isdigit(*p) && !isblank(*(p + 1)))
		{
			hasError = true;
			issue = std::string(p).substr(0, 2);
			return InvalidFormat;
		}
	}
	if (operatorCount + 1 != digitCount)
		return InvalidFormat;
	if (operatorCount + digitCount - 1 != spaceCount)
		return InvalidFormat;
	hasError = false;
	return NoError;
}

bool RPN::_calculate(char op)
{
	if (hasError)
		return false;
	if (_stack.empty())
		return false;
	if (_stack.size() < 2)
		return false;
	double second = _stack.top();
	_stack.pop();
	double first = _stack.top();
	_stack.pop();
	switch (op)
	{
	case '+':
		_stack.push(first + second);
		break;
	case '-':
		_stack.push(first - second);
		break;
	case '/':
		if (second == 0)
		{
			_destroy(&op);
			throw DivisionByZeroException();
		}
		_stack.push(first / second);
		break;
	case '*':
		_stack.push(first * second);
		break;
	default:
		return false;
	}
	return true;
}

void RPN::_destroy(const char *p)
{
	hasError = true;
	issue = std::string(p).substr(0, 2);
	std::cerr << "Error: " << getIssue() << std::endl;
	while (!_stack.empty())
		_stack.pop();
}

void RPN::handleError(Error error)
{
	hasError = true;
	switch (error)
	{
	case InvalidFormat:
		issue = "Invalid Format";
		throw IllegalFormatException();
		break;
	case NotSupported:
		issue = "Not Supported";
		throw NotSupportedException();
		break;
	case ResultTooLarge:
		issue = "Result Too Large";
		break;
	case DivisionByZero:
		issue = "Division By Zero";
		throw DivisionByZeroException();
		break;
	default:
		break;
	}
}

double RPN::compute(const char *expression)
{
	for (const char *p = expression; *p; ++p)
	{
		if (isdigit(*p))
		{
			if (!isblank(*(p + 1)))
			{
				_destroy(p);
				throw IllegalFormatException();
			}
			_stack.push(std::stoi(std::string(p).substr(0, 1)));
		}
		if (_isOperator(*p))
		{
			if ((*(p + 1) && !isblank(*(p + 1))) || \
				(*(p + 1) && !*(p + 2) && isblank(*(p + 1))))
			{
				_destroy(p);
				throw IllegalFormatException();
			}
			_calculate(*p);
		}
	}
	if (_stack.size() > 1)
		throw IllegalFormatException();
	_result = _stack.top();
	_stack.pop();
	return _result;
}

bool RPN::_isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

std::string RPN::getIssue()
{
	if (!hasError)
		return "";
	return issue;
}

const char *RPN::IllegalFormatException::what() const throw()
{
    return "Illegal Format Exception!";
}

const char *RPN::NotSupportedException::what() const throw()
{
    return "Format is not Supported!";
}

const char *RPN::DivisionByZeroException::what() const throw()
{
    return "Division by Zero Exception!";
}
