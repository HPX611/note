# 函数

## 	参数

### 		1.位置参数

​			需要按位置出入对应的参数

```python
def func(a,b,c):
    return "".join((c,b,a))
print(func("x","y","z"))
输出为 zyx
```

### 		2.关键字参数

​			形式参数的名字与需要传入所对应的实际参数用等号连接

```python
def func(a,b,c):
    return "".join((c,b,a))
print(func(c="x",b="y",a="z"))
输出为 xyz
```

​			**注：位置参数与关键字参数同时使用时需要将关键字参数放在后面**

### 		3.默认参数

​			在调用函数的时候没有传入实参的话，采用默认的参数值来代替，在定义函数时需要将默认的参数放在后面

```python
def func(a,b,c="小明"):
    return "".join((c,b,a))
print(func("作业","没写"))
输出为 小明没写作业

def func(a="作业",b,c="小明"):
    return "".join((c,b,a))
print(func("没写"))
无法运行
  File "D:\python\main.py", line 1
    def func(a="作业",b,c="小明"):
                        ^
SyntaxError: non-default argument follows default argument
```

### 		4./和*两侧参数传输的要求

​			/左侧不能使用关键字参数，右侧随意

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-28 193108.png)

​				*右侧只能是关键字参数，左侧随意

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-28 193326.png)

### 5.收集参数

```python
def func(*x): #收集参数是将多组参数进行打包成为元组
    print("有{}个参数".format(len(x)))
    print("第二个参数是{}".format(x[1]))
    print(x) # 元组
    print(type(x))
func(1,2)

输出为
有2个参数
第二个参数是2
(1, 2)
<class 'tuple'>
```

如果在收集参数后面还需要指定其他参数，调用函数时要用关键字参数来指定后面的参数，如print

同时也可以按字典去打包

```
def func(**x): #收集参数是将多组参数进行打包成为字典
    print(x)
func(a=1,b=2)

def fun(a,*b,**c):
    print(a,b,c)
fun(1,2,3,4,x=5,y=6)

输出为
{'a': 1, 'b': 2}
1 (2, 3, 4) {'x': 5, 'y': 6}
```

### 6.解包参数

```python
args=(1,2,3,4)
def func(a,b,c,d):
    print(a,b,c,d)
func(args)

#没有传递b,c,d的参数
Traceback (most recent call last):
  File "D:\python\main.py", line 4, in <module>
    func(args)
TypeError: func() missing 3 required positional arguments: 'b', 'c', and 'd'

func(*args) #将元组进行解包 传进去了4个参数
输出为  1 2 3 4

kwargs={'a':1,'b':2,'c':3,'d':4}
func(**kwargs) #将字典进行解包
输出为  1 2 3 4
```



## 	闭包

```python
def outer_function(x):
    # 内部函数
    def inner_function(y):
        return x + y
    # 返回内部函数的引用
    return inner_function

# 创建闭包
closure = outer_function(10)

# 使用闭包
result = closure(5)
print(result)  # 输出 15

result1 = closure(5)  # 10 + 5 = 15
result2 = closure(10)  # 10 + 10 = 20
```

在这个例子中：

- `outer_function` 是外部函数，它接受一个参数 `x`。
- `inner_function` 是内部函数，它定义在 `outer_function` 内部，可以访问 `outer_function` 的局部变量 `x`。
- `outer_function` 返回了 `inner_function` 的引用，形成了闭包。

当我们调用 `outer_function(10)` 时，它返回了一个闭包，即 `inner_function` 的引用，并且这个闭包捕获了 `x` 的值为 10。之后，我们可以多次调用闭包，传递不同的参数给 `inner_function`，而它仍然能够访问到 `x` 的值。

**闭包的特点是它能够"记住"定义它时的环境，即使这个环境在创建闭包后发生了改变。这种特性使得闭包在许多情况下非常有用，例如在函数式编程、回调函数、装饰器等方面。**

## 	装饰器

```python
import time  #调用一个模块
def time_master(func):
    def s():
        print("开始执行程序...")
        x=time.time()
        func()
        y=time.time()
        print("程序执行结束...")
        print("共好时{}秒".format(y-x))
    return s  # 返回嵌套函数的引用
@time_master  #语法糖  和fun1=time_master(fun1)一样
def fun1():
    time.sleep(1)

fun1() #该函数与定义的函数不一样了  相当与发生的重载
```

