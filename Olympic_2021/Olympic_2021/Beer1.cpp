#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Beer1() {
	vector<int> beer_prices;
	int beer_count, money, price, total_pairs = 0;

	while (cin >> beer_count >> money) {
		if (beer_count == 0 && money == 0) {
			break;
		}

		while (beer_count--) {
			cin >> price;
			beer_prices.push_back(price);
		}

		sort(beer_prices.begin(), beer_prices.end(), greater<int>());

		int counter = 1;

		for (int current_price : beer_prices) {
			for (int i = counter; i < beer_prices.size(); i++) {
				if (current_price + beer_prices[i] <= money) {
					total_pairs += beer_prices.size() - i;
					break;
				}
			}

			counter++;
		}


		cout << total_pairs << endl;
		total_pairs = 0;
		beer_prices.erase(beer_prices.begin(), beer_prices.end());
	}


	return 0;
}

