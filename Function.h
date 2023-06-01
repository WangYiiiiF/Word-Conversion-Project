#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

void word_transform(ifstream& map_file, ifstream& input);
map<string, string> buildMap(ifstream& map_file);
const string& transform(const string& s, const map<string, string>& m);

void word_transform(ifstream& map_file, ifstream& input, ofstream& out_file)
{
	auto tran_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
			{
				cout << " ";
				out_file << " ";
			}
			cout << transform(word, tran_map);
			out_file << transform(word, tran_map);
		}
		cout << endl;
		out_file << endl;
	}
}

map<string, string> buildMap(ifstream& map_file)
{
	map<string, string> trans_map;
	string key;
	string value;

	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	return trans_map;

}

const string& transform(const string& s, const map<string, string>& m)
{
	auto map_it = m.find(s);

	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}
