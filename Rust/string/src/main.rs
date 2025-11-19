fn main() {
    let mut a: String=String::from("Hello world");
    a.push('!');
    println!("{}",&a);
    let s:&str=&a[0..3];
    println!("{}",&s);
    let mut b:String=String::new();
    b.push_str("foo");
    println!("&b: {}",&b);
    let c=format!("{}{}", a , b);
    println!("a+&b: {}",c);
    println!("a: {}",&a);
}
