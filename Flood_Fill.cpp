#include <bits/stdc++.h>
using namespace std;

void floodfill( int r, int c , vector<vector<char> > &input , int i, int j , char color , char tocolor)
{
	if (i < 0 || i >= r || j < 0 || j >= c)return;

	if (input[i][j] != color) return ;

	input[i][j] = tocolor;

	floodfill( r, c, input , i + 1 , j , color , tocolor );
	floodfill( r, c, input , i - 1 , j , color , tocolor );
	floodfill( r, c, input , i , j + 1 , color , tocolor );
	floodfill( r, c, input , i , j - 1 , color , tocolor );
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt" , "r" , stdin);
	freopen("output1.txt" , "w" , stdout);
#endif

	int r, c;

	cin >> r >> c;

	vector<vector<char> > input(r , vector<char> (c));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> input[i][j];
		}
	}

	int i = 2;
	int j = 3;

	floodfill( r, c, input , i, j, '.' , '$');

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << input[i][j] << " ";
		}
		cout << endl;
	}

}