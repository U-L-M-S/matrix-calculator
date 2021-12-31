#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>





using namespace std;


void matrixMultiplicationInstructions() {

	cout << "The multiplication of two matrices is only possible if the matrice A row quantity and the matrice B coloumn quantity are the same." << endl;
	cout << "Ex:" << endl;

	float fRowsMatrixA = 2, fColumnsMatrixA = 3;
	int iAMatrixEX[] = { 1, 2, 3 };
	int iBMatrixEX[] = { 4, 5, 6 };
	int* iMatrixEX[] = { iAMatrixEX, iBMatrixEX };

	for (int i = 0; i < fRowsMatrixA; i++)
	{
		for (int j = 0; j < fColumnsMatrixA; j++) {
			cout << iMatrixEX[i][j] << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "This is a " << fRowsMatrixA << " x [" << fColumnsMatrixA << "] matrice." << endl << endl;

	int iRowsMatrixB = 3, iColumnsMatrixB = 3;
	int iAMatrixBEX[] = { 6, 5, 4 };
	int iBMatrixBEX[] = { 1, 2, 3 };
	int iCMatrixBEX[] = { 2, 4, 6 };
	int* iMatrixBEX[] = { iAMatrixBEX, iBMatrixBEX };

	for (int i = 0; i < iRowsMatrixB; i++)
	{
		for (int j = 0; j < iColumnsMatrixB; j++) {
			cout << iMatrixBEX[i][j] << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "This is a [" << iRowsMatrixB << "] x " << iColumnsMatrixB << " matrice." << endl << endl << endl;
	cout << "As you can see. The matrices A (2x[3]) and B ([3]x3)" << "can be multiplificated." << endl;
	cout << "Press ENTER to continue you multiplifications of matrices." << endl;
	cin.get();

}

void matrixSumInstructions() {
	cout << "The sum of two matrices is only possible if they have the same quantity of rows and columns." << "EX:";

	float fRowsMatrixA = 3, fColumnsMatrixA = 3;
	int iAMatrixEX[] = { 1, 2, 3 };
	int iBMatrixEX[] = { 4, 5, 6 };
	int iCMatrixEX[] = { 7, 8, 9 };
	int* iMatrixEX[] = { iAMatrixEX, iBMatrixEX, iCMatrixEX };

	for (int i = 0; i < fRowsMatrixA; i++)
	{
		for (int j = 0; j < fColumnsMatrixA; j++) {
			cout << iMatrixEX[i][j] << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "This is a " << fRowsMatrixA << " x [" << fColumnsMatrixA << "] matrice." << endl << endl;

	int iRowsMatrixB = 3, iColumnsMatrixB = 3;
	int iAMatrixBEX[] = { 6, 5, 4 };
	int iBMatrixBEX[] = { 1, 2, 3 };
	int iCMatrixBEX[] = { 2, 4, 6 };
	int* iMatrixBEX[] = { iAMatrixBEX, iBMatrixBEX, iCMatrixBEX };

	for (int i = 0; i < iRowsMatrixB; i++)
	{
		for (int j = 0; j < iColumnsMatrixB; j++) {
			cout << iMatrixBEX[i][j] << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "This is a [" << iRowsMatrixB << "] x " << iColumnsMatrixB << " matrice." << endl << endl << endl;
	cout << "As you can see. The matrices A ([3]x[3]) and B ([3]x[3])" << "can be multiplificated." << endl;
	cout << "Press ENTER to continue you multiplifications of matrices." << endl;
	
}

void matrixMultiplication() {

		char cInstructions;
		cout << "Do you want to see the instructions for a multiplications of matrices? (y/n)" << endl;

		cin >> cInstructions;
		if (cInstructions == 'y' || cInstructions == 'Y')
		{
			matrixMultiplicationInstructions();
		}

		char cMatrixCorrection;

		double dMatrixA[15][15], dMatrixB[15][15], dMultMatrixAB[15][15];
		int iRowsMatrixA, iColumnMatrixA, iRowsMatrixB, iColumnMatrixB, iTempMultMatrixAB;


		cout << "Put down  the nescessary valuers..." << endl;
		cout << "Put here how many rows there is in the first matrix (Matrix A):  ";
		cin >> iRowsMatrixA;
		cout << endl;
		cout << "Put here how many columns there is in the matrix A:  ";
		cin >> iColumnMatrixA;
		cout << endl << endl;
		cout << "Put here all numbers of Matrice A" << endl << "Ex: " << endl;
		cout << "1 2 3	 [ENTER]" << endl;
		cout << "4 5 6	 [ENTER]" << endl;
		cout << "7 8 9	 [ENTER]" << endl << endl << endl;
		cout << "Now it's your turn: " << endl;

		for (int i = 0; i < iRowsMatrixA; i++)
		{
			for (int j = 0; j < iColumnMatrixA; j++) {
				cin >> dMatrixA[i][j];
			}
		}

		cout << endl << endl;
		



		cout << "Put here how many rows there is in the secound matrix (Matrix B):  ";
		cin >> iRowsMatrixB;
		cout << endl;
		cout << "Put here how many columns there is in the matrix B:  ";
		cin >> iColumnMatrixB;
		cout << endl << endl;

		for (int i = 0; i < iRowsMatrixB; i++)
		{
			for (int j = 0; j < iColumnMatrixB; j++) {
				cin >> dMatrixB[i][j];
			}
		}



		int count = 0;
		cout << "Please wait..." << endl << "Loading [ ";
		for (count; count < 10; ++count) {
			cout << " - ";
			fflush(stdout);
			Sleep(500);
		}
		cout<< ">]" << endl << "Done" << endl;


		cout << endl << endl;
		cout << "Your matrices look like this" << endl;


		cout << "Your matrice looks like this" << endl;
		cout << "Matrix A" << endl;
		for (int i = 0; i < iRowsMatrixA; i++)
		{
			for (int j = 0; j < iColumnMatrixA; j++) {
				cout << "[ " << dMatrixA[i][j] << " ] ";
			}
			cout << endl;
		}

		cout << endl << endl << endl << "MatrixB" << endl;


		for (int i = 0; i < iRowsMatrixB; i++)
		{	
			for (int j = 0; j < iColumnMatrixB; j++)
			{
				cout << "[ " << dMatrixB[i][j] << " ] ";
			}
			cout << endl;
		}


		cout << endl;
		cout << "Does your matrices look like you wanted ?";
		cout << endl;
		cout << "(y/n)?";
		cin >> cMatrixCorrection;
		if (cMatrixCorrection == 'y' || cMatrixCorrection == 'Y')
		{
			cout << "PERFECT :D. let's continue..." << endl << "Press ENTER to continue";
		}
		if (cMatrixCorrection == 'n' || cMatrixCorrection == 'N')
		{

			int iMatriceCorection;
			cout << "ok... Which one ?"<< endl;
			cout << "press 1 for Matrice A" << endl;
			cout << "press 2 for Matrice B" << endl;
			cout << "press 3 for both Matrices" << endl;
			cin >> iMatriceCorection;
			switch (iMatriceCorection)
			{
			case 1:
				cout << "Alright... let's we try again. " << endl << "[ENTER TO CONTINUE]";
				cin.get();
				cout << "Put here how many rows there is in the first matrix (Matrix A):  ";
				cin >> iRowsMatrixA;
				cout << endl;
				cout << "Put here how many columns there is in the matrix A:  ";
				cin >> iColumnMatrixA;
				cout << endl << endl;
				cout << "Put here all numbers of Matrice A" << endl << "Ex: " << endl;
				cout << "1 2 3	 [ENTER]" << endl;
				cout << "4 5 6	 [ENTER]" << endl;
				cout << "7 8 9	 [ENTER]" << endl << endl << endl;
				cout << "Now it's your turn: " << endl;

				for (int i = 0; i < iRowsMatrixA; i++)
				{
					for (int j = 0; j < iColumnMatrixA; j++) {
						cin >> dMatrixA[i][j];
					}
				}

				cout << endl << endl;
				cout << "Your matrice looks like this" << endl;
				for (int i = 0; i < iRowsMatrixA; i++)
				{
					for (int j = 0; j < iColumnMatrixA; j++) {
						cout << "[ " << dMatrixA[i][j] << " ] ";
					}
					cout << endl;
				}

				break;
			
			case 2:

				cout << "Alright... let's we try again. " << endl << "[ENTER TO CONTINUE]";
				cin.get();
				cout << "Put here how many rows there is in the secound matrix (Matrix B):  ";
				cin >> iRowsMatrixB;
				cout << endl;
				cout << "Put here how many columns there is in the matrix B:  ";
				cin >> iColumnMatrixB;
				cout << endl << endl;

				for (int i = 0; i < iRowsMatrixB; i++)
				{
					for (int j = 0; j < iColumnMatrixB; j++) {
						cin >> dMatrixB[i][j];
					}
				}

				cout << endl << endl;
				cout << "Your matrice looks like this" << endl;
				for (int i = 0; i < iRowsMatrixB; i++)
				{
					for (int j = 0; j < iColumnMatrixB; j++)
					{
						cout << "[ " << dMatrixB[i][j] << " ] ";
					}
					cout << endl;
				}

				break;

			case 3:

				matrixMultiplication();

				break;
			default:

				cout << "Sorry I couldn't understand what you mean... So let's we try for the beginning. ok? " << endl << "[ENTER TO CONTINUE]";
				cin.get();
				matrixMultiplication();

				break;
			}

		}

		cout << endl << endl;
		if (iColumnMatrixA != iRowsMatrixB)
		{

			cout << "I'm sorry but this matrices can't be multiplicated" << endl << "I sugest you to read the Instructions..." << endl << "[ENTER TO CONTINUE]";
			cin.get();
			matrixMultiplication();

		}
		else
		{
			for (int i = 0; i < iRowsMatrixA; i++)
			{
				for (int j = 0; j < iRowsMatrixB; j++)
				{
					for (int k = 0; k < iRowsMatrixB; k++)
					{
						iTempMultMatrixAB += dMatrixA[i][k] * dMatrixB[k][j];
					}
					dMultMatrixAB[i][j] = iTempMultMatrixAB;
					iTempMultMatrixAB = 0;
				}
			}
		}
	
	
	
}

void matrixSum() {

	int iRowsMatrix, iColumnsMatrix;
	double dMatrixA[15][15], dMatrixB[15][15];

	cout << "Do you want to see the instructions for addition of matrices first?" << "(y/n)";
	char cInstructions; 	
	cin >> cInstructions;
	if (cInstructions == 'y' || cInstructions == 'Y')
	{
		matrixSumInstructions();
		cin.get();
	}
	if (cInstructions == 'n' || cInstructions == 'N')
	{
		cout << "ok. No instructions..." << endl << "Press ENTER to continue";
		cin.get();
	}
	else
	{
		cout << "Ups... something is wrong. Try to put y OR n";
		matrixSum();
	}


	cout << "Now put the valuer for the rows:  ";
	cin >> iRowsMatrix;
	cout << "Now put the valuer for the columns:  ";
	cin >> iColumnsMatrix;

	cout << "Now put the valuers for the first matrix (Matrix A)" << endl;
	for (int i = 0; i < iRowsMatrix; i++)
	{

		for (int j = 0; j < iColumnsMatrix; j++)
		{
			cin >> dMatrixA[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "Now put the valuers for the secound matrix (Matrix B)" << endl;
	for (int i = 0; i < iRowsMatrix; i++)
	{

		for (int j = 0; j < iColumnsMatrix; j++)
		{
			cin >> dMatrixB[i][j];
		}
		cout << endl;
	}

	cout << endl;

	cout << "Do your matrixes look like this ?" << endl;

	for (int i = 0; i < iRowsMatrix; i++)
	{

		for (int j = 0; j < iColumnsMatrix; j++)
		{
			cout << dMatrixA[i][j];
		}
		cout << "\t + \t";
		for (int j = 0; j < iColumnsMatrix; j++)
		{
			cout <<" [ " << dMatrixB[i][j] << " ] ";
		}
		cout << endl;
		cout << endl;
	}

	
}

void matrixSubtraction() {

}



void instructions() {

	cout << " A matrix is made of two valuers..." << endl << endl;
	cout << "Rows --->" << endl;
	cout << "Columns |" << endl;
	cout << "        |" << endl;
	cout << "        |" << endl;
	cout << "       \\/" << endl << endl << endl;

}

int main(int arg, char* argv[]) {



	float fMatrixOperation;
	char cInstructions;
	cout << "Do you want to see the instructions ? (y/n)";
	cin >> cInstructions;

	if (cInstructions == 'y' || cInstructions == 'Y')
	{
		instructions();
		cin.get();
	}
	
	if (cInstructions == 'n' || cInstructions == 'N')
	{
		cout << "ok. No instructions..." << endl << "Press ENTER to continue";
		cin.get();
	}



	cout << "Please select the option you want to do..." << endl;
	cout << "(1) for Multiplication of matrices" << endl;
	cout << "(2) for sum of matrices" << endl;
	cout << "(3) for subtraction of matrices" << endl << endl;
	cin >> fMatrixOperation;



	if (fMatrixOperation == 1)
	{
		cout << "matrixMultiplication";
		//matrixMultiplication();
	}
	if (fMatrixOperation == 2)
	{
		cout << "matrixSum";
		//matrixSum();
	}
	if (fMatrixOperation == 3)
	{
		cout << "matrixSubtraction";
		//matrixSubtraction();
	}
	else
	{
		"Ups... something wrong! please restart the program and select a option between 1 and 3";
		exit(4);
	}


	return 0;
}