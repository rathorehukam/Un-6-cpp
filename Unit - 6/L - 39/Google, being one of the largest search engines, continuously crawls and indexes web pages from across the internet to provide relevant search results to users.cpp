











// You are using GCC
#include <iostream>
#include <string>

struct WebPage {
    std::string name;
    bool status;
};

template <typename T>
void push_back(T*& arr, size_t& size, size_t& capacity, const T& value) {
    if (size >= capacity) {
        if (capacity == 0) {
            capacity = 1;
        } else {
            capacity *= 2;
        }

        T* newArr = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    arr[size++] = value;
}

template <typename T>
void displayArray(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i].name << ": " << (arr[i].status ? "Indexed successfully" : "Indexing failed") << std::endl;
    }
}

int main() {
    size_t n;
    std::cin >> n;

    WebPage* webPageUrls = new WebPage[n];
    size_t size = 0;
    size_t capacity = n;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> webPageUrls[i].name;
        std::cin >> webPageUrls[i].status;
        size++;
    }

    std::string updateUrl;
    std::cin >> updateUrl;
    bool newStatus;
    std::cin >> newStatus;

    for (size_t i = 0; i < n; ++i) {
        if (webPageUrls[i].name == updateUrl) {
            webPageUrls[i].status = newStatus;
            break;
        }
    }

    displayArray(webPageUrls, size);

    delete[] webPageUrls;
    return 0;
}
