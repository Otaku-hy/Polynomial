# 一元多项式计算器

## 编译

本项目使用`c++17`标准，用`cmake`进行项目的构建。

执行以下命令编译这个项目：

Windows:

```bash
$ cmake -B build
$ cmake --build build

$ ./build/Debug/Poly.exe
```

Linux/MacOS:

```bash
$ cmake -B build
$ cmake --build build

$ ./build/Poly.exe
```

## 交互操作介绍

 1. Polynomial读入格式

    从`PolynomialInput.txt`中按照给定的方式读取多项式

    格式：

    ```
    #BEGIN_POLYNOMiAL
    	#name: name//name here
    	2 1.0//data here   2为指数支持负数(int)，1.0为系数(double)
    #END_POLYNOMIAL           
    //在begin，end语句块中请不要空行
    ```

    具体例子参考`PolynomialInput.txt`

 2. 交互选项

​		`"1" `：对`PolynomialInput.txt`中输入的所有多项式进行更新，支持对之前输入的多项式进行更改，所有将存储在一个polynomialPool中，支持通过名字对以前存储的多项式进行访问。

​		`"2"`：查询某个名为<name>的多项式，输出其值

​		`"3"`：将两个多项式相加，表达式：

```bash
$ p3 = p1 + p2    （1）
$ p1 + p2		  （2）
```

​				两种表达式，有不同的含义，(1)表示命名一个p3的多项式，他的值为p1 + 				p2，并输出多项式的值，并将p3存入polynomial pool中。(2)表示计算p1 + 				p2的值并输出。

​		`"4"`：将两个多项式相减，表达式：

```bash
$ p3 = p1 - p2    （1）
$ p1 - p2		  （2）
```

​		`"5"`：计算某一多项式在x=a 这一点的值，表达式：

```bash
$ p2 1.0
```

​		`"6"`：退出计算器

​		`"7"`：输入1-6的操作数提示非法输入，需要用户重新输入 