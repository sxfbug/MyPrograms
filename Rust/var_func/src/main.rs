


fn main(){
    println!("Hello world!");
    let a=3;
    let b=4;
    let result1=func1(a,b);
    println!("the value of result1: {:?}",result1);
    let c:char='s';
    let d:f64=2.1;
    println!("the value of result2: {:?}",func2(c,d));
    println!("return value of func3:{}\n",func3());
}

fn func1(x:i32,y:i32){
    println!("input value is {x} and {}\nthe total value is {}",y,x+y);
}

fn func2 (x:char,y:f64) ->f64 {
    println!("input char is {x},float is {}",y);
    let y=y+1.0;
    y+2.0  //也可以不加分号，让表达式的值成为返回值，来使用一个隐式返回

    //return y;//可以用return语句显式地指明返回值
}

fn func3()->i32{
    println!("in func3, calling func4\nthe return value of func4 is :{}",func4());
    func4()//把函数调用作为返回值，让fn4的返回值成为fn3的返回值
}

fn func4()->i32{
    let a=3;
    let b=20;
    a+b
}