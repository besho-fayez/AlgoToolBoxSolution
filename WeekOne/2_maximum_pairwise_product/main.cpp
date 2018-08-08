#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cin;
using std::ofstream;
using std::cout;
using std::max;

/*! Get Max Value we got from Multiplying the two max Values in the vector
 *  using two nested loops , Algorithm with Complexity "n squared"
 */
int64_t MaxPairwiseProduct(const vector<int>& numbers)
{
	int64_t product = 0;
	int n = numbers.size();


	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (product < numbers[i] *numbers[j])
				product = numbers[i] *numbers[j];
		}
	}
return product;
}

/*! Get Max Value we got from Multiplying the two max Values in the vector
 *  using two loops to get those two max values in the vector ,
 *  Algorithm with Complexity "2 n"
 */
int64_t MaxPairwiseProductFast( vector<int>& numbers)
{
	int n = numbers.size();

/*! Get First Max value within the Vector in the first place */
	int SwapValueTemp ;
	for (int i = 1; i < n; ++i)
	{
		if (numbers[0] < numbers[i])
		{
			SwapValueTemp = numbers[0];
			numbers[0] = numbers[i];
			numbers[i] = SwapValueTemp;
		}
	}
/*! Get Second Max value within the Vector in the Second place */
	for (int i = 2; i < n; ++i)
	{
		if (numbers[1] < numbers[i])
		{
			SwapValueTemp = numbers[1];
			numbers[1] = numbers[i];
			numbers[i] = SwapValueTemp;
		}
	}

return numbers[0] * numbers[1];
}


/*! Testing the Fast Algo by comparing random output from the two Algos
 * that we have
 * then writing the result in output file ".txt file"
 * Values generation by Pseudo Generator
 * writing the output in output file
 */
bool AlgorithmTest (int NumOfTestIterations)
{
	bool Flag = true;

	ofstream myfile;
	myfile.open ("AlgoResult.txt");

	for (int i =0 ; i < NumOfTestIterations ; i++)
	{
		int n =  rand() % 10;
		myfile << "n =" << n <<"\n";

		vector<int> numbers(n);
		for (int i = 0; i < n; ++i)
		{
			numbers[i] = rand() % 100000;
			myfile << numbers[i] <<"\t";
		}

		if (MaxPairwiseProduct(numbers) != MaxPairwiseProductFast(numbers))
		{
			Flag = false;
			myfile << "\n Failing Test Case \n";
		}
		else
		{
			myfile << "\n Passing Test Case \n";
		}
	}

	myfile.close();
return Flag;
}


int main()
{
	int NumOfIterations;
	cin >> NumOfIterations;

	if (!AlgorithmTest(NumOfIterations))
		cout << "Failure in the ALgo , Have a look to the .txt file";
	else
		cout << "No Failure in the ALgo";


return 0;
}
