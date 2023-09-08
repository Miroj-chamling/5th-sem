#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int numPoints;
    cout << "Enter the number of random points to generate: ";
    cin >> numPoints;

    int pointsInsideCircle = 0;

    for (int i = 0; i < numPoints; ++i) {
        // Generate random coordinates between -1 and 1
        double x = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
        double y = static_cast<double>(rand()) / RAND_MAX * 2 - 1;

        // Check if the point is inside the quarter unit circle
        if (x * x + y * y <= 1) {
            pointsInsideCircle++;
        }
    }

    // Estimate p using the Monte Carlo method
    double pi = 4.0 * static_cast<double>(pointsInsideCircle) / numPoints;

    cout << "Estimated value of pI: " << pi << endl;

    return 0;
}
