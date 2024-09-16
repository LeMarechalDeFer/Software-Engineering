#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

int findMinDifference(std::vector<std::string>& timePoints) {
    int size_tab = timePoints.size();
    std::vector<int> totalTime(size_tab); 

    // Convertir chaque heure en minutes totales depuis minuit
    for (int i = 0; i < size_tab; i++) {
        std::string hour_string = timePoints[i].substr(0, 2);
        std::string minute_string = timePoints[i].substr(3, 2);

        int hour_int = std::stoi(hour_string);
        int minute_int = std::stoi(minute_string);

        // Convertir l'heure en minutes totales
        totalTime[i] = minute_int + (60 * hour_int);
    }

    // Trier les temps en minutes
    std::sort(totalTime.begin(), totalTime.end());

    // Initialiser la différence minimale avec une valeur grande
    int minDiff = std::numeric_limits<int>::max();

    // Parcourir le tableau et comparer les écarts consécutifs
    for (size_t i = 1; i < totalTime.size(); ++i) {
        int diff = totalTime[i] - totalTime[i - 1];
        minDiff = std::min(minDiff, diff);
    }

    // Gérer le cas cyclique entre le dernier et le premier temps
    int wrapAroundDiff = (1440 - totalTime.back()) + totalTime.front(); // 1440 = 24 * 60
    minDiff = std::min(minDiff, wrapAroundDiff);

    return minDiff;
}

int main() {
    std::vector<std::string> timePoints = {"23:59", "00:00"};

    std::cout << "La durée minimale est : " << findMinDifference(timePoints) << " minutes" << std::endl;

    return 0;
}
