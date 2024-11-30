use std::io::{self, BufRead};

fn solution(lines: &mut std::io::Lines<std::io::StdinLock>) -> io::Result<()> {
    // Read a line of input for a number of integers
    if let Some(Ok(line)) = lines.next() {
        let nums: Vec<usize> = line
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

        if nums.len() != 2 {
            panic!("Fewer arguments...");
        }

        // let [a, b, c] = nums[..];
        let [n, k] = <[usize; 2]>::try_from(nums).unwrap();

        if let Some(Ok(line)) = lines.next() {
            let arr: Vec<i32> = line
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();

            let start:usize = std::cmp::max(0, n-k);
            let end:usize = n;
            for i in start..end {
                print!("{}", arr[i]);

                if !(start == 0 && i == end-1) {
                    print!(" ");
                }
            }
            for i in 0..start {
                print!("{} ", arr[i]);
            }
            print!("\n");
            return Ok(());
        }
    }

    Ok(())
}

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    // Read the number of test cases
    // let t: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap_or(1);
    let t: i32 = 1;

    // Call solution t times
    for _ in 0..t {
        solution(&mut lines)?;
    }

    Ok(())
}
