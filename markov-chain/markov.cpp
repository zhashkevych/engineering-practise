#include <iostream>
#include <random>
using namespace std;

const char WEATHER_SUNNY = 'S';
const char WEATHER_RAINY = 'R';

double P[2][2] = {
    {0.8, 0.2}, // S -> S, S -> R
    {0.4, 0.6}, // R -> S, R -> R
};

int main() {
    // params
    int N = 1000;

    // get initial state
    char state;
    cout << "Start state (S or R): ";
    cin >> state;

    if (state != WEATHER_SUNNY && state != WEATHER_RAINY) {
        cout << "Incorrect initial state. Termination\n";
        return 0;
    }

    // random numbers generator
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);

    int sunny = 0;
    int rainy = 0;

    for (int day = 0; day < N; ++day) {
        // count current state
        if (state == WEATHER_SUNNY) sunny++;
        else rainy++;

        if (day < 20) {
            cout << "day #" << day << ". state -> " << state << "\n";
        }
        
        double x = dist(gen);
        
        // Markov transitions
        int idx = (state == WEATHER_SUNNY) ? 0 : 1;
        state = (x < P[idx][0]) ? WEATHER_SUNNY : WEATHER_RAINY;
    }

    cout << "total days: " << N << "\n";
    cout << "rainy days " << static_cast<double>(rainy) / N * 100.0 << "%\n";
    cout << "sunny days " << static_cast<double>(sunny) / N * 100.0  << "%\n";
}
