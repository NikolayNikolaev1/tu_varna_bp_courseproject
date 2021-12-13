#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> towers(3);
vector<int> disk_positions;
void Hanoi(int source_tower, int target_tower, int count);
void Output();

int HanoiTower() {
	int disk_count;
	cin >> disk_count;
	// Creates helper vector with 1-based values, showing that all the disks are in the first tower.
	disk_positions = vector<int>(disk_count + 1, 1);
	// Sets all disks in the first tower vector.
	for (int i = disk_count; i >= 1; i--) {
		towers[0].push_back(i);
	}

	Output();
	Hanoi(0, 2, disk_count);

	return 0;
}

// Recursive.
void Hanoi(int source_tower, int target_tower, int count) {
	if (count == 0) {
		return;
	}
	
	int free_tower = 3 - source_tower - target_tower;
	Hanoi(source_tower, free_tower, count - 1);

	int top_disk = towers[source_tower].back();
	towers[source_tower].pop_back();
	towers[target_tower].push_back(top_disk);

	disk_positions[top_disk] = target_tower + 1;
	Output();

	Hanoi(free_tower, target_tower, count - 1);
}

void Output() {
	// Outputs the current disk positions.
	for (int i = 1; i < disk_positions.size(); i++) {
		cout << disk_positions[i] << " ";
	}

	cout << endl;
}