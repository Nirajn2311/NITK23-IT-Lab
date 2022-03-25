from multiprocessing import Process, shared_memory


def ipc_sm(shm_name, rw, data=None):
    mem = shared_memory.SharedMemory(shm_name)
    if rw:
        mem.buf[:len(data)] = bytes(data, encoding='utf-8')
        print("\nData written in memory:", data)
    else:
        print("\nData read from memory:", str(
            bytes(mem.buf), encoding='utf-8').rstrip('\x00'))


if __name__ == "__main__":
    mem_size = int(input("Enter shared memory size: "))
    data = input("Enter data to be stored in memory: ")

    if mem_size <= 0:
        print("\nINVALID/NULL SIZE ENTERED!!")
        exit()

    if len(data) > mem_size:
        print("\nDATA LENGTH GREATER THAN MEMORY LENGTH!!")
        exit()

    shm = shared_memory.SharedMemory(create=True, size=mem_size)

    p_w = Process(target=ipc_sm, args=(shm.name, 1, data))
    p_w.start()
    p_w.join()

    p_r = Process(target=ipc_sm, args=(shm.name, 0))
    p_r.start()
    p_r.join()

    shm.close()
    shm.unlink()
