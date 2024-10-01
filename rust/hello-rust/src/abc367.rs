use std::io::{self, BufRead};

fn solution(lines: &mut std::io::Lines<std::io::StdinLock>) -> io::Result<()> {
    // Read a line of input for 3 integers
    if let Some(Ok(line)) = lines.next() {
        let nums: Vec<i32> = line
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

        if nums.len() != 3 {
            panic!("Fewer arguments...");
        }

        // let [a, b, c] = nums[..];
        let [a, mut b, c] = <[i32; 3]>::try_from(nums).unwrap();

        while b != c {
            b = (b+1) % 24;

            if b == a {
                println!("No\n");
                return Ok(());
            }
        }
    }
    println!("Yes\n");

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
