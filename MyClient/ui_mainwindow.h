/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QLineEdit *leditServerPort;
    QComboBox *comboServerName;
    QLabel *labelServerPort;
    QLabel *labelServerName;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSocketState;
    QPushButton *btnConnect;
    QPushButton *btnStart;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(321, 127);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(9);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(50);
        progressBar->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(progressBar, 2, 0, 1, 2);

        leditServerPort = new QLineEdit(centralWidget);
        leditServerPort->setObjectName(QStringLiteral("leditServerPort"));

        gridLayout->addWidget(leditServerPort, 1, 1, 1, 1);

        comboServerName = new QComboBox(centralWidget);
        comboServerName->setObjectName(QStringLiteral("comboServerName"));
        comboServerName->setEditable(true);

        gridLayout->addWidget(comboServerName, 0, 1, 1, 1);

        labelServerPort = new QLabel(centralWidget);
        labelServerPort->setObjectName(QStringLiteral("labelServerPort"));

        gridLayout->addWidget(labelServerPort, 1, 0, 1, 1);

        labelServerName = new QLabel(centralWidget);
        labelServerName->setObjectName(QStringLiteral("labelServerName"));

        gridLayout->addWidget(labelServerName, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelSocketState = new QLabel(centralWidget);
        labelSocketState->setObjectName(QStringLiteral("labelSocketState"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelSocketState->setFont(font);
        labelSocketState->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelSocketState);

        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));

        horizontalLayout->addWidget(btnConnect);

        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        horizontalLayout->addWidget(btnStart);

        horizontalLayout->setStretch(0, 1);

        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 2);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        leditServerPort->setText(QApplication::translate("MainWindow", "12345", Q_NULLPTR));
        comboServerName->clear();
        comboServerName->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "192.168.0.123", Q_NULLPTR)
        );
        labelServerPort->setText(QApplication::translate("MainWindow", "Server Port", Q_NULLPTR));
        labelServerName->setText(QApplication::translate("MainWindow", "Server Name", Q_NULLPTR));
        labelSocketState->setText(QApplication::translate("MainWindow", "TCP SOCKET STATE", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("MainWindow", "CONNECT", Q_NULLPTR));
        btnStart->setText(QApplication::translate("MainWindow", "START", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
