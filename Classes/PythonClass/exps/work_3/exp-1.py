# 1. 创建Person类，属性有姓名、年龄、性别，创建方法person_info打印个人信息
class Person:
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender

    def person_info(self):
        print("姓名：", self.name)
        print("年龄：", self.age)
        print("性别：", self.gender)


# 2. 创建Student类(继承Person类)，属性有学院college，班级class，重写父类person_info方法，调用父类方法打印个人信息外，学生的学院班级也打印出来。
class Student(Person):
    def __init__(self, name, age, gender, college, class_num):
        super().__init__(name, age, gender)
        self.college = college
        self.class_num = class_num

    def person_info(self):
        super().person_info()
        print("学院：", self.college)
        print("班级：", self.class_num)


# 3. 创建Teacher类(继承Person类)，属性有学院college，专业pro，重写父类person_info方法，调用父类方法打印个人信息外，老师的学院专业也打印出来。
class Teacher(Person):
    def __init__(self, name, age, gender, college, major):
        super().__init__(name, age, gender)
        self.college = college
        self.major = major

    def person_info(self):
        super().person_info()
        print("学院：", self.college)
        print("专业：", self.major)


# 4. 定义一个函数info，参数为一个实例对象，函数内调用对象的person_info方法。
def info(obj):
    obj.person_info()


# 5. 分别创建一个Person对象、一个Student对象、一个Teacher对象并调用各自的person_info方法。
p = Person("张三", 25, "男")
s = Student("李四", 20, "女", "计算机学院", "计算机科学与技术")
t = Teacher("王五", 35, "男", "计算机学院", "软件工程")

p.person_info()
print('='*20)
s.person_info()
print('='*20)
t.person_info()
print('='*20)

# 6. 以5创建的对象为参数，分别调用4定义的函数，体会类的多态性。
info(p)
print('='*20)
info(s)
print('='*20)
info(t)
