// Lab_10.2
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void formt(string& str) {
	size_t pos_space = str.find(' '),
		start = 0, end = 0, tos;
	string m;
	while (start = str.find_first_of("0123456789", start), start < pos_space&& start != -1) {
		end = str.find_first_not_of("0123456789.,", start + 1);
		m = str.substr(start, end - start);
		if (tos = m.find_first_of(".,"), tos != -1 && tos + 3 < m.length()) {
			m = to_string(stof(m));
			tos = m.find_first_of(".,");
			m = m.substr(0, tos + 3);
			str.replace(start, end - start, m);
			pos_space -= end - start - m.length();
			start += m.length() + 1;
		}
		else start = end;
	}
}

void formt_file(ifstream &in, ofstream &out) {
	string tmp;
	while (!in.eof()) {
		getline(in, tmp);
		formt(tmp);
		out << tmp << endl;
	}
}

void main() {
	string t = "r.txt", t2 = "m.txt";

	cout << "Input input  filename: "; cin >> t;
	cout << "Input output filename: "; cin >> t2;

	ifstream in_file(t);
	ofstream out_file(t2);
	if (in_file.is_open()) {
		if (out_file.is_open())
		{
			formt_file(in_file, out_file);
			cout << "File successfully formatted!";
			out_file.close();
		}else cout << "Can't open output file!";
		in_file.close();
	}
	else cout << "Can't open input file!";
	cout << endl;
}