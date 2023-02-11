/*Input
The input consists of several test cases. Each test case begins with an integer N (3 ≤ N ≤ 2000) then have N rows, each containing two integers X and Y (-2000 ≤ X, Y ≤ 2000) indicating the coordinates of each supercomputer within the deposit. The input ends with N = 0 and should not be processed.

Output
For each test case you should print: "Tera que comprar uma fita de tamanho x.", Where x is the total of tape required to cover all computers, with two decimal places.
Input sample:		 Output sample: 
6			 tera que comprar uma fita de tamanho 27.78.			
0 8                      tera que comprar uma fita de tamanho 12.00.
1 6
8 7
6 6
8 0
3 1
5
1 1
1 4
2 3
4 4
4 1
0
 */
#include <algorithm>
#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
float result = 0;
// iPair is integer pairs
#define iPair pair<int, int>
// Stores the result (points of convex hull)
set<iPair> hull;

typedef struct{
    int x;
    int y;
}ponto;
// Returns the side of point p with respect to line
// joining points p1 and p2.
int findSide(iPair p1, iPair p2, iPair p)
{
	int val = (p.second - p1.second) * (p2.first - p1.first) -(p2.second - p1.second) * (p.first - p1.first);

	if (val > 0)
		return 1;
	if (val < 0)
		return -1;
	return 0;
}
// returns a value proportional to the distance
// between the point p and the line joining the
// points p1 and p2
int lineDist(iPair p1, iPair p2, iPair p)
{
	return abs ((p.second - p1.second) * (p2.first - p1.first) -(p2.second - p1.second) * (p.first - p1.first));
}

float perimeter(iPair p1, iPair p2){
    return sqrt(pow(p1.first - p2.first, 2) + (pow(p1.second - p2.second, 2)));
}
// End points of line L are p1 and p2. side can have value
// 1 or -1 specifying each of the parts made by the line L
void quickHull(iPair a[], int n, iPair p1, iPair p2, int side)
{
	int ind = -1;
	int max_dist = 0;
	
	for (int i=0; i<n; i++)
	{
		int temp = lineDist(p1, p2, a[i]);
		if (findSide(p1, p2, a[i]) == side && temp > max_dist)
		{   
		    
			ind = i;
			max_dist = temp;
			
		}
	}

	if (ind == -1)
	{
	    result = perimeter(p1, p2) + result;
		hull.insert(p1);
		hull.insert(p2);
		return;
	}

	quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
	quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}
vector<ponto> printHull(iPair a[], int n){
	
	int min_x = 0, max_x = 0;
	for (int i=1; i<n; i++)
	{
		if (a[i].first < a[min_x].first )
			min_x = i;
		if (a[i].first > a[max_x].first)
			max_x = i;
	}

	
	quickHull(a, n, a[min_x], a[max_x], 1);

	quickHull(a, n, a[min_x], a[max_x], -1);

	ponto p;
	vector<ponto>all;
	while (!hull.empty())
	{
	
		p.x= (*hull.begin()).first;
		p.y= (*hull.begin()).second;
		all.push_back(p);
		hull.erase(hull.begin());
	}
	return all;
}


int main()
{
    int amount_of_points;
    cin >> amount_of_points;
    vector<float>awnser;
    //Make some case using the amount_of_points to store, all much points each case will have and calculate the perimeter of each polygon
    while(amount_of_points != 0){
        iPair a[2001];
        for (int i = 0; i < amount_of_points; i++) {
            int x, y;
            cin >> x >> y;
            a[i] = std::make_pair(x, y);
        }
        vector<ponto> pontos;
        pontos = printHull(a, amount_of_points);
        awnser.push_back(result);
        result =0;
        cin>>amount_of_points;
    }
    for(int i =0; i <awnser.size();i++){
        printf("Tera que comprar uma fita de tamanho %.2f.\n", awnser[i]);
    }
	return 0;
}



