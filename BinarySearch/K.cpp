#include <iostream>
#include <vector>

using namespace std;

bool isThisTimePos(long long M, long long N, vector<long long>& T, vector<long long>& Z, vector<long long>& Y, long long guess)
{
    long long count = 0;
    long long timeLeft;

    for (long long i = 0; i < N; i++) {
        timeLeft = guess;

        while (timeLeft > 0) {
            if (T[i] * Z[i] >= timeLeft) {
                count += timeLeft / T[i];
                timeLeft = -1;
            } else {
                count += Z[i];
                timeLeft -= T[i] * Z[i];
                timeLeft -= Y[i];
            }
        }

        if (count >= M) {
            break;
        }
    }

    return count >= M;
}

long long findMinTime(long long M, long long N, vector<long long>& T, vector<long long>& Z, vector<long long>& Y)
{
    long long left = -1;
    long long right = (100 + 100) * M + 1;
    long long guess;

    while (right - left > 1) {
        guess = left + (right - left) / 2;
        if (isThisTimePos(M, N, T, Z, Y, guess) == true) {
            right = guess;
        } else {
            left = guess;
        }
    }
    return right;
}

void findEachCount(long long M, long long N, vector<long long>& T, vector<long long>& Z, vector<long long>& Y, long long time)
{
    vector<long long> counts (N, 0);
    long long sumCounts = 0;
    long long packets;
    for (long long i = 0; i < N; i++) {
        packets = time / (T[i] * Z[i] + Y[i]);
        counts[i] = packets * Z[i];
        counts[i] += min((time - packets * (T[i] * Z[i] + Y[i])) / T[i], Z[i]);
        sumCounts += counts[i];
    }

    long long overage = sumCounts - M;

    long long deleting;
    for (long long i = N - 1; i > -1; i--) {
        deleting = min(counts[i], overage);
        counts[i] -= deleting;
        overage -= deleting;
        if (overage == 0) {
            break;
        }
    }

    for (long long i = 0; i < N; i++) {
        cout << counts[i] << " ";
    }
}

int main()
{
    long long M, N;
    cin >> M >> N;

    vector<long long> T, Z, Y;
    long long input;

    for (long long i = 0; i < N; i++) {
        cin >> input;
        T.push_back(input);

        cin >> input;
        Z.push_back(input);

        cin >> input;
        Y.push_back(input);
    }

    long long minTime = findMinTime(M, N, T, Z, Y);

    cout << minTime << "\n";

    findEachCount(M, N, T, Z, Y, minTime);
}