把一个数据存储到机器里面，不同的机器会给它以不同的表示顺序。
从高位开始存储称为**大端法**、反之称为**小端法**
下面是测试机器字节顺序地代码：
~~~
#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
	size_t i;
	for (i = 0; i < len; i++)
		printf("%.2x" , start[i]);
		printf("\n");
	}
void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int)); 
	}
void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
	}
void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
	}
int main(){
	int a=12345;
	show_int(a);
	show_float((float)a);
	show_pointer((void*)a);
	return 0;
}
~~~
show_bytes函数传入指向字节序列的指针和它的字节数。  
观察byte_pointer的定义:unsigned char *  
代码把数据的地址指针转化为unsigned char*  
即 unsigned char * (&x) 被转换为x数值的字符串形式  
接着对每个字符进行十六进制输出  
此处的%.2x可换为%02x，具体原因不得而知。。 

以上代码在我的机器上（华硕灵耀14）运行结果如下:  
39300000  //int型12345的字节表示  
00e44046  //float型12345的字节表示  
3930000000000000  //pointer型12345(地址)字节表示  
为小段表示法，与书中描述的**大多数Intel兼容机使用小端模式**相吻合
