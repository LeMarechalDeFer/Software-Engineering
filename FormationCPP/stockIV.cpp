//"Dynamic Programming with Two Passes" ou "Forward-Backward Scan"

/*
Pour le suivant il faut :
Gestion des contraintes dans les problèmes de DP (nombre limité de transactions ici)
Optimisation mémoire avec Sliding Window (pour réduire la complexité spatiale)


*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size_tab = prices.size();
        if (size_tab == 0) return 0;  // Gérer le cas où la taille du tableau est 0

        std::vector<int> tab_min_profit(size_tab, 0);
        std::vector<int> tab_max_profit(size_tab, 0);
        
        int min_price = INT_MAX;
        int max_price = 0;
        int best_profit = 0;

        // Calculer le profit maximum jusqu'à chaque jour (gauche -> droite)
        for (int i = 0; i < size_tab; i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            if (i > 0) {
                tab_min_profit[i] = std::max(tab_min_profit[i - 1], prices[i] - min_price);  // Profit en vendant à ce jour
            }
        }

        // Calculer le profit maximum après chaque jour (droite -> gauche)
        for (int i = size_tab - 1; i >= 0; i--) {
            if (prices[i] > max_price) {
                max_price = prices[i];
            }
            if (i < size_tab - 1) {
                tab_max_profit[i] = std::max(tab_max_profit[i + 1], max_price - prices[i]);  // Profit en achetant à ce jour
            }
        }

        // Calculer le meilleur profit possible avec deux transactions
        for (int i = 0; i < size_tab; i++) {
            best_profit = std::max(best_profit, tab_min_profit[i] + tab_max_profit[i]);
        }

        return best_profit;
    }
};


/*
123. Best Time to Buy and Sell Stock III
Solved
Hard
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/