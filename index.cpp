#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        this->age = 23;
    }
    void printAge()
    {
        cout << this->age <<endl;
    }
    ~Person(){}
public:
    int age;
};

int main()
{
    Person p;
    cout << "对象地址："<< &p <<endl;
    cout << "age地址："<< &(p.age) <<endl;
    cout << "对象大小："<< sizeof(p) <<endl;
    cout << "age大小："<< sizeof(p.age) <<endl;
    return 0;
}
//输出结果
//对象地址：0x7fffec0f15a8
//age地址：0x7fffec0f15a8
//对象大小：4
//age大小：4

// int *p[10]
// int (*p)[10]
// int *p(int)
// int (*p)(int)

// 被free回收的内存会首先被ptmalloc使用双链表保存起来，
// 当用户下一次申请内存的时候，会尝试从这些内存中寻找合适的返回。
// 这样就避免了频繁的系统调用，占用过多的系统资源。
// 同时ptmalloc也会尝试对小块内存进行合并，避免过多的内存碎片

// 一个指针占内存的大小跟编译环境有关，而与机器的位数无关。

// int a = 10;int* const b1 = &a;        //顶层const，b1本身是一个常量
// const int* b2 = &a;       //底层const，b2本身可变，所指的对象是常量
// const int b3 = 20; 		   //顶层const，b3是常量不可变
// const int* const b4 = &a;  //前一个const为底层，后一个为顶层，b4不可变
// const int& b5 = a;		   //用于声明引用变量，都是底层const

// 当数组名当做形参传递给调用函数后，就失去了原有特性，退化成一般指针，
// 多了自增、自减操作，但sizeof运算符不能再得到原数组的大小了

// 智能指针的本质就是避免悬空指针的产生
// 野指针：指针变量未及时初始化 => 定义指针变量及时初始化，要么置空。
// 悬空指针：指针free或delete之后没有及时置空 => 释放操作后立即置空。

// 类型匹配尚且没有问题，但是一旦出现int* pInt=(int*)malloc(100*sizeof(char))就很可能带来一些问题，
// 而这样的转换C并不会提示错误

// dynamic_cast比static_cast涉及更多具体的类型检查

// 使用宏定义的地方都可以使用 inline 函数
// 类成员接口函数来读写类的私有成员或者保护成员，会提高效率
// 宏定义时要注意书写（参数要括起来）否则容易出现歧义
// 内联函数可以进行参数类型检查,且具有返回值,在编译时直接将函数代码嵌入到目标代码中,进行参数类型检查

// Socket编程中，往往需要将操作系统所用的小端存储的IP地址转换为大端存储,才能进行网络传输

// int a = 0x1234;
//     //由于int和char的长度不同，借助int型转换成char型，只会留下低地址的部分
//     char c = (char)(a);
//     if (c == 0x12)
//         cout << "big endian" << endl;
//     else if(c == 0x34)
//         cout << "little endian" << endl;

// plain new，nothrow new和placement new
// plain new == new
// void* operator new(std::size_t) throw(std::bad_alloc);
// plain new在空间分配失败的情况下，抛出异常std::bad_alloc而不是返回NULL,判断返回值是否为NULL是徒劳的
// void * operator new(std::size_t,const std::nothrow_t&) throw();
// nothrow new在空间分配失败的情况下是不抛出异常，而是返回NULL
// void* operator new(size_t,void*);
// placement new在一块已经分配成功的内存上重新构造对象或对象数组,调用对象的构造函数

// static 隐藏 (不被 extern)
// static 保持变量内容的持久
// static 默认初始化为0（static变量）
// static C++中的类成员声明static

// int* const a; 顶层修饰，a是指针，指针存储的地址不可以被修改，地址指向的值是可以修改
// const int* b; 底层修饰，b是指针，指针存储的地址可以修改，指针指向的值不可修改

// delete[]时，数组中的元素按逆序的顺序进行销毁
// allocator申请一部分内存，不进行初始化对象，只有当需要的时候才进行初始化操作

// new [] 一个对象数组，在分配数组空间时多分配了 4 个字节的大小，专门保存数组的大小
// 在 delete [] 时就可以取出这个保存的数，就知道了需要调用析构函数多少次了

// 函数体中初始化,是在所有的数据成员被分配内存空间后才进行
// 列表初始化是给数据成员分配内存空间时就进行初始化

// string继承自basic_string,其实是对char*进行了封装，封装的string包含了char*数组，容量，长度等属性
// 可以进行动态扩展，在每次扩展的时候另外申请一块原空间大小两倍的空间（2*n）

// 内存泄漏：堆内存开辟用完后，没有free/delete，空间权限没有解除，无法使用，意味不能空间，空间泄露了一部分
// 一定要将基类的析构函数声明为虚函数
// 对象数组的释放一定要用delete []

// 对象复用：对象存储到“对象池”中实现对象的重复利用，这样可以避免多次创建重复对象的开销，节约系统资源

// reinterpret_cast 用于类型之间进行强制转换
// const_cast const转非const
// static_cast 没有类型检查,数据类型之间转换,空指针转换成目标空指针,任何类型的表达式转换成void类型
// dynamic_cast 类层次间的上行转换和下行转换,还可以用于类之间的交叉转换,具有类型检查

// 指针加减本质是对其所指地址的移动，移动的步长跟指针的类型是有关系的

