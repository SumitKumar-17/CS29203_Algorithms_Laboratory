#include <stdio.h>
#include <stdlib.h>


struct Point {
    double x, y;
};


void merge(struct Point points[], int indices[], int left, int mid, int right, int dominant_indices[]) {
    int i = left, j = mid + 1, k = 0;
    int* temp_indices = (int*)malloc((right - left + 1) * sizeof(int));
    
    while (i <= mid && j <= right) {
        if (points[indices[i]].x < points[indices[j]].x) {
            dominant_indices[indices[i]] += j - mid - 1;
            temp_indices[k++] = indices[i++];
        } else {
            temp_indices[k++] = indices[j++];
        }
    }
    
    while (i <= mid) {
        dominant_indices[indices[i]] += j - mid - 1;
        temp_indices[k++] = indices[i++];
    }
    
    while (j <= right) {
        temp_indices[k++] = indices[j++];
    }
    
    for (i = 0; i < k; ++i) {
        indices[left + i] = temp_indices[i];
    }
    
    free(temp_indices);
}


void compute_dominant_indices(struct Point points[], int indices[], int left, int right, int dominant_indices[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        compute_dominant_indices(points, indices, left, mid, dominant_indices);
        compute_dominant_indices(points, indices, mid + 1, right, dominant_indices);
        merge(points, indices, left, mid, right, dominant_indices);
    }
}

int main() {
    struct Point points[] = {
        {0.513533, 0.663353}, {0.419047, 0.379945}, {0.238431, 0.269107},
        {0.753736, 0.624979}, {0.561628, 0.204133}, {0.693606, 0.244839},
        {0.189784, 0.162833}, {0.748571, 0.837021}, {0.271007, 0.106876},
        {0.253977, 0.136737}
    };
    int n = sizeof(points) / sizeof(points[0]);
    int* indices = (int*)malloc(n * sizeof(int));
    int* dominant_indices = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }

    compute_dominant_indices(points, indices, 0, n - 1, dominant_indices);

    printf("Dominant indices: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", dominant_indices[i]);
    }
    printf("\n");

    free(indices);
    free(dominant_indices);
    
    return 0;
}