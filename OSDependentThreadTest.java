public class OSDependentThreadTest {
    static final int THREAD_COUNT = 500; // Adjust for your machine
    static final int ITERATIONS = 1000;

    public static void main(String[] args) throws InterruptedException {
        long start = System.currentTimeMillis();

        Thread[] threads = new Thread[THREAD_COUNT];

        for (int i = 0; i < THREAD_COUNT; i++) {
            threads[i] = new Thread(() -> {
                for (int j = 0; j < ITERATIONS; j++) {
                    try {
                        // simulate work with a timed wait (not sleeping the CPU)
                        synchronized (Thread.currentThread()) {
                            Thread.currentThread().wait(1);  // Mac handles this much better
                        }
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
            });
            threads[i].start();
        }

        for (int i = 0; i < THREAD_COUNT; i++) {
            threads[i].join();
        }

        long end = System.currentTimeMillis();
        System.out.println("Total execution time: " + (end - start) + " ms");
    }
}