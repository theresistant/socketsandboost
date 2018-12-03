import sys
from PyQt5.QtWidgets import QMainWindow, QPushButton, QApplication, QLineEdit, QPlainTextEdit
import socket

class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        self.textbox1 = QPlainTextEdit(self)  #Creates a text box
        self.textbox1.move(40, 20)
        self.textbox1.resize(120, 100)

        self.textbox2 = QPlainTextEdit(self) #Creates another text box
        self.textbox2.move(180, 20)
        self.textbox2.resize(120,100)



        btn1 = QPushButton("Open", self) #Creates a button
        btn1.move(40, 135)
        btn2 = QPushButton("Close", self)  # Creates another button
        btn2.move(180, 135)

        btn1.clicked.connect(self.buttonClicked1)
        btn2.clicked.connect(self.buttonClicked2)

        self.statusBar()

        self.setGeometry(300, 300, 380, 300)
        self.setWindowTitle('PyQt App')
        self.show()


    def buttonClicked1(self):
        HOST = '127.0.0.1'  # The server's hostname or IP address
        PORT = 60000  # The port used by the server
        #texto = self.textbox1.text()
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((HOST, PORT))
            #t = str(texto).encode("ASCII")
            t = str('open').encode("ASCII")
            s.sendall(t)
            #data = s.recv(1024)

        #print('Received', repr(data))
        self.textbox1.appendPlainText("Opened Valve 1")
        self.textbox1.appendPlainText("Opened Valve 2")
        self.textbox1.appendPlainText("Opened Valve 3")
        self.textbox1.appendPlainText("Opened Valve 4")
        self.textbox1.appendPlainText("Opened Valve 5")
        self.textbox2.appendPlainText("Opened Valve 6")
        self.textbox2.appendPlainText("Opened Valve 7")
        self.textbox2.appendPlainText("Opened Valve 8")
        self.textbox2.appendPlainText("Opened Valve 9")
        self.textbox2.appendPlainText("Opened Valve 10")
        #s.close( )

    def buttonClicked2(self):
        HOST = '127.0.0.1'
        PORT = 60000
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((HOST, PORT))
            t = str('close').encode("ASCII")
            s.sendall(t)
        self.textbox1.clear()
        self.textbox2.clear()
        self.textbox1.appendPlainText("Closed Valve 1")
        self.textbox1.appendPlainText("Closed Valve 2")
        self.textbox1.appendPlainText("Closed Valve 3")
        self.textbox1.appendPlainText("Closed Valve 4")
        self.textbox1.appendPlainText("Closed Valve 5")
        self.textbox2.appendPlainText("Closed Valve 6")
        self.textbox2.appendPlainText("Closed Valve 7")
        self.textbox2.appendPlainText("Closed Valve 8")
        self.textbox2.appendPlainText("Closed Valve 9")
        self.textbox2.appendPlainText("Closed Valve 10")


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
