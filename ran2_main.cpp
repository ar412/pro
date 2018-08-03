#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX_HEIGHT 610
#define MAX_WIDTH 10
#define BLK_SIZE 3

enum ROTATE {
	ROTATE_90 = 1,
	ROTATE_180,
	ROTATE_270,
	ROTATE_360
};

enum CMD {
	INIT = 1,
	NEW_CANDY,
	ROTATE,
	MOVE,
	TIMEDBOMB,
	GROUND
};

// Initialize the grid with a defined width
extern void InitGrid(int width);

// Add a new candy pair at (0,1) locaiton on the top of the grid
extern void AddCandyPair(int candy[]);

// Rotate candy pair by rot steps { 1 -> 90 degree, 2 -> 180 degree, 3 -> 270 degree, 4 -> 360 degree }
extern void RotateCandyPair(int rot);

// Move candy pair horizontally left & right (-10 <= dist <= 10)
extern void MoveCandyPair(int dist);

// Add a bomb chain, with length = count & TimerToBlast = life
extern void AddTimedBomb(int count, int life);

// Drop the candy pair OR bomb to the ground level, return the max height of the top-most row that is occupied (with single candy or more)
extern int GroundCandyPair();

extern void GetTC();

int main(void)
{
	int T, WB, NC, cmd;
	int nc, rot, dis, hc, hl;
	int block[2];

	setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> NC;
		cout << "case #" << tc + 1 << endl;

		nc = 0;

		while (nc < NC)
		{
			cin >> cmd;
			switch (cmd)
			{
			case INIT:
				cin >> WB;
				InitGrid(WB);
				break;
			case NEW_CANDY:
				cin >> block[0] >> block[1];
				AddCandyPair(block);
				break;
			case ROTATE:
				cin >> rot;
				RotateCandyPair(rot);
				break;
			case MOVE:
				cin >> dis;
				MoveCandyPair(dis);
				break;
			case TIMEDBOMB:
				cin >> hc >> hl;
				AddTimedBomb(hc, hl);
				break;
			case GROUND:
				cout << GroundCandyPair() << endl;
				nc++;
				break;
			}
		}
	}
}