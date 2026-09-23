def test():
    global num
    num = 100
    print(num)
    return num

print(test())   # here we are returning the value of num from the function and printing it
num = 200
print(num)

# 列表
my_list = ['nihao', 'yo', 222, 15.5]

# 字典
my_dict = {'name': 'zhangsan', 'age': 18, 'gender': 'male'}    
# 字典的key必须是不可变类型，value可以是任意类型
# 字典的key不能重复，value可以重复
# 字典的key和value是一一对应的，key和value之间用冒号分隔，key和value之间用逗号分隔

# 元组
my_tuple = (1, 2, 3, 4, 5)
# 元组是不可变的，不能修改元组中的元素

my_list = ["nihao", "yo", 222, 15.5, True]
print(my_list)
print(type(my_list))

# 定义一个嵌套的列表
list2 = [[1, 2, 3], [4, 5, 6]]
print(list2)
print(type(list2))

# 嵌套的列表如何索引呢？
try:
    print(list2[0][1])  # 输出结果为2
    print(list2[1][2])  # 输出结果为6
    print(list2[0][2])  # 输出结果为3
    print(list2[1][0])  # 输出结果为4
    print(list2[0][0])  # 输出结果为1
    print(list2[1][1])  # 输出结果为5
    print(list2[0][3])  # 会抛出IndexError
except IndexError as e:
    print(f"索引错误: {e}")

# 定义一个嵌套的字典
dict2 = {"name": "zhangsan", "age": 18, "gender": "male", "hobbies": ["reading", "swimming"]}
print(dict2)
print(type(dict2))

# 如果将函数定义为class（类）的成员的话，那么这就是一个方法
def add(x, y):
    """ 
    这是一个加法函数
    :param x: 第一个加数
    :param y: 第二个加数
    :return: 两个数的和
    """
    return x + y

class student:
    def add(x, y):
        """
        这是一个加法函数
        :param x: 第一个加数
        :param y: 第二个加数
        :return: 两个数的和
        """
        return x + y

my_list = ["1", "2", "3", "4", "5", "6", 7, 8, 9, 0]
index = my_list.index("5")  # 查找列表中第一个等于5的元素的索引
print(index)  # 输出结果为4

index = my_list.index(7)
print(index)  # 输出结果为6

my_list[0] = "yoyoyoyoyyo"
print(my_list)

my_list[0] = "1"
print(my_list)

# insert()方法
my_list.insert(0, "0")
print(my_list)

# 追加元素
my_list.append("10")
print(my_list)

# 追加一批元素
my_list.extend([11, 12, 13, 14, 15, 16, 17, 18, 19, 20])
print(my_list)

# 删除元素
my_list.remove("10")
print(my_list)

# 删除指定位置的元素
my_list.pop(0)
print(my_list)

# 删除所有元素
my_list.clear()
print(my_list)

# 统计元素个数
my_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print(my_list.count(1))

# 列表的元素数量
print(len(my_list))

# 元组
t1 = (1, "hello", True)
t2 = ()
t3 = tuple()

tuples = [t1, t2, t3]
for t in tuples:
    print(type(t))

# 元组查找下标
print(t1.index("hello"))
print(t1.index(True))
print(t1.count(True))
print(len(t1))

my_str = "ith"

# 1. 通过下标索引取值
print(f"第一个字符: {my_str[0]}")  # 输出: i
print(f"最后一个字符: {my_str[-1]}")  # 输出: h

# 2. index方法
position = my_str.index("t")
print(f"'t'的位置: {position}")

# 3. replace方法
new_str = my_str.replace("i", "python")
print(f"替换后: {new_str}")

# 4. split方法
test_str = "hello world python"
words = test_str.split(" ")
print(f"分割结果: {words}")

# 5. strip方法
test_str2 = "  hello  "
print(f"去除空格后: '{test_str2.strip()}'")

test_str3 = "***hello***"
print(f"去除*后: '{test_str3.strip('*')}'")

# 6. 统计字符串中某字符串的出现次数
count_i = my_str.count("i")
print(f"'i'出现的次数: {count_i}")

# 7. 统计字符串的长度
length = len(my_str)
print(f"字符串长度: {length}")

my_dict = {"name": "zhangsan", "age": 18, "gender": "male"}
print(my_dict["name"])
print(my_dict["age"])
print(my_dict["gender"])

score = my_dict.pop("name")
my_dict.clear()

keys = my_dict.keys()
my_dict = {"name": "zhangsan", "age": 18, "gender": "male"}
for key in keys:
    print(key)

values = my_dict.values()
for value in values:
    print(value)

# 定义五类数据容器
numbers = [1, 2, 3, 4, 5]  # 列表
point = (10, 20)  # 元组
person = {"name": "张三", "age": 18}  # 字典
unique_items = {1, 2, 3, 4}  # 集合
text = "Hello"  # 字符串

print(len(numbers))
print(len(point))
print(len(person))
print(len(unique_items))
print(len(text))

# 容器类型转换
tuple_numbers = tuple(numbers)
print(tuple_numbers)

list_point = list(point)
print(list_point)

list_person = list(person.items())
print(list_person)

list_unique_items = list(unique_items)
print(list_unique_items)

list_text = list(text)
print(list_text)

tuple_text = tuple(text)
print(tuple_text)

