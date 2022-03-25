from threading import Thread, Semaphore
import time
import random

queue = []
MAX_NUM = 5

semaphore = Semaphore()


class Producer(Thread):
    def run(self):
        nums = range(10)
        global queue

        while True:
            semaphore.acquire()

            if len(queue) == MAX_NUM:
                print("Queue is full, Producer will wait for queue to have space")
                semaphore.release()
                print("Queue has space which was notified by the Consumer to the Producer")

            num = random.choice(nums)
            queue.append(num)
            print("Produced", num)
            semaphore.release()

            time.sleep(random.random())


class Consumer(Thread):
    def run(self):
        global queue

        while True:
            semaphore.acquire()

            if not queue:
                print("Queue is empty, Consumer will wait for queue to have some data")
                semaphore.release()
                print("Queue has data which was notified by the Producer to the Consumer")

            num = queue.pop(0)
            print("Consumed", num)
            semaphore.release()

            time.sleep(random.random())

if __name__ == "__main__":
    Producer().start()
    Consumer().start()
