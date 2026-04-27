
#include <stdio.h>

int comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int temp[100];
    int i = l, j = m + 1, k = l;

    printf("\nMerging: ");
    for(int x = l; x <= r; x++)
        printf("%d ", arr[x]);

    while(i <= m && j <= r) {
        comparisons++;
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= m)
        temp[k++] = arr[i++];

    while(j <= r)
        temp[k++] = arr[j++];

    for(i = l; i <= r; i++)
        arr[i] = temp[i];

    printf("\nAfter Merge: ");
    for(int x = l; x <= r; x++)
        printf("%d ", arr[x]);
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("\n\nSorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTotal comparisons: %d", comparisons);

    return 0;
}