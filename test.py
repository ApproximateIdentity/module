import module
import threading


thread_groups = []

for j in xrange(100):
    threads = []
    for i in xrange(10):
        l = [str(val) for val in xrange(i)]
        t = threading.Thread(target=module.print_strings, args=(l,))
        threads.append(t)
    [t.start() for t in threads]
    thread_groups.append(threads)

for threads in thread_groups:
    [t.join() for t in threads]
