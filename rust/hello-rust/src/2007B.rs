use std::io::{self, BufRead};

fn solution(lines: &mut std::io::Lines<std::io::StdinLock>) -> io::Result<()> {
    // Read a line of input for a number of integers
    if let Some(Ok(line)) = lines.next() {
        let nums: Vec<usize> = line
            .split_whitespace()
            .map(|x| x.parse().expect("Parse error"))
            .collect();

        // let [a, b, c] = nums[..];
        let [n, m] = <[usize; 2]>::try_from(nums).expect("Expected two integers");

        if let Some(Ok(line)) = lines.next() {
            let a: Vec<i32> = line
                .split_whitespace()
                .map(|x| x.parse().expect("Parse error"))
                .collect();


            let mut x = *a.iter().max().unwrap();

            for (i, line) in lines.take(m).enumerate() {
                if let Ok(line) = line {
                    // Cant be vector of i32.
                    let mut split = line.split_whitespace();

                    let c: char = split.next().unwrap().chars().next().unwrap();
                    let l: i32 = split.next().unwrap().parse().unwrap();
                    let r: i32 = split.next().unwrap().parse().unwrap();

                    if x >= l && x <= r {
                        if c == '+' {
                            x+=1;
                        }
                        else {
                            x-=1;
                        }
                    }
                    print!("{}", x);

                    if i < m-1 {
                        print!(" ");
                    }
                }
            }
            print!("\n");
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
