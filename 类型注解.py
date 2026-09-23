# 变量类型注解
name: str = "CodeGeeX"
age: int = 25
var_1:int = 10
var_2:float = 3.14
var_3:bool = True

# 函数参数和返回值类型注解
def greet(name: str) -> str:
    return f"Hello, {name}!"
# 类属性和方法类型注解
class Person:
    def __init__(self, name: str, age: int):
        self.name: str = name
        self.age: int = age

    def say_hello(self) -> None:
        print(f"Hello, my name is {self.name} and I am {self.age} years old.")
# 类型注解的检查
def add(a: int, b: int) -> int:
    return a + b

import random

var_1=random.randint(1,10)       # type: int
var_2=random.randint(1,10)       # type: int
print(add(var_1,var_2))
# 类型注解的检查    
def add(a: int, b: int) -> int:
    return a + b
var_2=random.randint(1,10)
print(add(var_1,var_2))

def func(data:int, data2:int) -> int:# 函数参数和返回值类型注解
    return data + data2


func(1,2)
# func(1,"2")

# union类型注解
def process_data(data: int | str) -> None:
    if isinstance(data, int):
        print(f"Processing integer: {data}")
    elif isinstance(data, str):
        print(f"Processing string: {data}")
    else:
        print("Unsupported data type")

    # 这里是用于处理数据类型没有什么规律的方式

from typing import Union

my_list:list[Union[int, str]] = [1, "two", 3, "four"]
# 只需要使用方括号就可以调用union集合

    # 这里是用于处理数据类型没有什么规律的方式  

def func(data:Union[int, str]) -> None:
    if isinstance(data, int):
        print(f"Processing integer: {data}")
    elif isinstance(data, str):
        print(f"Processing string: {data}")
    else:
        print("Unsupported data type")

func(1)
func("2")
