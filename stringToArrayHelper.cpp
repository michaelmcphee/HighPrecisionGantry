/*This program helps the group code the robot as the group can type in string and then copy and paste the result in the code, it is not the focus of the project*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	char keysArray[29] = {'/','a', 'b', 'c', 'd', 'e', 'f', 'g','h','i','j','k','l','m','n','o','p',
		'q','r','s','t','u','v','w','x','y','z','1','2'};
	cout << "Input a string to type, enter 9 at end of string, 1 for space, and 2 for enter" << endl;
	char temp = '/';
	int total = 0;
	while (cin >> temp && temp !='9')
	{
		for (int count=0;count<29;count++)
		{
			if (temp == keysArray[count])
			{
				cout << count << ", ";
				total ++;
				//if the char matches one in the array it will return the index it is at
			}
		}
		
	}
	cout << endl;
	cout << "The total is:" << total << endl; //total number of character in the string
	return EXIT_SUCCESS;
}
