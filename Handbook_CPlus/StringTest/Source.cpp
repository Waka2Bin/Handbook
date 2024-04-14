#include <iostream>
#include <string>


using namespace std;

int main() {
	string s = "asdfg kfghk fgkh";
	size_t pos = s.find('d');
	size_t pos1 = s.find(' ');
	size_t pos2 = s.find(' ',pos1+1);
	string sub = s.substr(pos);
	string sub1 = s.substr(pos2+1);

	cout << pos<<endl;
	cout << sub << endl;
	cout << sub1 << endl;

}
