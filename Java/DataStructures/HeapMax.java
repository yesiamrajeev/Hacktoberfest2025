public class MaxHeap<T extends Comparable<T>> {
    private ArrayList<T> heap;

    public MaxHeap() {
        heap = new ArrayList<>();
    }

    public void insert(T data) {
        heap.add(data);
        bubbleUp(heap.size() - 1);
    }

    private void bubbleUp(int index) {
        if (index == 0) return;
        int parentIndex = (index - 1) / 2;
        if (heap.get(index).compareTo(heap.get(parentIndex)) > 0) {
            T temp = heap.get(index);
            heap.set(index, heap.get(parentIndex));
            heap.set(parentIndex, temp);
            bubbleUp(parentIndex);
        }
    }

    public T extractMax() {
        if (heap.isEmpty()) throw new IllegalStateException("Heap is empty");
        T max = heap.get(0);
        T last = heap.remove(heap.size() - 1);
        if (!heap.isEmpty()) {
            heap.set(0, last);
            heapify(0);
        }
        return max;
    }

    private void heapify(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap.get(left).compareTo(heap.get(largest)) > 0) {
            largest = left;
        }
        if (right < heap.size() && heap.get(right).compareTo(heap.get(largest)) > 0) {
            largest = right;
        }

        if (largest != index) {
            T temp = heap.get(index);
            heap.set(index, heap.get(largest));
            heap.set(largest, temp);
            heapify(largest);
        }
    }

    public T peek() {
        if (heap.isEmpty()) throw new IllegalStateException("Heap is empty");
        return heap.get(0);
    }

    public boolean isEmpty() {
        return heap.isEmpty();
    }

    public int size() {
        return heap.size();
    }

    public int height() {
        return (int) Math.floor(Math.log(heap.size()) / Math.log(2));
    }

    public void printHeap() {
        System.out.println(heap);
    }
}
