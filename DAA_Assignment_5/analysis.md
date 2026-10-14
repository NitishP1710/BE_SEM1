# Quick Sort: Deterministic and Randomized

## Aim
To implement and compare Deterministic Quick Sort and Randomized Quick Sort.

## Algorithm

### 1. Deterministic Quick Sort
1. Select the last element as the pivot.
2. Partition the array around the pivot.
3. Recursively sort the left and right subarrays.

### 2. Randomized Quick Sort
1. Select a random element as the pivot.
2. Swap it with the last element.
3. Partition the array around the pivot.
4. Recursively sort the left and right subarrays.

## Test Case

**Input**
```text
Enter number of elements: 6
Enter elements:
9 4 7 2 8 1
```

**Output**
```text
Deterministic Quick Sort:
1 2 4 7 8 9

Randomized Quick Sort:
1 2 4 7 8 9
```

## Complexity Analysis

| Case | Deterministic | Randomized (Expected) |
|---|---|---|
| Best | O(n log n) | O(n log n) |
| Average | O(n log n) | O(n log n) |
| Worst | O(n²) | O(n²) |
| Auxiliary Space (Worst) | O(n) | O(n) |

## Conclusion
Both algorithms sort the array using divide and conquer. Deterministic Quick Sort selects a fixed pivot, whereas Randomized Quick Sort selects a random pivot, reducing the likelihood of consistently unbalanced partitions on structured inputs.