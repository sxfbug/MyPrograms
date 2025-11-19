/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(x&y) & ~(~x&~y);
  //~(~(x&~y) & ~(~x&y))
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //不能直接移位，不知道int的字节数
  //得出1000……0
  //如果是逻辑右移，就可以
  return 1<<31;  

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //x^x=0
  //我服了，重点居然是要用！映射到0和1上吗，但是这个解法也太丑陋了
  return (!((~x)^(x+1))) & !(!((x+1)^0));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12   
 *   Rating: 2  
 */
int allOddBits(int x) {
  //移位，问题是  
  //我能不能人工制造一个大常量,不行
  //右移，有逻辑和算术的区别,最后用&规避了逻辑和算术右移带来的高位不同问题
  int t2 = x;
  int t4 = (x>>8);
  int t6 = (x>>16);
  int t8 = (x>>24);
  return  !(((t2&t4&t6&t8)&0xAA)^0xAA); 
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  //相当于掩码了
  int a=!((x|0xF)^0X3F);
  int b=!(!((x|0x35)^0x3F));
  int c=!(!((x|0x33)^0x3F));
  return a & b &  c   ;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //用两次！，把正数和0映射到1和0
  //通过求负数，可以把0和1映射成0x0000和0xffff
  int cond = !(!x);
  int mark = ~cond+1;
  return (mark&y) | (~mark&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
//大于和小于的二进制位特征
//从高位向低位比较？
//逐位进行比较，技术上可行，但是不符合题目要求
//另一个思路，利用加法实现减法，再比较符号位，这个思路成功了，没想到破局的居然是加号
// 4=0000 0100
// 5=0000 0101
// -5=1111 1011
// 4+(-5)=1111 1111 符号位=1,<0
return !((y+(~x+1))>>31);
}
  
//4      
/* 
 * logicalNeg - implement the ! operator, ??using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  //0位反+2=1，问题是非0的无数个数，怎么映射到一个确定的数
  //x^x=0,x^0=x
  //类比于三目运算符的思路？但是那里面可以用！
  //m=0xffff ffff
  // if x!=0
  // x&m=x, x|m=0xffffffff,x^m=~x
  // if x==0
  // x&m=0, x|m=0xffffffff,x^m=0xffffffff
  // x+~x+1=0,可以把所有数映射到0上（那你不如return 0，这是无意义的），但是这样不能区分出0  
  // 如果要区分出0,需要条件判断
  // ~0+1=0,即0=-0，但是非0数~x+1的结果是不确定的，因为输入的是int,符号位可能是0和1
  //如果这个数末尾是1,&1即可以得到1
  int iszero=~x+1;

  return (~1+1)^99;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  //数学上，要实现的是，求出对应的n,使得2^(n-1)<x<=2^n
  // 12= (0)0 1100, -5= (1)1 011，5=0101 ，-1=1111, -3=(1)101，3=(0)011 16=00 01 0000， -16=11 11 0000
  //但是为什么-1只需要1bit
  //负数，需要最高位2^(n-1)比自己小;正数需要2^(n-1)比自己大
  //思路：二分法。因为用算法也是用二分来做的
  //将数字和二分数进行减法，比较大小, but large constant is forbidden

      //思路：先找到这个数的符号位（最高位），再进行计算位数
  //对于正数，从左到右找到第一个非0位，就是次高位
  //负数和正数所需的位数是一样的，能不能把负数变成正数来一起计算
  //一次最多同时比较8bit
  //combine together
  //先找到首次出现1的地方，再进行二分法比较
  int is_neg= x>>31;//0 and 1
  int is_neg_allbit=~is_neg+1;//pos:0x0000 /neg:0xffff
  
  //问题：对于0x8000,操作后仍得到原value

  int num1=x>>24;//front 1-8bits
  int num1_abs=(is_neg_allbit&(~num1+1))|(~is_neg_allbit&num1);

  int front_8bit_is0=~(!(num1_abs^0))+1;//0xffff->full 0; 0x0000->not full 0
  //check which bit is 1
  int mark1=~(!((0x0f|num1_abs)^0x0f))+1;//front 1-4bits,(0000 1111 | x)^0000 1111,if 0x0000, 1-4bit is 0000
  //with !, 1->1-4bit is 0000,0->not 0000
  //with ~+1,ffff->1-4bit is 0000,  0->not 0000
  int m1_up_edge=0x08;
  int m1_down_edge=0x00;

  
  //如果我可以把所有结果都映射到0x0和0xf上，就可以用|的串联，实现寻找到唯一的结果
  //这样想不行，因为有先后的逻辑关系，必须是从高往低位检验
  //divided in two with sub

  int mark2=2;//front 5-8bits,(1111 0000 |x)^1111 0000, if 0x0000, 5-8bit is 0000


  int num2=(x>>16)-(num1<<8);//9-16bits
  int num2_abs=(is_neg_allbit&(~num2+1))|(~is_neg_allbit&num2);
  int front_9to16bit_is0=front_8bit_is0 & (~(!(num2_abs^0))+1);//1->full 0; 0->not full 0

  int num3=(x>>8)-((x>>16)<<8);//17-24bits
  int num3_abs=(is_neg_allbit&(~num3+1))|(~is_neg_allbit&num3);
  int front_17to24bit_is0=front_9to16bit_is0 & (~(!(num3_abs^0))+1);//1->full 0; 0->not full 0

  int num4=x-((x>>8)<<8);//25-32bits
  int num4_abs=(is_neg_allbit&(~num4+1))|(~is_neg_allbit&num4);
  int front_25to32bit_is0=front_17to24bit_is0 & (~(!(num3_abs^0))+1);//1->full 0; 0->not full 0
  
  return 0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  return 2;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
