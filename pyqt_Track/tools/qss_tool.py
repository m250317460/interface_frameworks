# 封装修改样式工具
# 定义一个专门用来操作qss样式的类
class QSSTool():
 # 静态方法
 @staticmethod
 def setQssToObj(file_path,obj):
     with open(file_path, 'r') as f:
         content = f.read()
         obj.setStyleSheet(content)
