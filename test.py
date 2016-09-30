import module
import threading


threads = []

for i in xrange(10):
    l = [str(val) for val in xrange(i)]
    t = threading.Thread(target=module.print_strings, args=(l,))
    threads.append(t)

[t.start() for t in threads]
[t.join() for t in threads]