```python
def add(func):
    def inner():
        x=func()
        return x+1
    return inner

def cube(func):
    def inner():
        x=func()
        return x*x*x
    return inner

def square(func):
    def inner():
        x=func()
        return x*x
    return inner

@add
@cube
@square
#相当于 test=add( cube ( square (test) ) )  语法糖是从下往上去调用
def test():
    return 2

print(test()) # (2 * 2) ^ 3 + 1 = 65
```

## lambda表达式

```python
def squareX(x):
    return x*x
print(squareX(3))

squareY = lambda y : y*y
print(squareY(3))

输出均为 9
```

lambda就是将函数简化为一行，同时可以作为元素放进序列里。

lambda是一个表达式而不是语句，它能出现在python语法中不允许def语句出现的地方，这是它的优势，但由于所有的功能代码都局限于一个表达式中去实现，因此lambda通常也只能实现那些较为简单的需求，python希望让lambda去做那些简单的事情不用专门想出这个函数的名字，它只是一个匿名函数，def语句负责那些定义功能复杂的函数，去处理那些复杂的工作

## 生成器

```python
#fun每次调用的时候提供一个数据，每次在执行yield i的时候生成一个数据暂停并保留状态，下次调用则从下一个语句 i+=1开始继续执行
def fun():
    i=0
    while i<=5:
        yield i
        i+=1
fun() #得到一个生成器对象
for i in fun(): # i每次从后面的可迭代对象中获取一个值 
    print(i)
   
输出为 0 1 2 3 4 5
```

生成器不像列表和元组那样是一个可迭代对象，它就是一个制作机器，作用就是每调用一次函数就提供一个数据并且记住当时状态，而列表和元组这些可迭代对象是一个容器，它里面存放的是早已经准备好的数据

生成器可以看作是一个特殊的迭代器，可以用next函数

```python
#生成器表达式
t=( i**2 for i in range(10) )
```

## 函数文档，类型注释，内省

### 函数文档

用help（）去查看所需要的函数，函数文档就是注释掉的部分，该部分对该函数的功能，参数等进行了解释

```python
def exchange(dollar,rate=6.32):
    """
    功能：汇率转换，美元->人民币
    :param dollar:美元的数量
    :param rate: 汇率，默认值为6.32
    :return: 人民币的数量
    """
    return dollar * rate
print(exchange(20))
help(exchange)

输出为
126.4
Help on function exchange in module __main__:

exchange(dollar, rate=6.32)
    功能：汇率转换，美元->人民币
    :param dollar:美元的数量
    :param rate: 汇率，默认值为6.32
    :return: 人民币的数量
```

### 类型注释

```python
#期望函数s传入的值为字符串，n传入的值为整数，返回值返回字符串
def times(s:str,n:int)->str:
    return s*n
#但这只是函数希望这样传入参数，如果传入其他类型的参数，程序也能运行
def times(s:str="ggg",n:int=3)->str:
    return s*n

def times(s:list,n:int)->list:
    return s*n

def times(s:list[int],n:int)->list:
    return s*n

def times(s:dict[str:int],n:int)->list:
    return list(s.keys())*n
```

### 内省

内省指在程序运行的时候能够进行自我检测的一种机制

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-29 175025.png)

## 高阶函数

当一个函数接受另一个函数作为参数的时候，那么这个函数就被称为高阶函数，如装饰器。

## 偏函数

偏函数是指对指定的函数进行二次包装，通常是将现有的函数部分参数预先绑定从而得到一个新的函数。偏函数的作用就是将一个函数的多个参数拆分进行传递。

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-29 180350.png)

其就像一个闭包

# 类和对象

## 封装

对象=属性+方法

一个简单的类

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-29 210452.png)

部分执行结果

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-29 210640.png)

在类里面创建函数是必须传入self参数，其传递的是事例对象本身

## 继承

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-29 212224.png)

类B继承类A，其可以访问类A的属性和方法，如果类B中有与类A属性和方法相同名称的属性和方法，则对其进行覆盖

isinstance判断一个对象是不是这个类，类B继承类A，所以b也是类A的对象

issubclass用于检测一个类是否为某个类的子类

## 多重继承

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-29 212801.png)

将上例的类B重新定义，由类C继承类A和类B，其访问顺序从左到右，需调用的属性或方法在当类找不到后在第一个父类里去寻找，再找不到了就去下一个父类里寻找

## 组合

Turtle,Cat,Dog都是类，Garden是一个类，将相关的事例放进Graden里，其就形成了一个组合

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-29 213326.png)

## 构造函数

![](C:\Users\pc\Pictures\Screenshots\屏幕截图 2023-05-29 214909.png)

## 重写

其实就是覆盖
