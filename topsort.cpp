#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <fstream>
using namespace std;

long long factorial(int n)
{
	if (n == 20)
		cout << "(!) Warning: possible LL overflow" << endl;
	if (n == 13)
		cout << "(!) Warning: possible unbearably long computation" << endl;
	
	if (n == 0) return 1;
	return 1ll*n*factorial(n-1);
}

set<string> vertices;
vector<pair<string, string>> edges;


bool check_perm(vector<string> perm)
{
	for (pair<string, string> condition : edges)
	{
		string i = condition.first, j = condition.second;
		int i_p = find(perm.begin(), perm.end(), i) - perm.begin(),
			j_p = find(perm.begin(), perm.end(), j) - perm.begin();
		if (i_p > j_p)
			return false;
	}
	return true;
}

int main()
{
	ifstream in("input.txt");
	vector<string> input;
	string t;
	while (in >> t)
	{
		input.push_back(t);
		vertices.insert(t);
	}
	cout << "Vertices: ";
	for (string v : vertices)
	{
		cout << v << " ";
	}
	cout << endl;
	
	assert(input.size() % 2 == 0);
	
	for (int i = 0; 2*i+1 < input.size(); i++)
	{
		edges.push_back({input[2*i], input[2*i+1]});
	}
	
	cout << "Edges: " << endl;
	for (pair<string, string> e : edges)
	{
		cout << e.first << " < " << e.second << endl;
	}
	
	long long k = 0;
	vector<string> perm;
	for (string v : vertices) perm.push_back(v);
	
	do
	{
		if (check_perm(perm) == true)
		{
			k++;
			cout << "|";
			for (string v : perm)
				cout << v << "|";
			
			cout << " ";
		}
	} while (next_permutation(perm.begin(), perm.end()));
	
	cout << endl;
	cout << "Total permutations: " << k << " out of " << factorial(vertices.size()) << endl;
	
	int numer = k, denom = factorial(vertices.size());
	int g = __gcd(numer, denom);
	numer /= g, denom /= g;
	cout << numer << "/" << denom;
	cout << endl;
	
}