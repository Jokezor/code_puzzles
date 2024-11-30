use std::io::{self, BufRead};

fn solution(lines: &mut std::io::Lines<std::io::StdinLock>, ind: usize) -> bool {
    // Read a line of input for a number of integers
    if let Some(Ok(line)) = lines.next() {
        let s: String = line;
        return s.len() == ind;
    }
    return false;
}

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    // Read the number of test cases
    // let t: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap_or(1);
    let t: usize = 12;

    let mut ans: usize = 0;

    // Call solution t times
    for ind in 0..t {
        if solution(&mut lines, ind+1) {
            ans += 1;
        }
    }

    println!("{}", ans);

    Ok(())
}