// 两个浮点数判断大小和是否相等不能直接用==来判断
// 只能通过相减并与预先设定的精度比较，记得要取绝对值

// 函数指针:类型是由其返回的数据类型和其参数列表共同决定
// 声明方法1:int (*pf)(const int&, const int&); => 返回值是int，指针名是pf
// 声明方法2:int* pf(const int&, const int&); => 返回值是int*

// 函数调用过程栈:先定义的变量先入栈
// int test(int a, int b); 调用顺序是 b,a,int

// #define是关键字，inline是函数
// 宏定义在预处理阶段进行文本替换，inline函数在编译阶段进行替换

// template<…>处理的意味着编译器不为它分配存储空间，它一直处于等待状态直到被一个模板实例
// 编译器编译.cpp文件时并不知道另一个.cpp文件的存在，也不会去查找（当遇到未决符号时它会寄希望于连接器）
// 遇到模板时就傻眼了，因为模板仅在需要的时候才会实例化出来

// cout<< 是函数,已存在针对各种类型数据的重载，所以会自动识别数据的类型
// 输出过程会首先将输出字符放入缓冲区，然后输出到屏幕
// cout < < "abc " < <endl; 或 cout < < "abc\n "; cout << flush; 是一样的.
// printf是行缓冲输出，不是无缓冲输出

// 变量声明:是仅仅告诉编译器，有个某类型的变量会被使用,编译器并不会为它分配任何内存
// 变量定义:就是分配了内存
// 函数声明:头文件里，对编译器说：这里我有一个函数叫function() 让编译器知道这个函数的存在
// 函数定义:一般在源文件里，具体就是函数的实现过程 写明函数体

// 在头文件中使用#define、#ifndef、#ifdef、#endif能避免头文件重定义

// 隐式转换，是指不需要用户干预，编译器私下进行的类型转换行为
// A* a = new A(); a=nullptr;
// nullptr 隐式转换成A*
// explicit关键字，在构造函数声明的时候加上explicit关键字，能够禁止隐式转换

// strcpy只能复制字符串，而memcpy可以复制任意内容
// strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出
// 复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy

// int main(int argc, char *argv[])内存结构：
// 程序在命令行下运行的时候，需要输入argc 个参数
// 每个参数是以char 类型输入的，依次存在数组里面
// 数组是 argv[]，所有的参数在指针
// char * 指向的内存中，数组的中元素的个数为 argc 个，第一个参数为程序的名称

// 空类
// 1)  Empty(); // 缺省构造函数
// 2)  Empty( const Empty& ); // 拷贝构造函数
// 3)  ~Empty(); // 析构函数
// 4)  Empty& operator=( const Empty& ); // 赋值运算符

// strcpy主要实现字符串变量间的拷贝
// sprintf主要实现其他数据类型格式到字符串的转化
// memcpy主要是内存块间的拷贝。

// 读写锁：
// 多个读者可以同时进行读
// 写者必须互斥（只允许一个写者写，也不能读者写者同时进行）
// 写者优先于读者（一旦有写者，则后续读者必须等待，唤醒时优先考虑写者）
// 互斥锁：
// 一次只能一个线程拥有互斥锁，其他线程只有等待

// 内存分区：
// 栈：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放
// 堆：就是那些由 new分配的内存块，释放编译器不管，由我们去控制，一个new对应一个delete
// 自由存储区：是C++中通过new和delete动态分配和释放对象的抽象概念
// 全局/静态存储区：全局变量和静态变量被分配到同一块内存中，在该区定义的变量若没有初始化，则会被自动初始化
// 常量存储区：这是一块比较特殊的存储区，这里面存放的是常量，不允许修改
// 代码区：存放函数体的二进制代码 (所有函数都存放在代码区，静态函数也不例外)

// this指针是类的指针，指向对象的首地址。
// this指针只能在成员函数中使用，在全局函数、静态成员函数中都不能用this。
// this指针只有在成员函数中才有定义，且存储位置会因编译器不同有不同存储位置
// 大多数编译器通过ecx（寄数寄存器）寄存器传递this指针,否则不同编译器产生的obj就无法匹配
// this指针只有在成员函数中才有定义
// 标准情况下this为右值，无法通过&符号获取地址

// delete this:
// delete this释放了类对象的内存空间，但是内存空间却并不是马上被回收到系统中
// 导致这段内存空间暂时并没有被系统收回
// 此时这段内存是可以访问的，但是其中的值却是不确定的
// 获取数据成员，可能得到的是一串很长的未初始化的随机数
// 访问虚函数表，指针无效的可能性非常高，造成系统崩溃

// 空类的大小不为0，不同编译器设置不一样，vs设置为1
// 带有虚函数的C++类大小不为1，因为每一个对象会有一个vptr指向虚函数表

// 在类的非静态成员函数访问类的非静态成员时，编译器会自动将对象的地址传给作为隐含参数传递给函数
// 这个隐含参数就是this指针
// This指针首先入栈，然后成员函数的参数从右向左进行入栈，最后函数返回地址入栈

// 类对象的大小:
// 类的非静态成员变量大小,成员函数也不占据
// 虚函数会在类对象插入vptr指针，加上指针大小
// 派生类继承的基类部分的数据成员也会存在在派生类中的空间中

// C语言中，NULL被定义为(void*)0,而在C++语言中，NULL则被定义为整数0
// #ifdef __cplusplus
// #define NULL 0
// #else
// #define NULL ((void *)0)
// #endif

// 