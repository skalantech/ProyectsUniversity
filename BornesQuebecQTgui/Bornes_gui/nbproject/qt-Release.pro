# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = Bornes_gui
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += BorneFontaineAjouter.cpp BorneStationnementAjouter.cpp BornesGUI.cpp SupprimerBorne.cpp main.cpp
HEADERS += BorneFontaineAjouter.h BorneStationnementAjouter.h BornesGUI.h SupprimerBorne.h
FORMS += BorneFontaineAjouter.ui BorneStationnementAjouter.ui BornesGUI.ui SupprimerBorne.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
