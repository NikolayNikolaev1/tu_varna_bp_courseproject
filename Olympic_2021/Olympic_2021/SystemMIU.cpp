#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MIURules(string& output_str, const char& rule);
int SystemMIU() {
	string current_input;
	string output;

	while (cin >> current_input) {
		output = "MI";

		for (int i = 0; i < current_input.length(); i++) {
			MIURules(output, current_input[i]);
		}

		cout << output << endl;
	}

	return 0;
}

void MIURules(string& output_str, const char& rule) {
	switch (rule) {
	case 'A': {
		if (output_str.back() == 'I') {
			output_str.push_back('U');
		}

		break;
	}
	case 'B': {
		string sub_str = output_str.substr(1, output_str.length());
		output_str.append(sub_str);
		break;
	}
	case 'C': {
		int found_index = output_str.find("III");

		while (found_index != string::npos) {
			output_str.replace(found_index, 3, "U");
			found_index = output_str.find("III");
		}

		break;
	}
	case 'D':
		int found_index = output_str.find("UU");

		while (found_index != string::npos) {
			output_str.replace(found_index, 2, "");
			found_index = output_str.find("UU");
		}

		break;
	}
}
