
class MinAndMaxHeap {
public:
    static vector<int> buildHeap(vector<int> heap, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(heap, n, i);
        }
        return heap;
    }

    static void heapify(vector<int>& heap, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            heapify(heap, n, largest);
        }
    }
};Priority Queue
