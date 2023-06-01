#include "Function.h"

int main()
{
	ifstream map_file,in_file;
	ofstream out_file;
	
	map_file.open("map.txt");
	in_file.open("text.txt");
	out_file.open("transformed.txt");

	word_transform(map_file, in_file, out_file);

	map_file.close();
	in_file.close();
}