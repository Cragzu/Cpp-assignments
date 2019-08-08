#include <string>
#include <iostream>

/* 10:45 - 10:57 (12 min)
 * 
 * return ignore if:
 * the first of these four digits is an 8 or 9;
 * the last digit is an 8 or 9;
 * the second and third digits are the same.
 * 
 * else return answer
*/

using namespace std;

int main() {
	
	bool ignore = false;
	int n1, n2, n3, n4;
	
	cin >> n1;
	cin >> n2;
	cin >> n3;
	cin >> n4;
	
	if (n1 == 8 || n1 == 9) // first digit 8 or 9
	{
		if (n2 == n3) // second and third are same
		{
			if (n4 == 8 || n4 == 9) // last digit 8 or 9
			{
				ignore = true;
			}
		}
	}
	
	if (ignore == true)
	{
		cout << "ignore";
	}
	
	else
	{
		cout << "answer";
	}
	
	
	return 0;
	
}
