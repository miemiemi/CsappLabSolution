/* 
 * CS:APP Data Lab 
 * 
 * <miemie mie>
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
  //从异或定义出发 代替定义中的or
  int fxy = ~x&y;
  int xfy = x&~y;
  return ~(~fxy&~xfy);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //啊这
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
  /* 偷鸡
  int y = x + 1;
  int test = x^y;
  int flag = !(x^~0);
  return !(~test + flag);
  */
  int y = x + 1;    // -1 或 tmin
  int flag = !y;    // -1:1 tmin:0
  x = ~(x + y);     // x == 0
  return !(x + flag);
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
  //mask
  int mask = (0xAA)|(0xAA<<8)|(0xAA<<16)|(0xAA<<24);
  int answer = (x&mask)^mask;
  return !answer;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //取反加一
  return ~x + 1;
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
  int n1 = 0x30,n2 = 0x3a;            // 48<=x<58
  int flag1 = (x + (~n1+1))>>31;      //应该为1----0 
  int flag2 = (x + (~n2+1))>>31;      //应该为1----1
  int answer = (flag1^flag2)&flag2;   //-1
  return !(answer+1);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {    
  // //x = 0 return z. else return y
  // //呜呜 不能移32位 我好傻
  // int iszero = !x +(~1 + 1);    //当x=0是1(iszero为全0) 其他时候为0(iszero为全1)
  // int movebits = 31;
  // int addtionalmove = 1;
  // int tempz = z<<(movebits&iszero)<<(addtionalmove&iszero);        //当x=0 为0 其他时为 32
  // //printf("x = %d y = %d z = %d tempz  = %d",x,y,z,tempz);
  // int tempy = y<<(movebits&(~iszero))<<(addtionalmove&(~iszero));     //当x=0 为32 其他时为 0
  // //printf(" tempy  = %d",tempy);
  // //int movebitsandiszero = movebits&iszero;
  // //int movebitsandnegiszero = movebits&(~iszero);
  // //printf(" movebitsandiszero  = %d  movebitsandnegiszero = %d \n",movebitsandiszero,movebitsandnegiszero);
  // return tempy|tempz;
  x = !!x;
  x = ~x+1;
  return (x&y)|(~x&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signx = x>>31;       //0或1
  int signy = y>>31;
  int flag  = signx^signy;
  int deff = flag&signx;    //x为负的时候小 deff = 1 否则为全0
  int sum = (~x+y)+1;       //y-x;
  int signsum = sum>>31;    //y>=x时 signsum = 0x00...00
  int same =signsum|flag;   //y>=x时 都为0
  return !(same&(~deff));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int flag = (x|(~x + 1))>>31;  //当x=0 时为0 其他都为全1
  return flag + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5       //0x0000000c 4 + 1
 *            howManyBits(298) = 10     //0x0000012a 9 + 1
 *            howManyBits(-5) = 4       //-8+3 0x1011 
 *            howManyBits(0)  = 1       //0x0
 *            howManyBits(-1) = 1       //0x1
 *            howManyBits(0x80000000) = 32    //tmin
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  //试试二分
  int b16,b8,b4,b2,b1,b0;
  int sign = x>>31;
  x = (x&~sign)|(~x&sign);

  b16 = !!(x>>16)<<4;   //全0时为1  高16位没有1时候 b16 = 0 有1时为16
  x = x>>b16;                 //在高16位中寻找
  b8 = !!(x>>8)<<3;     //全0时为1  高24位没有1时候 b8 = 0 有1时为8
  x = x>>b8;                  //在高8位中寻找
  b4 = !!(x>>4)<<2;     //全0时为1  高28位没有1时候 b4 = 0 有1时为4
  x = x>>b4;                  //在高4位中寻找
  b2 = !!(x>>2)<<1;     //全0时为1  高30位没有1时候 b2 = 0 有1时为2
  x = x>>b2;                  //在高2位中寻找
  b1 = !!(x>>1);         //全0时为1  高31位没有1时候 b4 = 0 有1时为1
  x = x>>b1;                  
  b0 = x;
  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
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
  //(-1)^s * M * 2^(e+1)
  int DenormalizedZero = 0x00;
  int DenormalizedOne = 0x7f800000;
  int isDenormalizedflag = uf&DenormalizedOne;
  int exp = isDenormalizedflag>>23;
  //int newexp = 0;
  if(isDenormalizedflag == DenormalizedOne)    //exp == 11111111 为正负无穷 或NaN
      return uf;
  if(isDenormalizedflag == DenormalizedZero){   //(2-bias)
      if(uf == 0||uf == 0x80000000)   //可以简化
        return uf;
      else{
        int sign = uf&0x80000000;
        return (uf<<1)|sign;
      }
  }
  else
      exp += 1;
  return (exp<<23)|(uf&0x807FFFFF);
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
  int DenormalizedZero = 0x00;
  int DenormalizedOne = 0x7f800000;
  int isDenormalizedflag = uf&DenormalizedOne;
  int exp = isDenormalizedflag>>23;
  const int bias = 127;
  int E = 0;                                   //exp -bias or 1 - bias
  int M = 0;                                   //significand
  int sign = uf>>31;                           //对无符号数的右移动  为逻辑右移
  int realmove = 0;
  if(isDenormalizedflag == DenormalizedOne)    //exp == 11111111 为正负无穷 或NaN
      return 0x80000000u;
  if(isDenormalizedflag == DenormalizedZero)   //(1-bias)
      return 0;
  E = exp - bias;
  if(E>30)   //左移超过int范围
      return 0x80000000u;
  else if(E<0)   //小于1
      return 0;
  //正常运算
  M = (uf&0x007FFFFF)|0x00800000;
  realmove = E - 23;
  if(realmove>=0)
      M = M << realmove;
  else
      M = M >> -realmove;
  if(sign == 1)
      return (~M + 1);      
  else if(sign == 0)
      return M;
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
  // //(-1)^s * M * 2^E    S = 0 M =1.00
  // //range -23 + (1-bias)
  // int bias = 127;
  // int exp = 0;
  // int movebits = 0;
  // if(x<-149)                    //2^(-23 + (1-bias))
  //   return 0;
  // if(x>127)                //2^(127)
  //   return 0x7F800000;
  // exp = x+bias;                 //(exp-bias) = x
  // if(exp<0){                    //DenormalizedZero
  // // 2^(-1) * 2^(-移动) *2^(1-bias) -移动-bias = x
  //     movebits  = - bias - x; 
  //     return 0x00400000>>movebits;
  // }
  // else
  //     return exp<<23;
  //逻辑没错 编译条件不同会导致超时(就这样了 阿巴阿巴阿巴阿巴！！！)
  //看到的逻辑最简介的解 会大概快一些()
  if(x < -149)
        return 0;
    else if(x < -126)
        return 1 << x+149;
    else if(x <= 0x7f)
        return (x+0x7f) << 23;
    else
        return 0xff << 23;
}
