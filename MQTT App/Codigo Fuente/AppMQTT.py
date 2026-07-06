import tkinter as Tk
from tkinter import ttk

import paho.mqtt.client as mqtt
import time

window = Tk.Tk()
window.geometry('350x350')
window.configure(bg = 'white')
bit = window.iconbitmap('Dependencias/Icono.ico')
window.title('Comunicacion MQTT')

s = ttk.Style()
s.configure('Suscribe.TRadiobutton', background = 'white')

a = ttk.Style()
a.configure('Creden.TRadiobutton', background = 'white')

grupo1 = Tk.IntVar(value=2)
grupo2 = Tk.IntVar(value=4)

grupo1 = 0
grupo2 = 1

selector = 0
selector_credenciales = 0

titulo = Tk.Label(window, text = 'Comunicación MQTT', 
               font = ("Georgia", 15, "italic"), 
               fg = 'blue', bg = 'white')
titulo.place(x = 7, y = 13)

def Modo1():
    global selector
    selector = 1
    print(selector)

def Modo2():
    global selector
    selector = 2
    print(selector)

def credenciales_SI():
    global selector_credenciales
    selector_credenciales = 1
    print(selector_credenciales)

def credenciales_NO():
    global selector_credenciales
    selector_credenciales = 2
    print(selector_credenciales)

sel_entrenamiento = ttk.Radiobutton(window, text = 'Suscribirse', 
                                    variable = grupo1, 
                                    style = 'Suscribe.TRadiobutton',
                                    value = 2, command = lambda: Modo1())
sel_entrenamiento.place(x = 230, y = 10)

sel_test = ttk.Radiobutton(window, text = 'Publicar', variable = grupo1, 
                           value = 3, command = lambda: Modo2(),
                           style = 'Suscribe.TRadiobutton')
sel_test.place(x = 230, y = 30)

titulo = Tk.Label(window, text = 'Credenciales', 
               font = ("Georgia", 10), 
               fg = 'red', bg = 'white')
titulo.place(x = 257, y = 70)

si_credenciales = ttk.Radiobutton(window, text = 'SI', 
                                    variable = grupo2, 
                                    style = 'Creden.TRadiobutton',
                                    value = 4, command = lambda: credenciales_SI())
si_credenciales.place(x = 260, y = 90)

no_credenciales = ttk.Radiobutton(window, text = 'NO', variable = grupo2, 
                           value = 5, command = lambda: credenciales_NO(),
                           style = 'Creden.TRadiobutton')
no_credenciales.place(x = 260, y = 110)

## Identificación entrada de texto

titulo = Tk.Label(window, text = 'Dirección IP:', 
               font = ("Arial", 10,), 
               fg = 'black', bg = 'white')
titulo.place(x = 20, y = 83)

titulo = Tk.Label(window, text = 'ID Cliente:', 
               font = ("Arial", 10,), 
               fg = 'black', bg = 'white')
titulo.place(x = 20, y = 63)

titulo = Tk.Label(window, text = 'Puerto:', 
               font = ("Arial", 10,), 
               fg = 'black', bg = 'white')
titulo.place(x = 20, y = 103)

titulo = Tk.Label(window, text = 'Tema:', 
               font = ("Arial", 10,), 
               fg = 'black', bg = 'white')
titulo.place(x = 20, y = 123)

titulo = Tk.Label(window, text = 'Usuario:', 
               font = ("Arial", 10,), 
               fg = 'red', bg = 'white')
titulo.place(x = 20, y = 143)

titulo = Tk.Label(window, text = 'Contraseña:', 
               font = ("Arial", 10,), 
               fg = 'red', bg = 'white')
titulo.place(x = 20, y = 163)

titulo = Tk.Label(window, text = 'KeepAlive:', 
               font = ("Arial", 10,), 
               fg = 'black', bg = 'white')
titulo.place(x = 20, y = 183)

titulo = Tk.Label(window, text = 'Mensaje:', 
               font = ("Arial", 10,), 
               fg = 'black', bg = 'white')
titulo.place(x = 20, y = 203)

titulo = Tk.Label(window, text = 'Recepción Mensaje:', 
               font = ("Arial", 13,), 
               fg = 'blue', bg = 'white')
titulo.place(x = 20, y = 243)

## Firma Aplicación

titulo = Tk.Label(window, text = 'App MQTT V1.0', 
               font = ("Arial", 7,), 
               fg = 'blue', bg = 'white')
titulo.place(x = 1, y = 322)

titulo = Tk.Label(window, text = 'Rubén Hinojar', 
               font = ("Arial", 7,), 
               fg = 'blue', bg = 'white')
titulo.place(x = 1, y = 335)

## Manipulación TXT

editor = open("Dependencias/Texto_IP.txt", "r")
IP_Address = editor.read()
editor.close()

editor = open("Dependencias/ID_Cliente.txt", "r")
ID_Cliente = editor.read()
editor.close()

editor = open("Dependencias/Puerto.txt", "r")
Puerto = editor.read()
editor.close()

editor = open("Dependencias/Tema.txt", "r")
Tema = editor.read()
editor.close()

editor = open("Dependencias/Usuario.txt", "r")
Usuario = editor.read()
editor.close()

