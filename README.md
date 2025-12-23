# Processes_Threads_IPC
## Study Folder - Operating Systems 

### `forks/`
Examples using **process creation (`fork()`)** and execution control.

| File | Description |
|------|-------------|
| `fork.c` | Basic fork example showing parent and child PIDs. |
| `fork_wait.c` / `fork_wait.cpp` | Demonstrates `fork()` with `wait()` to synchronize parent and child. |
| `fork_exec.c` | Shows `fork()` combined with `execvp()` to run an external program. |
| `fork_concurrency.cpp` | Illustrates parent and child running concurrently, printing interleaved output. |

---

### `memory/`

#### `IPC/`
System V Shared Memory examples.

| File | Description |
|------|-------------|
| `SHMServer.c` | Creates a shared memory segment and writes data for a client. |
| `SHMClient.c` | Reads data from the shared memory created by the server. |

#### `mapped_memory/`
Memory-mapped file examples (`mmap()`).

| File | Description |
|------|-------------|
| `mmap_write.c` | Writes a random integer to a memory-mapped file. |
| `mmap_read.c` | Reads the integer from the memory-mapped file and modifies it. |

#### `simple_shared_memory.c`
Demonstrates basic allocation, writing, detaching, and reattaching of shared memory within a single process.

---

### `threads/`
Examples using **POSIX threads (`pthread`)** and synchronization.

| File | Description |
|------|-------------|
| `arrow_th_mutex.c` | Two threads printing arrows with a mutex to avoid interleaved output. |
| `arrow_th_semaphore.c` | Same as above but using semaphores instead of a mutex. |
| `arrows_thread1.c` | Threads printing arrows without any synchronization (chaotic output). |
| `thread_create_bugFree.c` | Thread example with proper `pthread_join()` to ensure completion. |
| `thread_create_withBug.c` | Thread example without `pthread_join()`, may terminate prematurely. |

---
## OS concepts in practice
- How **processes** are created, scheduled, and synchronized.
- How **threads** share resources and require **mutexes or semaphores**.
- How **inter-process communication (IPC)** works via **shared memory** or **memory-mapped files**.
- How synchronization affects **output order, mutual exclusion, and data consistency**.
