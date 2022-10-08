//#ifdef CONNECT_H
//#define CONNECT_H

#include <iostream>
using namespace std;

class CONNECT4
{
private:
	int size;
	int arr[7][7];
	bool won;     // variable for determining either player won or not.
	int turn;
public:
	CONNECT4();

	void ShowBoard();

	bool OutofBound(int row,int column);

	bool IsWon(int row, int column);

	bool SpaceCheck(int column);

	bool IsBoardFull();

	void SwitchTurn();

	void Start();

};
//#endif