

fn main() {
    let mut s: Vec<char> = vec!["A"," ","m","a","n",","," ","a"," ","p","l","a","n",","," ","a"," ","c","a","n","a","l",":"," ","P","a","n","a","m","a"];

    for i in s{
        print!("{}",i);
    }
}


fn reverse_string( s: &mut Vec<char>) {
    let length:usize=s.len();
    let mut front:usize=0;
    let mut back:usize=length-1;
    let mut temp:char;
    let mut cnt=0;
    while back as i32-front as i32>=1{
        
        temp=s[back];
        s[back]=s[front];
        s[front]=temp;
       //println!("front={}\tback={}\n",front,back);
        back=back-1;
        front=front+1;
        cnt+=1;
    }
    //println!("len={}",s.len());
    //print!("cnt={}\n",cnt);

}