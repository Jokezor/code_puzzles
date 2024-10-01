use std::io::{self, BufRead};

fn solution(lines: &mut std::io::Lines<std::io::StdinLock>) -> io::Result<()> {
    // Read n and m from input
    if let Some(Ok(line)) = lines.next() {
        let nums: Vec<usize> = line.split_whitespace()
            .map(|x| x.parse().expect("Parse error"))
            .collect();

        let [n, m] = <[usize; 2]>::try_from(nums).expect("Expected two integers");

        // Read the array 'a'
        if let Some(Ok(line)) = lines.next() {
            let a: Vec<i32> = line.split_whitespace()
                .map(|x| x.parse().expect("Parse error"))
                .collect();

            let mut max_value = *a.iter().max().unwrap();

            // Loop through m operations
            for (i, line) in lines.take(m).enumerate() {
                if let Ok(line) = line {
                    let mut split = line.split_whitespace();
                    let c: char = split.next().unwrap().chars().next().unwrap();
                    let left: i32 = split.next().unwrap().parse().expect("Parse error");
                    let right: i32 = split.next().unwrap().parse().expect("Parse error");

                    if max_value >= left && max_value <= right {
                        if c == '+' {
                            max_value += 1;
                        } else if c == '-' {
                            max_value -= 1;
                        }
                    }

                    // Print result with space management
                    print!("{}", max_value);
                    if i < m - 1 {
                        print!(" ");
                    }
                }
            }
            println!();
        }
    }

    Ok(())
}


fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    // Read the number of test cases
    let t: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap_or(1);
    // let t: i32 = 1;

    // Call solution t times
    for _ in 0..t {
        solution(&mut lines)?;
    }

    Ok(())
}
