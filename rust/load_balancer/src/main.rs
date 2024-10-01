use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

struct Worker {
    id: usize,
    is_running: Arc<Mutex<bool>>,
}

impl Worker {
    fn new(id: usize) -> Self {
        Worker {
            id,
            is_running: Arc::new(Mutex::new(true)),
        }
    }

    fn start(&self) -> Arc<Mutex<bool>> {
        let is_running = self.is_running.clone();
        let id = self.id;
        thread::spawn(move || {
            println!("Worker {} started.", id);
            while *is_running.lock().unwrap() {
                // Simulate doing work
                thread::sleep(Duration::from_millis(100));
            }
            println!("Worker {} stopped.", id);
        });
        self.is_running.clone()
    }

    fn stop(&self) {
        let mut running = self.is_running.lock().unwrap();
        *running = false;
    }

    fn health_check(&self) -> bool {
        // Simulate a health check
        *self.is_running.lock().unwrap()
    }
}

fn main() {
    // Create workers
    let worker1 = Worker::new(1);
    let worker2 = Worker::new(2);
    let standby_worker = Worker::new(3);

    // Start workers
    let worker1_handle = worker1.start();
    let worker2_handle = worker2.start();
    let standby_handle = standby_worker.start();

    // Shared state for round-robin
    let counter = Arc::new(Mutex::new(0));

    // Health check thread
    let workers = vec![worker1_handle.clone(), worker2_handle.clone()];
    let monitor_counter = counter.clone();
    let health_check_thread = thread::spawn(move || {
        loop {
            thread::sleep(Duration::from_secs(1));
            let mut failed_worker = None;
            for (i, worker_running) in workers.iter().enumerate() {
                if !*worker_running.lock().unwrap() {
                    failed_worker = Some(i);
                    break;
                }
            }
            if let Some(failed_index) = failed_worker {
                // Handle failover
                println!(
                    "Worker {} failed health check. Standby takes over.",
                    failed_index + 1
                );
                // Stop standby thread
                standby_worker.stop();

                // Replace failed worker with standby
                let new_worker = Worker::new(failed_index + 1);
                let new_worker_handle = new_worker.start();

                // Update the workers vector
                let mut workers = workers;
                workers[failed_index] = new_worker_handle;

                // Start a new standby
                let new_standby = Worker::new(4);
                let new_standby_handle = new_standby.start();

                println!("New standby worker started.");

                break; // For simplicity, we exit after handling one failure
            }
        }
    });

    // Simulate handling requests
    for i in 0..10 {
        let counter = counter.clone();
        let workers = vec![worker1.is_running.clone(), worker2.is_running.clone()];
        thread::spawn(move || {
            let mut num = counter.lock().unwrap();
            let worker_index = *num % workers.len();
            *num += 1;
            println!("Request {} handled by worker {}", i, worker_index + 1);
        });
        thread::sleep(Duration::from_millis(50));
    }

    // Simulate terminating a worker to test failover
    thread::sleep(Duration::from_secs(2));
    println!("Terminating worker 2 to simulate failure.");
    worker2.stop();

    // Wait for health check thread to handle the failure
    health_check_thread.join().unwrap();

    // Keep the main thread alive to observe the output
    thread::sleep(Duration::from_secs(2));
}
