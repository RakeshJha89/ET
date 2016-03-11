#include <iostream>
using namespace std;

/*
3)  Write the code for the following function, without using any built-in functions.

char* itoa(int Value, int Base);

where the returned value is allocated on behalf of the caller, value is the integer to convert, and base is octal, decimal, or hex.

*/

void c_divide_modulo(int _divident, int _divisor, int& _quotient, int& _remainder)
{
	int count = 0;
	int div = _divident;
	while(div >= _divisor)
	{
		count ++;
		div -= _divisor;
	}
	_quotient = count;
	_remainder = div;
}

char* c_itoa(int _val, int _base, char* _buffer)
{
	int buffCount = 0;
	int val = _val;
	int base = _base;
	int qtn, rmd;

	if(val == 0)
	{
		_buffer[buffCount++] = '0';
	}

	while(val > 0)
	{
		c_divide_modulo(val, base, qtn, rmd);
		val = qtn;
		_buffer[buffCount++] = rmd > 9 ? (rmd - 10) + 'A': rmd + '0';
	}

	/*Reverse the buffer*/
	int i = 0;
	int j = buffCount - 1;
	while(i < j)
	{
		char tempChar = _buffer[i];
		char tempChar2 = _buffer[j];
		_buffer[i] = tempChar2;
		_buffer[j] = tempChar;
		i++;
		j--;
	}
	_buffer[buffCount] = '\0';
	return _buffer;
}


int main(int* argv, char** argc)
{
	int t;
	int number, base;
	cout << "Main executed \n";
	cout << "Enter number to convert \n";
	cin >> number;
	cout << "Enter base to convert \n";
	cin >> base;
	int buffSize = sizeof(char) * 256;
	char* buffer = new char[buffSize];
	memset(buffer, '\0', buffSize);
	c_itoa(number, base, buffer, buffSize); 
	cout << buffer << endl;
	cin>>t;
	delete[] buffer;
	return 0;
}