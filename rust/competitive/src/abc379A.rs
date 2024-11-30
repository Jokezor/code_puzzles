use std::io::{self, BufRead};

fn solution(lines: &mut std::io::Lines<std::io::StdinLock>) -> io::Result<()> {

    if let Some(Ok(line)) = lines.next() {
        let s: Vec<char> = line.trim().chars().collect();

        if let [first, second, third] = s.as_slice() {
            println!("{second}{third}{first} {third}{first}{second}");
        }
        else {
            eprintln!("Error, input must contain exactly 3 integers.");
        }
    }
    Ok(())
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
