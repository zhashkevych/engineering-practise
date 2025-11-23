#include <iostream>
#include <random>
using namespace std;

const char WEATHER_SUNNY = 'S';
const char WEATHER_RAINY = 'R';

const int STATE_SS = 0;
const int STATE_SR = 1;
const int STATE_RS = 2;
const int STATE_RR = 3;

double P[4][2] = {
    {0.9, 0.1}, // SS
    {0.5, 0.5}, // SR
    {0.6, 0.4}, // RS
    {0.3, 0.7}, // RR
};

int encodeState(char stateA, char stateB) {
    if (stateA == WEATHER_SUNNY && stateB == WEATHER_SUNNY) return STATE_SS;
    if (stateA == WEATHER_SUNNY && stateB == WEATHER_RAINY) return STATE_SR;
    if (stateA == WEATHER_RAINY && stateB == WEATHER_SUNNY) return STATE_RS;
    return STATE_RR;
}

void inc(int state, int* sunny, int* rainy) {
    if (state == STATE_SS || state == STATE_RS) (*sunny)++;
    else (*rainy)++;
}

int main() {
    // params
    int N = 1000;

    // get initial state
    char stateA;
    cout << "First inital state (S or R): ";
    cin >> stateA;
    
    char stateB;
    cout << "Second inital state (S or R): ";
    cin >> stateB;

    if ((stateA != WEATHER_SUNNY && stateA != WEATHER_RAINY) ||
        (stateB != WEATHER_SUNNY && stateB != WEATHER_RAINY)) {
        cout << "Incorrect initial state. Termination\n";
        return 0;
    }

    // random numbers generator
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);

    int sunny = 0;
    int rainy = 0;

    // calculation for first 2 days
    inc(encodeState(stateA, stateB), &sunny, &rainy);

    for (int day = 2; day < N; ++day) {
        // detect state, increment counters
        int stateIdx = encodeState(stateA, stateB);
        inc(stateIdx, &sunny, &rainy);

        if (day < 20) {
            cout << "Day #" << day << ": (" << stateA << stateB << ") -> " << stateB << "\n";
        }

        double x = dist(gen);
        
        // Markov transitions
        stateA = stateB;
        stateB = (x < P[stateIdx][0]) ? WEATHER_SUNNY : WEATHER_RAINY;
    }

    cout << "total days: " << N << "\n";
    cout << "rainy days " << static_cast<double>(rainy) / N * 100.0 << "%\n";
    cout << "sunny days " << static_cast<double>(sunny) / N * 100.0  << "%\n";
}