set_text = set(text)
print(set_text)

set_person = set(person)
print(set_person)

set_numbers = set(numbers)
print(set_numbers)

# 函数参数示例
def my_function(name, age):
    print(f"Name: {name}, Age: {age}")

my_function("Alice", 25)
my_function(name="Alice", age=25)

def user_info(name, age, gender):
    print(name, age, gender)

user_info(name="zyx", gender="man", age=18)

def user_info_with_defaults(name, age=18, gender="man"):
    print(name, age, gender)

user_info_with_defaults(name="zyx")

def user_info_varargs(*args):
    print(args)

def user_info_kwargs(**kwargs):
    print(kwargs)

user_info_kwargs(name=2, age=3)

def test_func(compute, x, y):
    result = compute(x, y)
    return result

x, y = 0, 0
print(test_func(lambda x, y: x + y, x, y))

# 文件操作示例
try:
    with open(r"D:\学习\word.txt", "r", encoding="UTF-8") as f:
        content = f.read()
        count = content.count("L")
        print(f"字母L出现的次数为：{count}")

    with open(r"D:\学习\word.txt", "r", encoding="UTF-8") as f:
        count = 0
        for line in f:
            line = line.strip()
            words = line.split(" ")
            for word in words:
                if word == "L":
                    count += 1
        print(count)

    # 账单处理
    bill_content = """name, date, money, type, remarks
周木轮, 2022-01-01, 100000, 消费, 正式
周木轮, 2022-01-02, 300000, 收入, 正式
周木轮, 2022-01-03, 100000, 消费, 测试
林俊杰, 2022-01-01, 300000, 收入, 正式
林俊杰, 2022-01-02, 100000, 消费, 测试
林俊杰, 2022-01-03, 100000, 消费, 正式
林俊杰, 2022-01-04, 100000, 消费, 测试
林俊杰, 2022-01-05, 500000, 收入, 正式
张学友, 2022-01-01, 100000, 消费, 正式
张学友, 2022-01-02, 500000, 收入, 正式
张学友, 2022-01-03, 900000, 收入, 测试
王力宏, 2022-01-01, 500000, 消费, 正式
王力宏, 2022-01-02, 300000, 消费, 测试
王力宏, 2022-01-03, 950000, 收入, 正式
刘德华, 2022-01-01, 300000, 消费, 测试
刘德华, 2022-01-02, 100000, 消费, 正式
刘德华, 2022-01-03, 300000, 消费, 正式"""

    with open(r"D:\实验文档\bill.txt", "w", encoding="UTF-8") as fn:
        fn.write(bill_content)

    with open(r"D:\实验文档\bill.txt", "r", encoding="UTF-8") as fn, \
         open(r"D:\实验文档\bill.txt.bak", "w", encoding="UTF-8") as fw:
        for line in fn:
            line = line.strip()
            if line.split(",")[4] == "测试":
                continue
            fw.write(line + "\n")

except IOError as e:
    print(f"文件操作错误: {e}")
# 定义私有成员变量和方法
class MyClass:
    def __init__(self):
        self.__private_var = 10

    def __private_method(self):
        print("This is a private method.")

    def public_method(self):
        print("This is a public method.")
        self.__private_method()

obj = MyClass()
print(obj._MyClass__private_var)
obj.public_method()
# obj.__private_method()  # 这行代码会引发AttributeError异常
# 如何吸收异常
try:
    # 可能引发异常的代码
    pass
except Exception as e:
    # 处理异常的代码
    print(f"An error occurred: {e}")
finally:
    # 无论是否发生异常，都会执行的代码
    print("This will always execute.")

class phone:  # 定义一个名为phone的类
    __is_5G_enable = False  # 使用双下划线定义私有类属性，表示5G功能默认关闭
    def __check_5G(self):  # 使用双下划线定义私有方法，用于检查5G状态
        if self.__is_5G_enable:  # 检查5G是否开启
            print ("5G开启")  # 如果5G开启，打印提示信息
            return
        else :  # 如果5G未开启
            print("5G will close,use 4G")  # 打印使用4G的提示信息
            return
        return  # 返回（虽然这个return语句实际上不会执行到）
    def call_by_5G(self):  # 定义公共方法，通过5G拨打电话
        self.__check_5G()  # 调用私有方法检查5G状态
        print("is in the call")  # 打印通话提示信息
        return

phone=phone()  # 创建phone类的实例对象
phone.call_by_5G()  # 调用实例对象的call_by_5G方法

# 理解继承的概念


class phone:
    IMEI = None  # 序列号

    product = None  # 厂商

    def call_by_4g(self):
        print("4g phone")

        return

    pass


class phone_2022(phone):  # 这里就做出了继承
    face_id = True

    print("IMEI")

    def call_by_5G(self):
        print("2022 new phone")

        return

    pass


phone_new = phone_2022()
phone_new.call_by_5G()

# class 类名 （父亲名）
# 从父本那里继承类和方法


# 继承这里有单继承和多继承


class red_line:
    yk = "red_line"

    def control(self):
        print("red_line was open")
        return

    pass


# 多继承


class phone_2025(phone_2022, red_line):
    print("2025")
    phone.call_by_4g
    phone_2022.call_by_5G
    red_line.control
    pass


phone=phone_2025()
phone.red_line.control




