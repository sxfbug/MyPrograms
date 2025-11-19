#[derive(Debug,Clone)]
//如果派生了clone,就可以在不获取所有权的情况下，从结构体实例中复制数据
struct Animal{
    name:String,
    creature:String,
    age:i32,
    is_healthy:bool
}

impl Animal {
    fn new(i:i32)->Self{
        Self{
            name:String::from("default"),
            creature:String::from("default"),
            age:i,
            is_healthy:true,
        }
    }
    fn shout(&self){
        println!("{} species {} is shouting",self.creature,self.name);
    }

}


fn main(){
    let hachimi=Animal{
        name:String::from("hachimi"),
        creature:String::from("cat"),
        age:2,
        is_healthy:true
    };

    let nanbeiluduo=Animal{
        age:1,
        ..hachimi.clone()
    };

    //println!("hachimi:{:?}\n,nanbeiluduo:{:?}"
    //,hachimi,nanbeiluduo);
    // 因为move了hachimi的string,所以此时hachimi的所有权被移交给了nanbeiluduo
    //也就不能print了,如果用clone就没事

    let axiga=Animal{
        name:String::from("axiga"),
        creature:String::from("cat"),
        ..hachimi
    };
    //axiga复制的没有分配在堆上的变量，所以所有权依然在nanbeiluduo那里，两者都可以打印
    println!("nanbeiluduo:{:?}\naxiga:{:?}",nanbeiluduo,axiga);
    dbg!(&nanbeiluduo);
    dbg!(&axiga);

    let manbo=Animal::new(10);
    manbo.shout();
    dbg!(&manbo);
}