# 继承复写
class phone:
    def call_by_4g(self):
        print("4G通话")

    def call_by_5g(self):
        print("5G通话")

        return

    producer = "apple"


class myphone(phone):
    producer = "xiaomi"  # 这里就做出了覆写

    # 覆写属性
    def call_by_5g(self):
        print("5G通话 was fix")
        # 覆写方法
        return


phone_new = myphone()
phone_new.call_by_5g()
print(phone_new.producer)
# print(phone_new.call_by_5g())

# super()函数
class phone:
    def call_by_4g(self):
        print("4G通话")

    def call_by_5g(self):
        print("5G通话")

        return

    producer = "apple"  # 类属性，表示手机的生产商


class myphone(phone):  # 继承自phone类的子类
    producer = "xiaomi"  # 重写了父类的producer属性
    def call_by_5g(self):  # 重写了父类的call_by_5g方法
        print("5G通话 was fix")
        super().call_by_5g()  # 调用父类的call_by_5g方法
        # 这里难道不会被覆写吗？    
        
        # 
        return


phone_new = myphone()  # 创建myphone类的实例
phone_new.call_by_5g()  # 调用实例的call_by_5g方法
print(phone_new.producer)  # 打印实例的producer属性值

