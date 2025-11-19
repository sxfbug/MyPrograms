fn main() {
    liftoff();
    timed_loop();
    print!("\n");
    feb(6);
    println!("{}",tem_exchange(1.0));
}

fn liftoff(){
    for number in (1..4).rev() {
        println!("{number}!");
    }
    println!("LIFTOFF!!!");
}

fn timed_loop(){
    let a: (char, i32, f64)=('a',2,1.1);
    let b=[1,2,3,5];
    for i in b{
        print!("{i}\t");
    }
    print!("\n");

    for x in (2..5).rev(){
        print!("{x}\t")
    }
}

fn func1(){
    let mut cnt: i32=0;
    loop{
        cnt=cnt+1;
        //print!("cnt:{cnt}");
        print!("loop time: {}\n",cnt);

        let result: i32=if cnt>10 {
            cnt
        }
        else{
            0
        };

        if cnt==5 {
            print!("now is 5\n");
            continue;
        }
           
        print!("the return value:{result}");
        
        if result>10{
            break;
        }
        
    }
    print!("\nloop is done");
}


fn feb(x:i32){
    let mut pre1=0;
    let mut pre2=1;
    let mut now=0;
    if x==1{
        print!("{pre1}");
    }
    else if x==2{
        print!("{pre2}")
    }
    else{
        for i in 3..(x+1){
            now=pre1+pre2;
            pre1=pre2;
            pre2=now;
        }
        println!("{now}");
    }
}

fn tem_exchange(c:f64)->f64{
    c*1.8+32.0
}