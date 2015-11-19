class Set:
	class Full(Exception):
		pass

	def __init__( self, maxSize ):
		""" Initialise the set, maxSize is the maximum number of
			values that can be stored in the set at any time """
		self.__maxSize = maxSize
		self.__set = [None]*self.__maxSize
		self.__items = 0

	def is_in( self, value ):
		""" Checks to see if value is in the set or not,
			returns True if it is and False if it isn't """
		# COMPLETE ME

		return False

	def add( self, value ):
		""" Add value to the set, raises set.Full 
			exception if set is full """
		# COMPLETE ME

	def num_items( self ):
		""" Returns the number of values currently stored in the 
			set """
		return self.__items

	def remove( self, value ):
		""" Removes value from the set if it is present,
			returns True if value did exist and False if it did not """
		
		# COMPLETE ME
		return False



if __name__ == '__main__':

	s = Set( 5 )
	
	# === adding test ======
	print( 'Adding a' )
	s.add('a')
	if s.num_items() != 1:
		print( 'Error - set should have 1 item but claims it has %d' % s.num_items() )

	if not s.is_in('a'):
		print( 'Error - set should contain \'a\' but claims it doesn\'t' )

	print( 'Adding b' )
	s.add('b')
	if s.num_items() != 2:
		print( 'Error - set should have 2 item but claims it has %d' % s.num_items() )

	if not s.is_in('b'):
		print( 'Error - set should contain \'b\' but claims it doesn\'t' )

	print( 'Adding a again' )
	s.add('a')
	if s.num_items() != 2:
		print( 'Error - set should have 2 item but claims it has %d' % s.num_items() )

	if not s.is_in('a'):
		print( 'Error - set should contain \'a\' but claims it doesn\'t' )

	if s.is_in('c'):
		print( 'Error - set doesn\'t contain \'c\' but claims it does' )

	if s.remove('c'):
		print( 'Error - set doesn\'t contain \'c\' but claimed that remove() just got rid of it' )


	print( 'Removing a ')
	if not s.remove( 'a' ):
		print( 'Error - set contained \'a\' but set claimed that remove() can\'t get rid of it' )

	if s.num_items() != 1:
		print( 'Error - set should have 1 item but claims it has %d' % s.num_items() )

