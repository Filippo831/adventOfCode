use std::fs;

fn read_file() -> String {
    let file_name = "input.txt";
    let my_file:String = fs::read_to_string(file_name).expect("error opening file"); 
    println!("{}", my_file);
    return my_file;
}

fn part_one(my_input: String){
    let mut whileControl:bool = true;
    while(whileControl){
        let mut index:usize= 0; 
        let mut changes:i32 = 0;
        while index < my_input.len() {
            if my_input[index] == my_input.index(index+1)-32 | my_input.index(index) == my_input.index(index+1)+32{

            }
        }
    }
}

fn main() {
    let my_input = read_file();
    part_one(my_input);
    println!("Hello, world!");
}
