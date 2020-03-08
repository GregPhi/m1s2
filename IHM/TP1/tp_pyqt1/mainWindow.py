import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *


class MainWindow(QMainWindow):
	def __init__(self):
		super(MainWindow, self).__init__()
		QObject.__init__(self)
		self.resize(500,300)
		self.setWindowTitle("TP PyQt")

		openAct = QAction(QIcon("./open.png"), "Open", self)
		openAct.setShortcut("Ctrl+N")
		openAct.setToolTip("Open File")
		openAct.setStatusTip("Open file")
		openAct.triggered.connect(self.openFile)

		saveAct = QAction(QIcon("./save.png"), "Save", self)
		saveAct.setShortcut("Ctrl+S")
		saveAct.setToolTip("Save File")
		saveAct.setStatusTip("Save file")
		saveAct.triggered.connect(self.saveFile)

		copyAct = QAction(QIcon("./copy.png"), "Copy", self)
		copyAct.setShortcut("Ctrl+C")
		copyAct.setToolTip("Copy File")
		copyAct.setStatusTip("Copy file")

		quitAct = QAction(QIcon("./quit.png"), "Quit", self)
		quitAct.setShortcut("Ctrl+Q")
		quitAct.setToolTip("Quit File")
		quitAct.setStatusTip("Quit file")
		quitAct.triggered.connect(self.quitApp)

		bar = self.menuBar()
		fileMenu = bar.addMenu( "File" )
		fileMenu.addAction(openAct)
		fileMenu.addAction(saveAct)
		fileMenu.addAction(quitAct)
		fileMenu.addAction(copyAct)

		self.textEdit = QTextEdit()
		self.setCentralWidget(self.textEdit)

		statusBar = QStatusBar(self)
		self.setStatusBar(statusBar)

	def closeEvent(self, event):
		choice = QMessageBox.question(self, 'Quit !',"Do you want to quit ?", QMessageBox.Yes | QMessageBox.No)
		if choice == QMessageBox.Yes:
			event.accept()
		else:
			event.ignore()

	def edit(self):
		self.textEdit = QTextEdit()
		self.setCentralWidget(self.textEdit)

	def openFile(self):
		fileName = QFileDialog.getOpenFileName(self, "Open")
		file = open(fileName[0],'r')
		self.edit()
		with file:
			text = file.read()
			self.textEdit.setText(text)

	def saveFile(self):
		fileName = QFileDialog.getSaveFileName(self, "Save")
		file = open(fileName[0],'w')
		text = self.textEdit.toPlainText()
		file.write(text)
		file.close()

	def quitApp(self):
		choice = QMessageBox.question(self, 'Quit !',"Do you want to quit ?", QMessageBox.Yes | QMessageBox.No)
		if choice == QMessageBox.Yes:
			print("QUIT !")
			sys.exit()
		else:
			pass

def main(args):
	app = QApplication(args)
	win = MainWindow()
	win.show();
	app.exec()

if __name__ == "__main__":
	main(sys.argv)
