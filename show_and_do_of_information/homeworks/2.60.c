#include <stdio.h>
unsigned replace_byte(unsigned x, unsigned char b, int i)
{
        /* 1. 首先将 0x12345678 变为 0x12005678 */
        int w = sizeof(int) - 1; /* 取值范围: 0~3 */
        int shift_left = (i & w)<<3;//这里的3代表1个字节8比特 
        unsigned m = x & ~(0xFF << shift_left);
        /* 2. 将 0xAB 左移 2 两个字节得到数值 0x00AB0000 */
        unsigned int n = (unsigned)b << shift_left;
        /* 3. 将 0x12005678+0x00AB0000 作为结果返回 */
        return m + n;
}
int main(){
	int a=0x12345678;
	int b=replace_byte(a,0xBB,7);
	printf("%x",b);
	return 0;
}
/*
将四个字节(假设情况)中的其中一个替换为其他值，只需把其先变为0再赋值。  
shift_left是左移位数，(w&i)限制i的范围，<<3把字节位转化为比特位；   
故shift_left表示i位。

参考代码:[](https://github.com/vonzhou/CSAPP/blob/master/exercise/ex2-60.c)
*/
