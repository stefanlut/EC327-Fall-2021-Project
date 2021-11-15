#include <iostream>

using namespace std;

int main()
{


	char response;
	cout << "Do you have COVID: ";
	cin >> response;
	while(response != 'y' && response != 'Y' && response != 'n' && response != 'N')
	{

		cout << "I SAID, DO YOU HAVE COVID-19: ";
		cin >> response;
	}

	switch(response)
	{
		case 'y':
		case 'Y':
		cout << "Red Badge, go to Quarantine" << endl;
		break;

		case 'n':
		case 'N':
		cout << "Green Badge, you're good" << endl;
		break;

	}

	return 0;
}
