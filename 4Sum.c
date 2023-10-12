#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find four sum quadruplets
void fourSum(int nums[], int n, int target) {
    qsort(nums, n, sizeof(int), compare); // Sort the array
    int i, j, k, l;

    for (i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Avoid duplicates

        for (j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Avoid duplicates

            k = j + 1;
            l = n - 1;

            while (k < l) {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    printf("[%d, %d, %d, %d]\n", nums[i], nums[j], nums[k], nums[l]);

                    // Skip duplicates
                    while (k < l && nums[k] == nums[k + 1]) k++;
                    while (k < l && nums[l] == nums[l - 1]) l--;

                    k++;
                    l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
}

int main() {
    int nums[] = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    printf("The quadruplets are:\n");
    fourSum(nums, n, target);

    return 0;
}

// OUTPUT:

// The quadruplets are:
// [1, 1, 3, 4]
// [1, 2, 2, 4]
// [1, 2, 3, 3]

