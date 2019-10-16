
#include <iostream>
#include <cmath>

using namespace std;

bool isPrimeNum(int num)
{
    int top = num / 2;
    for (int i = 2; i <= top; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isInNums(int num, const int *nums, int size)
{
    for (int i = size - 1; i >= 0; i--) {
        if (nums[i] == num) {
            return false;
        }
    }
    return true;
}

void selectNextNum(int nums[], int pos, int n, int size)
{
    if (pos == size) {
        if (!isPrimeNum(nums[0] + nums[pos - 1])) return;
        for (int i = 0; i < size; i++) {
            if (i) cout << " ";
            cout << nums[i];
        }
        cout << endl;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (isInNums(i, nums, pos) && isPrimeNum(i + nums[pos - 1])) {
            nums[pos] = i;
            selectNextNum(nums, pos + 1, n, n);
        }
    }
}

int main()
{
    int n;
    int stage = 1;
    while (cin >> n) {
        if (stage != 1)cout<<endl;

        int* nums = new int[n];
        nums[0] = 1;
        cout << "Case " << stage<< ":" << endl;
        selectNextNum(nums, 1, n, n);

        delete[] nums;
        stage++;
    }
}