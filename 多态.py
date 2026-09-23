# 多态
# 传入不同的参数，得到不同的结果

# 多态的体现
# 1. 不同的子类对象调用相同的方法，产生不同的结果
# 2. 多态是方法的多态，属性没有多态

# 多态的优缺点
# 优点：增加了程序的灵活性
# 缺点：无法约束子类必须有什么方法

# 多态的应用场景
# 1. 需要使用到子类对象的地方，可以使用父类对象来代替
# 2. 需要使用到子类对象的方法的地方，可以使用父类对象来代替



class Animal:# 含有抽象方法的类，称为抽象类     
    def speak(self):# 空实现的
        # 抽象类好比是定义了一个标准，规定了子类必须实现的方法


        pass
class Dog(Animal):
    def speak(self):
        print("汪汪汪")
class Cat(Animal):
    def speak(self):
        print("喵喵喵")

def make_noise(animal: Animal):# 通过使用同样的函数，传入不同的方法引用，得到不同的结果
    animal.speak()
    return

make_noise(Dog())
make_noise(Cat())

# 这里就是在说，使用父类作出声明，使用子类做实际的工作，用以获得同一个行为不同的状态，这就是多态。
# 多态的体现：不同的子类对象调用相同的方法，产生不同的结果


class AC:   # 这里就是一个抽象类，就是一个标准，规定了子类必须实现的方法
    def cool_wind(self):
        """制冷"""
        pass
    def hot_wind(self):
        """制热"""
        pass

    def swing_l_r(self):
        """左右摆风"""
        pass
    def swing_u_d(self):
        """上下摆风"""
        pass



class midea_AC(AC):
    def cool_wind(self):
        print("美的空调制冷")
    def hot_wind(self):
        print("美的空调制热")
    def swing_l_r(self):
        print("美的空调左右摆风")
    def swing_u_d(self):
        print("美的空调上下摆风")

class gree_AC(AC):
    def cool_wind(self):# 这里是必须要覆写的
        print("格力空调制冷")
    def hot_wind(self):
        print("格力空调制热")
    def swing_l_r(self):
        print("格力空调左右摆风")
    def swing_u_d(self):
        print("格力空调上下摆风")

AC.hot_wind(gree_AC())
AC.cool_wind(midea_AC())# 这样的创建是不行的，没有创建自己的实例，缺少空调实例的初始化

# 我们现在采用实例化的方式，来创建空调实例，然后调用空调的方法
midea_ac = midea_AC()
gree_ac= gree_AC()
AC.cool_wind(gree_ac)
AC.cool_wind(midea_ac)



# 多态调用示例
def test_ac(ac_instance):
    """测试空调功能的多态函数"""
    print(f"\n测试 {ac_instance.__class__.__name__} 的功能:")
    ac_instance.cool_wind()
    ac_instance.hot_wind()
    ac_instance.swing_l_r()
    ac_instance.swing_u_d()

# 创建空调实例
midea_ac = midea_AC()
gree_ac = gree_AC()

# 使用多态方式调用
test_ac(midea_ac)
test_ac(gree_ac)


class AC:
    def cool_wind(self):
        """制冷"""
        pass
    def hot_wind(self):
        """制热"""
        pass
    def swing_l_r(self):
        """左右摆风"""
        pass
    def swing_u_d(self):
        """上下摆风"""
        pass

class midea_AC(AC):
    def cool_wind(self):
        print("美的空调：急速制冷开启")
    def hot_wind(self):
        print("美的空调：变频制热中")
    def swing_l_r(self):
        print("美的空调→左右摆风")
    def swing_u_d(self):
        print("美的空调↑上下摆风")

class gree_AC(AC):
    def cool_wind(self):
        print("格力空调：冷酷外机制冷")
    def hot_wind(self):
        print("格力空调：恒温舒适制热")
    def swing_l_r(self):
        print("格力空调↔左右摆风")
    def swing_u_d(self):
        print("格力空调↕上下摆风")

# ==================== 执行部分 ====================
if __name__ == "__main__":
    print("=== 开始测试空调 ===")
    
    # 1. 创建实例
    midea = midea_AC()
    gree = gree_AC()
    
    # 2. 调用方法（这会输出结果）
    print("\n--- 测试美的空调 ---")
    midea.cool_wind()     # 输出：美的空调：急速制冷开启
    midea.hot_wind()      # 输出：美的空调：变频制热中
    midea.swing_l_r()     # 输出：美的空调→左右摆风
    
    print("\n--- 测试格力空调 ---")
    gree.cool_wind()      # 输出：格力空调：冷酷外机制冷
    gree.swing_u_d()      # 输出：格力空调↕上下摆风
    
    # 3. 演示你的写法（也能输出，但不推荐）
    print("\n--- 测试你的写法 ---")
    AC.cool_wind(midea)   # 输出：美的空调：急速制冷开启
    AC.hot_wind(gree)     # 输出：格力空调：恒温舒适制热
    
    print("\n=== 测试结束 ===")

# 定义一个名为make_cool的函数，接收一个AC类型的参数ac
    def make_cool(ac:AC):
    # 调用ac对象的cool_wind方法，执行制冷功能
        ac.cool_wind()# 调用了统一的接口

# 调用make_cool函数，并传入midea_AC类的一个实例
    make_cool(midea_AC())
    