/*COSC 1410, Assignment 6
Tuesday, October 21, 2014
Write a program that uses a dynamic array that can grow when there is not enough space in the array to store a new element.
Static arrays, you must specify the size of the array (int list[5]) and the size cannot change. To overcome this limitation,
one solution is to use pointers to create dynamic arrays. Write a program that can store any number of integers in a dynamic array.
Assume the user will always enter proper type value (integer).
*/
#include <iostream>
using namespace std;

//Begining the program in main
void main() 
{
	//Initilizing the variables
	int value;
	int countedValues = 0;
	//Dynamic Array of size = 2
	int size = 2;
	int *actualDyn;
	actualDyn = new int[size]; //creates dynamically allocated array variable actualDyn, with 2 elements

	do {//Do all this while it doesn't equal to -1(exit)
		cout << "Please enter a value or -1 to end the program: " << endl; //Printing out what is needed
		cin >> value; //User Input
		if (value == -1) //If value equals to -1 the program should end (break loop)
		{
			break;
		}
		else if (countedValues == size)//Else if the counted values inputed equals to size
		{
			int* newDyn = new int[size];//Create a new Dynamic array

			for (int index = 0; index < countedValues; index++) {//For each index in newDyn it equals to each actualDyn array acording to the countedValues
				newDyn[index] = actualDyn[index];
			}
			delete actualDyn;//Delete actualDyn array

			size = size * 2;//Double the size (size * 2)
			actualDyn = new int[size];//actualDyn array with a new size of 4

			for (int index = 0; index < countedValues; index++)//For each index in newDyn it equals to each actualDyn array acording to the countedValues
				actualDyn[index] = newDyn[index];
			delete newDyn;//Delete the newDyn array
		}

		actualDyn[countedValues] = value;//the array inputs the number of inputs in the [index]
		countedValues++;// A counter for inputs
	} while (value != -1);//Ends when value = -1

	cout << "New Array: ";//Ouput

	for (int index = 0; index < countedValues; index++) {//Output for the actualDyn array based on countedValues
		cout << endl << index + 1 << ". " << actualDyn[index] << " ";
	}
	cout << endl;
	system("pause");
}