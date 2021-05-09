import tkinter as tk
import time as time
#using the stopwatch from tkinter

class Application(tk.frame):
    
    #Variables
    
    
    #launching the application
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.createStartWidgets()
    
    def createStartWidgets(self):
        self.Breeze = tk.button(self, text="Breeze")

        #exit application button
        self.exit = tk.Button(self, text="Exit", fg="red", command=self.master.destroy)

##########################
# Guide Application Code #
##########################

#https://docs.python.org/3/library/tkinter.html

#class Application(tk.Frame):
#    def __init__(self, master=None):
#        super().__init__(master)
#        self.master = master
#        self.pack()
#        self.create_widgets()
#
#    def create_widgets(self):
#        self.hi_there = tk.Button(self)
#        self.hi_there["text"] = "Hello World\n(click me)"
#        self.hi_there["command"] = self.say_hi
#        self.hi_there.pack(side="top")
#
#        self.quit = tk.Button(self, text="QUIT", fg="red",
#                              command=self.master.destroy)
#        self.quit.pack(side="bottom")
#
#    def say_hi(self):
#        print("hi there, everyone!")

root = tk.Tk()
app = Application(master=root)
app.mainloop()