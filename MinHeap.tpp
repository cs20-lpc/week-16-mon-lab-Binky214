template <typename T>
void MinHeap<T>::siftUp(int i) {

    // move node upwards if smaller than its parent
    while (i > 0 && data[i] < data[parent(i)]) {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {

    // grab size of array
    int n = size();

    // move node downwards by swapping with smallest child
    while (true) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        // if left is smaller
        if (l < n && data[l] < data[smallest]) {
            smallest = l;
        }

        // if right is smaller
        if (r < n && data[r] < data[smallest]) {
            smallest = r;
        }

        // if right/left is smaller than parent
        if (smallest != i) {
            swap(data[i], data[smallest]);
            i = smallest;
        }

        // exit if smallest
         else {
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {

    // add value
    data.push_back(value);

    // sift up into proper position
    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {

    // empty case
    if (empty()) {
        throw runtime_error("Heap is empty");
    }

    // save root 
    T rootValue = data[0];

    // move last element to root
    data[0] = data.back();

    // pop last element (which is now root)
    data.pop_back();

    // sift down if not empty
    if (!empty()) {
        siftDown(0);
    }

    // return original root value
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {

    // invalid index case
    if (index < 0 || index >= size()) {
        throw runtime_error("Invalid index");
    }
    
    // swap the index want to remove to the end of the array
    swap(data[index], data.back());

    // remove end of the array index (which was moved in the line before)
    data.pop_back();

    // resort
    if (index < size()) {
        // attempt sift up
        siftUp(index);

        // restore heap property
        siftDown(index);
    }
}