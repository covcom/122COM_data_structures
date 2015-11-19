#include <exception>
#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
	const int maxSize;
	char *stack;
	int pos;

public:
	class Full: public exception
	{
	public:
		virtual const char* what() const throw()
  		{
    		return "Stack is full";
  		}
	};

	class Empty: public exception
	{
	public:
		virtual const char* what() const throw()
  		{
    		return "Stack is empty";
  		}
	};

	/** Initialise the stack, maxSize is the maximum number of
		values that can be stored in the stack at any time */
	Stack( const int maxSize ) : maxSize(maxSize)
	{
		pos = 0;
		stack = new char[ maxSize ];
	}	

	~Stack()
	{
		delete [] stack;
	}

	/** Returns the number of values currently stored in the 
		stack */
	int num_items()
	{
		// REPLACE ME
		return 0;
	}

	/** Add value to the top of the stack, raises Stack::Full 
		exception if stack is full */
	void push( char value )
	{
		if( num_items() < maxSize )
		{
			stack[ pos ] = value;
			pos += 1;
		}
		else
		{
			throw Full();
		}
	}

	/** Returns the value currently stored at the top of the 
		stack, raises Stack::Empty exception if stack is 
		empty */
	char top()
	{
		// COMPLETE ME
	}

	/** Removes and returns the value currently stored at the
		top of the stack, raises Stack::Empty exception if stack
		is empty */
	char pop()
	{
		// COMPLETE ME
	}
};

int main()
{
	string testvalues = "abcde";

	Stack s( testvalues.length() );

	// === pushing test ======
	for( int i=0; i<testvalues.length(); ++i )
	{
		char c = testvalues[i];
		s.push( testvalues[i] );

		cout << "Pushing " << c << endl;

		if( s.top() != c )
		{
			cerr << "Error - last thing pushed was " << c << " but top of stack contains " << s.top() << endl;
		}

		if( s.num_items() != i+1 )
		{
			cerr << "Error - pushed " << i+1 << " values but stack reports size of " << s.num_items() << endl;
		}
	}

	// === is full test ======
	try
	{
		s.push( 'f' );
		cerr << "Error - tried to push to a full stack but no exception" << endl;
	}
	catch( Stack::Full& error )
	{}

	// === pop test ======
	for( int i=testvalues.length()-1; i>=0; --i )
	{
		char c = testvalues[i];
		char val = s.pop();

		cout << "Popping " << val << endl;

		if( val != c )
		{
			cerr << "Error - wrong value was popped from the stack, expecting " << c << " but got " << val << endl;
		}
	
		if( s.num_items() != i )
		{
			cerr << "Error - stack should have " << i << " values but claims it has " << s.num_items() << " values" << endl;
		}
	}

	// === empty test ======
	try
	{
		s.pop();
		cerr << "Error - tried to pop from an empty stack but no exception" << endl;
	}
	catch( Stack::Empty& error )
	{}

	try
	{
		s.top();
		cerr << "Error - tried to get top off an empty stack but no exception" << endl;
	}
	catch( Stack::Empty& error )
	{}

	return 0;
}