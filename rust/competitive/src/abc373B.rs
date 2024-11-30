use std::io::{self, BufRead};

fn solution(lines: &mut std::io::Lines<std::io::StdinLock>) -> io::Result<()> {

    let alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".as_bytes();
    // Read a line of input for a number of integers
    if let Some(Ok(line)) = lines.next() {
        let s = line.trim();
        let mut positions = [0usize; 26];

        // Map each character to its position in the input string
        for (i, c) in s.chars().enumerate() {
            positions[(c as u8 - b'A') as usize] = i;
        }

        let mut ans = 0;
        let mut prev_pos = positions[0]; // Position of 'A'

        // Iterate over the indices for 'B' to 'Z'
        for &curr_pos in &positions[1..] {
            ans += (curr_pos as isize - prev_pos as isize).abs();
            prev_pos = curr_pos;
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
