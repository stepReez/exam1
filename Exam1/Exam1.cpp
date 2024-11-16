
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

float multiply(int start, int end, vector<float> vector) {
    float mul = 1;
    for (int i = start + 1; i < end; i++) {
        mul *= vector[i];
    }
    return mul;
}

int main()
{
    cout << "Enter array size: ";
    int n;
    cin >> n;

    vector<float> array(n);
    float sum = 0;
    
    bool sign = true;

    
    float fabsMax = 0;
    float fabsMin = numeric_limits<float>::max();;

    int minIndex;
    int maxIndex;

    float x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        array[i] = x;
        if (x > 0) {
            sum += x;
        }

        if (x > fabsMax) {
            fabsMax = x;
            maxIndex = i;
        }

        if (fabs(x) < fabsMin) {
            fabsMin = fabs(x);
            minIndex = i;
        } 
    }

    float mul;

    if (minIndex < maxIndex) {
        mul = multiply(minIndex, maxIndex, array);
    }
    else {
        mul = multiply(maxIndex, minIndex, array);
    }
    
    cout << "Sum of positive elements of an array: " << sum << endl;
    cout << "The result of multiplying the elements of an array located between the maximum and minimum absolute elements: " << mul << endl;

}
