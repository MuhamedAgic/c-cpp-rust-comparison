
use rayon::prelude::*;

fn main() {
    let vec: Vec<i32> = (1..=10).collect();
    let threshold = 10;

    let filtered: Vec<i32> = vec.par_iter()
        .map(|&x| x * x)           // square each element
        .filter(|&x| x >= threshold) // filter squares < threshold
        .collect();

    println!("Filtered squares >= {}:", threshold);
    filtered.iter().for_each(|x| print!("{} ", x));
    println!();
}

