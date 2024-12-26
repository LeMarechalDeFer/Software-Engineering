        #include <iostream>
#include <vector>

// Linear Scan Algorithm (Algorithme de balayage linéaire):
// - Recherche d'éléments spécifiques (Linear Search)
// - Calculs simples : maximum, minimum, somme, etc.
// - Détection ou comptage d'éléments
// - Extraction ou vérification conditionnelle
// - Analyse de sous-séquences
//    - Single Pass Algorithm
//    - Kadane's Algorithm




// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int min  = 0;
//         int max  = 0;
//         int i ;
//         int profit;
//         for(i = 0; i< prices.size(); i++){
//             profit = price[0] - prices[i] ;
//             if(profit>max){
//                 profit = max ;
//             }
//         }


//     }
// };


// OK mais trop complexe o(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max  = 0;
        int i, j ;
        int profit;
        for(i = 0; i< prices.size(); i++){
            for(j=0; j< prices.size(); j++){
                profit = prices[j] - prices[i] ;
                if(profit>max && i<j){
                    max = profit ;
                }
            }
        }
        return max ;
    }
};

//incorrect 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int min = 0; 
        int i ;
        int profit;
        for(i = 0; i< prices.size(); i++){
            profit = prices[i] - prices[min];
            if(profit < prices[min]){
                min = i ;
            }
            if(profit>prices[max]){
                max = i ;
            }
            
        }
        if(max=0){
            return 0;
        }else{
            return profit = prices[max]-prices[min];
        }
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.empty()){
            return 0 ;
       }

       int minPrice = prices[0];
       int maxProfit = 0 ;
       int profit ; 
       int i;

       for(i=0 ; i < prices.size(); i++){
            profit = prices[i] - minPrice;

            if(profit > maxProfit){
                maxProfit = profit ;
            }

            if(prices[i] < minPrice ){
                minPrice = prices[i];
            }
       }
       return maxProfit;
    }
};      