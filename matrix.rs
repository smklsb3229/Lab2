use std::io::{self, Write};

fn main() -> io::Result<()> {
        let mut row = String::new();
        let mut col = String::new();

        print!("행 = ");
        io::stdout().flush()?;
        io::stdin().read_line(&mut row)?;

        print!("열 = ");
        io::stdout().flush()?;
        io::stdin().read_line(&mut col)?;

        let row: usize = row.trim().parse().unwrap();
        let col: usize = col.trim().parse().unwrap();

        let mut matrix1: Vec<Vec<i32>> = vec![vec![0; col]; row];
        let mut matrix2: Vec<Vec<i32>> = vec![vec![0; col]; row];

        println!("행렬 1 input : ");
        for i in 0..row{
                let mut input_string = String::new();
                io::stdin().read_line(&mut input_string)?;
                let numbers: Vec<i32> = input_string.split_whitespace()
                    .map(|s| s.parse::<i32>().expect("Parse error"))
                    .collect();
                if numbers.len() != col {
                    return Ok(());
                }

                matrix1[i] = numbers;
        }
        
        println!("행렬 2 input : ");
        for i in 0..row{
                let mut input_string = String::new();
                io::stdin().read_line(&mut input_string)?;
                let numbers: Vec<i32> = input_string.split_whitespace()
                    .map(|s| s.parse::<i32>().expect("Parse error"))
                    .collect();

                if numbers.len() != col {
                    return Ok(());
                }

                matrix2[i] = numbers;
        } 

        println!("행렬 1 + 행렬 2 result : ");

        for i in 0..row {
            for j in 0.. col {
                print!("{}, ", matrix1[i][j] + matrix2[i][j]);
            }
            println!("");
        }

        Ok(())
}
