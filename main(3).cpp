#include <vector>
#include <iostream>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        counts = std::vector<int>(101, 0);
        numCount = 0;
    }

    void addNum(int num) {
        counts[num]++;
        numCount++;
    }

    double findMedian() {
        int medianPos = numCount / 2;
        int median1 = -1, median2 = -1;
        int count = 0;

        for (int i = 0; i <= 100; i++) {
            count += counts[i];
            if (numCount % 2 == 0) {
                if (count == medianPos - 1) {
                    median1 = i;
                } else if (count == medianPos) {
                    median2 = i;
                    break;
                }
            } else {
                if (count > medianPos) {
                    median1 = i;
                    break;
                }
            }
        }

        if (numCount % 2 == 0) {
            return (median1 + median2) / 2.0;
        } else {
            return median1;
        }
    }

private:
    std::vector<int> counts;
    int numCount;
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    std::cout << medianFinder.findMedian() << std::endl; // Output: 1.5
    medianFinder.addNum(3);
    std::cout << medianFinder.findMedian() << std::endl; // Output: 2.0

    return 0;
}
