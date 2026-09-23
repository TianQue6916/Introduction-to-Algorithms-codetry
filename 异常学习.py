print("Hello World")
# 捕获异常
try:
    # 尝试将用户输入转换为整数
    num = int(input("请输入一个整数："))
    # 打印转换后的整数
    print(num)
except ValueError:
    # 如果输入无法转换为整数，捕获ValueError异常并提示
    print("输入的不是整数")
else:
    # 如果try块中的代码没有发生异常，执行此块
    print("输入的是整数")
finally:
    # 无论是否发生异常，都会执行此块
    print("程序结束")
# 自定义异常
class MyError(Exception):
    def __init__(self, message):
        self.message = message

try:
    raise MyError("自定义异常")
except MyError as e:
    print(e.message)
# 异常处理
try:
    num = int(input("请输入一个整数："))
    print(num)
except ValueError:
    print("输入的不是整数")
else:
    print("输入的是整数")
finally:
    print("程序结束")



# 演示异常的传递性
def divide(x, y):
    try:
        result = x / y
    except ZeroDivisionError:
        print("除数不能为0")
        raise
    return result

try:
    divide(10, 0)
except ZeroDivisionError:
    print("捕获到异常")
# 演示异常的传递性