editor = open("Dependencias/Contrasena.txt", "r")
Contrasena = editor.read()
Contrasena_dato = int(Contrasena)
editor.close()

editor = open("Dependencias/KeepAlive.txt", "r")
KeepAlive = editor.read()
editor.close()

editor = open("Dependencias/Mensaje.txt", "r")
Mensaje = editor.read()
editor.close()

## Entrada de Texto

entryText = Tk.StringVar()
entryText.set(IP_Address)
textIP = Tk.Entry(window, width = 20, textvariable=entryText)
textIP.place(x = 100, y = 85)

entryText = Tk.StringVar()
entryText.set(ID_Cliente)
textID = Tk.Entry(window, width = 20, textvariable=entryText)
textID.place(x = 100, y = 65)

entryText = Tk.StringVar()
entryText.set(Puerto)
Puerto = Tk.Entry(window, width = 20, textvariable=entryText)
Puerto.place(x = 100, y = 105)

entryText = Tk.StringVar()
entryText.set(Tema)
Tema = Tk.Entry(window, width = 20, textvariable=entryText)
Tema.place(x = 100, y = 125)

entryText = Tk.StringVar()
entryText.set(Usuario)
Usuario = Tk.Entry(window, width = 20, textvariable=entryText)
Usuario.place(x = 100, y = 145)

entryText = Tk.StringVar()
entryText.set(Contrasena)
Contrasena = Tk.Entry(window, width = 20, textvariable=entryText)
Contrasena.place(x = 100, y = 165)

entryText = Tk.StringVar()
entryText.set(KeepAlive)
KeepAlive = Tk.Entry(window, width = 20, textvariable=entryText)
KeepAlive.place(x = 100, y = 185)

entryText = Tk.StringVar()
entryText.set(Mensaje)
Mensaje = Tk.Entry(window, width = 20, textvariable=entryText)
Mensaje.place(x = 100, y = 205)

## Comunicacion MQTT

def run():
    
    textIP_dato = str(textIP.get())
    textID_dato = str(textID.get())
    Puerto_dato = int(str(Puerto.get()))
    Tema_dato = str(Tema.get())
    Usuario_dato = str(Usuario.get())
    Contrasena_dato = str(Contrasena.get())
    KeepAlive_dato = int(str(KeepAlive.get()))
    Mensaje_dato = str(Mensaje.get())

    editor = open("Dependencias/Texto_IP.txt", "w")
    editor.write(str(textIP.get()))
    editor.close()

    editor = open("Dependencias/ID_Cliente.txt", "w")
    editor.write(str(textID.get()))
    editor.close()

    editor = open("Dependencias/Puerto.txt", "w")
    editor.write(str(Puerto.get()))
    editor.close()

    editor = open("Dependencias/Tema.txt", "w")
    editor.write(str(Tema.get()))
    editor.close()

    editor = open("Dependencias/Usuario.txt", "w")
    editor.write(str(Usuario.get()))
    editor.close()

    editor = open("Dependencias/Contrasena.txt", "w")
    editor.write(str(Contrasena.get()))
    editor.close()

    editor = open("Dependencias/KeepAlive.txt", "w")
    editor.write(str(KeepAlive.get()))
    editor.close()

    editor = open("Dependencias/Mensaje.txt", "w")
    editor.write(str(Mensaje.get()))
    editor.close()
    
    if selector == 1:
        def on_message (client, userdata, message):
            print('  ')
            print('Tema = ',message.topic)
            global mensaje
            mensaje = str(message.payload.decode("utf-8"))
            print("Mensaje = ", mensaje)
            #print('message qos = ', message.qos)
            #print('message retain flag = ', message.retain)

            titulo = Tk.Label(window, text = '                                                                                                   ',
                              font = ("Georgia", 10), 
                              fg = 'black', bg = 'white')
            titulo.place(x = 20, y = 273)
            
            titulo = Tk.Label(window, font = ("Georgia", 10), 
                                fg = 'black', bg = 'white')
            titulo.place(x = 20, y = 273)

            texto = Tk.StringVar()
            texto.set(mensaje)
            titulo.config(textvariable=texto)
            
            if mensaje == 'Adios':
                client.disconnect()
                client.loop_stop()
            
        client = mqtt.Client(textID_dato, clean_session = True)

        client.on_message = on_message

        if selector_credenciales == 1:
             client.username_pw_set(Usuario_dato, password = Contrasena_dato)

        client.connect(textIP_dato, port = Puerto_dato, keepalive = KeepAlive_dato)

        client.loop_start()

        client.subscribe(Tema_dato, qos = 0)
    
    if selector == 2:

        client = mqtt.Client(textID_dato, clean_session = True)

        if selector_credenciales == 1:
            client.username_pw_set(Usuario_dato, password = Contrasena_dato)

        client.connect(textIP_dato, port = Puerto_dato, keepalive = KeepAlive_dato)

        client.publish (Tema_dato, Mensaje_dato)
        
accion = Tk.Button(window, text = 'Comunicar',
                command = lambda: run(),
                fg = 'black', bg = 'white', font = ('Georgia', 12, 'italic'))
accion.place(x = 125, y = 315)

window.mainloop()
