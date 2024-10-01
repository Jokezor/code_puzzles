use std::io::{self, BufRead};

fn solution(lines: &mut std::io::Lines<std::io::StdinLock>) -> io::Result<()> {

    let alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".as_bytes();
    // Read a line of input for a number of integers
    if let Some(Ok(line)) = lines.next() {
        let s = line.as_bytes();
        let mut start : i32 = 0;
        let mut ans : i32 = 0;
        let mut new_ind : i32 = 0;

        // We start at a.

        for i in 0..26 {
            if s[i as usize] as char == 'A' {
                start = i;
                new_ind = start;
                break;
            }
        }

        for i in 1..26 {
            start = new_ind;
            for k in 0..26 {
                if s[k as usize] == alphabet[i as usize] {
                    new_ind = k;
                    let diff = i32::abs((start - new_ind).try_into().unwrap());
                    ans += diff;
                    break;
                }
            }
        }
        println!("{}", ans);
        return Ok(());
    }
    return Ok(());
}

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    // Read the number of test cases
    // let t: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap_or(1);
    let t: usize = 1;

    // Call solution t times
    for _ in 0..t {
        solution(&mut lines);
    }

    Ok(())
}
