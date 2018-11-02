/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_6;
    QFrame *frame_9;
    QLabel *label_5;
    QFrame *frame_10;
    QFrame *line;
    QFrame *frame_17;
    QPushButton *pushButton_2;
    QFrame *frame_5;
    QLabel *label;
    QPushButton *btnPlay_2;
    QPushButton *btnPlay;
    QFrame *frame_3;
    QSpinBox *spinBox;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QComboBox *comboBox;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_8;
    QFrame *frame_7;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QFrame *frame_4;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->setWindowModality(Qt::NonModal);
        Settings->resize(321, 361);
        Settings->setStyleSheet(QStringLiteral(""));
        Settings->setModal(false);
        frame = new QFrame(Settings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 301, 341));
        frame->setStyleSheet(QLatin1String("#frame {\n"
"	border-radius: 3px;\n"
"\n"
"	background: url(:/data/bg.png);\n"
"\n"
"	border: 1px solid rgba(0, 0, 0, 255);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 301, 341));
        frame_2->setStyleSheet(QLatin1String("#frame_2 {\n"
"	border: 0;\n"
"	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(0, 0, 301, 31));
        frame_6->setStyleSheet(QLatin1String("#frame_6 {\n"
"	background-color: qlineargradient(spread:pad, x1:0.006, y1:1, x2:0, y2:0, stop:0.0113636 rgba(100, 0, 0, 210), stop:1 rgba(200, 0, 0, 210));\n"
"\n"
"	border-top: 1px solid rgba(255, 67, 70, 150);\n"
"	border-bottom: 1px solid rgb(0, 0, 0);\n"
"\n"
"	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"}"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_9 = new QFrame(frame_6);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setGeometry(QRect(0, 0, 301, 31));
        frame_9->setStyleSheet(QLatin1String("#frame_9 {\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 50), stop:1 rgba(0, 0, 0, 0));\n"
"\n"
"	border: 0;\n"
"}"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_9);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 0, 221, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lao UI"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label_5->setFont(font);
        label_5->setStyleSheet(QLatin1String("color: #fff;\n"
"padding-left: 4px;\n"
"padding-top: -2px;"));
        frame_10 = new QFrame(frame_9);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setGeometry(QRect(6, 6, 16, 18));
        frame_10->setStyleSheet(QLatin1String("background: url(:/data/settings.png);\n"
"border: 0;"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        line = new QFrame(frame_9);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(30, 6, 1, 18));
        line->setStyleSheet(QLatin1String("background: rgba(0, 0, 0, 50);\n"
"border: 0;"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        frame_17 = new QFrame(frame_9);
        frame_17->setObjectName(QStringLiteral("frame_17"));
        frame_17->setGeometry(QRect(0, 0, 591, 31));
        frame_17->setStyleSheet(QStringLiteral("border: 0;"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame_17);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(276, 7, 18, 18));
        pushButton_2->setStyleSheet(QLatin1String("#pushButton_2 {\n"
"	background: url(:/data/close.png);\n"
"	\n"
"	border: 0;\n"
"}\n"
"\n"
"#pushButton_2:hover {\n"
"	background: url(:/data/close_hover.png);\n"
"}"));
        frame_6->raise();
        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(0, 29, 301, 311));
        frame_5->setStyleSheet(QLatin1String("#frame_5 {\n"
"	background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0.006, stop:0 rgba(0, 0, 0, 200), stop:0.943182 rgba(0, 0, 0, 0), stop:1 rgba(0, 0, 0, 97));\n"
"\n"
"	border: 0;\n"
"}"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 281, 21));
        label->setStyleSheet(QLatin1String("#label {\n"
"	background: rgb(59, 59, 59);\n"
"\n"
"	padding-left: 5px;\n"
"\n"
"	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"\n"
"	color: rgb(235, 235, 235);\n"
"}"));
        btnPlay_2 = new QPushButton(frame_5);
        btnPlay_2->setObjectName(QStringLiteral("btnPlay_2"));
        btnPlay_2->setGeometry(QRect(140, 280, 71, 24));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0.006, 1, 0, 0);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(0.006, 1, 0, 0);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient1.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QLinearGradient gradient2(0.006, 1, 0, 0);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient2.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0.006, 1, 0, 0);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient3.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0.006, 1, 0, 0);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient4.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QLinearGradient gradient5(0.006, 1, 0, 0);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient5.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient6(0.006, 1, 0, 0);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient6.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush7(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient7(0.006, 1, 0, 0);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient7.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush8(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QLinearGradient gradient8(0.006, 1, 0, 0);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient8.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush9(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        btnPlay_2->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(8);
        btnPlay_2->setFont(font1);
        btnPlay_2->setStyleSheet(QLatin1String("#btnPlay_2 {\n"
"	background-color: qlineargradient(spread:pad, x1:0.006, y1:1, x2:0, y2:0, stop:0.0113636 rgba(75, 0, 0, 225), stop:1 rgba(175, 0, 0, 225));\n"
"\n"
"	border-top: 1px solid rgba(255, 67, 70, 150);\n"
"	border-bottom: 1px solid rgb(0, 0, 0);\n"
"\n"
"	border-radius: 3px;\n"
"\n"
"	padding-top: -4px;\n"
"\n"
"	color: #fff;\n"
"}\n"
"\n"
"#btnPlay_2:hover {\n"
"	background-color: qlineargradient(spread:pad, x1:0.006, y1:1, x2:0, y2:0, stop:0.0113636 rgba(100, 0, 0, 255), stop:1 rgba(200, 0, 0, 225));\n"
"}\n"
"\n"
"#btnPlay:pressed {\n"
"	/*background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(218, 77, 0, 255), stop:1 rgba(255, 138, 0, 255));\n"
"\n"
"	border: 1px solid rgba(170, 0, 0, 150);*/\n"
"\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(81, 0, 0, 255), stop:1 rgba(153, 0, 0, 255));\n"
"}\n"
"\n"
"#btnPlay:disabled {\n"
"	background-color: qlineargradient(spread:pad, x1:0.006, y1:1, x2:0, y2:0, stop:0.0113636 rgba(43, 43, "
                        "43, 255), stop:0.994318 rgba(79, 79, 79, 255));\n"
"\n"
"	border-top: 1px solid rgb(0, 0, 0);\n"
"\n"
"	color: rgb(175, 175, 175);\n"
"}"));
        btnPlay_2->setFlat(true);
        btnPlay = new QPushButton(frame_5);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setGeometry(QRect(220, 280, 71, 24));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient9(0.006, 1, 0, 0);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient9.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush10(gradient9);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient10(0.006, 1, 0, 0);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient10.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush11(gradient10);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush11);
        QLinearGradient gradient11(0.006, 1, 0, 0);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient11.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush12(gradient11);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient12(0.006, 1, 0, 0);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient12.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush13(gradient12);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient13(0.006, 1, 0, 0);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient13.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush14(gradient13);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        QLinearGradient gradient14(0.006, 1, 0, 0);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0.0113636, QColor(75, 0, 0, 225));
        gradient14.setColorAt(1, QColor(175, 0, 0, 225));
        QBrush brush15(gradient14);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush15);
        QBrush brush16(QColor(175, 175, 175, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        QLinearGradient gradient15(0.006, 1, 0, 0);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0.0113636, QColor(43, 43, 43, 255));
        gradient15.setColorAt(0.994318, QColor(79, 79, 79, 255));
        QBrush brush17(gradient15);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        QLinearGradient gradient16(0.006, 1, 0, 0);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0.0113636, QColor(43, 43, 43, 255));
        gradient16.setColorAt(0.994318, QColor(79, 79, 79, 255));
        QBrush brush18(gradient16);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush18);
        QLinearGradient gradient17(0.006, 1, 0, 0);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0.0113636, QColor(43, 43, 43, 255));
        gradient17.setColorAt(0.994318, QColor(79, 79, 79, 255));
        QBrush brush19(gradient17);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush19);
        btnPlay->setPalette(palette1);
        btnPlay->setFont(font1);
        btnPlay->setStyleSheet(QLatin1String("#btnPlay {\n"
"	background-color: qlineargradient(spread:pad, x1:0.006, y1:1, x2:0, y2:0, stop:0.0113636 rgba(75, 0, 0, 225), stop:1 rgba(175, 0, 0, 225));\n"
"\n"
"	border-top: 1px solid rgba(255, 67, 70, 150);\n"
"	border-bottom: 1px solid rgb(0, 0, 0);\n"
"\n"
"	border-radius: 3px;\n"
"\n"
"	padding-top: -4px;\n"
"\n"
"	color: #fff;\n"
"}\n"
"\n"
"#btnPlay:hover {\n"
"	background-color: qlineargradient(spread:pad, x1:0.006, y1:1, x2:0, y2:0, stop:0.0113636 rgba(100, 0, 0, 255), stop:1 rgba(200, 0, 0, 225));\n"
"}\n"
"\n"
"#btnPlay:pressed {\n"
"	/*background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(218, 77, 0, 255), stop:1 rgba(255, 138, 0, 255));\n"
"\n"
"	border: 1px solid rgba(170, 0, 0, 150);*/\n"
"\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(81, 0, 0, 255), stop:1 rgba(153, 0, 0, 255));\n"
"}\n"
"\n"
"#btnPlay:disabled {\n"
"	background-color: qlineargradient(spread:pad, x1:0.006, y1:1, x2:0, y2:0, stop:0.0113636 rgba(43, 43, 43, "
                        "255), stop:0.994318 rgba(79, 79, 79, 255));\n"
"\n"
"	border-top: 1px solid rgb(0, 0, 0);\n"
"\n"
"	color: rgb(175, 175, 175);\n"
"}"));
        btnPlay->setFlat(true);
        frame_3 = new QFrame(frame_5);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 30, 281, 171));
        frame_3->setStyleSheet(QLatin1String("#frame_3 {\n"
"	background: rgb(99, 99, 99);\n"
"\n"
"	border-bottom-left-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        spinBox = new QSpinBox(frame_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(50, 10, 81, 22));
        spinBox->setMaximum(9999);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 13, 41, 16));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 13, 41, 16));
        spinBox_2 = new QSpinBox(frame_3);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(190, 10, 81, 22));
        spinBox_2->setMaximum(9999);
        comboBox = new QComboBox(frame_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 50, 221, 22));
        comboBox->setEditable(false);
        comboBox->setInsertPolicy(QComboBox::InsertAtTop);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 53, 41, 16));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1, 101, 281, 41));
        line_2 = new QFrame(frame_3);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 81, 261, 20));
        line_2->setStyleSheet(QStringLiteral("color: rgb(50, 50, 50)"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::HLine);
        line_3 = new QFrame(frame_3);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 143, 261, 20));
        line_3->setStyleSheet(QStringLiteral("color: rgb(50, 50, 50)"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setFrameShape(QFrame::HLine);
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 100, 281, 41));
        frame_7 = new QFrame(frame_5);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setGeometry(QRect(10, 230, 281, 41));
        frame_7->setAutoFillBackground(false);
        frame_7->setStyleSheet(QLatin1String("#frame_7 {\n"
"	background: rgb(99, 99, 99);\n"
"\n"
"	border-bottom-left-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"}"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        comboBox_2 = new QComboBox(frame_7);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 9, 260, 22));
        comboBox_2->setEditable(false);
        comboBox_2->setInsertPolicy(QComboBox::InsertAtTop);
        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 210, 281, 21));
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QLatin1String("#label_3 {\n"
"	background: rgb(59, 59, 59);\n"
"\n"
"	padding-left: 5px;\n"
"\n"
"	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"\n"
"	color: rgb(235, 235, 235);\n"
"}"));
        frame_4 = new QFrame(Settings);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(60, 450, 120, 80));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", Q_NULLPTR));
        label_5->setText(QApplication::translate("Settings", "<html><head/><body><p>Settings</p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Settings", "Close", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QString());
        label->setText(QApplication::translate("Settings", "Resolution", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnPlay_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnPlay_2->setText(QApplication::translate("Settings", "Cancel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnPlay->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnPlay->setText(QApplication::translate("Settings", "Apply", Q_NULLPTR));
        label_2->setText(QApplication::translate("Settings", "Width", Q_NULLPTR));
        label_4->setText(QApplication::translate("Settings", "Height", Q_NULLPTR));
        comboBox->setCurrentText(QString());
        label_6->setText(QApplication::translate("Settings", "Screen", Q_NULLPTR));
        label_7->setText(QApplication::translate("Settings", "<html><head/><body><p align=\"center\"><span style=\" color:#000000;\">Fullscreen (Windowed) is recommended for</span></p><p align=\"center\"><span style=\" color:#000000;\">Windows 10 and up in order to maintain compability.</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("Settings", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">Fullscreen (Windowed) is recommended for</span></p><p align=\"center\"><span style=\" color:#ffffff;\">Windows 10 and up in order to maintain compability.</span></p></body></html>", Q_NULLPTR));
        comboBox_2->setCurrentText(QString());
        label_3->setText(QApplication::translate("Settings", "Version", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
