# MultiThreaded Merge Sort

This project implements a multithreaded version of the Merge Sort algorithm in C++. It demonstrates the use of threads and mutexes to parallelize the sorting process for improved performance on multi-core systems.

## Features

- Standard Merge Sort implementation.
- Parallel Merge Sort using `std::thread` for concurrent execution.
- Thread-safe operations using `std::mutex`.

## Requirements

- C++17 or later.
- A compiler that supports multithreading (e.g., GCC, Clang).
- `g++` for compilation (if using GCC).

## Compilation and Execution

To compile and run the program, use the following command:

```bash
g++ -std=c++17 -pthread -o main main.cpp ./sorting/mergeSort.cpp ./sorting/parallelMergeSort.cpp && main
```

## File Structure

```
PROJECTS/
└── MultiThreaded_MergeSort/
    ├── main.cpp                # Entry point of the program
    ├── sorting/
    │   ├── mergeSort.cpp       # Standard Merge Sort implementation
    │   ├── parallelMergeSort.cpp # Parallel Merge Sort implementation
    └── README.md               # Project documentation
```

## How It Works

1. **Merge Sort**: A divide-and-conquer algorithm that recursively splits the array into halves, sorts them, and merges them back.
2. **Parallel Merge Sort**: Uses multiple threads to sort different parts of the array concurrently, reducing execution time on multi-core systems.

## License

This project is open-source and available under the MIT License.
