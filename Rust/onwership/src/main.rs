fn main() {
    let s = String::from("hello");  // s 进入作用域
    let s=takes_ownership(s); // s的所有权交给函数后，通过返回值交回给s
    println!("{}",s);   //所以可以print
    takes_ownership(s); // 把s的所有权交给函数，没有取回
    //println!("{s}"); 此时print就会报错
    let s=String::from("world");
    borrow(&s);
    println!("{}can still be used",s);// borrow使用的是引用，没有修改所有权，
    //所以依然可以使用s

    let s_borrow:&String=&s;
    takes_ownership(s);
    //let s_borrow:&String=&s; 这里，除非let s=takes_ownership(s);实现所有权的显式返回
    //否则所有权依然在函数那，上个代码依然会报错

    let mut s =String::from("the world");
    change_string(&mut s);//change使用的是可变引用，可以在函数中修改引用的值
    println!("changed string is:{}",s);


    test1();
}        

fn takes_ownership(s:String)->String{
    println!("the string is:{s}");
    s
}

fn borrow(s:&String){
    println!("borrow ownership of {}",s);
}

fn change_string(s:&mut String){
    s.push_str(" as one");
}

fn test1(){
    let mut s=String::from("123");
    let _r1=&mut s;
    let  _r2=&s;
    //println!("r1:{}",_r1); //如果只是单纯在同一作用域里声明了可变和不可变引用
    //不会编译错误。但是如果使用了其中之一，就会出现错误
}
