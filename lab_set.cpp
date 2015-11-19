#include <exception>
#include <iostream>
#include <string>
using namespace std;

class Set
{
private:
	const int maxSize;
	char *set;
	int items;

public:
	class Full: public exception
	{
	public:
		virtual const char* what() const throw()
  		{
    		return "Set is full";
  		}
	};

	/** Initialise the Set, maxSize is the maximum number of
		values that can be stored in the Set at any time **/
	Set( const int maxSize ) : maxSize(maxSize)
	{
		items = 0;
		set = new char[ maxSize ];  // create the array to store the set
		for( int i=0; i<maxSize; ++i )
		{
			set[i] = 0;					// set the starting value of every element to 0
		}
	}	

	~Set()
	{
		delete [] set;
	}

	/** Checks to see if value is in the set or not,
			returns True if it is and False if it isn't **/
	bool is_in( char value )
	{
		// COMPLETE ME

		return false;
	}

	/** Add value to the set, raises set.Full 
			exception if set is full **/
	void add( char value )
	{
		// COMPLETE ME
	}

	/** Returns the number of values currently stored in the 
		set **/
	int num_items()
	{
		return items;
	}

	/** Removes value from the set if it is present,
		returns True if value did exist and False if it did not **/
	bool remove( char value )
	{
		// COMPLETE ME

		return false;
	}
};

int main()
{
	Set s( 5 );
	
	// === adding test ======
	cout << "Adding a" << endl;
	s.add('a');
	if( s.num_items() != 1 )
	{
		cerr << "Error - set should have 1 item but claims it has " << s.num_items() << endl;
	}

	if( !s.is_in('a') )
	{
		cerr << "Error - set should contain 'a' but claims it doesn't" << endl;
	}

	cout << "Adding b" << endl;
	s.add('b');
	if( s.num_items() != 2 )
	{
		cerr << "Error - set should have 2 item but claims it has " << s.num_items() << endl;
	}

	if( !s.is_in('b') )
	{
		cerr << "Error - set should contain 'b' but claims it doesn't" << endl;
	}

	// === duplicate test ======
	cout << "Adding a again" << endl;
	s.add('a');
	if( s.num_items() != 2 )
	{
		cerr << "Error - set should have 2 item but claims it has " << s.num_items() << endl;
	}

	if( !s.is_in('a') )
	{
		cerr << "Error - set should contain 'a' but claims it doesn't" << endl;
	}

	if( s.is_in('c') )
	{
		cerr << "Error - set doesn't contain 'c' but claims it does" << endl;
	}

	if( s.remove('c') )
	{
		cerr << "Error - set doesn't contain 'c' but claimed that remove() just got rid of it" << endl;
	}

	// === removing test ======
	cout << "Removing a" << endl;
	if( !s.remove('a') )
	{
		cerr << "Error - set contained 'a' but set claimed that remove() can't get rid of it" << endl;
	}

	if( s.num_items() != 1 )
	{
		cerr << "Error - set should have 1 item but claims it has " << s.num_items() << endl;
	}

	return 0;
}