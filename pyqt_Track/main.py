
import sys

from PyQt5 import QtCore
from PyQt5.QtCore import pyqtSignal,Qt,pyqtSlot
from PyQt5.QtWidgets import QApplication,QMainWindow,QFileDialog,QLabel,QMessageBox
from mainwindow import Ui_MainWindow
from tools.qss_tool import QSSTool
import cv2
from PIL import Image
import numpy as np
import threading

class Track_window(QMainWindow,Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.pauseFlag,self.cutFlag,self.detectFlag,self.trackFlag = False,False,False,False
        self.th_stop = False

        # self.open.clicked.connect(self.openVideoFile)
    @pyqtSlot()
    def SelectVideo(self):
        print("选择文件槽函数")
        self.openVideoFile()
    @pyqtSlot()
    def SetROIArea(self):
        print("设置区域槽函数")
        # 先设置暂停，完成后继续
        self.pauseFlag = True
        # 在这里获取到要截取的部分，并且打上flag
        self.target_bbox = self.Setroi()
        print(self.target_bbox)

        self.cutFlag = True
        # 之后获取源图像的对应区域
        # target_img = (target_bbox)
        # cv2.imshow(target_img)


        self.pauseFlag = False
    # 重载关闭事件

    def closeEvent(self, e):
        self.pauseFlag = False
        self.th_stop = True


    @pyqtSlot()
    def PlayorPause(self):
        print("播放/暂停槽函数")
        self.pauseFlag = not self.pauseFlag
    @pyqtSlot()
    def Detect(self,stage):
        # 修改界面文件
        # self.isdetect.stateChanged['int'].connect(lambda: MainWindow.Detect(self.isdetect.isChecked()))
        # self.istrack.stateChanged['int'].connect(lambda: MainWindow.Track(self.istrack.isChecked()))
        print("检测槽函数")
        print(stage)
        if stage == True:
            print("开始检测")
            # 开始检测后根据 self.target_bbox 进行区域的设置,应该在播放函数中设置对应的操作
            self.detectFlag = True
        elif stage == False:
            print("停止检测")
            self.detectFlag = False
        else:
            print("检测函数意料外的情况")

    @pyqtSlot()
    def Track(self,stage):
        print("跟踪槽函数")
        if stage == True:
            print("开始跟踪")
            self.trackFlag = True
        elif stage == False:
            print("停止跟踪")
            self.trackFlag = False
        else:
            print("跟踪函数意料外的情况")

    def play(self, video_path):

        # 播放视频
        self.stopFlag = False
        self.video_capture = cv2.VideoCapture(video_path)
        if not self.video_capture.isOpened():
            raise IOError("Couldn't open webcam or video")
        print("成功打开视频文件")
        # 这里因为要进程帧的处理，所以必须使用while而不能用vlc等等播放的插件
        while True:
            if cv2.waitKey(1) & self.pauseFlag:
                continue
            if self.th_stop:
                break


            return_value, frame = self.video_capture.read()
            # 如果检测到有ROI选项,则开始同时显示ROI区域,这里是示例,这个主要用于检测模块
            if self.cutFlag:
                cv2.imshow("test",frame[self.target_bbox[1]:self.target_bbox[1]+self.target_bbox[3],self.target_bbox[0]:self.target_bbox[0]+self.target_bbox[2]])
                '''
                frame[self.target_bbox[1]:self.target_bbox[1] + self.target_bbox[3],self.target_bbox[0]:self.target_bbox[0] + self.target_bbox[2]]
                上面这个变量就是获取到的感兴趣区域
                这里可以添加对这个区域的追踪以及检测的代码
                '''
                if self.detectFlag:
                    # 这里添加检测代码
                    pass
                if self.trackFlag:
                    # 这里添加跟踪代码
                    pass

            # <class 'PIL.Image.Image'>
            # print(f"返回帧图像的格式{type(frame)},{frame.shape}")
            '''
            opencv中图像返回的mat（即frame）是BGR，需要转化为RGB
            Image打开是RGB格式
            '''
            frame = cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
            image = Image.fromarray(frame)
            # 这里转化为Pixmap即可
            image = image.toqpixmap()
            self.video_panel.setPixmap(image)


    def openVideoFile(self):
        # 获取视频文件
        videoName, _ = QFileDialog.getOpenFileName(self, "Open", "", "*.mp4;;*.avi;;All Files(*)")
        print(videoName)
        # 这里直接开始播放了
        if videoName:
            self.th = threading.Thread(target=self.play(videoName))
            self.th.start()
        else:
            QMessageBox.information(self, "提示", "没有选择文件", QMessageBox.Yes)
    def Setroi(self):
        _,frame = self.video_capture.read()

        if frame!= "":
            # 获取到图片后开始剪裁,这里图片的格式需要时Numpy
            bbox = cv2.selectROI("SelectROI",frame,False)
            cv2.destroyWindow("SelectROI")
            return bbox

        else:
            QMessageBox.information(self, "提示", "请先开始播放视频再进行区域选取", QMessageBox.Yes)

if __name__ == '__main__':

    app=QApplication(sys.argv)
    QSSTool.setQssToObj('./qss/style.qss',app)

    syst=Track_window()
    syst.show()
    sys.exit(app.exec_())
