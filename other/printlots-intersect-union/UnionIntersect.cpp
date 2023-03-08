#include <iostream>
#include "MyVector.h"

MyVector<int> Intersect( MyVector<int> L, MyVector<int> P )
{
	MyVector<int> IntersectList;
	//represent index of L and P respectively
	int l, p;

	//start at the beginning of both lists
	l = 0;
	p = 0;

	while ( l < L.size() && p < P.size() )
	{
		//if the next val in L is == current value in L, then increament l 
		while ( l < L.size() && L[ l ] == L[ l + 1 ])
		{
			l++;
		}
		//if next val in P is == current val in P, then increment p
		while ( p < P.size() && P[ p ] == P[ p + 1 ])
		{
			p++;
		}

		if ( L[ l ] < P[ p ] )
		{
			l++;
		}
		else if ( L[ l ] > P[ p ] )
		{
			p++;
		}
		//if both values are equal, add to intersect
		else
		{
			IntersectList.push_back( L[ l ] );
			l++;
			p++;
		}
	}

	return IntersectList;
}

MyVector<int> Union( MyVector<int> L, MyVector<int> P )
{
	MyVector<int> UnionList;

	//represent index of L, P respectively
	int l, p;
	l = 0;
	p = 0;

	while ( l < L.size() && p < P.size() )
	{
		//if the next val in L is == current val in L, increment l
		while ( l < L.size() && L[ l ] == L[ l + 1 ] )
		{
			l++;
		}
		while ( p < P.size() && P[ p ] == P[ p + 1 ] )
		{
			p++;
		}

		if ( L[ l ] < P[ p ] && L [ l ] != UnionList[ UnionList.size() ] )
		{
			UnionList.push_back( L[ l ] );
			l++;
		}
		else if ( L[ l ] > P[ p ] && P[ p ] != UnionList[ UnionList.size() ] )
		{
			UnionList.push_back( P[ p ] );
			p++;
		}
		else
		{
			if ( L[ l ] != UnionList[ UnionList.size() ] )
			{
				UnionList.push_back( L[ l ] );
				l++;
				p++;
			}
		}
	}

	// No look ahead here. 
	//add any remaining values from P and L into the union list, none of these will be ==
	while ( l < L.size() && L[ l ] == L[ l + 1 ] )
	{
		l++;
	}
	while ( l < L.size() )
	{
		UnionList.push_back( L[ l ] );
		l++;
	}
	while ( p < P.size() && P[ p ] == P[ p + 1 ] )
	{
		p++;
	}
	while ( p < P.size() )
	{
		UnionList.push_back( P[ p ] );
		p++;
	}
	return UnionList;
}

// compute both intersect and union at the same time in linear time, accounts for duplicates,
// and lists of different sizes
void UnionIntersect( MyVector<int> L, MyVector<int> P )
{
	int l, p;

	l = 0;
	p = 0;
	MyVector<int> Union;
	MyVector<int> Intersect;

	while ( l < L.size() && p < P.size() )
	{
		while ( l < L.size() && L[ l ] == L[ l + 1 ] )
		{
			l++;
		}
		while ( p < P.size() && P[ p ] == P[ p + 1 ] )
		{
			p++;
		}

		if ( L [ l ] < P[ p ] && L[ l ] != Union[ Union.size() - 1 ] )
		{
			Union.push_back( L[ l ] );
			l++;
		}
		else if ( L[ l ] > P[ p ] && P[ p ] != Union[ Union.size() - 1 ] )
		{
			Union.push_back( P[ p ] );
			p++;
		}
		else
		{
			if ( L[ l ] != Intersect[ Intersect.size() - 1] )
				Intersect.push_back( L[ l ] );
				
			if ( L[ l ] != Union[ Union.size() ] )
			{
				
				Union.push_back( L[ l ] );
			}
			l++;
			p++;
		}

	}
	while ( l < L.size() )
	{
		while ( l < L.size() && L[ l ] == L[ l + 1 ] )
		{
			l++;
		}
		
		if ( L[ l ] != Union[ Union.size() - 1 ] )
		{
			Union.push_back( L[ l ] );
		}
		l++;
	}

	while ( p < P.size() )
	{
		while( P[ p ] == P[ p + 1 ] )
		{
			p++;
		}
		if ( P[ p ] != Union[ Union.size() - 1 ] )
		{
			Union.push_back( P[ p ] );
		}
		p++;
	}



	//printing is linear time
	std::cout << "UNION:" << std::endl; 
	for ( auto itr = Union.begin(); itr != Union.end(); itr++ )
	{
		std::cout<< *itr << std::endl;
	}

	std::cout << "INTERSECT:" << std::endl;
	for ( auto itr = Intersect.begin(); itr != Intersect.end(); itr++ )
	{
		std::cout << *itr << std::endl;
	}

}

int main()
{
	MyVector<int> L;
	L.push_back( 2 );
	L.push_back( 2 );
	L.push_back( 2 );
	L.push_back( 3 );
	L.push_back( 3 );
	L.push_back( 4 );
	L.push_back( 7 );
	L.push_back( 7 );
	L.push_back( 8 );
	L.push_back( 22 );
	L.push_back( 22 );

	MyVector<int> P;
	P.push_back( 1 );
	P.push_back( 2 );
	P.push_back( 4 );
	P.push_back( 4 );
	P.push_back( 6 );
	P.push_back( 6 );
	P.push_back( 7 );
	P.push_back( 8 );
	P.push_back( 10 );
	P.push_back( 10 );
	P.push_back( 10 );
	P.push_back( 11 );
	P.push_back( 11 );

	MyVector<int> I( std::move( Intersect( L, P ) ) );
	
	std::cout << "INTERSECT:" << std::endl;
	for ( int i = 0; i < I.size(); i++ )
	{
		std::cout << I[ i ] << std::endl;
	}

	MyVector<int> U( std::move( Union( L, P ) ) );
	std::cout << "UNION:" << std::endl;
	for ( int i = 0; i < U.size(); i++ )
	{
		std::cout << U[ i ] << std::endl;
	}

	UnionIntersect( L, P );

	return 0;
}
