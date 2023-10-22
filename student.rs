use std::collections::BTreeMap;
use std::io::{self, Write};

#[derive(Debug)]
struct Student{
    mid_test_score: i32,
    fin_test_score: i32,
}

fn main() -> io::Result<()>{
    let mut students = BTreeMap::<String, Student>::new();

    print!("학생 수를 입력하세요 : ");
    io::stdout().flush()?;

    let mut input = String::new();
    io::stdin().read_line(&mut input)?;

    let stu_count: usize = input.trim().parse().unwrap();

    for _ in 0..stu_count{
        print!("학생 정보를 입력하세요 : ");
        io::stdout().flush()?;

        let mut input = String::new();
        io::stdin().read_line(&mut input)?;

        let parts: Vec<&str> = input.split_whitespace().collect();

        if parts.len() != 3{
            return Ok(());
        }

        let name = parts[0].to_string();

        let mid_test_score: i32 = parts[1].parse().unwrap();
        let fin_test_score: i32 = parts[2].parse().unwrap();

        students.insert(name, Student { mid_test_score, fin_test_score });

        println!("{:?} TREE에 추가되었습니다.", students.last_key_value());
    }
    
    println!("TREE 내용 : ");
    for (name, student) in &students{
        println!(
            "이름 = {}, 중간 점수 = {}, 기말 점수 = {}",
            name,
            student.mid_test_score,
            student.fin_test_score
        );
    }

    Ok(())
}
